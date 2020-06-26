

import java.io.PrintStream;
import java.util.Scanner;

public class Tree {

	TNode root;
	Scanner sc;
	
	Tree(){
		sc = new Scanner(System.in);
		root = new TNode("data");
	}
	
	public void Input(Scanner input) {
		root = question(input);
	}
	
	TNode question(Scanner input) {
		if(input.nextLine().equals("Q:")){				// If computer received a line "Q:"
			return(new TNode(input.nextLine(),question(input),question(input))); // constructing Tree + recursive (go through this method again)
		}
		else {											// If computer received a line "A:"
			return (new TNode(input.nextLine()));
		}
	}
	
	TNode newQuestions(TNode root, PrintStream output) {
		if(root != null) {
			if((root.left != null)||(root.right != null)) {
				output.println("Q:");				// this is writing down information into file
				output.println(root.data);			// this is for question
			} else {
				output.println("A:");				// this is writing down information into file
				output.println(root.data);			// this is for answer
			}
			root.left = newQuestions(root.left,output);	
			root.right = newQuestions(root.right,output);
		}
		return (root);
	}
	
	public void newQuestion(PrintStream output) {
		root = newQuestions(root,output);
	}
	
	TNode askQuestions(TNode root) {
		if((root.left == null)&&(root.right == null)) {       // if there is not information from children node
			System.out.println( "Is it " + root.data + "?");
			String guess = sc.nextLine();
			
			if(guess.equals("yes")) {
				System.out.println("Yeah!!  I got it!" + "\n");
				
			} 
			else if(guess.equals("no")) {
				System.out.println("What was in your mind?");
				
				String done = "";		// makes it to string
				done = sc.nextLine();	//makes it to string
				TNode newAnswer = null;
				newAnswer = new TNode(done);
				System.out.println("Enter a question to be able to answer yes or no.");
				
				String userQuestion = "";     //makes it to string
				userQuestion = sc.nextLine();
				System.out.println("What is your answer of your question?");
				System.out.println("Please type 'yes' or 'no'");
				
				String last = "";          
				last = sc.nextLine();									// the question will be replaced to the head
				
				if(last.equals("yes")) {								// if user said yes, then the new information would go to child tree for yes
					TNode data = new TNode(root.data);					// the prior data will go to child tree for no as an answer.
					TNode question = new TNode(userQuestion,newAnswer,data);	
					root = question;
					System.out.println("Your input has been recorded successfully!! ");
				}else if(last.equals("no")){							// the answer of the new information will go to child tree for no
					TNode data = new TNode(root.data);					// the prior data will go to child tree for yes as an answer
					TNode question = new TNode(userQuestion, data, newAnswer);
					root = question;
					System.out.println("The information has been recorded successfully!! ");
				}else {
					return root;
				}
				
			}else {
				System.out.println("Please enter your answer as yes or no");
			}
		} else {
			System.out.print(root.data + "\n");
			String guess = sc.nextLine();
			if(guess.equals("yes")){
				root.left = askQuestions(root.left);
			}else if(guess.equals("no")){
				root.right = askQuestions(root.right);
			}else {
				System.out.println("Please Eneter your answer as yes or no");
				root = askQuestions(root);
			}
		}
		return root;
	}
	public TNode askUser() {
		return askQuestions(root);
	}
	public boolean userInput(String input) {   // This method is making the program to keep playing until the user says no.
		System.out.println(input + "");
		String rp = sc.nextLine();
		while((!rp.equals("yes"))&&(!rp.equals("no"))) {
			System.out.println("Please enter your answer as yes or no.");
			System.out.print(input + "");
			rp = sc.nextLine();
		}
		return (rp.equals("yes"));
	}
}
