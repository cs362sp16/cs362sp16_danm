/******************
* playCard() TEST *
******************/

#include "dominion.h"
#include <stdio.h>


int failed = 0;

// Assert function.
void myAssert(int num, char* message) {
	if (num == 0){
		printf("TEST SUCCESSFULLY PASSED.\n", message);
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

// Tests playCard()
int main(){

	struct gameState g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,
						mine,ambassador,outpost,baron,tribute};
	
	int i;
	for(i = 0; i < 100; i++){
		int randSeed = rand % 5000;
		int randPlayers = rand % 4;
		int currPlayer = whoseTurn(&g);
		
		do{
			randPlayers = rand % 4;
		}while(randPlayers < 2);
		
		initializeGame(randPlayers, k, randSeed, &g);

		printf("playCard() TEST #%d\n", i+1);

		playCardCheck = playCard(currPlayer, 0, 0, 0, &g);

		myAssert(playCardCheck, "1");

		checkAsserts();
	}

	return 0;
}