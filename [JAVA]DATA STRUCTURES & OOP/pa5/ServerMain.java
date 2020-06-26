//Gawun && Deboye
//11/June/2018 Spring
// CSE223 by Nick Macias
// PA5: there are three programs: Threads.java, ServerMain.java, and ClientMain.java. This program is setting up server and text can be exchangable between ServerMain and ClientMain 



import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.io.PrintWriter;

public class ServerMain {
	ServerSocket socket;

/////////////////////////////////////////////////////////////////////////
	public static void main(String[] args) {  //main run-program
		ServerMain program = new ServerMain();
		program.run();
	}
////////////////////////////////////////////////////////////////////////

	ServerMain(){
		try{
			socket = new ServerSocket(1201); // for port 1201
			System.out.println(socket.getInetAddress() + ":" + socket.getLocalPort());
		} catch(IOException e){
			System.err.print(e.getMessage());
		}
	}

	public void run() {
		while (true) {
			Socket client = null; // initialized
			PrintWriter out;

			try {
				client = this.socket.accept();
				out = new PrintWriter(client.getOutputStream());
			} catch (IOException e) {
				throw new RuntimeException("Error getting the client's connection", e);
			}
			System.out.println("It is connected by: " + client);
			Thread thread = new Thread(new Threads(client)); // makes the server with thread

			thread.start();

			Scanner scanner = new Scanner(System.in); //scan the input
			while (scanner.hasNextLine()) {
				out.println(scanner.nextLine());
				if (out.checkError()) { ///user connection lost
					thread.interrupt();
					break;
				}
										
				out.flush();
			}
			try {
				client.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			thread.interrupt();
		}
	}
}
