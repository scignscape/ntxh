/*
This shader implements Phong shading.  Phong shading is equivalent to
the Gouraud implemented by the standard OpenGL pipeline except that
instead of doing lighting caluclations on vertices and interpolating
colors, normals are interpolated and lighting is performed per fragment.
This can result in a much smoother surface.

Copyright 2006 Sandia Corporation.
Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
license for use of this work by or on behalf of the
U.S. Government. Redistribution and use in source and binary forms, with
or without modification, are permitted provided that this Notice and any
statement of authorship are reproduced on all copies.
*/

varying vec3 N;
varying vec3 V;
varying vec3 L;

void propFuncVS(void)
{
    // adjust normals to eye direction
    vec3 normalCorrected = gl_Normal;
    V = normalize(gl_ModelViewMatrixInverse * vec4(0.0, 0.0, 0.0, 1.0)).xyz;

    float dotnormal = dot(gl_Normal, V);
    if(0.0 > dotnormal)
        normalCorrected = vec3(0.0 - normalCorrected.x, 0.0 - normalCorrected.y, 0.0 - normalCorrected.z);

    N = normalize(gl_NormalMatrix*normalCorrected);
    V = -vec3(gl_ModelViewMatrix*gl_Vertex);
    L = vec3(gl_ModelViewMatrix*(vec4(gl_LightSource[0].position)-gl_Vertex));
    gl_Position = ftransform();
}
