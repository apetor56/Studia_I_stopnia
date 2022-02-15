import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Decode dec = new Decode();
		Scanner scan = new Scanner(System.in);
		
		String s = "0000111111111111110000000000111111111111111111111111111111111111111111111111111111110000000";
		for(int i = 0; i < s.length(); i++)
				dec.input(s.charAt(i) - '0');
		System.out.println(dec.output());
	}

}
