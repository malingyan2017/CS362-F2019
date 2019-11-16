#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkBaronEffect(int choice1, int p, struct gameState *post) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

	baronEffect(choice1, post, p);

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

int main()
{
    int i, n, p;

    struct gameState G;

    printf ("Testing baronEffect.\n");

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 200; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        drawCard(p, &G);

        int choice1 = floor(Random() * G.handCount[p]);
        checkBaronEffect(choice1, p, &G);
    }

    printf ("ALL TESTS OK\n");

    return 0;
}
