/* This is a shader for test Isophote */

varying vec3 normal;

void propFuncVS()
{
  /* Transform the normal. */
  normal = normalize(gl_Normal);

  gl_Position = ftransform();
}
