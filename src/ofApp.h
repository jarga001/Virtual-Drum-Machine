#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "ofGraphics.h"
#include "ofSoundPlayer.h"
#include "Circle.h"

class ofApp : public ofBaseApp{
	public:
        ofImage flag;
        ofImage background;
        ofImage plusSign;
        ofImage minusSign;
        ofImage playButton;

        ofSoundPlayer soundTom1;
        ofSoundPlayer soundTom2;
        ofSoundPlayer soundTom3;
        ofSoundPlayer soundHiHat;
        ofSoundPlayer soundSnare;
        ofSoundPlayer soundKick;

        ofTrueTypeFont myFont;
        ofTrueTypeFont scoreFont;

        int state;

        ofRectangle drums[100][100];

        ofColor onColor;
        ofColor offColor;

        ofRectangle runner;

        ofRectangle faster;
        ofRectangle slower;

        ofRectangle playPauseButton;

        int makeSound[6][16];

        int speed;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
