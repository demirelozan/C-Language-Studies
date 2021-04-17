#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//To count the total times both players and computers wins.
int _playerWinCount;
int _computerWinCount; 

//rpsGenerator is for generating Computers selection in response to Players pick.
int rpsGenerator();
//rpsCompare is the function where Players and Computers selections are compared.
int rpsCompare();

//_computerPick is the return value from the generation function(rpsGenerator), it is used at the comparison function(rpsCompare) to compare players and computers selections.
	int _computerPick;
//_playersPickValue is used to send players pick to rpsCompare function. Not a necessary one but makes if statements more clean so that I dont have to use strcmp on every statement in rpsCompare() function.
	int _playersPickValue;
	
//These variables are used to count players pick choices. It is restored globally so that other functions can have access. Also they are used to show how many times player picked each one after round 5.
int playersRockPicks = 0;
int playersPaperPicks = 0;
int playersScissorsPicks = 0;

//These variables are used to count computers pick choices. They are used to show computers pick results after round 5.
int computersRockPicks = 0;
int computersPaperPicks = 0;
int computersScissorsPicks = 0;

int main()
{
	_playerWinCount = 0;
	_computerWinCount = 0;
	
	//Game continues till one side reaches 15 wins.
	while( !(_playerWinCount >=15 || _computerWinCount >= 15) )
	{
		char playersPick[1];
		printf("Pick one: r = Rock; p = Paper; s = Scissors; o = Exit \n ");
		scanf("%s", playersPick);
		printf("You pressed: %s\n", playersPick);
		
		if(!strcmp(playersPick,"s") || !strcmp(playersPick,"S") || !strcmp(playersPick,"p") || !strcmp(playersPick,"P") || !strcmp(playersPick,"r") || !strcmp(playersPick,"R"))
		{
			
			// if  _playersPickValue is 0 , then player has picked Rock
			// if  _playersPickValue is 1 , then player has picked Paper
			// if  _playersPickValue is 2 , then player has picked Scissors
			if(!strcmp(playersPick,"r") || !strcmp(playersPick,"R"))
			{
				_playersPickValue = 0; 
		
			}
			else if(!strcmp(playersPick,"p") || !strcmp(playersPick,"P"))
			{
				_playersPickValue = 1;
							
			}
			else if(!strcmp(playersPick,"s") || !strcmp(playersPick,"S"))
			{
				_playersPickValue = 2;
				
		    }  				
			
			srand((unsigned)time(0));
			rpsGenerator();
			rpsCompare();
			
			printf("Player win count: %d\n",_playerWinCount);
			printf("Computer win count: %d\n",_computerWinCount);
			if((playersRockPicks + playersPaperPicks + playersScissorsPicks) >= 5)
			{
			printf("Player has picked Rock: %d, Paper: %d , Scissors: %d times\n", playersRockPicks, playersPaperPicks, playersScissorsPicks);
			printf("Computer has picked Rock: %d, Paper: %d , Scissors: %d times\n", computersRockPicks, computersPaperPicks, computersScissorsPicks);
				
			}
			
		}
		else if(!strcmp(playersPick,"o") || !strcmp(playersPick,"O"))
		{
			printf("Was a nice game, bye!\n");
			break;
		}
		else 
		{
			printf("You pressed wrong key, Try again\n");
		}
		

		
		
				
	}
		
}


int rpsGenerator()
{
	//Starting chances are set to 10, if the starting values decreases to a number like 1; Computer reacts to Players previous choices more precisely.
	int rockChance = 10 + playersScissorsPicks;
	int paperChance = 10 +  playersRockPicks;
	int scissorsChance = 10 + playersPaperPicks;
	
	
	//To check the chances of computers picks, in response to players picks
	//printf("rockChance: %d\n", rockChance);
	//printf("paperChance: %d\n", paperChance);
	//printf("scissorsChance: %d\n", scissorsChance);
	
	int totalSpace = rockChance + paperChance + scissorsChance;
	short int minSpace = 0;
	int computerMove;
	
	// if _computerPick returns 0 , then it means computer has picked Rock
	// if _computerPick returns 1 , then it means computer has picked Paper
	// if _computerPick returns 2 , then it means computer has picked Scissors
	computerMove = rand() % (totalSpace - minSpace) + minSpace;
	if(computerMove> minSpace && computerMove < rockChance )
	{
		_computerPick = 0;
		computersRockPicks++;
		return _computerPick;
	}
	if(computerMove > rockChance && computerMove < (rockChance + paperChance))
	{
		_computerPick = 1;
		computersPaperPicks++;
		return _computerPick;
	}
	if(computerMove > (rockChance + paperChance) && computerMove < totalSpace )
	{
		_computerPick = 2;
		computersScissorsPicks++;
		return _computerPick;
	}
	
}

int rpsCompare()
{
			//If player picked Scissors
			if(_playersPickValue == 2)
			{
				playersScissorsPicks++;//Increases after computers pick. So that the next pick of computer reacts to the previous picks. And current pick does not get affected by it.
				if(_computerPick == 0)
				{
					printf("Computer picked Rock, You Lose!\n");
					_computerWinCount++;
					return 0;
				}
				if(_computerPick == 1)
				{
					printf("Computer picked Paper, You Win!\n");
					_playerWinCount++;
					return 0;
				}
				if(_computerPick == 2)
				{
					printf("Computer picked Scissors, Tie\n");
					return 0;
				}
				
				
			
			}
			//If player picked Paper
			else if(_playersPickValue == 1) 			
			{
				playersPaperPicks++;//Increases after computers pick. So that the next pick of computer reacts to the previous picks. And current pick does not get affected by it.
				if(_computerPick == 0)
				{
					printf("Computer picked Rock, You Win!\n");
					_playerWinCount++;
					return 0;
				}
				if(_computerPick == 1)
				{
					printf("Computer picked Paper, Tie!\n");
					return 0;
				}
				if(_computerPick == 2)
				{
					printf("Computer picked Scissors, You Lose!\n");
					_computerWinCount++;
					return 0;
				}
								
			}
			//If player picked Rock
			else if(_playersPickValue == 0) 			
			{
				playersRockPicks++;//Increases after computers pick. So that the next pick of computer reacts to the previous picks. And current pick does not get affected by it.
				if(_computerPick == 0)
				{
					printf("Computer picked Rock, Tie!\n");
					return 0;
				}
				if(_computerPick == 1)
				{
					printf("Computer picked Paper, You Lose!\n");
					_computerWinCount++;
					return 0;
				}
				if(_computerPick == 2)
				{
					printf("Computer picked Scissors, You Win!\n");
					_playerWinCount++;
					return 0;
				}	
											
			}	
}
