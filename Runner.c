#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Road length and max step is pre defined.
#define ROAD_LENGTH 40
#define MAX_STEP 4


//Used array of pointers to access the adresses of the components of assigned array. So that I could access runnerlist and use/change the values.
void ShowPositions(int (*runnerList[]), int runnerNumber);
int NextTurn(int (*runnerList[]), int runnerNumber);

int gameOver;

int main()
{
	//Input of the Number of the Racers.
	int runnerNumb;
	printf("How many runners will be in the race? \n");
	scanf("%d", &runnerNumb);

	//srand is used to set the seed which is used by rand() to generate "random" numbers in the NextTurn() function.
	srand((unsigned int)(time(NULL)));
	
	gameOver = 0;
	
	int runnerlist[runnerNumb];
	int *_runnerlist[runnerNumb];
	
	// I am using the pointer(*_runnerlist) to access the components of the array(runnerlist).
	for(int n = 0; n < runnerNumb; n++)
	{
		runnerlist[n] = 0;
	
		_runnerlist[n] = &runnerlist[n]; //Setting each component.
	}
	
	while((gameOver < 1))
	{
	
	printf("Press ENTER key to Continue\n");  
	getchar();  
	ShowPositions(_runnerlist, runnerNumb);	
	NextTurn(_runnerlist, runnerNumb);		
	}

		
	
	
}

// ShowPositions is where the positions of the runners current positions are displayed.
void ShowPositions(int (*runnerList[]), int runnerNumber)
{

	for(int i = 0; i < runnerNumber; i++)
	{
		printf("Runner %d |", i + 1);
		for(int j = 0; j <= (*runnerList[i]) ; j++ )
		{
			printf(" ");
		}
		printf("*\n");
	}
}
//Next Turn is where the positions of the runners increase by a random value between 1 and MAX_STEP. After this incrementation, there exists a check for, if the runner has passed the ROAD_LENGTH. 
//I have defined an integer value(int i) and an variable length array(winnerList), which is dependent to int i; to keep the runners who has passed the road length in. 
//In the for loop, if the current runner(int n) has passed the ROAD_LENGTH; i increases, resulting a new value in the array winnerList[i] getting created. I equalize the winnerList[i] (the created value) to n + 1 to get the number of the runner who has passed ROAD_LENGTH.
//I use this array so that, if there are more than 1 runners who passes the ROAD_LENGTH, I will keep each of them in an array, so that I can choose randomly from them, no matter how many there are.
int NextTurn(int (*runnerList[]), int runnerNumber)
{
	
	int i = 0;
	int winnerList[i];
	
	for(int n = 0; n < runnerNumber; n++)
	{
	*runnerList[n] = (*runnerList[n]) + ( 1 + (int)rand() % (MAX_STEP));	
	//printf("%d is %d \n", n+1, *runnerList[n]); //This comment can be turned on to check the values of each runner at every turn.
	if(*runnerList[n] >= ROAD_LENGTH)
	{
		i++;
		winnerList[i] = (n+1);
	}
	}

	if(i > 0)	
	{
		if(i > 1)
		{
			i = 1 +	(int)rand() % (i); //random number generation using the length of array to pick the winner in the array of winners. 
			gameOver =1;
			printf("We have a winner...\n");
			printf("The Winner is Runner %d \n", winnerList[i]);
			return winnerList[i];
					
		}
		else
		{
			gameOver =1;
			printf("We have a winner...\n");
			printf("The Winner is Runner %d \n", winnerList[i]);
			return winnerList[i];
			
		}

	}
	else
		return 0;
}
