/************
* Mihai Dan *
************/

#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


/*********************
* TESTING BARON CARD *
*********************/


int main(){
	struct gameState g;
	
	int result;
	int random = 0;
	int currentPlayer = 1; 
	int handCount, deckCount;
	int good = 0, bad =0;
	int i, j;
	
	int k[10] = {adventurer, gardens, embargo, village, minion, 
					mine, cutpurse, sea_hag, tribute, smithy};
	
	printf("**** Begin Random Testing for Baron Card ****\n");
	printf("Each suite consists of 500 test cases.\n\n");
	
	for(j = 0; j < 14; j++){
		printf("Testing suite #%d...\n", j+1);
		
		for(i = 0; i < 500; i++){
			
			// Setting random variables.
			int numPlayers = rand() % 4;
			int gameSeed = rand() % 5000;
			
			// Initialize the game.
			initializeGame(numPlayers, k, gameSeed, &g);
			
			// 1 out of 9 chance that the deck is empty.
			random = rand() %9;
			if(random == 4){
				g.deckCount[currentPlayer] = 0;
				deckCount = 0;
			}else{
				deckCount = rand() % MAX_DECK;
				g.deckCount[currentPlayer] = deckCount;
			}
			
			handCount = rand() % MAX_HAND;
			g.handCount[currentPlayer] = handCount;
			
			g.discardCount[currentPlayer] = rand() % MAX_DECK;
			
			result = cardEffect(baron, 1, 1, 1, &g);
			if(result == 0){
				good++;
			}else{
				bad++;
			}
		}
	}
	
	printf("Baron Card Test Complete!\n");
	
	if(good > bad){
		printf("Majority of tests passed!\n\n");
		return 0;
	}else{
		printf("Majority of tests failed...\n\n");
		return 1;
	}
	
}