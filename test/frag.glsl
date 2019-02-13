#version 330 core
out vec4 color;
uniform float a;
in vec2 c;
void main() {

    color = vec4(c, 0, 1);

}
