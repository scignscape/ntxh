/* This is a vertex program for phong shading.  Since the lighting is done
 * in the fragment shader, it basically just transforms the vertices and
 * passes the lighting parameters.
 */

/*
 * Copyright 2006 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

varying vec3 normal,lightVec,viewVec, posi;

void propFuncVS()
{
    normal=gl_NormalMatrix*gl_Normal;
    posi.xyz = gl_Vertex.xyz;
    viewVec=-(gl_ModelViewMatrix*gl_Vertex).xyz;
    lightVec=(gl_LightSource[0].position).xyz+viewVec;
    gl_Position=ftransform();
    gl_FrontColor = gl_Color;
    gl_TexCoord[0]= gl_MultiTexCoord0;
    gl_TexCoord[1]= gl_MultiTexCoord1;
}
