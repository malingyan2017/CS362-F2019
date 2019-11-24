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

	refactoredBaron(post,choice1, p);

	printf("Testing when choice1 is %d:\n", choice1);
   
	if (choice1){
        //myAssert(pre.numBuys + 1 == post->numBuys, "numBuys should increase by 1");
        printf("numBuys should increase by 1: \n");
        printf("pre numbuy: %d", pre.numBuys);
        printf("post numbuy: %d", post->numBuys);

	
        myAssert(pre.coins + 4 == post->coins,"coins should increase by 4" );

        if(pre.discardCount[0] + 1 != post->discardCount[0]){
        printf("failed, discount should increase by 1.\n");
        }
        else{
        printf("passed, discount test\n");
        }
    }
    else{
        if(pre.supplyCount[estate] - 1 != post->supplyCount[estate]){
        printf("failed, supplycount estate should decrease by 1.\n");
        }
        else{
        printf("passed, supplycount estate should decrease by 1.\n");
        }
    }
}
    
	

int main()
{
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

	int playernum = 2;
	int seed = 100;
    int i;

	struct gameState G;
	memset(&G, 23, sizeof(struct gameState));

    for (i = 0; i < 100; i++){
        printf("\nbegin random test baroneffect round %d\n", i);
        initializeGame(playernum, k, seed, &G);

    int choice1=random()%2;
    int p = 0;

    G.numBuys= random()% 100;
    G.coins=random()%100;
    G.discardCount[p]= random()%10;
    G.supplyCount[estate] = random()%10;



	checkBaronEffect(choice1, p, &G);
	


    
    }
	printf ("Test completed.\n");

    exit(0);

    
}
