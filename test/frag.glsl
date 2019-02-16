#version 330 core
out vec4 color;
uniform float a;
in vec2 c;
in vec2 uvout;
uniform sampler2D text;
void main() {

    color = vec4(uvout, 0, 1);
    color = texture(text, uvout);

}
