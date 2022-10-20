#shader vertex
#version 330 core

layout(location = 0 ) in vec4 position;
layout(location = 1 ) in vec4 position;
layout(location = 2 ) in vec4 position;
layout(location = 3 ) in vec4 position;

void main()
{
	gl_Position = position;
}

#shader fragment
#version 330 core

out vec4 color;

void main()
{
	color = vec4(0.2f, 0.6f, 0.2f, 1.0f);
}