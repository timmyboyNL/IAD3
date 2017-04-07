#include <SQLiteCpp/include/SQLiteCpp/Database.h>
#include "ofApp.h"

void ofApp::setup() {
    string databasePath = ofToDataPath("bevolking.sqlite", true);
    db = new SQLite::Database(databasePath);
	bevolking.load("bevolking.png");
}

void ofApp::update() {
    int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 100, 1900, 2016, true);

    if (year != selectedYear) {
        selectedYear = year;
        string sql = "SELECT year, north, east, south, west, north+east+south+west AS total FROM bevolking WHERE year=?";

        SQLite::Statement query(*db, sql);

        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            total = query.getColumn("total").getInt();
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
            ofLog() << selectedYear << " " << total << " "
                    << north << " " << east << " " << south << " " << west
                    << endl;
        }

        query.reset();
    }

}

void ofApp::draw() {
    ofBackground(ofColor::white);

	ofSetColor(ofColor::black);
    ofDrawCircle(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2, west * 1.0f / total * 300);
    ofDrawCircle(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2, east * 1.0f / total * 300);
    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 * 0.5, north * 1.0f / total * 300);
    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 * 1.5, south * 1.0f / total * 300);

	ofSetColor(ofColor::orange);
	ofDrawBitmapString("west", ofGetWidth() / 2 * 0.5 - 16, ofGetHeight() / 2);
	ofDrawBitmapString("east", ofGetWidth() / 2 * 1.5 - 16, ofGetHeight() / 2);
	ofDrawBitmapString("north", ofGetWidth() / 2 - 18, ofGetHeight() / 2 * 0.5);
	ofDrawBitmapString("south", ofGetWidth() / 2 - 18, ofGetHeight() / 2 * 1.5);

	ofSetColor(ofColor::darkorange);
	ofDrawBitmapString(ofToString(west), ofGetWidth() / 2 * 0.5 - 16, ofGetHeight() / 2 - 10);
	ofDrawBitmapString(ofToString(east), ofGetWidth() / 2 * 1.5 - 16, ofGetHeight() / 2 - 10);
	ofDrawBitmapString(ofToString(north), ofGetWidth() / 2 - 18, ofGetHeight() / 2 * 0.5 - 10);
	ofDrawBitmapString(ofToString(south), ofGetWidth() / 2 - 18, ofGetHeight() / 2 * 1.5 - 10);

	bevolking.draw(ofGetWidth() / 2 - 50, ofGetHeight() / 2 - 50, 100, 100);
	ofDrawBitmapString(ofToString(selectedYear), ofGetWidth()/ 2 - 16, ofGetHeight() / 2 + 22);

}

void ofApp::keyPressed(int key) {
 
}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}