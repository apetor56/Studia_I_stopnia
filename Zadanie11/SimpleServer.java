import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;


public class SimpleServer {

	private static void showSocketInfo( Socket so ) {
		try {
			System.out.println( "Numer portu, do ktorego gniazdo jest dolaczone, getLocalPort()     = " + so.getLocalPort() );
			System.out.println( "Numer zdalnego portu, do ktorego gniazdo jest dolaczone, getPort() = " + so.getPort() );
			System.out.println( "Adres IP lokalny getLocalAddress() = " + so.getLocalAddress() );
			System.out.println( "Adres IP zdalny  getInetAddress() =  " + so.getInetAddress() );
			System.out.println( "getReceiveBufferSize() = " + so.getReceiveBufferSize() );
			System.out.println( "getSendBufferSize()    = " + so.getSendBufferSize() );
			
		} catch (SocketException e) {
			e.printStackTrace();
		}
	}
	
	
	public static void main(String[] args) {
		final int PORT = 55555;
		
		try {
			ServerSocket so = new ServerSocket( PORT ); // tworzymy gniazdo oczekujace na klienta
			while ( true ) {
				System.out.println( "A teraz sobie poczekamy" );
				Socket s = so.accept(); // to blokujaca metoda, czekamy na klienta
				System.out.println( " - o jest klient " );
				showSocketInfo( s );
				
				
				PrintWriter out = new PrintWriter( s.getOutputStream() );
				out.println( "Witaj kimkolwiek jestes !" );
				out.flush();
				try {
					Thread.sleep( 5000 ); // spimy przez 5 sekund
				}
				catch ( InterruptedException e ) {}
				out.println( "Witaj jeszcze raz kimkolwiek jestes !" );
				out.flush();
				out.close();
			}
		}
		catch ( IOException ex ) { ex.printStackTrace(); }
 	}

}
