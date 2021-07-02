#version 330
layout(triangles) in;
layout(points, max_vertices = 30) out;

void main() {

    for (int i = 0; i < gl_in.length(); i++){
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
    EndPrimitive();
}
