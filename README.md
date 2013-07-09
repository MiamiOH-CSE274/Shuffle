Shuffle
=======

How many times should you shuffle a deck of cards, if you want to be certain that it is actually randomly scrambled? You will solve this real-life problem via simulation. 

Using either your Queue or Linked List implementation from lab is recommended.

Background info
---------------

Standard decks of playing cards contain 52 cards. In order to play a game, one of the players usually attempts to randomize the order of the cards by "shuffling" them. We will consider a standard "riffle" shuffle (See: http://www.wikihow.com/Shuffle-a-Deck-of-Cards-(Riffle-Bridge) ).

<object width="560" height="315"><param name="movie" value="//www.youtube.com/v/o-KBNdbJOGk?hl=en_US&amp;version=3"></param><param name="allowFullScreen" value="true"></param><param name="allowscriptaccess" value="always"></param><embed src="//www.youtube.com/v/o-KBNdbJOGk?hl=en_US&amp;version=3" type="application/x-shockwave-flash" width="560" height="315" allowscriptaccess="always" allowfullscreen="true"></embed></object>

You may notice, however, that a single "riffle" of the cards won't end up scrambling them much: For example, there is quite a good chance that the bottom card of the deck will end up being one of the bottom 2-3 cards on the deck after the riffle.

Ideally, we would like the cards to be randomly shuffled, independently of where they started. So even if a card (say the Ace of Spades) is on top of the deck when you start, it is equally liked to be in any of the 52 possible positions at the end of the shuffle. In other words, we want the positions of the cards in the deck to be uniformly randomly distributed by the shuffle.

In this project you will use a data structure (either queue or linked list is recommended) to simulate shuffling a deck of cards. You will implement a simple algorithm that models/simulates a riffle shuffle. Then you will use this code to try to answer the question: How many times do I need to riffle the cards to get them well shuffled?