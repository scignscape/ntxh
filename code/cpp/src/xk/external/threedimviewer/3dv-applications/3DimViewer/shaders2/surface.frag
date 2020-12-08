#ifndef __GLSL_CG_DATA_TYPES
#define saturate(type) clamp(type,0.0,1.0)
#endif

uniform sampler3D t3D;                  // 3D texture containing data
uniform sampler1D LookUp;               // color and transparency look-up texture
uniform sampler3D tRaysStartEnd;        // back-facing world coords
uniform sampler2D Noise;                // Noise offset used to remove aliasing [replacable by internal GLSL noise generator]
uniform sampler2D Depth;

varying vec4 fragWorldPosition;

uniform vec2 inputAdjustment;
uniform vec2 imageAdjustment;
uniform vec3 sVector;
uniform vec3 tResolution;
uniform float StopCondition;
uniform vec2 wSize;             // Viewport size 
uniform vec4 pl;                // plane that cuts the volume
uniform vec2 surfacePar;        // normal vector surface find parameters
uniform float textureSampling;
uniform mat4 invProjectionMatrix;
uniform mat4 invModelViewMatrix;

uniform sampler3D tSkip3D;      // skipping 3D texture
uniform vec3 skipTexSize;
uniform vec3 tSkipResolution;

uniform float skipCondition;

// Compute position against the cutting plane
float cuttingPlane(vec3 pos)
{
    return (pl.x * pos.x + pl.y * pos.y + pl.z * pos.z + pl.w);
}

// Compute plane intersection
float planeCut(vec3 pos, float value, float defvalue)
{
    return (cuttingPlane(pos) > 0.0 ? value : defvalue);
}

// Use the skipping volume to evaluate the given position
int isMeaningful(vec3 pos)
{
    // is the voxel otside of the cutting plane
    if (cuttingPlane(pos) < 0.0)
    {
        return 0;
    }

    // sample a voxel at initial position
    vec4 voxel = texture3D(tSkip3D, pos * skipTexSize);

    // minimum and maximum voxel value 
    float vmax = voxel.g;
    vmax = saturate((vmax * inputAdjustment.x + 0.001) + inputAdjustment.y);

    // is the position considered empty?
    return (vmax < skipCondition) ? 0 : 1;
}

// Compute length of the step in the 3D texture
float stepLength(vec3 path)
{
    // All converted to the first quadrant
    vec3 aPath = abs(path);

    // to be explained later
    // basically computes line/plane intersection
    vec3 t = tResolution.xyz / (aPath + 1e-20);
    float d2x = length(aPath*t.x); // intersection with a plane perpendicular to the X axis
    float d2y = length(aPath*t.y); // intersection with a plane perpendicular to the Y axis
    float d2z = length(aPath*t.z); // intersection with a plane perpendicular to the Z axis

    // return the closest intersection - that is, the correct one
    return min(d2x, min(d2y, d2z));
}

// Compute ray depth in depth buffer
float computeDepth(vec3 backWC, vec3 frontWC, float rayTermination)
{
    vec3 terminationWC = frontWC + ((backWC - frontWC) * vec3(rayTermination));
    vec4 iproj = gl_ModelViewProjectionMatrix * vec4(terminationWC, 1.0);
    iproj.z /= iproj.w;
    return (iproj.z + 1.0) * 0.5;
}


