// Name : Gawun Kim
// May 3 2018
// CSE 223 by Nick Macias
// Program Assignment 2
// Description : There are 4 of classes. Main, IndexUtility, PositionList, and WordList. This program is
//               user can input some words. This program labels index orderly and sorts output. This program is
// 				 Java base.

public class Main 
{

	public static void main(String[] args) 
	{
		IndexUtility myIU = new IndexUtility(); 
		WordList myList = myIU.buildIndex();
		myList.print(); // show the index
	}
}