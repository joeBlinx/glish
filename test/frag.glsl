#version 330 core
out vec4 color;
uniform vec2 col;
void main() {

    color = vec4(col[0], 0, 0, 1);

}
