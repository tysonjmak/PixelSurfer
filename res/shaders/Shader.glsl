#shader vertex
#version 330 core

layout (location = 0) in vec2 a_position;
layout (location = 1) in vec2 a_tex_coords;

out vec2 o_tex_coords;
uniform mat4 projection;

void main()
{
	o_tex_coords = a_tex_coords;
	gl_Position = projection * vec4(a_position, 0.0, 1.0);
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 frag_color;

in vec2 o_tex_coords;
uniform sampler2D frag_texture;

void main()
{
	frag_color = texture(frag_texture, o_tex_coords);
}
