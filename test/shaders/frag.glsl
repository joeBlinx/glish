#version 450 core
out vec4 color;

in VS_OUT{
    vec2 uv;
}fs_in;

layout (binding = 1) uniform sampler2D color_map;

void main() {

    color = texture(color_map, fs_in.uv);
}