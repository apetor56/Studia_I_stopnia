import java.math.*;
public class Main {

	public static void main(String[] args) {
//		String[] words = {"001", "001", "001", "010", "111", "011", "001", "001", "110", "000", "001", "001", "001", "001"};
		String[] words = {"000", "001", "000", "001", "000", "001", "000", "001", "011", "001", "000", "110", "001", "000", "111", "001", "001", "000", "000", "000", "001"};
		Compression com = new Compression();
		for(String x : words)
			com.addWord(x);
		
		com.compress();
		for(int i = 0; i < com.words.size(); i++)
			System.out.println(com.getWord());
	}

}
