// Name  : Gawun Kim
// Class : CSE 215
// Date  : OCT/24/2017
// Program Assignment 1
//This is discrete math and this is a program which is showing two sets and involved works (intersection, union, cardinally).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char setA[120], setB[120];
char Element(char setA[]);
int Dup(char letter,char setA[]);
void rmDup(char setA[]);
void intersection(char sect[], char tempB[]);
void negation(char sect[],char tempB[]);



int main()
{
 char UnionAB[120], sect[120], tempB[120];
 int cardA=0, cardB=0, i=0,  j=0;//cardinality
	printf("Please enter the following elements in set A\n");
	fgets(setA,120,stdin);					//This is asking for input
		if(setA[0]=='\n')
		{
       		 setA[0]= '0';//if the first input is a enter then the set is an empty set
		 cardA=1;
		} //1 element in that set;
		else
		{
		 rmDup(setA);//if its not empty then remove duplicates
			while(setA[i])
			{//loop to find cardinality
			  if(setA[i]=='\0')		break;           // exiting the loop
			  else if(setA[i]=='\n')	break;		 // Same
			cardA++;
			i++;
       			}
		}

   printf("\nPlease enter the following elements in set B\n");
   fgets(setB,120,stdin);
	if(setB[0]=='\0'){
        	setB[0]= '0';
		cardB=1;}
	else
	{
		(rmDup(setB));
		while(setB[j])
		{
		  if(setB[j]=='\0')			break;
	          else if(setB[j]=='\n') 		break;

		  cardB++;
		  j++;
       		}
	}//ALL STEPS FOR A IS REPEATED FOR B!!!
strcpy(sect,setA); //copies the string pointed by set A to the array sect
strcpy(tempB,setB); // same here for set B

UnionAB[0]='\0';//union
strcat(UnionAB,setA); //concatenates the string to to end of the destination string
strcat(UnionAB,setB); //same here for set B
rmDup(UnionAB); // rempves any duplications between the unioun of A and B

Element(setA); //puts the string from set A to an array
printf("\n\nSet A: {%s}\n", setA);
Element(setB);//same but for set B
printf("Set B: {%s}\n", setB);
printf("Cardinality of A: %i\n", cardA);
printf("Cardinality of B: %i\n", cardB);
Element(UnionAB); //takes the union of both sets and puts them into an array
printf("A U B: {%s}\n", UnionAB);
intersection(sect,tempB);
negation(sect,tempB);
}

char Element(char setA[])
{
 int i, target, c;
 for(i=0;i<strlen(setA);i++)
	{
	if(setA[i]=='\n')	setA[i]='\0';
	}
return *setA;
}


void rmDup(char setA[])
{
  int n = 0;
  int i = 0;
  char A[120];
  A[i] = '\0';

  while (setA[n])
  {
 	if (Dup(setA[n],A) == 0)
	{
         A[i] = setA[n];
         i++;
      	}
     n++;
  }

  A[i]='\0';
  strcpy(setA, A);
}

int Dup(char letter,char setA[])
{
    int n = 0;
	while (setA[n])
	{
	  if (letter == setA[n])
	  {
	   return 1;
    	  }
	 n++;
	}
    return 0;
}

///////////////////////////////////////////////////
void intersection(char sect[], char tempB[])
{
int i, n = 0;
      for(i=0;i<strlen(sect);i++)
	{
        if(sect[i]=='\n')	sect[i]='\0';
	}
printf("\nA intersection B: {");
     while(sect[n]){
        if(Dup(sect[n],tempB))
        {
            printf("%c,",sect[n]);
        }
        n++;
     }
printf("\b}");
}
/////////////////////////////////////////////////////////////////

void negation(char sect[],char tempB[])
{
int n = 0;
printf("\nSet A negate B: {");
   while (sect[n])
   {
	if ((Dup(sect[n],tempB)) == 0)
	{
        printf("%c,",sect[n]);
	}
     n++;
   }
printf("\b}\n");
}

