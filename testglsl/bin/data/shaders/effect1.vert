#version 120

varying vec2 vTexCoord;
varying vec3 pos;

void main() {
    vTexCoord =  gl_Vertex.xy;
    pos = gl_Vertex.xyz;
    gl_Position = ftransform();
}
