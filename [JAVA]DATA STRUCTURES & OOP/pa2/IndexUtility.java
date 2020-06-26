// Name : Gawun Kim
// May 3 2018
// CSE 223 by Nick Macias
// Program Assignment 2
// Description : There are 4 of classes. Main, IndexUtility, PositionList, and WordList. This program is
//               user can input some words. This program labels index orderly and sorts output. This program is
// 				 Java base.


import java.util.Scanner;

public class IndexUtility 
{
	static WordList theList;

	//This is a constructor that scans the users file and indexes it by removing anything
	//other than the letters A-Z.
	IndexUtility() 
	{
		theList = new WordList();
	}
	
	WordList buildIndex() 
	{
		Scanner s;
		s = new Scanner(System.in);
		int ref = 1;
		while (s.hasNextLine()){ //while there is still input
			String lowerS;
			try {
				lowerS = s.next().toLowerCase(); //converts everything to upper case 
			}catch(Exception e) {
				s.close();
				return theList;
			}
			lowerS = lowerS.replaceAll("[^a-z]",""); //replaces anything that is not letters A-Z with nothing
			if(!lowerS.isEmpty()) 
			{
				theList.addWord(lowerS, ref);
			}
			ref++; //increment the reference
			}
		s.close();
		return theList;
	}
}