#include "testApp.h"
#include "LinkedList.h"
#include <iostream>

/* READ THIS FIRST!
 *
 * Before you do any development, you will need to tell the IDE where the openFrameworks libraries are installed.
 * Whenever you change computers you may have to re-do this step.
 *
 * Mac: 1) The easiest fix is to make sure your openFrameworks directories are 3 levels above your project directory.
 *         For example, on my system the .xcodeproj file is at 
 *         /Users/brinkmwj/Work/Teaching and learning/Courses/2013-2014_Fall/CSE274/git/Shuffle/Shuffle.xcodeproj 
 *         ... my openFrameworks libraries are at
 *         /Users/brinkmwj/Work/Teaching and learning/Courses/2013-2014_Fall/libs
 *
 */

//How many experiments should we do between each re-draw of the screen?
// Bigger numbers make the program much faster
#define EXPS_PER_UPDATE 2
//How many times should I call shuffle before measuring the result?
#define SHUFFLES_PER_EXP 1

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    
    //old OF default is 96 - but this results in fonts looking larger than in other programs.
	ofTrueTypeFont::setGlobalDpi(72);
    
    arial24.loadFont("arial.ttf",24);
    
    for(int i=0;i<52*52;i++){
        shuffleCounts[i] = 0;
        randCounts[i] = 0;
    }
    experimentsDone = 0;
    
    std::srand ( unsigned ( std::time(0) ) );
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<EXPS_PER_UPDATE; i++){
        doShuffleExperiment(SHUFFLES_PER_EXP);
        doRandExperiment();
        experimentsDone += 1;
    }
}

//-----------
//Print out a matrix so that high numbers are white, low numbers are black
//-----
void testApp::drawMatrix(float x, float y, float width, float height, double matrix[], double min, double max){
    float sqWidth = width/52.0;
    float sqHeight = height/52.0;
    
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            //j corresponds to x, i corresponds to y
            double intensity = (matrix[j+i*52]-min)/(max-min);
            if(intensity < 0) intensity = 0;
            if(intensity > 1) intensity = 1;
            ofSetColor((int)(255*intensity));
            ofFill();
            ofRect(x+j*sqWidth, y+i*sqHeight, sqWidth, sqHeight);
        }
    }
}

//--------------------------------------------------------------
//Draw should always be as fast as possible, so any heavy computations
// should be done in update.
//-----
void testApp::draw(){
    //Draw the two matrices
    drawMatrix(5,5+24+5+24+5,260,260,randCounts, 0, experimentsDone/26);
    drawMatrix(260+10,5+24+5+24+5,260,260,shuffleCounts,0,experimentsDone/26);
    
    //Draw info about how long we have been running
    //Draw text in black
    ofSetColor(0);
    ostringstream stringBuilder;
    stringBuilder << experimentsDone << " experiments done" << flush;
    double strWidth = arial24.stringWidth(stringBuilder.str());
    double strX = (ofGetWidth() - strWidth)/2;
    arial24.drawString(stringBuilder.str(), strX, 260+5+24+5+24+24+5);
    
    //Clear out the string buffer for re-use
    stringBuilder.clear();
    stringBuilder.str("");
    
    //Calculate the p value for true random, and print it
    stringBuilder << "p < " << pValue(randCounts) << flush;
    strWidth = arial24.stringWidth(stringBuilder.str());
    strX = 5 + (260 - strWidth)/2;
    arial24.drawString(stringBuilder.str(), strX, 130+5+24+5+24+24+5);
    
    //Clear out the string buffer for re-use
    stringBuilder.clear();
    stringBuilder.str("");
    
    //Calculate the p value for shuffle, and print it
    stringBuilder << "p < " << pValue(shuffleCounts) << flush;
    strWidth = arial24.stringWidth(stringBuilder.str());
    strX = 10 + 260 + (260 - strWidth)/2;
    arial24.drawString(stringBuilder.str(), strX, 130+5+24+5+24+24+5);
    
    //Clear out the string buffer for re-use
    stringBuilder.clear();
    stringBuilder.str("");
    
    //Calculate the p value for shuffle, and print it
    stringBuilder << "If shuffle is truly random, what is chance\nof this outcome? (small is bad)" << flush;
    strWidth = arial24.stringWidth(stringBuilder.str());
    strX = (ofGetWidth() - strWidth)/2;
    arial24.drawString(stringBuilder.str(), strX, 24);
}

/*
 * Use this as a comparison for your shuffle algorithm. This
 * is an implementation of the Fisher-Yates Shuffle
 * (http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle )
 * which is generally considered to be the right way to generate
 * a uniformly random permuation.
 */
