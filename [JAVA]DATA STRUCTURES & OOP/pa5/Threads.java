//Gawun && Deboye
//11/June/2018 Spring
// CSE223 by Nick Macias
// PA5: there are three programs: Threads.java, ServerMain.java, and ClientMain.java. This program is setting up server and text can be exchangable between ServerMain and ClientMain 



import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.util.Scanner;

public class Threads implements Runnable {

	private Socket socket;

	public Threads(Socket socket) {
		this.socket = socket;
	}

	public void run() {
		try {
			InputStream input = socket.getInputStream();
			Scanner sc = new Scanner(input);
			while (!Thread.interrupted()) {
				while (sc.hasNextLine()) {
					System.out.println(sc.nextLine());
				}
			}
			sc.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
