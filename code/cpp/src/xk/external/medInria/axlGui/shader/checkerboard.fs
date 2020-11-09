varying vec3 surfacePos;
const float checkSize = 0.1;

void propFuncFS()
{
    vec3 color;
    vec3 position = surfacePos / checkSize;

    float total = floor(position.x) + floor(position.z); //+ floor(position.y)

    bool isEven = mod(total, 2.0) == 0.0;

    vec4 color1 = vec4(0.0,0.0,0.0,1.0);
    vec4 color2 = vec4(1.0,1.0,1.0,1.0);

    // set the actual fragment colour.
    gl_FragColor = (isEven)? color1:color2;
}
