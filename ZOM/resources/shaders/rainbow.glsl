#shader vertex
#version 330 core

layout(location = 0) in vec4 p;

out vec4 vertexColor;

void main()
{
	gl_Position = p;
	vertexColor = vec4(p.x,p.y,p.x*p.y,1.0f);
}

#shader fragment
#version 330 core

out vec4 color;
in vec4 vertexColor;

void main()
{
	color = vertexColor;
}