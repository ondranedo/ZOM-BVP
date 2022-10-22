#shader vertex
#version 330 core

layout(location = 0) in vec2 position;

out float normalPos;
out vec3 pos;

void main()
{
  normalPos = (position.x + position.y)/2;
  pos = vec3(position,1.0f);

  gl_Position = vec4(position,0.0f,1.0f);
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
  
  float diffuse1 = dot( pos, dir1);
  float diffuse2 = dot( pos, dir2);
  
  vec3 col1 = diffuse1 * vec3(1,0,0.5);
  vec3 col2 = diffuse2 * vec3(0,0.5,1);
  
  color = vec4(dot(col1,col2),dot(col1,pos),dot(pos,col2), 1.0);
}
