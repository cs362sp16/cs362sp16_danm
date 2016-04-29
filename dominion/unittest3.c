/***********
* END TURN *
***********/

#include "dominion.h"
#include <stdio.h>

int failed = 0;

// Assert function.
void myAssert(int num, char* message) {
	if (num == 0){
		printf("TEST #%s SUCCESSFULLY PASSED.\n\n", message);
	} else if(num != 0) {
		printf("FAILED ASSERTION: %s\n\n", message);
		failed = 1;
	}
}

void checkAsserts() {
	if (!failed) {
		printf("\nALL TESTS SUCCESSFULLY COMPLETED.\n");
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
	
	printf("\n\n************   UNIT TEST 3   ****************\n\n");
	
	// Check to see who's turn it is.
	int turnCount = whoseTurn(&g);
	printf("PLAYER PLAYING: Player %d\n", turnCount+1);
	
	// End turn.
	int endCheck = endTurn(&g);
	myAssert(endCheck, "1");
	
	// Check to see if Player 2 is playing.
	int turnCount2 = whoseTurn(&g);
	printf("PLAYER PLAYING: Player %d\n", turnCount2+1);
	
	// End turn again.
	int endCheck2 = endTurn(&g);
	myAssert(endCheck2, "2");
	
	// Check to see if it went back to Player 1.
	int turnCount3 = whoseTurn(&g);
	printf("PLAYER PLAYING: Player %d\n", turnCount3+1);
	
	// Check asserts.
	checkAsserts();
	
	printf("\n\n***************   DONE   *******************\n\n");
	
	return 0;
}