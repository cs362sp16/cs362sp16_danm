CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
asimpletest:
	gcc -o simpletest asimpleunittest.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
unittestresults:
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	
	rm -f unittestresults.out
	./unittest1 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
randomcardtest:
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
	rm -f randomtestcard1.out
	rm -f randomtestcard2.out
	rm -f randomtestadventurer.out
	
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	
testdominion: testdominion.c dominion.o rngs.o
	gcc -o testdominion -std=c99 testdominion.c dominion.o rngs.o $(CFLAGS)	
	rm -f testdominion.out
	./testdominion 42 >> testdominion.out
	
playcardtest:
	gcc -o playCardTest playCardTest.c dominion.o rngs.o $(CFLAGS)
	rm -f playCardTest.out
	./playCardTest >> playCardTest.out
	
testdominion.diff: testdominion.c dominion.o rngs.o
	gcc -o testdominion -std=c99 testdominion.c dominion.o rngs.o $(CFLAGS)	

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
