#version 450 core
out vec4 color;

in VS_OUT{
    vec2 uv;
    float index;
}fs_in;

layout (binding = 1) uniform sampler2DArray color_map;

void main() {

    color = texture(color_map, vec3(fs_in.uv, fs_in.index));
}