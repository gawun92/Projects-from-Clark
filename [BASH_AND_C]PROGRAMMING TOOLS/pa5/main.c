// Name  : Gawun Kim
// Class : CSE 224 Daily
// Date  : DEC/01/2017
// Program assignment 5
// FILE 1


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


#include<stdio.h>
#include<string.h>

int isSpace(int c);
int Ignore(int c);
int Seperate(int c);
int upper();
int input();
int Phrase(char *str, int length);
int insert(char *str);
void sort();
void print();





int main(void)
{
        int c;
        char s[201];

        while ((c=Phrase(s,201)) != EOF)
        {
                insert(s);
        }
        sort();
        print();
                return 0;

}