void main()
{
    // sample ray's start and end points
    vec4 backPPos = vec4(texture3D(tRaysStartEnd, vec3(gl_FragCoord.xy * wSize, 1.5 / 2.0)).xyz, 1.0);
    vec4 frontPPos = vec4(backPPos.xy, texture3D(tRaysStartEnd, vec3(gl_FragCoord.xy * wSize, 0.5 / 2.0)).z, 1.0);
    vec4 backVPos = invProjectionMatrix * backPPos;
    vec4 frontVPos = invProjectionMatrix * frontPPos;
    frontVPos /= frontVPos.w;
    backVPos /= backVPos.w;
    vec4 frontWPos = invModelViewMatrix * frontVPos;
    vec4 backWPos = invModelViewMatrix * backVPos;

    vec3 frontWC = frontWPos.xyz;
    vec3 backWC =  backWPos.xyz;
    vec4 frontTC = vec4(frontWC * 0.5 + 0.5, 0.0);
    vec4 backTC =  vec4(backWC * 0.5 + 0.5, 0.0);

    // set initial color
    vec3 color = vec3(0.0), shade;

    // set initial translucency
    float trans = 1.0;

    // maximum normal length
    float maxNormalLength = 1.0 / length(vec3(1.0, 1.0, 1.0));

    // set ray direction
    vec3 RayPath = backTC.rgb - frontTC.rgb;

    // normalized direction
    vec3 nPath = normalize(RayPath);

    // light position comes from OpenGL (hack!)
    vec3 vLight = nPath;

    // viewer is at the end of the ray
    vec3 vCamera = nPath;

    // adjust length of the step (vector)
    vec3 CoarsePath = nPath * tSkipResolution.x;

    // adjust length of the step (vector)
    //vec3 FinePath = nPath * stepLength(RayPath);
    vec3 FinePath = nPath * tResolution.x;

    // distance to travel by the ray
    float tDistance = length(RayPath);

    // length of a coarse step (scalar)
    float tCoarseStep = length(CoarsePath);

    // length of a fine step (scalar)
    float tFineStep = length(FinePath);

    // calculate the number of fine steps in a single coarse step
    int NumOfFineSteps = int(tCoarseStep / tFineStep);

    // where to start in the texture (scalar)
    float tPositionStart = texture2D(Noise, (gl_FragCoord.xy - vec2(0.5)) * wSize).r * tFineStep;

    // where to start in the texture (vector)
    vec3 vtPositionStart = frontTC.rgb + nPath * tPositionStart;

    // is the initial voxel meaningful?
    int voxelFlagStart = isMeaningful(vtPositionStart);

    // outer loop
    for (int i = 0; i < 256; i++)
    {
        // stop when (almost) no more color is being added
        // check if the ray is still vithin the textured volume
        if (trans <= StopCondition || tPositionStart > tDistance)
            break;

        // next position
        vec3 vtPositionEnd = vtPositionStart + CoarsePath;
        float tPositionEnd = tPositionStart + tCoarseStep;

        // is the end position meaningful?
        int voxelFlagEnd = isMeaningful(vtPositionEnd);

        // should this part of the volume be passed
        if ((voxelFlagStart + voxelFlagEnd) != 0)
        {
            // inner loop
            vec3 vtPosition = vtPositionStart;
            float tPosition = tPositionStart;
            for (int j = 0; j < NumOfFineSteps; j++)
            {
                // stop when (almost) no more color is being added
                if (trans <= StopCondition)
                    break;

                // z-buffer check
                if (texture2D(Depth, (gl_FragCoord.xy) * wSize).r < computeDepth(backWC, frontWC, tPosition / tDistance))
                    break;

                // sample voxel at the current position
                float voxel = planeCut(vtPosition, saturate((texture3D(t3D, vtPosition).r * inputAdjustment.x + 0.001) + inputAdjustment.y), 0.0);

                // sample Look-Up texture
                vec4 LUT = texture1D(LookUp, voxel);

                if (LUT.a < 0.99)
                {
                    // sample surrounding voxels
                    const float minvoxel = 0.7;
                    vec3 aPosition = vtPosition + vec3(0.0, 0.0, sVector[2]);
                    float N00P = planeCut(aPosition, 1.0, minvoxel) * texture3D(t3D, aPosition).r;
                    vec3 bPosition = vtPosition + vec3(0.0, 0.0, -sVector[2]);
                    float N00M = planeCut(bPosition, 1.0, minvoxel) * texture3D(t3D, bPosition).r;
                    vec3 cPosition = vtPosition + vec3(0.0, sVector[1], 0.0);
                    float N0P0 = planeCut(cPosition, 1.0, minvoxel) * texture3D(t3D, cPosition).r;
                    vec3 dPosition = vtPosition + vec3(0.0, -sVector[1], 0.0);
                    float N0M0 = planeCut(dPosition, 1.0, minvoxel) * texture3D(t3D, dPosition).r;
                    vec3 ePosition = vtPosition + vec3(sVector[0], 0.0, 0.0);
                    float NP00 = planeCut(ePosition, 1.0, minvoxel) * texture3D(t3D, ePosition).r;
                    vec3 fPosition = vtPosition + vec3(-sVector[0], 0.0, 0.0);
                    float NM00 = planeCut(fPosition, 1.0, minvoxel) * texture3D(t3D, fPosition).r;

                    // estimate a normal vector
                    vec3 normal = vec3(NP00 - NM00,
                                       N0P0 - N0M0,
                                       N00P - N00M);

                    // gradient magnitude
                    float normalLength = length(normal) * maxNormalLength;
                    float alphaDiv = pow(normalLength * surfacePar.x, surfacePar.y);

                    // add current voxel color to accumulation variable
                    // and multiply by transparency
                    // (voxel aplha * accumulated transparency)
                    if (alphaDiv > 0.005)
                    {
                        // normal vector
                        normal = normalize(normal);

                        // Shade is computed by Lambertian shading model
                        float DiffuseColor = saturate(dot(normal, vLight));

                        // Lambertian term + Ambient term
                        shade = DiffuseColor * LUT.rgb + 0.05 * LUT.rgb;

                        // accumulate color
                        float transparency = saturate(LUT.a / alphaDiv);
                        float alpha = saturate(1.0 - transparency);
                        alpha *= textureSampling;
                        color += saturate(shade) * (alpha)* trans;

                        // accumulate translucency
                        trans *= 1.0 - alpha;
                    }
                }

                // move ray to the next position - both the scalar and the vector
                vtPosition += FinePath;
                tPosition += tFineStep;
            }
        }

        // move to the next position
        vtPositionStart = vtPositionEnd;
        tPositionStart = tPositionEnd;
        voxelFlagStart = voxelFlagEnd;
    }

    // if not enought color is accumulated than fragment is discarded 
    if ((tPositionStart > tDistance) && (all(lessThan(color, vec3(0.01)))))
    {
        gl_FragData[0] = vec4(0.0, 0.0, 0.0, 0.0);
        gl_FragData[1] = vec4(1.0, 0.0, 0.0, 0.0);
    }
    else
    {
        gl_FragData[0] = vec4(saturate((color * imageAdjustment.y) + imageAdjustment.x), 0.0);
        gl_FragData[1] = vec4(0.0, (1.0 - trans), 0.0, 0.0);
    }
}
