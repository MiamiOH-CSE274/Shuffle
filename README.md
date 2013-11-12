Author
==========
"Luo, Yu", luoy6
Shuffle
=======

How many times should you shuffle a deck of cards, if you want to be certain that it is actually randomly scrambled? You will solve this real-life problem via simulation. 

Using either your Queue or Linked List implementation from lab is recommended.

Background info
---------------

Standard decks of playing cards contain 52 cards. In order to play a game, one of the players usually attempts to randomize the order of the cards by "shuffling" them. Here are some well known types of shuffles:

1. "Riffle" shuffle (See: http://www.wikihow.com/Shuffle-a-Deck-of-Cards-(Riffle-Bridge) or video at http://youtu.be/o-KBNdbJOGk )
2. "Overhand" shuffle (See: http://youtu.be/N2xlgAFWBZM)
3. "Faro" or "Pharaoh" shuffle (See: http://youtu.be/ch_SMNQ-awM)
4. "Hindu" shuffle (See: http://youtu.be/LgVFb1U_fco)

Ideally, we would like the cards to be randomly shuffled, independently of where they started. So even if a card (say the Ace of Spades) is on top of the deck when you start, it is equally likely to be in any of the 52 possible positions at the end of the shuffle. In other words, we want the positions of the cards in the deck to be uniformly randomly distributed by the shuffle.

In this project you will use a data structure (either queue or linked list is recommended) to simulate shuffling a deck of cards. You will implement a simple algorithm that models/simulates a real shuffle. Then you will use this code to try to answer the question: How many times do I need to riffle the cards to get them well shuffled?

OpenFrameworks
--------------

This project uses openFrameworks to help visualize the results. You should expect that it will take you several days to get openFrameworks installed and working!

You can download openFrameworks from http://openframeworks.cc

For Windows, I recommend downloading the version for Visual Studio 10, and working with Visual C++ Express 10. For Mac, I recommend using XCode.

The best way to create an openFrameworks project is to start by cloning the project from github. Then go to the apps/myApps/ folder in your openFrameworks folder, and copy all the files from emptyExample project, *except for src*, into your repo. So you will use the src folder from github, everything else from openFrameworks.

The program ought to compile and run at this point, showing you a graphical window ... if not, it probably means that your openFrameworks library and include files are not in the right place. 

Requirements
------------

1. Implement the "shuffle" function
2. If your shuffle consists of separate steps (for example, most people will have a "cut" step and a "merge" step) implement those as separate functions
3. Try different values for the `SHUFFLES_PER_EXP` constant, and determine how many shuffles are needed to get a good result
4. Answer the questions below
5. Create and post a portfolio video, as described below

Bonus requirements
--------
These are optional, but can be worth bonus points if you come up with something interesting.

1. Can you design your shuffle so that it is:
 1. Realistic (corresponds to something you can really do in real life)
 2. NOT really random
 3. Fools the Chi-square test, and also the visual inspection
2. How would you design a statistical test that proves that your shuffle isn't random? (discuss this in your portfolio video)

Questions
=========

#### 1. Which type of shuffle did you choose? If it wasn't one of the four that I listed, please also provide me with a link to a video or text description of the shuffle you implemented.

I chose Hindu shuffle. 

#### 2. Explain, in English, the steps of your shuffling algorithm.

First, place all 52 cards into the ArrayQueue. After that, I start to remove top chunk off the ArrayQueue and place them into the cards array. The number of cards in my top chunk is represented by a random number between 1 to 20. After I removed the first top chunk, I keep doing the same process to the remaining cards in the ArrayQueue until the Queue is empty. 

#### 3. Does your algorithm reasonably simulate the actual physical process of shuffling? Explain your reasoning in a short paragraph.
Yes, I think my algorithm reasonably simulate the actual physical process of shuffling. When I do a Hindu shuffle, I need to grab a bottom chunk. I will then place the top chunk to the bottom. I will keep doing the same process to the remaining cards until the original bottom chunk is empty. 


#### 4. Do you use randomness in your algorithm (you probably *should*)? Explain how, and what random event it corresponds to in real life.

Yes, I use randomness in my algorithm. I use a random number between 1 to 20 to represent the number of cards in the top chunk. In real life, it is hard to grab exactly the same amount of bcards every time, so this randomeness is reasonable. 

#### 5. With your shuffle, how many times does it need to be repeated in order to give a random shuffle? Be sure to do several hundred thousand experiments.

With my shuffle, it needs at least 45 times in order to give a very random shuffle

Portfolio Video
=========

Explain your code, as you would to a boss or colleague in the workplace. You will most likely want to use a screen-capture software. You should, at minimum, do the following:

1. Show your program running with 2-3 different values of `SHUFFLES_PER_EXP` to show how it affects your results.
2. Show your shuffle code, briefly explaining what each function that you wrote is meant to do. You do NOT need to explain any of the provided code, unless you made some meaningful change you want to describe.
3. If something is not working (or if you aren't sure), explain that part carefully.
4. Explain which data structure you used to represent decks of cards (you might have used your ArrayQueue, your linked list, or something else), and why you chose it.
5. As you worked through the project, did you discover that your shuffle wasn't as random as you expected? What did you do to improve your shuffle algorithm? What was wrong with it?

The video should certainly be less than 2 minutes long. I (or the grading assistant) ought to be able to grade your program based solely on your video, so be sure that we can see your code style, and can accurately assess what works, or doesn't work, in your program. The "Questions" above might also be things you want to talk about in your video: The video should be able to be understood even by someone that isn't in the class, and hasn't read your question answers.

#### 1. Give the link to your portfolio video on YouTube.

Please see: http://youtu.be/e998rvGmgE0
