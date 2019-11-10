#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkAmbassadorEffect1(struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int handPos = 1;
	int currentPlayer = 0;
	int choice1 = 1;
	int choice2 = 3;

	int r;

	r = ambassadorEffect(choice1, choice2, handPos, post, currentPlayer);

	printf("Testing when choice2 is 3: \n");
	myAssert(r == -1, "return value should be -1");
}

void checkAmbassadorEffect2(struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int handPos = 1;
	int currentPlayer = 0;
	int choice1 = 1;
	int choice2 = -1;

	int r;

	r = ambassadorEffect(choice1, choice2, handPos, post, currentPlayer);

	printf("\nTesting when choice2 is -1: \n");
	myAssert(r == -1, "return value should be -1.");
}

void checkAmbassadorEffect3(struct gameState *post) {
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

	int r = ambassadorEffect(choice1, choice2, handPos, post, currentPlayer);

	printf("\nTesting when choice 2 is 2: \n");
	myAssert(r == 0, "r should be 0.");
	myAssert(pre.handCount[currentPlayer] == post->handCount[currentPlayer] - 2, "handCount currentPlayer decrease by 2");
	myAssert(post->supplyCount[post->hand[currentPlayer][choice1]] = 2 + pre.supplyCount[pre.hand[currentPlayer][choice1]], "supplycount should increase by 2");
	//myAssert(pre.handCount[1] + 1 == post->handCount[1], "handCount next player increase by 1");
	printf("next player before handcount: %d", pre.handCount[1]);
	printf("next player post handcount: %d", post->handCount[1]);
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

    printf ("Testing ambassadorEffect.\n");

	checkAmbassadorEffect1(&G);
	checkAmbassadorEffect2(&G);
	checkAmbassadorEffect3(&G);

    printf ("Test completed.\n");

    exit(0);
}
