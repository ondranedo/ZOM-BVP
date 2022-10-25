#shader vertex
#version 330 core

layout(location = 0) in vec2 position;

void main()
{
	gl_Position = vec4(position,0.0,1.0);
}

#shader fragment
#version 330 core

out vec4 colorFragment;

uniform vec2 resolution;
uniform vec2 move_dir;
uniform float zoom;

const float MAX_ITER = 215.0;

float mandelbrot(vec2 uv)
{
	vec2 c = uv*3;
	c -=  move_dir;
	c = c / pow(zoom, 6) - move_dir - vec2(0.1,0.1);
	vec2 z = vec2(0.0);
	float iter = 0.0;
	for(float i = 0.0; i < MAX_ITER; i++)
	{
		z = vec2(z.x * z.x - z.y * z.y, 2.0* z.x * z.y) + c;
		if(dot(z,z) > 4.0) return iter / MAX_ITER;
		iter++;
	}
	return 0.0;
}

vec3 hash13(float m)
{
	float x = fract(dot(m    ,m)*6513.4564);
	float y = fract(dot(m + x,m)*4522.1232);
	float z = fract(dot(m + y,m)*1123.9414);
	return vec3(x,y,z);
}

void main()
{	
	vec2 uv = (gl_FragCoord.xy - 0.5 * resolution.xy) / resolution.y;
	vec3 col = vec3(0.0);

	float m = mandelbrot(uv);
	col += hash13(m);
	col = pow(col, vec3(0.45));

	colorFragment = vec4(col, 1.0);
}