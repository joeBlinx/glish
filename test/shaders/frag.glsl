#version 450 core
out vec4 color;
layout(std140, binding = 0) uniform ColorsBlock{
    vec4 colors;
}colors;

layout(std140, binding = 2) uniform CountBlock{
    uint count;
}count;

in VS_OUT{
    vec2 uv;
}fs_in;

layout (binding = 3) uniform sampler2D color_map;
void main() {

    color = texture(color_map, fs_in.uv)*clamp(float(count.count)/40000, 0., 1.);
}