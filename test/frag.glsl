#version 330 core
out vec4 color;
uniform float a;

void main() {

    color = vec4(0.5, a, 0, 1);

}
