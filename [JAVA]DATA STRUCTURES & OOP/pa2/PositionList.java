// Name : Gawun Kim
// May 3 2018
// CSE 223 by Nick Macias
// Program Assignment 2
// Description : There are 4 of classes. Main, IndexUtility, PositionList, and WordList. This program is
//               user can input some words. This program labels index orderly and sorts output. This program is
// 				 Java base.


class PositionListNode 
{
	public int location;
	public PositionListNode next;

	PositionListNode(int loc) 
	{
		location = loc;
		next = null;
	}
}

public class PositionList 
{

	PositionListNode handle;

	PositionList() 
	{
		handle = null; //set handle to be the first node
	}

	void add(int loc) 
	{
		if (handle == null) //if the list is empty then add a new node
		{ 
			this.handle = new PositionListNode(loc);
			return;
		}
		PositionListNode n = new PositionListNode(loc);
		PositionListNode temp = handle; //set a temp to handle the first node
		while (temp.next != null) //check if next is null if not keep going down the list
		{ 
			temp = temp.next;
		}
		temp.next = n; //if next is null then add the new node
		return;
	}
	
	public String toString() //toString method to print the list
	{ 
		String out = "";
		PositionListNode temp = handle; //sets a temp to the first node
		if (temp == null) // if the list is empty just return out
		{ 
			return out;
		}
		while (temp != null) //other wise print the temp location
		{ 
			out += " " + temp.location;
			temp = temp.next; // and move to the next node
		}
		return out; //then print
	}
}