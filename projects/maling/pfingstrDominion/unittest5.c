#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkMineEffect1(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int choice1 = 1;
	int choice2 = 7;
	int handPos = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}
	for (i = 0; i < 6; ++i) {
		drawCard(nextPlayer, post);
	}

	printf("Testing when choice2 is 7:\n");

	int r = refactoredMine(post, choice1, choice2, currentPlayer, handPos);

	myAssert(r == -1, "return value is -1.\n");
}

void checkMineEffect2(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int choice1 = 1;
	int choice2 = -2;
	int handPos = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}
	for (i = 0; i < 6; ++i) {
		drawCard(nextPlayer, post);
	}

	printf("Testing when choice2 is -2:\n");
	int r = refactoredMine(post, choice1, choice2, currentPlayer, handPos);

	myAssert(r == -1, "return value should be -1.\n");
}


void checkMineEffect3(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int choice1 = 5;
	int choice2 = 2;
	int handPos = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}
	for (i = 0; i < 6; ++i) {
		drawCard(nextPlayer, post);
	}

	printf(" Testing when choice2 is 2:\n");
	refactoredMine(post, choice1, choice2, currentPlayer, handPos);

	//myAssert(pre.coins + choice2 == post->coins, "coins");
	printf("pre coins: %d\n", pre.coins);
	printf("post coins: %d\n", post->coins);

	printf("pre handcount: %d\n", pre.handCount[currentPlayer]);
	printf("post handcount: %d\n", post->handCount[currentPlayer]);
	//myAssert(pre.handCount[currentPlayer] == post->handCount[currentPlayer], "handcount not change");
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

    printf ("Testing mineEffect.\n");

	checkMineEffect1(&G);
	checkMineEffect2(&G);
	checkMineEffect3(&G);

    printf ("Test completed.\n");

    exit(0);
}
