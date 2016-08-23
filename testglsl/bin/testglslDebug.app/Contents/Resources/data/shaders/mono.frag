#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform float time;

varying vec2 vTexCoord;

void main() {
    vec4 samplerColor = texture2DRect(texture, vTexCoord);
    float mono = (samplerColor.r + samplerColor.g + samplerColor.b) / 3.0;
    gl_FragColor = vec4(mono, mono, mono, 1.0);
}
