varying vec3 surfacePos;

void propFuncVS()
{
    // takes the texture's surface position from the 3D
    // coordinates of gl_Vertex
    surfacePos = gl_Vertex.xyz;

    // this is the critical line: set the vertex's screen position.
    // can also be written as gl_Position = ftransform();
    gl_Position = gl_ProjectionMatrix *  gl_ModelViewMatrix * gl_Vertex;
}
