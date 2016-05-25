/****************
* Mihai Dan     *
* 5/24/2016     *
* Assignment 4  *
****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>

char *cardNameFunc(int cardNum);
int getState(int, struct gameState *g);
int initializeGame(int numPlayers, int kingdomCard[10], int randomSeed, struct gameState *state);

int main(int argc, char *argv[]){

	// Check if there are enough arguments.
	if(argc != 2){
		printf("Please enter a seed. (i.e. testdominion 42\n");
		return -1;
	}
	
	// Initialize variables.
	struct gameState g;
	int gameSeed = atoi(argv[1]);
	int numPlayers;
	int rando;
	int runTimes = 0;
	int currPlayer;

	// Initializing the game.
	printf("Beginning testing!\n");
	
	printf("Initializing Game\n");
	int k[10] = {gardens, adventurer, steward, minion, village, salvager, sea_hag, embargo, mine, smithy};	
	
	// Get number of players.
	do{
		numPlayers = rand() % 4;
	}while(numPlayers < 2);
	printf("The number of players is: %d\n", numPlayers);
	
	// Get kingdom cards.
	printf("Kingdom Cards used are: ");
	for(int i = 0; i < 10; i++){
		printf("%s ", cardNameFunc(k[i]));
	}
	printf("\n");

	// Assert that game initialized correctly.
	int result = initializeGame(numPlayers, k, gameSeed, &g);
	assert(result == 0);

	// Place cards in hand.
	printf("\nPlacing cards in hand\n");
	for(int i = 0; i < numPlayers; i++){
		printf("Player %d: ", i+1);
		for(int j = 0; j < numHandCards(&g); j++){
			printf("%s ", cardNameFunc(handCard(j, &g)));
		}
		printf("\n");
	}
	printf("\n");
	
	// Game is initialized and ready to be played.
	
	printf("Finished initialization of game!\n");
	
	while(!isGameOver(&g)){
		runTimes++;
		currPlayer = whoseTurn(&g);
		printf("\nThe current player is: %d\n", currPlayer + 1);
		printf("Current hand: ");
		for(int i = 0; i < numHandCards(&g); i++){
			printf("%s ", cardNameFunc(handCard(i, &g)));
		}
		

	// Action phase.
	printf("\nEntering the Action Phase\n");
	
	while(g.numActions > 0){
		int numActionCards = 0;
		int numMoneyCards = 0;
		int *actionCardIndex = NULL;
		int *moneyIndex = NULL;
		int choice1 = -1;
		int choice2 = -1;
		int choice3 = -1;
		
		// Check if any of the cards are action cards.
		for(int i = 0; i < numHandCards(&g); i++){
			int card = handCard(i, &g);
			if(card >= adventurer && card != gardens){
				numActionCards++;
				actionCardIndex = realloc(actionCardIndex, numActionCards * sizeof(int));
				actionCardIndex[numActionCards-1] = i;
			}
			else if(card >= copper && card <= gold){
				numMoneyCards++;
				moneyIndex = realloc(moneyIndex, numMoneyCards * sizeof(int));
				moneyIndex[numMoneyCards-1] = i;
			}
		}
		
		// Check if the player can't do anything.
		if(numActionCards == 0){
			printf("Player %d has no action to play.\n", currPlayer + 1);
			
			printf("\nEntering Buying Phase!\n");
			
			int money = getState(currPlayer, &g);
			if(money >= 8){
				printf("Bought province\n");
				money = buyCard(province, &g);
			}else if(money >= 6){
				printf("Bought gold\n");
				money = buyCard(gold, &g);
			}else if(money >= 5){
				printf("Bought duchy\n");
				money = buyCard(duchy, &g);
			}else if(money >= 3){
				printf("Bought steward\n");
				money = buyCard(steward, &g);
			}else if(money >= 2){
				printf("Bought estate\n");
				money = buyCard(estate, &g);
			}
			
			// Buying phase complete.
			
			printf("Ending Turn\n");
			endTurn(&g);
			break;
		}
		
		rando = rand() % numActionCards;
		int pickACard = handCard(actionCardIndex[rando], &g);
		
		if(pickACard == ambassador){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = rand() % numHandCards(&g), choice2 = 1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if (pickACard == baron){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = 0, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == embargo){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = rand() % (curse + 1 - treasure_map) + treasure_map, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == feast){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = rand() % (duchy + 1 - treasure_map) + treasure_map, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == mine){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = moneyIndex[rand() % numMoneyCards], choice2 = copper, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == minion){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = (rand() % 1) + 1, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == remodel){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = rand() % numHandCards(&g), choice2 = rand() % (estate + 1 - treasure_map) + treasure_map, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == remodel){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = rand() % numHandCards(&g), choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else if(pickACard == steward){
			printf("The card picked was: %s\n", cardNameFunc(pickACard));
			choice1 = (rand() % 3) + 1, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}else{
			printf("The card picked was %s\n", cardNameFunc(pickACard));
			choice1 = -1, choice2 = -1, choice3 = -1;
			playCard(pickACard, choice1, choice2, choice3, &g);
		}
		
		printf("Finished Action.\nHere is the new Hand: ");
		for(int i = 0; i < numHandCards(&g); i++){
			printf("%s ", cardNameFunc(handCard(i, &g)));
		}
		printf("\n");
		free(actionCardIndex);
		
		// Entering buying phase now that action phase is over.
		
		printf("Entering Buying Phase!\n");
		
		int money = getState(currPlayer, &g);
		if(money >= 8){
			printf("Bought province\n");
			money = buyCard(province, &g);
		}else if(money >= 6){
			printf("Bought gold\n");
			money = buyCard(gold, &g);
		}else if(money >= 5){
			printf("Bought duchy\n");
			money = buyCard(duchy, &g);
		}else if(money >= 2){
			printf("Bought estate\n");
			money = buyCard(estate, &g);
		}
		
		// Finished the buying phase.
		
		printf("Ending Turn\n");
		endTurn(&g);
		}
	}
	
	// End game.
	
	printf("Finished Game!\nIt took %d runTimes to complete the game!\n", runTimes/2);
}

int getState(int currPlayer, struct gameState *g){
	updateCoins(currPlayer, g, 0);
   	return g->coins;
}   

char* cardNameFunc(int cardNum){
	switch (cardNum) {
		case adventurer: return "Adventurer";
		case council_room: return "Council Room";
		case feast: return "Feast";
		case great_hall: return "Great Hall";
		case mine: return "Mine";
		case remodel: return "Remodel";
		case smithy: return "Smithy";
		case curse: return "Curse";
		case estate: return "Estate";
		case duchy: return "Duchy";
		case ambassador: return "Ambassador";
		case cutpurse: return "Cutpurse";
		case embargo: return "Embargo";
		case outpost: return "Outpost";
		case salvager: return "Salvager";
		case sea_hag: return "Sea Hag";
		case province: return "Province";
		case copper: return "Copper";
		case silver: return "Silver";
		case gold: return "Gold";
		case gardens: return "Gardens";
		case village: return "Village";
		case baron: return "Baron";
		case minion: return "Minion";
		case steward: return "Steward";
		case tribute: return "Tribute";
		case treasure_map: return "Treasure Map";
		default: return "";
	}
}
