#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int randInt(int min, int max)
{
	int randNum = rand();
	return randNum%(max-min) + min;
}

float randFloat(float min, float max, int precision)
{
	min = min*pow(10,2);
	max = max*pow(10,2);
	int randNum = randInt((int)min, (int)max);
	return (float)randNum/((float) pow(10,2));
}

int main()
{
	
	srand(time(0));
	float horse1Chance = 0.4f;
	float horse2Chance = 0.3f;
	float horse3Chance = 0.2f;
	float horse4Chance = 0.1f;
	
	int horse1Wins = 0;
	int horse2Wins = 0;
	int horse3Wins = 0;
	int horse4Wins = 0;
	int maxRaces = 5000;
	//Simulate races N times
	int i=0;
	for(i=0;i<maxRaces;i++)
	{
		float randNum = randFloat(0.0f, 1.0f,2);
		if(randNum > (1.0f - horse1Chance))
		{
			horse1Wins++;
		}else if(randNum > (1.0f -(horse1Chance + horse2Chance)))
		{
			horse2Wins++;
		}else if(randNum > (1.0f -(horse1Chance + horse2Chance+horse3Chance)))
		{
			horse3Wins++;
		}else{
			horse4Wins++;
		}
	}
	
	
	printf("Winnings: 1:%d 2:%d 3:%d 4:%d\n", horse1Wins, horse2Wins, horse3Wins, horse4Wins);
	printf("Winning percentage: 1:%f 2:%f 3:%f 4:%f", (float)horse1Wins/5000.0f, (float)horse2Wins/5000.0f, (float)horse3Wins/5000.0f, (float)horse4Wins/5000.0f);
	
}
