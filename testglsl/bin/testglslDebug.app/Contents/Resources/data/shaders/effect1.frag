#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform float time;
uniform float rand;

varying vec2 vTexCoord;
varying vec3 pos;

void main() {
    // vec4 samplerColor = texture2DRect(texture, vTexCoord);
    // gl_FragColor = vec4(samplerColor.r, samplerColor.g, samplerColor.b, 1.0);
    vec4 col = texture2DRect(texture, vTexCoord);
    vec4 col_r = texture2DRect(texture,vTexCoord + vec2(-35.0*rand,0));
    vec4 col_l = texture2DRect(texture,vTexCoord + vec2( 35.0*rand,0));
    vec4 col_g = texture2DRect(texture,vTexCoord + vec2( -10.5*rand,0));


    col.b = col.b + col_r.b*max(1.0,sin(pos.y*1.2)*2.5)*rand;
    col.r = col.r + col_l.r*max(1.0,sin(pos.y*1.2)*2.5)*rand;
    col.g = col.g + col_g.g*max(1.0,sin(pos.y*1.2)*2.5)*rand;

    gl_FragColor.rgba = col.rgba;
}
