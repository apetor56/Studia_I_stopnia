
class Decode extends DecoderInterface {
	private String code = ""; 	// code przechowuje input od uzytkownika
	@Override
	public void input(int bit) {
		code += String.valueOf(bit);
	}

	@Override
	public String output() {
		int xLength = 0;	// xLength przechowuje dlugosc X
		int pos = 0;		// pos przechowuje pierwsza pozycja w "code" po pierwszym zakodowanym zerze 
		String out = "";	// output
		
//		pierwsza petla poszukuje pierwszego zakodowanego zera, zapisuje dlugosc X
//		oraz pierwsza pozycje po zakodowanym zerze
		for(int i = 0; i < code.length(); i++) {
			if(code.charAt(i) == '1') {
				xLength++;
				pos++;
				continue;
			}
//			jesli znak na pozycji "i" jest zerem, xLength != 0 to znaczy, ze
//			znalezlismy dlugosc X, wiec mozna zakonczyc petle
			if(code.charAt(i) == '0' && xLength != 0) {
				out = "0";
				break;
			}
			pos++;
		}
		
		int count = 0;		// licznik jedynek pomagajacy wyznaczyc zakodowane wartosci		
		for(int i = pos; i < code.length(); i++) {
			while(i != code.length() && code.charAt(i) == '1') {
				count++;
				i++;
			}
//			jesli poprzedni znak byl jedynka a obecny jest zerem to nalezy zakodowac wartosc
//			i nastepnie wyzerowac licznik jedynek
			if(i < code.length() && code.charAt(i - 1) == '1' && count != 0) {
				out += String.valueOf(count / xLength - 1);
				count = 0;
			}
		}
		
		return out;
	}

	@Override
	public void reset() {
		code = "";
	}
}

