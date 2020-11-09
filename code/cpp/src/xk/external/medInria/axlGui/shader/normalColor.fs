/* This is a shader for test Isophote */

varying vec3 normal;

void propFuncFS()
{
	gl_FragColor = vec4(normal, 1.0);
}
