// Name : Gawun Kim
// Class : CSE 224
// Program assignment 2
// Date : 10/18/2017

// This is stick game with C. The user and computer will compete the game.
// At first, user can set a total number.  From this moment, the game is starting.
// A computer will take some amount of sticks. (one stick or two sticks or three sticks)
// then the total number would be (total) - (some amount of sticks from coumputer)
// and, it is a user's turn and a user also can take some amount of sticks (1 or 2 or 3)
// This patter would be keep going and the last picker(making a total number as zero) would be a winner of this game.

#include<stdio.h>


void printSticks(int n);  // This is the code for making sticks. All the code regarding this one is on the bottom.
void game(int i);  	  // This is the code for the game rule. All the code regarding this one is on the bottom. 

int main(int argc, char* argv[])  // main

{
double x, i;
double answer;

if (argc == 2)  /////////////////////It allows only one digit. Next of the file name.
{
 answer = sscanf(argv[1],"%lf",&i);	// For the first (total number)Input
	if (i < 0)			// If an input number is less than zero
	{
	  	 printf("You entered negative number\n");
		 printf("Please input a valid positive number\n");
    	   	 	 char line[20];
			double i, answer;
	   	 	fgets(line, sizeof(line), stdin);   // This is for asking again.
	   		answer = sscanf(line,"%lf",&i);		// This is asking for the second input
				if (i < 0)				// In second asking, if it is negative
				{
		 		  printf("You typed a negative number. Bye\n");
			 	  return -1;			// Then go out
				}
				if (answer != 1)		// In the second asking, if it is number or not.
				{
				  printf("You did not input a number\n");
				  return -1;			// Then go out
				}
				 if (i > 0)			//  In the second asking, if the second input is a valid postive integer. It will go through this.
				{ 
				  printf("%lf is valid\n",i);
				  printSticks(i);		// printSticks <- I already mentioned before in void~~ and it will make sticks by using the input.
			 	  game(i);			// And start the counting game.
				}
	
	}
	
	if (answer != 1)				// Whether it is number or not.
	{
	 printf("You did not input a number\n");
	 printf("Please enter a valid positive number\n");
	 	char line[20];
		 double i, answer;
		fgets(line, sizeof(line), stdin);	// This is the second asking(chance)
		answer = sscanf(line,"%lf", &i);
		if (i < 0)				// whether it is negative?
		{
		  printf ("You typed a negative number. Bye~\n");
		  return -1;				// if it is negative? then go out
		}
		if (answer != 1)			//if it is not number
		{
		  printf("You did not input a number. Bye~\n");
		  return -1;				// Then go out
		}
		
		if(i > 0)				// if i is a positibe number it is a valid number.
		{
		 printf("%lf is valid number\n",i);
		 printSticks(i);			// Then this number will go through printSTicks to make sticks
		 game(i);				// and starting the counting game.
		}
	}
		
	else						// before I mentioned (if i is not a number, and i is a negative number), and else is a valid number
	{
	  printf("%lf is a valid number\n",i);
	  printSticks(i);				// This is for making sticks
	  game(i);					//start the counting game.
	}
	
}

	
else   // If argc is not 2..... it is an invalid number.
{
printf("You should have to input one positive integer. Enter this number\n");
	char line[20];
	double i, answer;
	fgets(line, sizeof(line), stdin);  //// so that require another input 
	answer = sscanf(line,"%lf",&i);
		if (i < 0)			//// if the second input is a negative number
		{
		printf("You entered a negative number. Bye~\n");
		 return -1;				// End this loop
		}
		if (answer != 1)		// If it is not number
		{
		printf("You did not input a number. Bye~\n");
		 return -1;			//End this loop
		}
		else					//and it is valid..
		{
		printf("%lf is a valid number.\n",i);
		printSticks(i);			// making sticks
		game(i);			//and start the counting game.
		}

 }


}


void printSticks(int n)					// At first, I used void printSticks(int n) And the below one is the code for that.
{
	for (int x=0; x<n; x++)				// The sticks are generated from this part.
{
		printf("|");				// They are consisted of for loop.
}
	printf("(%d)\n",n);
}	


void game (int i)					// At first, I used void printSticks (int i) and the below one  is the code for that
{
	while (i > 0)					// The counting game has to keep counting until zero so that i>0
		{
			int computer = i%4;		// Also, i%4 is can be zero then it will be a problem in this game
			if (computer ==0)
			{
				computer = 1;		// so that I changed the value when i is mutiples of 4
			}
			printf("This is my turn~!\n");
			i=i-computer;			// and subtract this value
		if (i==0)				/// This is checking whether computer win or not
		{
		printf("I am winner\n");
		return;					// and finish this game. This is void so that just "return;"
		}
		printSticks(i);				// This is out of if loop. This part is generating the sticks
		
  int k;
    printf("Then your turn~!\n");			// This part is for user turn.
	char line[20];
	fgets(line,sizeof(line),stdin);
	int value = sscanf(line,"%d",&k); 		// This is to ask how many sticks the user want to get
							// This is the part to check whether user input is 1 or 2 or 3.
while(value == 0)					// Also, value is zero it means it is not a number
{						
	printf("You should insert 1,2, or 3\n");
	fgets(line,sizeof(line),stdin);
	value = sscanf(line,"%d",&k);			// and Keep asking until user typing a valid number
}



	while ((k != 1) && (k != 2) && (k != 3))	// if user input some number that is not 1 or 2 or 3
	{
	printf("You should insert 1, 2 or 3\n");
		fgets(line,sizeof(line),stdin);		// It is asking second input.
		int value = sscanf(line,"%d",&k);	// It keeps asking until user typing a valid number
	}

	i=i-k;						// This is calculation (initial - calcuated one)
		if (i ==0)				// It is checking whether user win or not.
		{	
		printf ("You are winner\n");		
		return;					// And finish the game. It is void so that just "return;"
		}

printSticks(i);						// And printing user's sticks 
}}
