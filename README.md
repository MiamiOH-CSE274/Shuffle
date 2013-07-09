Shuffle
=======

How many times should you shuffle a deck of cards, if you want to be certain that it is actually randomly scrambled? You will solve this real-life problem via simulation. 

Using either your Queue or Linked List implementation from lab is recommended.

Background info
---------------

Standard decks of playing cards contain 52 cards. In order to play a game, one of the players usually attempts to randomize the order of the cards by "shuffling" them. We will consider a standard "riffle" shuffle (See: http://www.wikihow.com/Shuffle-a-Deck-of-Cards-(Riffle-Bridge) or video at http://youtu.be/o-KBNdbJOGk ).

Ideally, we would like the cards to be randomly shuffled, independently of where they started. So even if a card (say the Ace of Spades) is on top of the deck when you start, it is equally liked to be in any of the 52 possible positions at the end of the shuffle. In other words, we want the positions of the cards in the deck to be uniformly randomly distributed by the shuffle.

In this project you will use a data structure (either queue or linked list is recommended) to simulate shuffling a deck of cards. You will implement a simple algorithm that models/simulates a riffle shuffle. Then you will use this code to try to answer the question: How many times do I need to riffle the cards to get them well shuffled?