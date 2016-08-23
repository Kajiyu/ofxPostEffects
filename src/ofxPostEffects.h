#pragma once

#include "ofMain.h"

class ofxPostEffects {
public:
  void setFbo(ofFbo &fbo);
  void addShader(ofShader &shader);
  void addShader(string filename);
  void addShader(string vert, string frag);
  void changeShader(int num);
  void changeNextShader();
  void begin();
  void customSetUniform1f(string uniname, float value);
  void customSetUniform2f(string uniname, float value1, float value2);
  void end();

protected:
  vector<ofShader> shaders;
  int index = 0;
  bool isShaderBegan = false;
  bool isFboSet = false;
  ofFbo mFbo;
};
