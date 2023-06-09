#shader vertex
#version 330 core

layout (location = 0) in vec2 a_position;
layout (location = 1) in vec2 a_tex_coords;

out vec2 v_tex_coords;

uniform mat4 u_projection;
uniform mat4 u_model;

void main()
{
	v_tex_coords = a_tex_coords;
	gl_Position = u_projection * u_model * vec4(a_position, 0.0, 1.0);
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 f_color;

in vec2 v_tex_coords;

uniform sampler2D u_texture;

void main()
{
	f_color = texture(u_texture, v_tex_coords);
}
