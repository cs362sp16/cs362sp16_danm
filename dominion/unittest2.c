/*************
* CARD COUNT *
*************/

#include "dominion.h"
#include <stdio.h>

int failed = 0;

int myAssert(int num, char* message) {
	if (num == 0){
		printf("TEST #%s SUCCESSFULLY PASSED.\n\n", message);
	} else if(num != 0) {
		printf("\nFAILED ASSERTION: %s\n\n", message);
		failed = 1;
	}
}

void checkAsserts() {
	if (!failed) {
		printf("ALL TESTS SUCCESSFULLY COMPLETED.\n");
	}
}

int main(){
	// Initialize game and cards.
	struct gameState g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,
						mine,ambassador,outpost,baron,tribute};
	
	// Pick a random seed.					
	int randomSeed = 60;
	
	// Initialize game.
	initializeGame(2, k, randomSeed, &g);
	
	int numCards = numHandCards(&g);
	
	// Check to see if hand has 5 cards.
	printf("Checking if Player 1 has 5 cards in hand...\n");
	if(numCards == 5){
		myAssert(0, "1");
	}else if(numCards != 5){
		myAssert(-1, "Player 1 card count failed.\n");
	}
	
	// Check to see if hand has 6 cards.
	printf("Checking if Player 1 has 6 cards in hand...\n");
	if(numCards == 6){
		myAssert(0, "1");
	}else if(numCards != 6){
		myAssert(-1, "Player 1 card count failed.\n");
	}
	
	// End turn.
	endTurn(&g);
	
	//Check to see if hand has 5 cards.
	printf("Checking if Player 2 has 5 cards in hand...\n");
	if(numCards == 5){
		myAssert(0, "3");
	}else if(numCards != 5){
		myAssert(-1, "Player 2 card count failed.\n");
	}

	
	// Check asserts.
	checkAsserts();
}