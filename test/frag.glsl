#version 400 core
out vec4 color;
in vec2 uv;
void main() {

    color = vec4(uv, 0, 1);

}