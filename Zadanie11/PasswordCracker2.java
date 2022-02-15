import java.io.BufferedReader;
// import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.*;

public class PasswordCracker2 implements PasswordCrackerInterface {
    private String defaultPassword;
    private String oldPassword;
    private int trial = 0;
    private int correct = 0;
    private int which = 0;

    PasswordCracker2() {
        defaultPassword = new String();
        oldPassword = new String();
    }

    String guessPassword(String sequence) {
        if(trial == 0) {
            for(int i = 0; i < sequence.length(); i++) {
                defaultPassword += PasswordComponents.passwordComponents.get(sequence.charAt(i)).get(0);
                oldPassword += PasswordComponents.passwordComponents.get(sequence.charAt(i)).get(0);
            }
        }
        else {
            oldPassword = defaultPassword;

            List<Character> currentList = new ArrayList<Character>();
            currentList = PasswordComponents.passwordComponents.get(sequence.charAt(which));
            // Character z = currentList.get(defaultPassword.indexOf(defaultPassword.charAt(correct)) + 1);
            // String znak = Character.toString(z);
            Character currentChar = defaultPassword.charAt(which);
            int currentIndex = currentList.indexOf(currentChar);

            if(currentIndex + 1 == currentList.size()) {
                which++;
                return defaultPassword;
            }

            defaultPassword = defaultPassword.substring(0, which) + currentList.get(currentIndex + 1) + defaultPassword.substring(which + 1, defaultPassword.length());
        }
        
        trial++;
        return defaultPassword;
    }

    @Override
    public String getPassword(String host, int port) {
        // TODO Auto-generated method stub
        Socket socket = null;
        BufferedReader bufferReader = null;

        try {
            socket = new Socket(host, port);
            bufferReader = new BufferedReader( new InputStreamReader( socket.getInputStream() ) );

            String s;
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            writer.println("Program");
            
            while ( ( s = bufferReader.readLine() ) != null ) {
				// System.out.println( s );
                
                if(s.contains("schema : ")) {
                    s = s.replaceAll("schema : ", "");
                    String mess = new String();
                    String schema = s;

                    // 729110156
                    
                    int i = 0;
                    int oldCorrect = 0;

                    while(true) {
                        if(i == 0){
                            mess = bufferReader.readLine();
                            // System.out.println(mess);
                            i++;
                        }

                        String password = guessPassword(schema);
                        // System.out.println(password);
                        writer.println(password);
                        
                        mess = bufferReader.readLine();
                        // System.out.println(mess);
                        
                        if(mess.contains("To nie hasło, odgadnięto ") && mess.contains(" znaków")) {
                            oldCorrect = correct;
                            mess = mess.replaceAll("To nie hasło, odgadnięto ", "");
                            mess = mess.replaceAll(" znaków", "");
                            correct = Integer.parseInt(mess);
    
                            // System.out.println("old: " + oldCorrect + ", current: " + correct);
                            if(oldCorrect > correct) {
                                defaultPassword = oldPassword;
                                correct = oldCorrect;
                                which++;
                            }
                        }
                        else {
                            mess = bufferReader.readLine();
                            // System.out.println(mess);
                            oldPassword = "";
                            defaultPassword = "";
                            trial = 0;
                            correct = 0;
                            which = 0;
                            
                            return "udalo sie";
                        }
                    }
                }
			}


        }
        catch ( UnknownHostException exc ) {
			System.out.println( "unknown host " + host );
		}
		catch ( ConnectException exc ) {
			System.out.println( "connection error with " + host );
		}
		catch ( Exception e ) {
			e.printStackTrace();
		}

        return "no niestety";
    }
}