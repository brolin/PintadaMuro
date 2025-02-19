#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

#define HOST "localhost"
#define PORT 12345

class testApp : public ofBaseApp{

 public:

  testApp();
  void setup();
  void update();
  void draw();

  void keyPressed  (int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void resized(int w, int h);

  ofTrueTypeFont font;
  ofxXmlSettings XML;
  ofTrueTypeFont TTF;
  
  string xmlStructure;
  string message;
  double seq; //Contador de la secuencia de muestras

 private:
  ofxOscSender sender;

};

#endif
