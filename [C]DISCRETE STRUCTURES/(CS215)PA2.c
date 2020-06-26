// Name : Gawun Kim // Date : Nov/19/2017 // CSE 215 // Program assignment 2
// This program is for Pascal triangle with using double array.

#include <stdio.h>
#include <stdlib.h>
#define max 15

///////////////////////////////////////////////////////////

void print(int array[max][max], int row)                // This will be printed some numbers that are given from somewhere..
{                                               // This function is the content of the double arrays
    for (int i=0;i<row;i++){
        for (int j=0;j<i+1;j++) printf (" %d", array[i][j]);
        printf ("\n");
    }
}

////////////////////////////////////////////////////////////

void pascalTriangle(int array[max][max], int row)       // This is calculating the number of the pascal triangle
{
    for (int i=0;i<row;i++){
    array[i][0] = 1;
    for (int j=1;j<=i-1;j++)                // This is from second to the last number
        array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            if (i!=0)   array[i][i] = 1;    // This is for the first line
    }
}

///////////////////////////////////////////////////////

int main () {
    int pascal[max][max];
    int size=15;

    pascalTriangle(pascal,size);
    print(pascal,size);
    return 1;
}
