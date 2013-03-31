#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofRegisterURLNotification(this);
    
    httpResponse = "NOT LOADED";
    httpsResponse = "NOT LOADED";
    httpsResponseAsync = "NOT LOADED";
    httpResponseAsync = "NOT LOADED";
    
    loaded = false;
    
    httpsURL = "https://api.instagram.com/v1/tags/selfie/media/recent?access_token=30744507.7a2f4c5.6935a8e5146a4508874ba7f034350127";
    
    httpURL = "http://api.flickr.com/services/rest/?method=flickr.photos.getRecent&api_key=76fee119f6a01912ef7d32cbedc761bb&per_page=1&format=json&nojsoncallback=1";
    
    
    ofLoadURLAsync(httpURL, "http-request");
    
    
    ofLoadURLAsync(httpsURL, "https-request");
}


void testApp::urlResponse(ofHttpResponse & response)
{
    if(response.status==200 && response.request.name == "https-request"){
        httpsResponseAsync  = ofToString(response.data);

    }if(response.status==200 && response.request.name == "http-request"){
        httpResponseAsync  = ofToString(response.data);

    }else{
		error = response.request.name+" "+ofToString(response.status)+" "+ofToString(response.data);
	}
}


//--------------------------------------------------------------
void testApp::update(){
    if(!loaded){
        
        ofHttpResponse h = ofLoadURL(httpURL);
        httpResponse = ofToString(h.data);
        
        
        ofHttpResponse p = ofLoadURL(httpsURL);
        httpsResponse = ofToString(p.data);

        loaded = true;
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
    loaded = !loaded;
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