/* Name : Gawun Kim
 * This game is Tic-tac-toe. There are two classes: MyPanel.java (it is for "JPanel") and MainGame.java (it is for "JFrame").  
 * In the program, the user can choose some of options before playing the game.
 * First, the user can choose "x" or "o". These signals will be painted on the panel as a mark.
 * Second, the user can choose the turn to start first or second. 
 * 
 * If the user wants to start the game, the user should click "Start" button and the game will be started
 * The user will compete with computer. The user can click(choose) one of the blanks(9 blanks)
 * The one to make a straight line (is consisted by three "x" or "o") will be a winner of this game
 */



import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class MyPanel extends JPanel {
	String[][] moves;
	int winLine;
	boolean ComputersTurn;
	
	MyPanel() {
		moves = new String[3][3]; 
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public void paint(Graphics g) {
		super.paint(g);
		Graphics2D g2 = (Graphics2D) g;
		g2.setColor(Color.BLACK);	//setting the game lines as black color
		g2.setStroke(new BasicStroke(2)); // the thickness of lines
		g2.drawLine(0, 100, 300, 100); //  horizontal line
		g2.drawLine(0, 200, 300, 200); //  horizontal line
		g2.drawLine(100, 0, 100, 300); //   vertical line
		g2.drawLine(200, 0, 200, 300); //   vertical line

 
		for (int y = 0; y < 3; y++) {  //two for loops to go through the whole array
			for (int x = 0; x < 3; x++) {
				// System.out.print(moves[x][y] + " ");
				if (moves[x][y] == "X") {  // if the move we are selecting is an X 
					drawXSquare(x, y, g2); // then it is drawing an X using the drawXsquare method
				}
				if (moves[x][y] == "O") {  // if the move we are selecting is an O 
					drawOSquare(x, y, g2);  // then it is drawing an O using the drawOsquare method
				}
			}
		}
	
		/*  The first  column is winLine 1
		 *  The Second column is winLine 2
		 *  The Third  column is winLine 3
		 *  
		 *  The first   row   is winLine 4
		 *  The second  row   is winLine 5
		 *  The third   row   is winLine 6
		 *  
		 *  winLine 7 and 8 are the diagonals
	
	   
		*/
		
		if (winLine == 1) {
			g2.drawLine(50, 0, 50, 300);
		} else if (winLine == 2) {
			g2.drawLine(150, 0, 150, 300);
		} else if (winLine == 3) {
			g2.drawLine(250, 0, 250, 300);
		} else if (winLine == 4) {
			g2.drawLine(0, 50, 300, 50);
		} else if (winLine == 5) {
			g2.drawLine(0, 150, 300, 150);
		} else if (winLine == 6) {
			g2.drawLine(0, 250, 300, 250);
		} else if (winLine == 7) {
			g2.drawLine(0, 0, 300, 300);
		} else if (winLine == 8) {
			g2.drawLine(0, 300, 300, 0);
		}
	}
	//once the mouse is clicked in the panel it gets the position from the MainGame class and uses them as arguments in the mouse clicked method
	public boolean MouseClicked(int x, int y) {
		int xPos = x / 100;  //because the panel is 300x300 
		int yPos = y / 100;    // the numbers are divided by 100 to know which square is it in 

		if(ComputersTurn)  //nothing to do if its the computers turn
			return false;
		
		if (moves[xPos][yPos] != null) {  //if the position is not null then that position is already taken
			System.err.println("This is allready taken, click somehwere else");
			return false;
		}
		if (MainGame.UserX) { //if the user's choice was x then set the position clicked to X and repaint other wise O and repaint
			moves[xPos][yPos] = "X";
			repaint();
		} else {
			moves[xPos][yPos] = "O";
			repaint();
		}
		
		if(winner(xPos, yPos)){
			return true; // The user wins
		}
		ComputersTurn = true;
		this.computerMove();
		return false;
	}

	public void drawXSquare(int x, int y, Graphics2D g) { // the method for the X
		int startX = 100 * x;
		int startY = 100 * y;
		int endX = 100 + startX;
		int endY = 100 + startY;
		g.drawLine(startX + 15, endY - 15, endX - 15, startY + 15);
		g.drawLine(startX + 15, startY + 15, endX - 15, endY - 15);
	}

	public void drawOSquare(int x, int y, Graphics2D g) { // the method for the O
		int startX = 100 * x;
		int startY = 100 * y;
		g.drawOval(startX + 15, startY + 15, 75, 75);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public boolean winner(int lastX, int lastY) { //checks for winners using the the Last x and y positions clicked

		boolean winner = false;
		String symbol = moves[lastX][lastY];
		int numFound = 0;
		// Left - Right
		for (int c = 0; c < 3; c++) { 
			if (moves[lastX][c] == symbol) //checks if the squares next to last position is the same
				numFound++; //counts the number of similar squares 
		}

		if (numFound == 3) { //if it finds 3 then we have a win
			if (lastX == 0) { //checks which line it is repaints the panel and returns
//			 System.out.println("winLine = 1");
				winLine = 1;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			} else if (lastX == 1) {
				winLine = 2;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			} else if (lastX == 2) {
				winLine = 3;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			}
		}
		// up and down
		int r;
		numFound = 0;
		for (r = 0; r < 3; r++) {
			if (moves[r][lastY] == symbol)
				numFound++;
		}

		if (numFound == 3) {
			if (lastY == 0) {
				winLine = 4;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			} else if (lastY == 1) {
				winLine = 5;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			} else if (lastY == 2) {
				winLine = 6;
				winner = true;
				MainGame.running = false;
				repaint();
				return true;
			}

		}

		numFound = 0;
		for (int i = 0; i < 3; i++) {
			if (moves[i][i] == symbol)
				numFound++;
		}
		if (numFound == 3) {
			winLine = 7;
			winner = true;
			MainGame.running = false;
			repaint();
			return true;
		}

		numFound = 0;
		for (int i = 0; i < 3; i++) {
			if (moves[i][2 - i] == symbol)
				numFound++;
		}
		winLine = 0;
		if (numFound == 3) {
			winLine = 8;
			winner = true;
			MainGame.running = false;
			repaint();
			return true;
		}
		MainGame.won = winner;
		return winner;
	}
//resets the board to null
	public void reset() {
		for (int i = 0; i < 3; i++) //two for loops to go over the whole board 
			for (int j = 0; j < 3; j++) {
				moves[i][j] = null; //sets every value to null
				winLine = 0; //resets the win line
			}
		repaint(); //repaints the panel
	}
	//counts how many empty places are left
	public int howManyChoices(){
		int count = 0; //sets count to 0
		for(int i=0; i<3; i++){ //uses two for loops to go through the whole board
			for(int j=0; j<3; j++){
				if(moves[i][j] == null) //checks for empty spots
					count++;  //counts empty spots
			}
		}
		return count;  //returns the value
	}
	// decides what the computer move is
	public void computerMove() {
		int choices = howManyChoices();  //saves the number of available spots into the variable choices
		int random = 1; 
		if(choices > 1)
			random = ThreadLocalRandom.current().nextInt(1, choices);  //chooses a random number to make a move

		int empty = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (moves[i][j] == null) {
					empty++;
					if (empty == random) {
						// Make move
						if (MainGame.UserX) {  //if the user is X then computer is O and the other way around
							moves[i][j] = "O";
						} else {
							moves[i][j] = "X";
						}
						repaint(); //repaint the board
						winner(i,j);  //check for winners after every computer move 
						ComputersTurn = false;  //change turns
						return;
					}

				}
			}
		}
	}

	public void newGame() {
		reset();
		if(MainGame.UserFirst){  //if not users turn than its the computers
			ComputersTurn = false;
		}else{
			ComputersTurn = true;
			computerMove(); //make a move
		}
	}
}