void randomize(unsigned int cards[], unsigned int len){
    for(int i=1; i<len; i++){
        //We are going to swap item len-i with a random
        // item that comes before it (or itself)
        unsigned int t = cards[len-i];
        unsigned int which = rand()%(len-i+1);
        
        cards[len-i] = cards[which];
        cards[which] = t;
    }
}

void testApp::doRandExperiment(){
    //Initialize a deck of cards
    static unsigned int cards[52];
    for(int i=0;i<52;i++){
        cards[i] = i;
    }
    
    //randomly scramble it using Fisher-Yates shuffle
    randomize(cards,52);
    
    for(int i=0;i<52;i++){
        randCounts[i*52 + cards[i]] += 1.0;
    }
}

void shuffle(unsigned int cards[], unsigned int len){
   	LinkedList<int> list;
	LinkedList<int> target;
	
	target.add(0,cards[len]);
	//std::cout << target.get(0);
	
	for (int j = 0; j < len; j++){
		list.add(j,cards[j]);
	//	std::cout << list.get(j);
	}
		std::cout << std::endl;
	
	int targetSize = 1;
	int listSize = list.size();
	for (int f = 0; f < 52; f++){
		int rando = rand()%(listSize);
		std::cout << rando << std::endl;

		int rando2 = rand()%(targetSize);
		std::cout << rando2 << std::endl;
		list.splice(rando, 1, target, rando2);

		//target.add(rando2, list.get(rando));
		//list.remove(rando);
		listSize--;
		//targetSize++;
	}
	//list.splice(5, 0, target, 3);

	//for (int f = 0; f < 3; f++){
		//list.splice(0, f, target, f);
		//for (int p = 0; p < 5; p++){
			//int randomNum = rand()%(len-1);
			//int randomNum2 = rand()%(len-1);
			//list.splice(2, 1, target, 5);
			//list.splice(randomNum, 1, target, randomNum2);
			//list.splice(rand()%(len-1), rand()%(len-p+1), target, rand()%(len-p+1));
			//list.splice(list.size()-p, p, target, p);
			//target.splice(p, 4, list, p);
	//	}
	//}
	
	//for (int j = 0; j < len/2; j++){
		//list.add(j,list.get(j+1));
		
		//list.splice(j, len/2, target, j);
		//target.remove(len/2);
	//}
	//list.add(len - 1, temp);
	//std::cout << std::endl;
	
	for (int k = 0; k < len; k++){
		cards[k] = target.get(k);
		std::cout << "CARDS" << cards[k];
		}
	/*
	int temp = cards[0];
	for (int i = 0; i < len; i++){
		cards[i] = cards[i+1];
		}
	cards[len-1] = temp;*/
	
	
}

void testApp::doShuffleExperiment(int numShuffles){
    //Initialize a deck of cards
    static unsigned int cards[52];
    for(int i=0;i<52;i++){
        cards[i] = i;
    }
    
    //randomly scramble it using shuffle
    for(int i=0; i<SHUFFLES_PER_EXP;i++){
        shuffle(cards,52);
    }
    
    for(int i=0;i<52;i++){
        shuffleCounts[i*52 + cards[i]] += 1.0;
    }
}

std::string testApp::pValue(double matrix[]){
    //This implements the test of indepence, viewing our matrix
    // as a contingency table. See http://en.wikipedia.org/wiki/Pearson%27s_chi-squared_test
    //Note, however, that we are only testing one row of the matrix, which means
    // we are only testing one card ... not the whole deck.
    // To pass this test your algorithm only has to make sure the first
    // card is randomly moved. In fact, it isn't possible to use
    // a statistical test to prove a shuffle algorithm is truly random.
    // Instead, you would have to really prove it using probability theory.
    // This is just a quick and dirty test that is helpful for debugging.
    
    double chiSq = 0.0;
    double expected = ((double)experimentsDone)/52;
    for(int i=0;i<52;i++){
        double observed = matrix[i];
        chiSq += (observed-expected)*(observed-expected);
    }
    chiSq = chiSq/expected;
    
    //Critical values for 51 degrees of freedom
    double chi[] = {0.0,42.36,47.84,52.92,59.25,64.3,68.67,77.39,80.75};
    std::string p[] = {"100%","80%","60%","40%","20%","10%","5%","1%","0.5%"};

    int index = 0;
    while(index < 8){
        if(chiSq >= chi[index+1]){
            index++;
        } else {
            break;
        }
    }
    return p[index];
}
