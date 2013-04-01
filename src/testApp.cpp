#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofRegisterURLNotification(this);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    loaded = false;
    
    httpsURL = "https://api.instagram.com/v1/tags/selfie/media/recent?access_token=30744507.7a2f4c5.6935a8e5146a4508874ba7f034350127";
    
    httpURL = "http://api.flickr.com/services/rest/?method=flickr.photos.getRecent&api_key=76fee119f6a01912ef7d32cbedc761bb&per_page=1&format=json&nojsoncallback=1";
    
    httpResponse = "NOT LOADED";
    httpsResponse = "NOT LOADED";
    httpsResponseAsync = "NOT LOADED";
    httpResponseAsync = "NOT LOADED";
    
    errorCase = 0;
}


void testApp::urlResponse(ofHttpResponse & response)
{
    if(response.status==200 && response.request.name == "https-request"){
        httpsResponseAsync  = ofToString(response.data);
        
    }else if(response.status==200 && response.request.name == "http-request"){
        httpResponseAsync  = ofToString(response.data);
        
    }else{
		error = response.request.name+" "+ofToString(response.status)+" "+ofToString(response.data);
	}
}


//--------------------------------------------------------------
void testApp::update(){
    if (errorCase == 0) {

        if(!loaded){
            ofHttpResponse h = ofLoadURL(httpURL);
            httpResponse = ofToString(h.data);
            ofHttpResponse p = ofLoadURL(httpsURL);
            httpsResponse = ofToString(p.data);
            
            ofLoadURLAsync(httpURL, "http-request");
            ofLoadURLAsync(httpsURL, "https-request");
            
            loaded = true;
        }
    }
    if (errorCase == 1) {
        
        ofLog(OF_LOG_VERBOSE, "ofLoadURL(httpURL);");
        ofHttpResponse h = ofLoadURL(httpURL);
        httpResponse = ofToString(h.data);
        
        ofLog(OF_LOG_VERBOSE, "ofLoadURL(httpsURL);");
        ofHttpResponse p = ofLoadURL(httpsURL);
        httpsResponse = ofToString(p.data);
    }
    if (errorCase == 2) {
        
        if(ofGetFrameNum()%15){
            ofLog(OF_LOG_VERBOSE, "ofLoadURLAsync(httpURL, \"http-request\");");
            ofLoadURLAsync(httpURL, "http-request");
            ofLog(OF_LOG_VERBOSE, "ofLoadURLAsync(httpsURL, \"https-request\");");
            ofLoadURLAsync(httpsURL, "https-request");
        }
    }
    if (errorCase == 3) {
        if(ofGetFrameNum()%15){
            ofLog(OF_LOG_VERBOSE, "ofLoadURL(httpsURL);");
            ofHttpResponse h = ofLoadURL(httpURL);
            ofLog(OF_LOG_VERBOSE, "ofLoadURLAsync(httpURL, \"http-request\");");
            ofLoadURLAsync(httpURL, "http-request");
            httpResponse = ofToString(h.data);
            ofLog(OF_LOG_VERBOSE, "ofLoadURLAsync(httpsURL, \"https-request\");");
            ofLoadURLAsync(httpsURL, "https-request");
        }
    }
}


//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString("httpResponse "+httpResponse, 20, 20);
    ofDrawBitmapString("httpsResponse "+httpsResponse, 20, 60);
    ofDrawBitmapString("httpResponseAsync "+httpResponseAsync, 20, 100);
    ofDrawBitmapString("httpsResponseAsync "+httpsResponseAsync, 20, 140);
    ofDrawBitmapString("error "+error, 20, 180);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    loaded = false;
    
    httpResponse = "NOT LOADED";
    httpsResponse = "NOT LOADED";
    httpsResponseAsync = "NOT LOADED";
    httpResponseAsync = "NOT LOADED";
    
    if(key == '0'){
        errorCase = 0;
    }
    if(key == '1'){
        errorCase = 1;
    }
    if(key == '2'){
        errorCase = 2;
    }
    if(key == '3'){
        errorCase = 3;
    }
    if(key == '4'){
        errorCase = 4;
    }
    if(key == '5'){
        errorCase = 5;
    }
    if(key == ' '){
       ofLoadURLAsync(httpURL, "http-request");
       ofLoadURLAsync(httpsURL, "https-request"); 
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}