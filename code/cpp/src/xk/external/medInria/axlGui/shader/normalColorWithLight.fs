/* This shader implements the scalar product between normal and vector light
 * position - vertice position if the result is positive, then the color will be
 * Red, if it is negative, the color will be blue, else it will be green
 */

varying float scalar;

void propFuncFS()
{
  // compute final color

  float epsilon = 0.0001;
  vec4 finalColor = vec4(0.0, 1.0, 0.0, 1.0); //12
  if(scalar > epsilon )
  {
      finalColor = vec4(1.0, 0.0, 0.0, 1.0);
  }

  else if(-epsilon  > scalar )
  {
      finalColor = vec4(0.0, 0.0, 1.0, 1.0);
  }
  gl_FragColor = finalColor;
}
