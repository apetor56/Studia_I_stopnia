import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;


public class SimpleClient {

	public static void main(String[] args) {
		final int PORT = 55555;
		Socket so = null;
		BufferedReader br = null;
		String host = "127.0.0.1";
		
		try {
			so = new Socket( host, PORT ); // tworzymy gniazdo sieciowe
			br = new BufferedReader( new InputStreamReader( so.getInputStream() ) );	
			String line;
			while ( ( line = br.readLine() ) != null ) {
				System.out.println( line );  // to jest odczyt blokujacy !!! http://stackoverflow.com/questions/2776724/java-bufferedreader-readline-blocking
			}			
		}
		catch ( UnknownHostException exc ) {
			System.out.println( "Nie znam takiego hosta " + host );
		}
		catch ( ConnectException exc ) {
			System.out.println( "Blad polaczenia z serwerem " + host );
		}
		catch ( Exception e ) {
			e.printStackTrace();
		}
	}

}
