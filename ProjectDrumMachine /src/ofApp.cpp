#include "ofApp.h"
#include "ofGraphics.h"
#include "ofSoundPlayer.h"
#include<time.h>


//--------------------------------------------------------------
void ofApp::setup(){

int i,j;
speed=3;
state=0;

////////////////////////////////////////////////////////////// setting up the drums
for(j=0; j<6; j++)
{
for(i=0; i<16; i++)
{
drums[j][i].set(100+60*i, 100+60*j, 40, 40);
}
}

/////////////////////////////////////////////////////////////////// setting up the moving piece
runner.set(100,500,10,10);

//////////////////////////////////////////////////////// setting up a Flag variables
for(j=0; j<6 ; j++)
{
for(i=0; i<16; i++)
{
makeSound[j][i]=0;
}
}

///////////////////////////////////////////////////////// loading the sounds
soundTom1.loadSound("tom1.aif");
soundTom2.loadSound("tom2.aif");
soundTom3.loadSound("tom3.aif");
soundHiHat.loadSound("hihat.aif");
soundSnare.loadSound("snare.aif");
soundKick.loadSound("kick.aif");

///////////////////////////////////////////////////////////// setting up the color
onColor.set(139,69,19);
offColor.set(255,222,173);

///////////////////////////////////////////////////////////// setting up controlling buttons
slower.set(100,550,100,100);
faster.set(420,550,100,100);
playPauseButton.set(750,550,100,100);

///////////////////////////////////////////////////////////// loading the images
flag.loadImage("M.jpg");
background.loadImage("background.jpg");
plusSign.loadImage("plus.png");
minusSign.loadImage("minus.png");
playButton.loadImage("play.png");

/////////////////////////////////////////////////// loading the font
myFont.loadFont("font.otf",32);
scoreFont.loadFont("scorefont.ttf",32);

}

//--------------------------------------------------------------
void ofApp::update(){
int i;
int result;
////////////////////////////////////// setting limits to the speed and changing the speed
if(speed<=3) speed=3;
if(speed>=12) speed=12;
ofSetFrameRate(speed);

/////////////////////////////////////// moves moving piece
    if(state==1)
    {
        runner.x = runner.x + 60;
        if(runner.x > 1000) runner.x=100;

////////////////////////////////////////////////// attaching sounds to the each rows
        for(i=0;i<16;i++)
            {
                if((runner.x == drums[0][i].x) && (makeSound[0][i] == 1)) soundTom1.play();
                if((runner.x == drums[1][i].x) && (makeSound[1][i] == 1)) soundTom2.play();
                if((runner.x == drums[2][i].x) && (makeSound[2][i] == 1)) soundTom3.play();
                if((runner.x == drums[3][i].x) && (makeSound[3][i] == 1)) soundHiHat.play();
                if((runner.x == drums[4][i].x) && (makeSound[4][i] == 1)) soundSnare.play();
                if((runner.x == drums[5][i].x) && (makeSound[5][i] == 1)) soundKick.play();
            }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
int i,j;
//////////////////////////////////////////////////// drawing the background
background.draw(0,0,ofGetWidth(),ofGetHeight());

////////////////////////////// drawing runner
ofSetColor(218,165,32);
ofFill();
ofRect(runner);

//////////////////////////////// drawing drums
    for(j=0; j<6; j++)
    {
        for(i=0;i<16;i++)
        {
            if(makeSound[j][i]==1) ofSetColor(onColor);
            else ofSetColor(offColor);
            ofRect(drums[j][i]);
        }
    }

/////////////////////////////////// drawing buttons
ofNoFill();
ofSetColor(139,69,19);
ofRect(faster);
ofRect(slower);

ofSetColor(139,69,19);
ofRect(playPauseButton);

ofSetColor(255,255,255);
flag.draw(0,0,180,80);
plusSign.draw(420,550,100,100);
minusSign.draw(100,550,100,100);
playButton.draw(750,550,100,100);

//////////////////////////////////// drawing or writing a text
char str[200];

/////////////////////////////////Title
sprintf(str,"Sel 0309.v1");
ofSetColor(255,248,220);
myFont.drawString(str,230,80);
ofSetColor(255,255,255);

sprintf(str,"Sound of Elegance");
ofSetColor(255,248,220);
myFont.drawString(str,700,80);
ofSetColor(255,255,255);

sprintf(str,"Drum machine");
ofSetColor(255,248,220);
myFont.drawString(str,775,540);
ofSetColor(255,255,255);

///////////////////////////////Beat
sprintf(str,"%d bpm",speed*15);
ofSetColor(255,222,173);
scoreFont.drawString(str,210,620);
ofSetColor(255,255,255);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
int i,j;
////////////////////////////////////////////////////////////// changing flag variables and make drums sound when pressed
for(j=0;j<6;j++)
{
    for(i=0;i<16;i++)
    {
        if (drums[j][i].inside(x,y))
        {
            if(makeSound[j][i]==1)
            {
                makeSound[j][i]=0;
            }

            else
            {
                makeSound[j][i]=1;
            }
            if((j==0) && (makeSound[0][i]==1)) soundTom1.play();
            if((j==1) && (makeSound[1][i]==1)) soundTom2.play();
            if((j==2) && (makeSound[2][i]==1)) soundTom3.play();
            if((j==3) && (makeSound[3][i]==1)) soundHiHat.play();
            if((j==4) && (makeSound[4][i]==1)) soundSnare.play();
            if((j==5) && (makeSound[5][i]==1)) soundKick.play();
        }

    }
}
///////////////////////////////////////////////////////// changing speed
if(faster.inside(x,y)) speed=speed+1;
if(slower.inside(x,y)) speed=speed-1;
///////////////////////////////////////////////////////// play and stop
if(playPauseButton.inside(x,y)) state^=0x01;

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
