/*************
* ADVENTURER *
*************/

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
		printf("\nALL TESTS SUCCESSFULLY COMPLETED.\n");
	}
}

int main(){
	// Initialize game and cards.
	struct gameState g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,
						mine,ambassador,outpost,baron,tribute};
	
	// Pick a random seed.					
	int randomSeed = 750;
	
	// Initialize game.
	initializeGame(2, k, randomSeed, &g);
	
	printf("\n\n************   CARD TEST 1   ****************\n\n");
	
	printf("Checking to see if adventurer card was succesful...\n");
	
	int checkCard = cardEffect(adventurer, 0, 0, 0, &g, 0, 0);
	myAssert(checkCard, "1");
	
	printf("\nChecking to see how many cards are in player's hand...\n");
	int checkHand = numHandCards(&g);
	printf("(should be 7 cards)\n");
	printf("Player has %d cards in hand.\n", checkHand);
	if(checkHand == 7){
		myAssert(0, "2");
	}else{
		myAssert(1, "Wrong amount of cards.");
	}
	
	checkAsserts();
	
	printf("\n\n***************   DONE   *******************\n\n");
	
	return 0;
	
}