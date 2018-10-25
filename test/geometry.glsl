#version 330
layout(triangles) in;
layout(triangle_strip, max_vertices = 30) out;

void main() {
    gl_Position = gl_in[0].gl_Position;
    EmitVertex();
    float delta = 0.785398;
    mat2 rot = mat2(
        cos(delta), -sin(delta),
        sin(delta), cos(delta)
    );
    vec4 newPos = vec4(rot*vec2(gl_in[0].gl_Position), 0, 1);
    gl_Position = newPos;
    EmitVertex();

    gl_Position = vec4(0, 0, 0, 1);
    EmitVertex();
    for (int i = 0 ; i < 5; i++){

        gl_Position = newPos;
        EmitVertex();
        newPos = vec4(rot*vec2(newPos), 0, 1);
        gl_Position = newPos;
        EmitVertex();

        gl_Position = vec4(0, 0, 0, 1);
        EmitVertex();
    }


    EndPrimitive();
}
