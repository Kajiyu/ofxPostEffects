#include "ofxPostEffects.h"

void ofxPostEffects::addShader(ofShader &shader){
    shaders.push_back(shader);
}

void ofxPostEffects::addShader(string filename){
    ofShader tmp;
    tmp.load(filename);
    shaders.push_back(tmp);
}


void ofxPostEffects::addShader(string vert, string frag){
    ofShader tmp;
    tmp.load(vert, frag);
    shaders.push_back(tmp);
}


void ofxPostEffects::changeShader(int num){
    index = num;
}


void ofxPostEffects::changeNextShader(){
    if(index == shaders.size()-1){
        index = 0;
    } else {
        index++;
    }
}


void ofxPostEffects::setFbo(ofFbo &fbo){
    mFbo = fbo;
    isFboSet = true;
}


void ofxPostEffects::begin(){
    if(shaders.size() > 0){
        shaders[index].begin();
        shaders[index].setUniformTexture("texture", mFbo, 0);
        shaders[index].setUniform2f("resolution", mFbo.getWidth(), mFbo.getHeight());
        shaders[index].setUniform1f("time", ofGetElapsedTimef());
        shaders[index].setUniform1f("rand", ofRandom(0.5));
        shaders[index].setUniform1f("screenWidth", ofGetWidth());
        shaders[index].setUniform1f("screenHeight", ofGetHeight());
        isShaderBegan = true;
    } else {
        cout << "[warning] There is no shader in  Manager." << endl;
        isShaderBegan = false;
    }
}


void ofxPostEffects::customSetUniform1f(string uniname, float value){
    if(shaders.size() > 0){
        if(isShaderBegan) {
            shaders[index].setUniform1f(uniname , value);
        } else {
            cout << "[warning-customSetUniform1f] Shader not begun." << endl;
        }
    } else {
    }
}


void ofxPostEffects::customSetUniform2f(string uniname, float value1, float value2){
    if(shaders.size() > 0){
        if(isShaderBegan) {
            shaders[index].setUniform2f(uniname , value1, value2);
        } else {
            cout << "[warning-customSetUniform2f] Shader not begun." << endl;
        }
    } else {
    }
}


void ofxPostEffects::end(){
    if(shaders.size() > 0){
        if(isShaderBegan){
            shaders[index].end();
            isShaderBegan = false;
        } else {
            cout << "Shader not begun." << endl;
        }
    } else {

    }
}
