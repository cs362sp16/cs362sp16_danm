/***********
* BUY TEST *
***********/

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
	
	printf("\n\n************   UNIT TEST 1   ****************\n\n");
	
	// Player 1 draws.
	printf("Testing Player 1 buying:\n");
	int checkBuy = buyCard(1, &g);
	myAssert(checkBuy, "1");
	
	int checkBuy2 = buyCard(100, &g);
	myAssert(checkBuy2, "Card not valid.\n ");
	
	// End turn.
	endTurn(&g);
	
	// Player 2 draws.
	printf("Testing Player 2 buying:\n");
	int checkBuy3 = buyCard(1, &g);
	myAssert(checkBuy3, "3");
	
	int checkBuy4 = buyCard(1, &g);
	myAssert(checkBuy4, "Out of money.");
	
	// Check asserts.
	checkAsserts();
	
	printf("\n\n***************   DONE   *******************\n\n");
	
	return 0;
}