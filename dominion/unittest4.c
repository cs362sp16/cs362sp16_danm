/***************
* SHUFFLE TEST *
***************/

#include "dominion.h"
#include <stdio.h>

int failed = 0;

// Assert function.
void myAssert(int num, char* message) {
	if (num == 0){
		printf("TEST #%s SUCCESSFULLY PASSED.\n", message);
	} else if(num != 0) {
		printf("\nFAILED ASSERTION: %s\n", message);
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
	
	printf("\n\n************   UNIT TEST 4   ****************\n\n");
	
	printf("Shuffling on first turn...\n");
	
	// Checking to see if you can shuffle Player 1's deck.
	int shuffleCheck = shuffle(1, &g);
	myAssert(shuffleCheck, "1");
	
	// Ending player 1 and player 2's turn.
	endTurn(&g);
	endTurn(&g);
	
	printf("Shuffling on second turn...\n");
	
	// Checking to see if you can shuffle Player 1's deck on second turn.
	int shuffleCheck2 = shuffle(1, &g);
	myAssert(shuffleCheck2, "2");
	
	checkAsserts();
	
	printf("\n\n***************   DONE   *******************\n\n");
	
	return 0;
	
}