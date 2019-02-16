#version 330
layout(location = 0) in vec2 pos;
layout(location = 1) in vec2 b;
layout(location = 2) in vec2 uv;


out vec2 c;
out vec2 uvout;
void main(){

    gl_Position =  vec4(vec3(pos, 0), 1);
    //c = pos;
    c = b;//vec2(0.2, 0);
    uvout = uv;
}