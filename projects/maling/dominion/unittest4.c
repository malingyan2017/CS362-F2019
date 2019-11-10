#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkTributeEffect1(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}

	printf("Test when both card revealed are copper:\n");
	post->hand[nextPlayer][0] = copper;
	post->hand[nextPlayer][1] = copper;
	post->hand[nextPlayer][2] = baron;
	post->hand[nextPlayer][3] = silver;
	post->hand[nextPlayer][4] = gold;

	tributeEffect(currentPlayer, post);

	myAssert(pre.coins + 2 == post->coins, "coins should increase 2");
}

void checkTributeEffect2(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}
	//for (i = 0; i < 6; ++i) {
		//drawCard(nextPlayer, post);
	//}

	printf("\nTest when one revealed card is baron and other is copper: \n");
	post->discardCount[nextPlayer] = 5;
	post->deckCount[nextPlayer] = 8;

	post->hand[nextPlayer][0] = baron;
	post->hand[nextPlayer][1] = copper;
	post->hand[nextPlayer][2] = silver;
	post->hand[nextPlayer][3] = copper;
	post->hand[nextPlayer][4] = gold;

	tributeEffect(currentPlayer, post);

	printf("pre numactions are: %d\n", pre.numActions);
	printf("post numactions are:%d\n", post->numActions);

	//myAssert(pre.numActions + 1 == post->numActions, "numBuys should increase by 1");

	myAssert(post->coins == pre.coins + 2, "coins increase 2");
}

void checkTributeEffect3(struct gameState *post)
{
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int i;
	int currentPlayer = 0;
	int nextPlayer = 1;

	for (i = 0; i < 6; ++i) {
		drawCard(currentPlayer, post);
	}

	printf("\nTest when next player's discardcount + deckcount is <=1:\n");
	pre.discardCount[nextPlayer] = 1;
	pre.deckCount[nextPlayer] = 0;

	tributeEffect(currentPlayer, post);

	printf("pre discardcount: %d\n", pre.discardCount[nextPlayer]);
	printf("post discardcount: %d\n", post->discardCount[nextPlayer]);
	//myAssert(post->discardCount[nextPlayer] = pre.discardCount[nextPlayer] - 1,"discardcount for nextplayer decrease by 1");
}

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, tribute, village, baron, great_hall
                };

	int playernum = 2;
	int seed = 100;

	struct gameState G;
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(playernum, k, seed, &G);

    printf ("Testing tributeEffect.\n");

	checkTributeEffect1(&G);
	checkTributeEffect2(&G);
	checkTributeEffect3(&G);

    printf ("Test completed.\n");

    exit(0);
}
