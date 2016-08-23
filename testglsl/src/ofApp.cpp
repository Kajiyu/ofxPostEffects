#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    video.setup(ofGetWidth(), ofGetHeight());
    
    postEffects.addShader("shaders/effectNothing");
    postEffects.addShader("shaders/ghostEffect");
    postEffects.addShader("shaders/effect1");
    postEffects.addShader("shaders/mono");
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if(video.isFrameNew()){
        tex.loadData(video.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    tex.draw(0,0, ofGetWidth(), ofGetHeight());
    fbo.end();
    
    //set fbo for pre-texture.
    postEffects.setFbo(fbo);
    postEffects.begin();
    postEffects.customSetUniform1f("rightDiskSize", 0.5);
    postEffects.customSetUniform1f("leftDiskSize", 0.7);
    postEffects.customSetUniform1f("disksDistance", 0.7);
    postEffects.customSetUniform1f("r_changer", 0.4);
    postEffects.customSetUniform1f("g_changer", 5000);
    postEffects.customSetUniform1f("b_changer", 7000);
    postEffects.customSetUniform1f("dark_changer", 0.4);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    postEffects.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        postEffects.changeNextShader();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
