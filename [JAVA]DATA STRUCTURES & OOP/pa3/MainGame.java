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


import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JTextPane;
import javax.swing.JList;
import javax.swing.JOptionPane;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Color;
import javax.swing.ButtonGroup;

public class MainGame extends JFrame {

	public static boolean UserX;
	public static boolean UserFirst;
	public static boolean running = false;
	public static boolean won;
	
	private JPanel contentPane;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private final ButtonGroup buttonGroup_1 = new ButtonGroup();

///////////////////// Launch the application///////////////////
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run(){
				try {
					MainGame frame = new MainGame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	// Create the frame/////////////////////////////////////// 
	
	public MainGame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 469, 337);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JCheckBox chckbxUser = new JCheckBox("User");
		buttonGroup.add(chckbxUser);
		JCheckBox chckbxComputer = new JCheckBox("Computer");
		buttonGroup.add(chckbxComputer);
		chckbxComputer.setSelected(true);
		JCheckBox chckbxo = new JCheckBox("\"O\"");
		buttonGroup_1.add(chckbxo);
		chckbxo.setSelected(true);
		JCheckBox chckbxx = new JCheckBox("\"X\"");
		buttonGroup_1.add(chckbxx);
		JButton btnRestart = new JButton("Restart");
		btnRestart.setEnabled(false);
		MyPanel panel = new MyPanel();
		JButton btnStart = new JButton("Start");
		btnStart.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				//if button pressed the game starts blocks the user from changing settings and checks the turn
				running = true;
				chckbxUser.setEnabled(false);
				chckbxComputer.setEnabled(false);
				chckbxx.setEnabled(false);
				chckbxo.setEnabled(false);
				btnStart.setEnabled(false);
				btnRestart.setEnabled(true);
				if(UserFirst){              // this is indicating the turn to play.
					String st="Its the User's Turn";
					JOptionPane.showMessageDialog(null,st);
				}else{
					String st="Its the Computer's Turn";
					  JOptionPane.showMessageDialog(null,st);
				}
				panel.newGame();  //  start the game
			}
		});
		btnStart.setBounds(36, 202, 117, 29);
		contentPane.add(btnStart);
		
		chckbxComputer.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				chckbxUser.setSelected(false);
				UserFirst = false;
			}
		});
		chckbxComputer.setBounds(13, 38, 128, 23);
		contentPane.add(chckbxComputer);
		
		chckbxUser.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				UserFirst = true;
				chckbxComputer.setSelected(false);
			}
		});
		chckbxUser.setBounds(13, 73, 128, 23);
		contentPane.add(chckbxUser);
		
		chckbxx.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				UserX = true;
				chckbxo.setSelected(false);
			}
		});
		chckbxo.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				UserX = false;
				chckbxx.setSelected(false);
			}
		});
		chckbxx.setBounds(13, 140, 128, 23);
		contentPane.add(chckbxx);
		
		chckbxo.setBounds(13, 167, 128, 23);
		contentPane.add(chckbxo);
		
		JTextPane txtpnChooseWhoGoes = new JTextPane();
		txtpnChooseWhoGoes.setEditable(false);
		txtpnChooseWhoGoes.setText("Choose who goes first:");
		txtpnChooseWhoGoes.setBounds(6, 17, 148, 16);
		contentPane.add(txtpnChooseWhoGoes);
		
		JTextPane txtpnPickOne = new JTextPane();
		txtpnPickOne.setEditable(false);
		txtpnPickOne.setText("Pick one:");
		txtpnPickOne.setBounds(6, 121, 63, 16);
		contentPane.add(txtpnPickOne);
		

		panel.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (running || won){  //gets clickes only if game is running and no one won yet
				panel.MouseClicked(e.getX(), e.getY());

				}else{  //else prints the message bellow
					String st="Please Start the Game";
					  JOptionPane.showMessageDialog(null,st);
				}
			}
		});
		panel.setBackground(Color.WHITE);
		panel.setBounds(163, 6, 300, 300);
		contentPane.add(panel);
		
		btnRestart.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				running = false;  //ends game if running
				panel.reset();  //clears everyting 
				chckbxUser.setEnabled(true);
				chckbxComputer.setEnabled(true);
				chckbxx.setEnabled(true);
				chckbxo.setEnabled(true);
				btnStart.setEnabled(true);
				btnRestart.setEnabled(false);
				
			}
		});
		btnRestart.setBounds(36, 232, 117, 29);
		contentPane.add(btnRestart);
		
	}
}