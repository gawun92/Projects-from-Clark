//Gawun && Deboye
//11/June/2018 Spring
// CSE223 by Nick Macias
// PA5: there are three programs: Threads.java, ServerMain.java, and ClientMain.java. This program is setting up server and text can be exchangable between ServerMain and ClientMain 



import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;
import java.io.PrintWriter;


public class ClientMain {
	Scanner scanner;
	Socket socket;

////////////////////////////////////////////////////////////////////////
	public static void main(String[] args){  /// main run-program
		ClientMain program = new ClientMain();
		program.run();
	}
/////////////////////////////////////////////////////////////////////////

	private ClientMain() {
		try {
			System.out.print("Choose a host or IP address to connect to: ");
			scanner = new Scanner(System.in); // scan the input
			String host = scanner.nextLine();
			socket = new Socket(host, 1201);  //// for port 1201
			System.out.println(socket.getInetAddress() + ":" + socket.getLocalPort()); // prints for addess and port 

		} catch (IOException e) {
			System.err.print(e.getMessage());
		}
	}

	public void run() {
		PrintWriter out;
		try {
			out = new PrintWriter(socket.getOutputStream());
		} catch (IOException e) {
			throw new RuntimeException("Error getting out stream", e);
		}
		new Thread(new Threads(socket)).start(); // Make the server with thread

		while (scanner.hasNextLine()) {
			
			out.println(scanner.nextLine());
			out.flush(); // processsing immediately
					
		}
		scanner.close();
	}
}
