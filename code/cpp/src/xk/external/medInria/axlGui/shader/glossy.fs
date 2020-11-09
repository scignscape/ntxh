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

void propFuncFS()
{
    float w = 0.18*(1.0);

    vec3 l = normalize(L);
    vec3 n = normalize(N);
    vec3 v = normalize(V);
    vec3 h = normalize(l+v);

    float diffuse = abs(dot(l,n));
    float specular = smoothstep(0.72-w,0.72+w,pow(max(0.0,abs(dot(n,h))),1.0));

    gl_FragColor = vec4(gl_LightSource[0].diffuse*diffuse +gl_LightSource[0].specular*specular);
}
