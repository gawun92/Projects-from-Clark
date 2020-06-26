// Name : Gawun Kim
// May 3 2018
// CSE 223 by Nick Macias
// Program Assignment 2
// Description : There are 4 of classes. Main, IndexUtility, PositionList, and WordList. This program is
//               user can input some words. This program labels index orderly and sorts output. This program is
// 				 Java base.


class WordListNode 
{
	String word;
	WordListNode next;
	PositionList usage;
	
	WordListNode(String w, int loc) //returns an empty list
	{ 
		word = w;
		next = null;
		usage = new PositionList();
		usage.add(loc);
	}
}

public class WordList 
{

	WordListNode handle;
	
	WordList() 
	{
		handle = null; //set handle to be the first node
	}

	void addWord(String w, int loc) 
	{
		if (handle == null) //if the list is empty set the new node to handle
		{ 
			this.handle = new WordListNode(w, loc);
			return;
		}
		WordListNode node = FindNode(w);
		if (node == null) 
		{ 
			WordListNode cur = handle;
			WordListNode next = cur.next;
			// Are we first?
			if (w.compareTo(cur.word) < 0) //if <0 the word should be before the handle
			{ 
				handle = new WordListNode(w, loc); // set the new node to handle
				handle.next = cur; //move the previous handle to the next node
				return;
			}
			while (next != null) 
			{
				if (w.compareTo(next.word) < 0)  // This compares the rest of the list and sorts them
				{
					cur.next = new WordListNode(w, loc);
					cur.next.next = next;
					return;
				}

				cur = next;
				next = cur.next;
			}
			cur.next = new WordListNode(w,loc);
			return;
		}
		node.usage.add(loc);
		return;
	}

	public WordListNode FindNode(String word) // Finds the node that is equal to the argument 
	{ 
		WordListNode node = handle;
		if (node == null)
			return node; //returns null
		while (node != null) 
		{
			if (node.word.equals(word)) 
			{
				return node;
			}
			node = node.next;
		}
		return node;
	}
	
	public String toString() //to String method to print the wordlist
	{ 
		String out = "";
		WordListNode temp = handle;
		if (temp == null) 
		{
			return out;
		}
		while (temp != null) {
			out += temp.word + temp.usage + "\n"; //prints the word and reference 
			temp = temp.next;
		}
		return out;
	}
	
	public void print() 
	{
		System.out.println(IndexUtility.theList);
	}
}