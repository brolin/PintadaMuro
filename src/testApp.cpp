#include "testApp.h"
#include "stdio.h"

/*
  <muestra seq=1>
  <x>137</x>
  <y>115</y>
  <z>15</z>
  </muestra>
*/

//--------------------------------------------------------------
testApp::testApp(){

}

//--------------------------------------------------------------
void testApp::setup(){
  // open an outgoing connection to HOST:PORT
  sender.setup( HOST, PORT );

  if( XML.loadFile("datos.xml") ){
    message = "datos.xml loaded!";
  }else{
    message = "unable to load datos.xml check data/ folder";
  }

  cout<<message<<endl;

  double numDragTags = XML.getNumTags("muestra");

  cout<<numDragTags<<endl;

}

//--------------------------------------------------------------
void testApp::update(){
  /* Obtener valores del archivo xml */
  int x = XML.getValue("muestra:x", 0, seq);
  int y = XML.getValue("muestra:y", 0, seq);
  int z = XML.getValue("muestra:z", 0, seq);
  
  cout<<"Valor x: "<<x<<" Valor y: "<<y<<" Valor z: "<<z<<" muestra: "<<seq++<<endl;

  ofxOscMessage m;
  m.setAddress( "/brocha/aceleracion" );
  m.addIntArg( x );
  m.addIntArg( y );
  m.addIntArg( z );
  sender.sendMessage( m );
}


//--------------------------------------------------------------
void testApp::draw(){
  // display instructions
  string buf;
  buf = "sending osc messages to" + string( HOST ) + ofToString( PORT );
  ofDrawBitmapString( buf, 10, 20 );
  ofDrawBitmapString( "move the mouse to send osc message [/mouse/position <x> <y>]", 10, 50 );
  ofDrawBitmapString( "click to send osc message [/mouse/button <button> <\"up\"|\"down\">]", 10, 65 );
  ofDrawBitmapString( "press A to send osc message [/test 1 3.5 hello <time>]", 10, 80 );

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
  if ( key =='a' || key == 'A' )
    {
      ofxOscMessage m;
      m.setAddress( "/test" );
      m.addIntArg( 1 );
      m.addFloatArg( 3.5f );
      m.addStringArg( "hello" );
      m.addFloatArg( ofGetElapsedTimef() );
      sender.sendMessage( m );
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
  ofxOscMessage m;
  m.setAddress( "/mouse/position" );
  m.addIntArg( x );
  m.addIntArg( y );
  sender.sendMessage( m );
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
  ofxOscMessage m;
  m.setAddress( "/mouse/button" );
  m.addStringArg( "down" );
  sender.sendMessage( m );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
  ofxOscMessage m;
  m.setAddress( "/mouse/button" );
  m.addStringArg( "up" );
  sender.sendMessage( m );
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}
