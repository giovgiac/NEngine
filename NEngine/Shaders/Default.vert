#version 450

in vec4 position;
in vec4 color;
in vec2 textureCoordinate;

uniform mat4 transform;

out vec4 dstColor;
out vec2 texCoord;
	
void main() {
	texCoord = textureCoordinate;
	dstColor = color;
	gl_Position = transform * position;
}