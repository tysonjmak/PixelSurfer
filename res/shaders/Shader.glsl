#shader vertex
#version 330 core

layout (location = 0) in vec3 vb_position;
layout (location = 1) in vec3 vb_color;

out vec3 color_in;

uniform mat4 projection;

void main()
{
	color_in = vb_color;
	gl_Position = projection * vec4(vb_position, 1.0);
}

#shader fragment
#version 330 core

out vec4 frag_color;
in vec3 color_in;

void main()
{
	frag_color = vec4(color_in, 1.0f);
}
