#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkBaronEffect1(struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int choice1 = 1;
	int currentPlayer = 0;	
	baronEffect(choice1, post, currentPlayer);

	printf("Testing when choice1 is bigger than 0:\n");

	//myAssert(pre.numBuys + 1 == post->numBuys, "numBuys should be 1 less.");
	printf("numBuys before: %d\n", pre.numBuys);
	printf("numBuys after: %d\n", post->numBuys);
	printf("numBuys after should be : %d\n", pre.numBuys + 1);

	printf("coins before: %d\n", pre.coins);
	printf("coins after: %d\n", post->coins);
	printf("coins after should be: %d\n", pre.coins + 4);

	printf("discard count before: %d\n", pre.discardCount[0]);
	printf("discard count after: %d\n", post->discardCount[0]);
	printf("discard count after should be: %d\n", pre.discardCount[0] + 1);
}

void checkBaronEffect2(struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	int choice1 = 0;
	int currentPlayer = 0;	
	baronEffect(choice1, post, currentPlayer);

	printf("Testing when choice1 is not bigger than 0: \n");

	//myAssert(pre.numBuys + 1 == post->numBuys, "numBuys should be 1 less.");
	printf("numBuys before: %d\n", pre.numBuys);
	printf("numBuys after: %d\n", post->numBuys);
	printf("numBuys after should be : %d\n", pre.numBuys + 1);

	printf("coins before: %d\n", pre.coins);
	printf("coins after: %d\n", post->coins);
	printf("coins after should be: %d\n", pre.coins);

	printf("estate supply before: %d\n", pre.supplyCount[estate]);
	printf("estate supply after: %d\n", post->supplyCount[estate]);
	printf("estate supply after should be: %d\n", pre.supplyCount[estate] - 1);
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

    printf ("Testing baronEffect.\n");

	checkBaronEffect1(&G);
	checkBaronEffect2(&G);


    printf ("Test completed.\n");

    exit(0);
}
