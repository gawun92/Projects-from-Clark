// Gawun Kim
// CSE223 by Nick Macias
// Program assignment 4 
/* This program is close(?) to AI system. Computer will ask a question and it can guess user's thinking. It can record data into one file and it will be
 *  a base of the computer's question to ask.
 *  
 * There are three of main skills in this program: 
 * First : This is binary tree base (left and right). 
 * Second : Take out and in information from a file and use this information as a programming base.
 * 
 * The user should set up the file information for the beginning. One question and two answers.
 * for example, the information should be this shape.
 ******************************
 * Q:
 * Is it hard?
 * A:
 * Rock   
 * A:
 * Pilow
 ******************************
 */


                       ////////////// When user finished the program, information would recorded!
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	
	public static String database = "/home/gawun/Desktop/haha.txt";    // This the location of the file; the user should change it when dealing with the program
	
	public static void main(String[] args) throws FileNotFoundException{ // when file cannot be found, the error would be shown.
		Tree game = new Tree();
		game.Input(new Scanner(new File(database)));
		
		do {
			System.out.println("Think of object in your mind. I will guess what it is");
			System.out.println("If you think yes, then type 'yes'");
			System.out.println("If you think no, then type 'no'" + "\n");
			game.askUser();
		}
		
		while(game.userInput("Would you like me to guess your thinking again?"));
		
		game.newQuestion(new PrintStream(new File(database)));    /// When the user finishes the program, all information records into the file.
		System.out.println("Thank you Bye~ Your information has been saved into your txt file!! ");
	}

}
