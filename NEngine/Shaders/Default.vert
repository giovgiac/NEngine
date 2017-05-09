#version 450

in vec4 position;
in vec4 color;
in vec2 textureCoordinate;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 dstColor;
out vec2 texCoord;
	
void main() {
	texCoord = textureCoordinate;
	dstColor = color;
	gl_Position = projection * view * model * position;
}