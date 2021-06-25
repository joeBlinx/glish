#version 400 core
out vec4 color;
in vec2 uv;

uniform sampler2D image;
void main() {

    color = texture(image, uv)*0.5;

}