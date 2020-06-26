// Name  : Gawun Kim
// Class : CSE 224 Daily
// Date  : DEC/01/2017
// Program assignment 5
// FILE 2
 //  This is a program to sort inputs. It is sorting orderly depends on the length of words and the alphabet order.
// The user can insert multiple words and multiple words should be connecting with , . : ; ? ! between words
// For the output, words are converted to highcase
// Here is an example
/*
[wun@lnxsrv03 ~/testing]$ ./main
This.Is,A.Test,Version.This,is.Gawun.kim.I.am,studing,computer.science
00001 <A>
00001 <I>
00002 <IS>
00001 <AM>
00001 <KIM>
00002 <THIS>
00001 <TEST>
00001 <GAWUN>
00001 <VERSION>
00001 <STUDING>
00001 <COMPUTER>

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>


int upper()
{		// This is to convert from lowercase letters to uppercase letters
	int c = getchar();	
	c = toupper(c);
	return c;
}

int isSpace(int c)
{		// In  this code, TABs and more than two of spaces will be converted to one space
	if (c=='\n' || c=='\t'|| c==' ')
		return 1;
	else 
		return 0;
}

int Ignore(int c)
{		// This code makes result ignore the each of characters: (,),',",-
	if (c=='(' || c==')' || c=='\'' || c=='\"' || c=='-')
		return 1;
	else
		return 0;
}

int Seperate(int c)
{		//This code seperates phrases if it had these characters  , . : ; ? ! 
	if (c==',' || c=='.' || c==';' || c==':' || c=='?' || c=='!')
		return 1;
	else
		return 0;
}

int input()
{		// This code makes the result get the strings uppercased, without white spaces, and after it ignores the charaters that it should
	int c =  upper();
	if(c==EOF)
		return c;

	if (isSpace(c) == 1)
	{
		c = ' ';
	}
	if (Ignore(c) == 1)
	{
		c = input();
	}		
	return c;
}
int Phrase(char *str, int length)
{		// gets phrases after every tim it finds a seperator and stores it as a phrase
	int c=input();
	while (isSpace(c))
		c=input();

	int i=0;
	while (!Seperate(c) && c != EOF)
		{
			if (i< length)
			{
			str[i] = c;
			i++;
			}
		c=input();
		}
	str[i] = '\0';
	return c;
}

char dict[1000][201] = {'\0'};				// making every space equall to \0
int count[1000] = {0};
int dictlen=1000;
int insert(char *str)
{					// insert function looks for a place where it has \0 means it dosnt have a string in it and coppies the sting into it. 
					//if the string was similar to a previous one it would add 1 to the counter.

	int i;
	for (i = 0 ; i< dictlen; i++)
		{
			if(dict[i][0]=='\0')
			{
				strcpy(dict[i],str);
				count[i]++;
				return i;
			}
	
			if (strcmp(str,dict[i])==0)
			{
				count[i]++;
				return i;
			}
		}
	return 0;
}
void sort()
{			// This code is sorting function to compare the length of strings and swaps each of their places the order.
int i;
int c=1;
	while(c>0)
	{		// This while loop is keep going the sorting process until no more string to sort.
	c=0;
		for (i=0; i<dictlen-1 && count[i+1]>0; i++)
		{
			if (strlen(dict[i])>strlen(dict[i+1]))
			{
				char temp[201];
				int t;
				strcpy(temp,dict[i]);		// This line is to swap the location of strings.
				t=count[i];
				strcpy(dict[i],dict[i+1]);
				count[i]=count[i+1];
				strcpy(dict[i+1],temp);
				count[i+1]=t;	
				c++;
			} 	
		}
	}
}

void print()
	{
	 int i;
	  for (i=0; i<dictlen; i++)
		{
		if (count[i]>0)
		printf("%05d <%s>\n",count[i],dict[i]);		//This code will print five places for the counter and the dictionary. 
		}
	}

