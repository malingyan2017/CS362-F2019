#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkMinionEffect1(struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int handPos = 1;
	int currentPlayer = 0;
	int choice1 = 1;
	int choice2 = 0;

	minionEffect(handPos, choice1, choice2, post, currentPlayer);
	
	printf("Test when choice1 is bigger than 0: \n");
	
	myAssert(pre.coins + 2 == post->coins, "coins should increase by 2.");
}

void checkMinionEffect2(struct gameState *post) {
	int i;
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int handPos = 1;
	int currentPlayer = 0;
	int choice1 = 0;
	int choice2 = 2;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}
	for (i = 0; i < 6; ++i) {
		drawCard(1, post);
	}

	minionEffect(handPos, choice1, choice2, post, currentPlayer);

	printf("\nTest when choice2 is bigger than 0: \n");
	myAssert(post->handCount[currentPlayer] == 4, "handCount of current player should be 4");
	myAssert(post->handCount[1] == 4, "handCount of next player should be 4");
}

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

	int playernum = 2;
	int seed = 100;

	struct gameState G;
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(playernum, k, seed, &G);

    printf ("Testing minionEffect.\n");

	checkMinionEffect1(&G);
	checkMinionEffect2(&G);

    printf ("Test completed.\n");

    exit(0);
}
