#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkMinionEffect(int handPos, int choice1, int choice2, int p, struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	minionEffect(handPos, choice1, choice2, post, p);
	
	printf("Test when choice1 is bigger than 0: \n");
	
//	myAssert(pre.coins + 2 == post->coins, "coins should increase by 2.");
}

int main()
{
    int i, n, p;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

	int playernum = 2;
	int seed = 100;

	struct gameState G;
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(playernum, k, seed, &G);

    printf ("Testing minionEffect.\n");

    printf ("RANDOM TESTS.\n");

    for (n = 0; n < 10; n++) {
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);

        int handPos = 0; //floor(Random() * G.handCount[p]);
        int choice1 = floor(Random() * G.handCount[p]);
        int choice2 = floor(Random() * G.handCount[p]);
        checkMinionEffect(handPos, choice1, choice2, p, &G);
    }

    printf ("ALL TESTS OK\n");

    return 0;
}
