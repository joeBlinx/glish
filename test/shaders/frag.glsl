#version 450 core
out vec4 color;
layout(std140, binding = 0) uniform ColorsBlock{
    vec4 colors;
}colors;

void main() {

    color = colors.colors;

}