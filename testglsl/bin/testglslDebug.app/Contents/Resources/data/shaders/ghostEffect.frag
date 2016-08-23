#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform float time;
uniform float rand;
uniform float screenWidth;
uniform float screenHeight;
uniform float rightDiskSize;
uniform float leftDiskSize;
uniform float disksDistance;
uniform float r_changer;
uniform float g_changer;
uniform float b_changer;

uniform float dark_changer;
varying vec2 vTexCoord;


const float pi = 3.145;

vec4 samplerColor() {
  return texture2DRect(texture, vTexCoord);
}

vec2 point() {
  return vec2(vTexCoord.x/screenWidth, vTexCoord.y/screenHeight);
}

float mono() {
  return (samplerColor().r + samplerColor().g + samplerColor().b) / 3.0;
}


vec2 randoms(vec2 pos)
{
  return
    fract(
      (
        pow(
          pos+2.0,
          pos.yx+2.0
        )*22222.0
      )
    );
}

vec2 rand2(vec2 pos)
{
  return randoms(randoms(pos));
}

bool inCircle(vec2 position, vec2 offset, float size) {
    float len = length(position - offset);
    if (len < size) {
        return true;
    }
    return false;
}

// float neo_rand(vec2 co){
// }


float out_r() {
  return cos(point().x*0.7)*r_changer;
}


float out_g() {
  return mono() + vTexCoord.x/g_changer+ 0.1*sin(point().x*3);
}

float out_b() {
  float output1 = mono();
  if(point().x < pi/20.0){
    output1 += cos(point().x*10.0)*0.5;
  }
  output1 += vTexCoord.y/b_changer;
  return output1;
}

void main() {
    // float out_r = 0;
    // float out_g = mono + vTexCoord.x/5000.0;
    // float out_b = neo_rand(vTexCoord);
    vec2 position = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
    if(inCircle(position,vec2(disksDistance, 0.0), leftDiskSize)){
      gl_FragColor = samplerColor();
    } else if(inCircle(position,vec2((-1.0)*disksDistance, 0.0), rightDiskSize)){
      gl_FragColor = samplerColor();
    } else {
      gl_FragColor = vec4(out_r()-dark_changer, out_g()-dark_changer, out_b()-dark_changer, 1.0);
    }
}
