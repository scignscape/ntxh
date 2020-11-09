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

varying vec3 Normal;
varying vec4 EyePosition;
varying float scalar;

void propFuncVS(void)
{
  gl_Position = ftransform();

  /* Compute the position in eye coordinates. */
  EyePosition = gl_ModelViewMatrix*gl_Vertex;

  // adjust normals to eye direction
  vec3 normalCorrected = gl_Normal;
  vec3 V = normalize(gl_ModelViewMatrixInverse * vec4(0.0, 0.0, 0.0, 1.0)).xyz;

  float dotnormal = dot(gl_Normal, V);
  if(0.0 > dotnormal)
	normalCorrected = vec3(0.0 - normalCorrected.x, 0.0 - normalCorrected.y, 0.0 - normalCorrected.z);

  Normal = normalize(gl_NormalMatrix*normalCorrected);

  /* Pass lighting and coloring parameters. */
  gl_FrontColor = gl_Color;
  gl_BackColor = gl_Color;
  gl_TexCoord[0] = gl_MultiTexCoord0;

  //compute scalar
  vec3 lightDirection = normalize((gl_ModelViewMatrixInverse * gl_LightSource[0].position).xyz - gl_Vertex.xyz);// locate space
  scalar = dot(normalize(lightDirection),normalCorrected); // range [-1 1]
  scalar = (scalar + 1.0) * 6.0; // range [0 12]

}
