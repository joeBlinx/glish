#version 450 core
out vec4 color;
layout(std140, binding = 0) uniform ColorsBlock{
    vec4 colors;
}colors;

layout(std140, binding = 2) uniform CountBlock{
    uint count;
}count;

void main() {

    color = colors.colors*clamp(float(count.count)/40000, 0., 1.);

}