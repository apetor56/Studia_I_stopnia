import java.util.*;

public class Main {
	public static void main(String[] args) {
		Map<String, String> map = new HashMap<String, String>();
		
//		String in = "Dxb80 1*9c3ó8\n1023*4£ f*30{*, 5678x!xW**\n*\n}!#x8W470{* s7x6xw4!9i";
//		String in = "Wydzia³Fizyki,AstronomiiiInformatykiStosowanej";
		String in = "Wydzia³   Fizyki, 	Astronomii \n    i\n    Informatyki 			Stosowanej\nog³asza, ¿e i tak wszystkich na numerkach wypierdoli \nxD";
		Decrypter dec = new Decrypter();
		
//		dec.setInputText("dupa cipa Wydzia³ Fizyki, Astronomii i Informatyki Stosowanei");
		System.out.println(dec.getCode());
		System.out.println(dec.getDecode());	
	}
}
