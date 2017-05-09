#version 450

in vec4 dstColor;
in vec2 texCoord;

uniform sampler2D texture;

out vec4 color;

void main() {
	color = texture2D(texture, texCoord) * dstColor;
}