#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 535, 302+5+24+24+5, OF_WINDOW);
	ofRunApp(new testApp()); // start the app
}
