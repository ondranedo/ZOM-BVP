#shader vertex
#version 330 core

layout(location = 0) in vec2 position;

void main()
{
	gl_Position = vec4(position,0.0f,1.f);
}

#shader fragment
#version 330 core

out vec4 colorFragment;

uniform vec4 color;

void main()
{
	colorFragment = color;
}