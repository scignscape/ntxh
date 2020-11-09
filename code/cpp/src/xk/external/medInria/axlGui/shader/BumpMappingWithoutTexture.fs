/* This is a fragment program for phong shading.
 *
 * This shader performs 2 sided lighting, but assumes that all lights are
 * directional (changing that would be pretty easy to fix).
 *
 * This shader supports up to 5 lights.  The number 5 was picked because that is
 * how many lights are created by light kit.
 *
 * This shader does not support mapping scalars to colors.  You need to make
 * custom variations of the shader to either do texture lookups or to
 * replace the diffuse term with gl_Color.
 */

/*
 * Copyright 2006 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

float rand(vec2 n)
{
    return 0.5 + 0.5 *
    fract(sin(dot(n.xy, vec2(12.9898, 78.233)))* 43758.5453);
}


varying vec3 normal,lightVec,viewVec, posi;

void propFuncFS()
{
    vec4 color=gl_Color;
    float r = rand(posi.xy);
    vec3 N=vec3(r,r,r);

    N.x=N.x-0.5;
    N.y=N.y-0.5;
    N.z=N.z-0.5;

    N=normalize(N);
    vec3 L=normalize(lightVec);
    vec3 V=normalize(viewVec);
    vec3 R=normalize(2.0*dot(N,V)*N-V);

    float LdotN=dot(L,N);
    float LdotR=dot(L,R);
    // diffuse
    if(0.5 > LdotN)
        color=gl_Color*LdotN*2.0;
    // speculaire
    else if(LdotR > 0.7)
        color=gl_Color*LdotR*1.5-0.05;

    vec4 temp = normalize(color) * vec4(N, 1.0);
    gl_FragColor=vec4(temp.xyz, 1.0);
}
