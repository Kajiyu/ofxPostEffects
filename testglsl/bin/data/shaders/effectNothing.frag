#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform float time;

varying vec2 vTexCoord;

void main() {
    vec4 samplerColor = texture2DRect(texture, vTexCoord);
    gl_FragColor = vec4(samplerColor.r, samplerColor.g, samplerColor.b, 1.0);
}
