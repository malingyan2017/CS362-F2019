#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main(){

	printf("testing begin");
	
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			remodel, smithy, village, baron, great_hall};

	struct gameState G;

	int playernum = 2;
	int seed = 100;
	//int coppers[MAX_HAND];
	//int silvers[MAX_HAND];
	//int golds[MAX_HAND];
	int choice1 = 1;
	int currentPlayer = 0;	
	
	printf("test baron function.\n");

	memset(&G, 23, sizeof(struct gameState));
	initializeGame(playernum, k, seed, &G);
	baronEffect(choice1, &G, currentPlayer);
	
	printf("numBuys should increase by 1");
	if(G.numBuys == (G.numBuys + 1)){
		printf("pass numBuys");
	}
	else{
		printf("fail numBuys");
	}
	return 0;
}
