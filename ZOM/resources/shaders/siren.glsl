#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
out float normalPos;
out vec3 pos;

void main()
{
  normalPos = position.x * 0.5  + position.y * 0.5;
  pos = vec3(position.x,position.y,1.0);

  gl_Position = position;
}

#shader fragment
#version 330 core

in vec3 pos; 
in float normalPos; 
out vec4 color;

void main()
{
  float theta = normalPos*20.0;
  
  vec3 dir1 = vec3(cos(theta),0,sin(theta)); 
  vec3 dir2 = vec3(sin(theta),0,cos(theta));
  
  float diffuse1 = dot(pos,dir1);
  float diffuse2 = dot(pos,dir2);
  
  vec3 col1 = diffuse1 * vec3(1,0,0);
  vec3 col2 = diffuse2 * vec3(0,0,1);
  
  color = vec4(col1 + col2, 1.0);
}
