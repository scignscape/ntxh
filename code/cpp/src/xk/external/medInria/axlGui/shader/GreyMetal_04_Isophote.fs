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

varying vec3 Normal;
varying vec4 EyePosition;
varying float scalar;

uniform int NumLights;

/* Compute the contribution from a particular light source.  This basically
 * comes straight out of the OpenGL orange book. */
void DirectionalLight(in int lightIndex,
                      in vec3 normal,
                      inout vec4 ambient,
                      inout vec4 diffuse,
                      inout vec4 specular)
{
  /**** Compute ambient term. ****/
  ambient += gl_LightSource[lightIndex].ambient;

  /**** Compute diffuse term. ****/
  /* normal dot light direction.  Assume the light direction vector is already
     normalized.*/
  float nDotL = max(0.0, abs(dot(normal,
                             normalize(vec3(gl_LightSource[lightIndex].position)))));
  diffuse += gl_LightSource[lightIndex].diffuse * nDotL;

  /**** Compute specular term. ****/
  /* normal dot halfway vector */
  float nDotH = max(0.0, abs(dot(normal,
                             vec3(gl_LightSource[lightIndex].halfVector))));
  float pf;     /* Power factor. */
  if (nDotH <= 0.0)
    {
    pf = 0.0;
    }
  else
    {
    pf = pow(nDotH, 50.0);
    }
  specular += gl_LightSource[lightIndex].specular * pf;
}

void rgbToHsl(in vec3 rgb, inout vec3 hsl)
{
  float R = rgb.x;
  float G = rgb.y;
  float B = rgb.z;
  float Mt = max(rgb.x, rgb.y);
  float M  = max(Mt, rgb.z);
  float mt = min(rgb.x, rgb.y);
  float m = min(mt, rgb.z);
  float C = M - m;
  float L = 0.5 * M + 0.5 * m;
  float S = 0.0;

  int maxCase = 2;
  if(rgb.x >= rgb.y)
  {
    if(rgb.x >= rgb.z)
    {
        maxCase = 0;
    }
  }
  else if(rgb.y >= rgb.z)
  {
    maxCase = 1;
  }

 maxCase =0;

  if( C > 0.0)
    S = C / (1.0 - abs(2.0 * L - 1.0));

  float H =0.0;
   if(R >= G)
  {
      if(G >= B)
    {
        H= (G - B)/ C;
    }
  }

  if(G > R)
  {
      if(R >= B)
    {
        H= 2.0 - (R - B)/ C;
    }
  }

  if(G >= B)
  {
      if(B > R)
    {
        H= 2.0 + (B - R)/ C;
    }
  }

  if(B > G)
  {
      if(G > R)
    {
        H= 4.0 - (G - R)/ C;
    }
  }

  if(B > R)
  {
      if(R >= G)
    {
        H= 4.0 + (R - G)/ C;
    }
  }

  if(R >= B)
  {
      if(B > G)
    {
        H= 6.0 - (B - G)/ C;
    }
  }
  hsl += vec3(H,S,L);

}

void hslToRgb(in vec3 hsl, inout vec3 rgb)
{
  float C = (1.0 - abs(2.0 * hsl.z - 1.0)) * hsl.y;
  float Hprime = hsl.x * 1.0;// [0 6.0]
  float HprimeMod = Hprime;

  if(HprimeMod >= 6.0)
    HprimeMod -= 6.0;
  else if(HprimeMod >= 4.0)
    HprimeMod -= 4.0;
  else if(HprimeMod >= 2.0)
    HprimeMod -= 2.0;

  float X = C * ( 1.0 - abs(HprimeMod - 1.0));

  vec3 rgbTemp = vec3(0.0);
  if(1.0 > Hprime)
    rgbTemp = vec3(C, X, 0.0);
  else if(2.0 > Hprime)
    rgbTemp = vec3(X, C, 0.0);
  else if(3.0 > Hprime)
    rgbTemp = vec3(0.0, C, X);
  else if(4.0 > Hprime)
    rgbTemp = vec3(0.0, X, C);
  else if(5.0 > Hprime)
    rgbTemp = vec3(X, 0.0, C);
  else if(6.0 > Hprime)
    rgbTemp = vec3(C, 0.0, X);

  float m = hsl.z - 0.5 * C;

  rgb += rgbTemp;
  rgb += vec3(m, m, m);
}

void AllLights(in vec3 normal,
               inout vec4 ambient,
               inout vec4 diffuse,
               inout vec4 specular)
{
  DirectionalLight(0, normal, ambient, diffuse, specular);
  if (NumLights > 1)
    {
    DirectionalLight(1, normal, ambient, diffuse, specular);
    if (NumLights > 2)
      {
      DirectionalLight(2, normal, ambient, diffuse, specular);
      if (NumLights > 3)
        {
        DirectionalLight(3, normal, ambient, diffuse, specular);
        if (NumLights > 4)
          {
          DirectionalLight(4, normal, ambient, diffuse, specular);
          }
        }
      }
    }
}

void propFuncFS(void)
{
  /* If lighting the back of a polygon, flip normal.*/
  vec3 normal = normalize(Normal);

  /* Compute light contributions. */
  vec4 ambient = vec4(0.0);
  vec4 diffuse = vec4(0.0);
  vec4 specular = vec4(0.0);

  AllLights(normal, ambient, diffuse, specular);

  vec4 finalColor = (diffuse*vec4(0.4, 0.4, 0.4, 1.0) + specular*vec4(1.0, 1.0, 1.0, 1.0));

  // compute scalar
  int parity = int(scalar);
  float fparity = float(parity);

  if((mod(fparity, 2.0) == 0.0))
  {
    gl_FragColor = vec4(finalColor.xyz, 1.0);
  }
  else
  {
    /* reduction on the Lighness by Hsl system */
    vec3 finalColorHsl = vec3(0.0);
    rgbToHsl(finalColor.xyz, finalColorHsl);
    vec3 darkFinalColorHsl = vec3(finalColorHsl.x, finalColorHsl.y, min(1.0, 1.6 * finalColorHsl.z));
    vec3 darkFinalColorRgb = vec3(0.0);
    hslToRgb(darkFinalColorHsl, darkFinalColorRgb);
    gl_FragColor = vec4(darkFinalColorRgb, 1.0);
  }
}
