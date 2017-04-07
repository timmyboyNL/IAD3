#include "ofApp.h"

void ofApp::setup() {
	ofBackground(BLACKNESS);

}


void ofApp::update() {
	
	

	

}

void ofApp::draw() {

	int elementCount = json["cnt"].asInt();
	for (int i = 0; i < elementCount; i++) {
		ofDrawBitmapString((json["list"][i]["main"]["temp_max"].asInt()), ofRandom(ofGetWidth()/2, ofGetHeight()/2), ofRandom(ofGetWidth()/2,ofGetHeight()/2));
	}

	
	//
	//	ofLog() << "Maximale temperatuur is: " << i << " : " << json["list"][i]["main"]["temp_max"] << endl;
	//}

}

void ofApp::keyPressed(int key) {
    getData();
}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}

void ofApp::getData() {
    string url = "http://api.openweathermap.org/data/2.5/forecast?q=Rotterdam,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";

    bool success = json.open(url);
    if (success) {
        int elementCount = json["cnt"].asInt();
        ofLog() << json["cnt"].asInt() << " elementen gekregen" << endl;

        for (int i = 0; i < elementCount; i++) {
			
            ofLog() << "Datum van element #" << i << " : " << json["list"][i]["main"]["temp_max"] << endl;
        }

    } else {
        ofLog() << "Oops. No data!" << endl;
    }
}