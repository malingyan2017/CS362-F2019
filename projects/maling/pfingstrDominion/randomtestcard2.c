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

	refactoredMinion(post, choice1, choice2, p, handPos);
	
	if(choice1 > 0 && choice2 == 0){
        if(pre.coins + 2 == post->coins){
            printf("passed, coins should increase by 2.\n");
        }
        else{
            printf("failed, coins should increae by 2.\n");
        }
    }
    else if(choice1 == 0 && choice2 >0) {
        if(post->handCount[0] == 4){
            printf("passed, handcount should be 4.\n");
        }
        else{
            printf("failed, handcount should be 4.\n");
        }
    }
	
//	myAssert(pre.coins + 2 == post->coins, "coins should increase by 2.");
}

int main()
{
    int n, p;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

	int playernum = 2;
	int seed = 100;
    p = 0;

	struct gameState G;
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(playernum, k, seed, &G);

    printf ("Testing minionEffect.\n");

    printf ("RANDOM TESTS.\n");

    for (n = 0; n < 100; n++) {
        
        printf("test minioneffect round %d:\n", n);
        //G.deckCount[p] = floor(Random() * MAX_DECK);
        //G.discardCount[p] = floor(Random() * MAX_DECK);
        G.coins=random()%10;
        G.handCount[p] = floor(Random() * MAX_HAND);

        int handPos = 0; //floor(Random() * G.handCount[p]);
        int choice1 = random()%2;
        int choice2 = random()%2;
        printf("choice1 = %d, choice = %d\n", choice1, choice2);
        checkMinionEffect(handPos, choice1, choice2, p, &G);
    }

    printf ("Test completed\n");

    return 0;
}
