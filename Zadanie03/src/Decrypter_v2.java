import java.util.*;

class Decrypter implements DecrypterInterface {
	private String code;
	private String name;
	private int nameSize;
	
	Decrypter() {
		name = "Wydzia\u0142Fizyki,AstronomiiiInformatykiStosowanej";
		nameSize = 46;
	}
	
	@Override
	public void setInputText(String encryptedDocument) {
		if(encryptedDocument != null)
			code = encryptedDocument.replaceAll("\\s+", "");		
		else
			code = "";
	}

	@Override
	public Map<Character, Character> getCode() {
		Map<Character, Character> mapCode = new HashMap<Character, Character>();
		
		for(int i = 0; i <= code.length() - nameSize; i++) {
			boolean ff = false;
			for(int j = 0; j < nameSize; j++) {
				if(!mapCode.containsKey(name.charAt(j))) {
					mapCode.put(name.charAt(j), code.charAt(i + j));
//					System.out.println("key: " + name.charAt(j) + "\tvalue: " + code.charAt(i + j));
				}
				else {
					Character c = name.charAt(j);
//					System.out.println(c);
					if(mapCode.get(c).charValue() != code.charAt(i + j)) {
						ff = true;
						break;
					}
				}
			}
			
			if(ff) {
				mapCode.clear();
				continue;
			}
			
			boolean f = true;
			for(int j = 0; j < nameSize; j++) {
				Character current = mapCode.get(name.charAt(j));
				Character key = ' ';
				for(Map.Entry<Character, Character> entry : mapCode.entrySet()) {
					if(mapCode.get(entry.getKey()) == current) {
						key = entry.getKey();
						break;
					}
				}
				if(key.charValue() != name.charAt(j)) {
					f = false;
					break;
				}
			}
			if(f) {
				mapCode.remove(',');
				return mapCode;
			}
			else
				mapCode.clear();
		}
		
		return mapCode;
	}

	@Override
	public Map<Character, Character> getDecode() {
		Map<Character, Character> mapDecode = new HashMap<Character, Character>();
		Map<Character, Character> mapCode = new HashMap<Character, Character>(getCode());
		
		for(Map.Entry<Character, Character> entry : mapCode.entrySet())
			mapDecode.put(entry.getValue(), entry.getKey());
		
		return mapDecode;
	}
}
