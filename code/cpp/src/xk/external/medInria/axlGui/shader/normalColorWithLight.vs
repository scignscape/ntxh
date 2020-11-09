/* This shader implements the scalar product between normal and vector light
 * position - vertice position if the result is positive, then the color will be
 * Red, if it is negative, the color will be blue, else it will be green
 */

varying float scalar;

void propFuncVS()
{
  gl_Position = ftransform();

  //compute scalar
  vec3 lightDirection = normalize((gl_ModelViewMatrixInverse * gl_LightSource[0].position).xyz - gl_Vertex.xyz);// locate space
  scalar = dot(normalize(lightDirection),gl_Normal); // range [-1 1]
}
