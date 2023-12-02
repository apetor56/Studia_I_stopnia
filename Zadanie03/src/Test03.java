import java.util.HashMap;
import java.util.Map;

public class Test03 {

  public static Map<Character, Character> stringToMap(String s) {
    Map<Character, Character> myMap = new HashMap<Character, Character>();
    String[] pairs = s.split(", ");
    for (int i = 0; i < pairs.length; i++) {
      String pair = pairs[i];
      String[] keyValue = pair.split("=");
      myMap.put(keyValue[0].toCharArray()[0], keyValue[1].toCharArray()[0]);
    }
    return myMap;
  }

  public static String decryptText(Map<Character, Character> decode, String text) {
    StringBuilder result = new StringBuilder();

    for (Character ch : text.toCharArray()) {
      Character decodedChar = decode.get(ch);
      if (decodedChar != null)
        result.append(decodedChar);
      else
        result.append(ch);
    }

    return result.toString();
  }

  public static Map<Character, Character> flipMap(Map<Character, Character> original) {
    Map<Character, Character> flipped = new HashMap<>();
    for (Map.Entry<Character, Character> entry : original.entrySet()) {
      flipped.put(entry.getValue(), entry.getKey());
    }
    return flipped;
  }

  public static void main(String[] args) throws Exception {
    int testCount = 0;
    String res;
    Decrypter dec = new Decrypter();
    Map<Character, Character> resultMap;
    Map<Character, Character> expectedMap;

    // ==== 1-1 test ====
    dec.setInputText(
        "Wydzia≥   Fizyki, 	Astronomii \n    i\n    Informatyki 			Stosowanej\nog≥asza, øe i tak wszystkich na numerkach wypierdoli \nxD");
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=i, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
      throw new Exception("test 1 failed, result: " + resultMap.toString());
    testCount++;

    // ==== test oramusa (code) ====
    String test2 = "Dxb80 1*9c3Û8\n1023*4£ f*30{*, 5678x!xW**\n*\n}!#x8W470{* s7x6xw4!9i";
    dec.setInputText(test2);
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=4, A=5, ≥=£, d=2, e=9, F=f, f=#, i=*, I=}, j=i, k={, m=W, n=!, o=x, r=8, s=6, S=s, t=7, W=1, w=w, y=0, z=3");
    if (!resultMap.equals(expectedMap))
      throw new Exception("test oramusa (code) failed: " + resultMap.toString());
    testCount++;

    // ==== test oramusa (original string match) ====
    String decodedStr = decryptText(dec.getDecode(), test2);
    if (!decodedStr.equals("Dobry WieczÛr\nWydzia≥ Fizyki, Astronomii\ni\nInformatyki Stosowanej"))
      throw new Exception("test oramusa (original string match) failed: " + decodedStr);
    testCount++;

    // ==== exact input test ====
    dec.setInputText("Wydzia≥ Fizyki, Astronomii i Informatyki Stosowanej");
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=i, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
      throw new Exception("exact input test failed: " + resultMap.toString());
    testCount++;

    // ==== pattern in the middle test ====
    dec.setInputText(
        "dupa Wydzia≥ Przyrodniczy xDD aaa Wydzia≥ Fizyki, Astronomii i Informatyki Stosowanej oadjsod aj alsd jals jasdl jasl djas l lsajd ;lajslaskdjalds ");
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=i, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
      throw new Exception("pattern in the middle test failed: " + resultMap.toString());
    testCount++;

    // ==== pattern in the end ====
    dec.setInputText(
        "dupa Wydzia≥ Przyrodniczy xDD aaa  oadjsod aj alsd jals jasdl jasl djas l lsajd ;lajslaskdjalds. I tak was wszystkich upierdolimy, podpisano Wydzia≥ Fizyki, Astronomii i Informatyki Stosowanej");
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=i, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
      throw new Exception("pattern in the end failed: " + resultMap.toString());
    testCount++;

    // ==== pattern in the middle with another fake pattern ====
    dec.setInputText(
        "dupa Wydzia≥ Przyrodniczy Wydzaa≥ Fizyki, Astronomii i Informatyki Stosowanej xDD aaa Wydzia≥ Fizyki, Astronomii i Informatyki Stosowanej oadjsod aj alsd jals jasdl jasl djas l lsajd ;lajslaskdjalds ");
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=i, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
      throw new Exception("pattern in the middle with another fake pattern test failed: " + resultMap.toString());
    testCount++;

    // ==== matching occurences, mismatching count pattern test ====
    dec.setInputText(
        "dupa Wydzia≥ Przyrodniczy Wadzia≥ Fizaki, Astronomii i Informataki Stosowanej xDD aa oadjsod aj alsd jals jasdl jasl djas l lsajd ;lajslaskdjalds ");
    res = dec.getCode().toString();
    if (!res.equals("{}"))
      throw new Exception("matching occurences, mismatching count pattern test failed: " + resultMap.toString());
    testCount++;

    // ==== caesar's cipher ROT10 map generation ====
    String rot10 = "Ginjsk≥ Psjius, Kcdbyxywss s Sxpybwkdius Cdycygkxot yq≥kcjk, øo s dku gcjicdusmr xk xewobukmr gizsobnyvs hN";
    dec.setInputText(rot10);
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=k, A=K, ≥=≥, d=n, e=o, F=P, f=p, i=s, I=S, j=t, k=u, m=w, n=x, o=y, r=b, s=c, S=C, t=d, W=G, w=g, y=i, z=j");
    if (!resultMap.equals(expectedMap))
      throw new Exception("caesar's cipher map generation failed, result: " + resultMap.toString());
    testCount++;

    // ==== caesar's cipher ROT10 decryption test ====
    decodedStr = decryptText(dec.getDecode(), rot10);
    if (!decodedStr.equals(
        "Wydzia≥ Fizyki, Astronomii i Informatyki Stosowanej oq≥asza, øe i tak wszystkimr na nemerkamr wyzierdovi hN"))
      throw new Exception("caesar's cipher decryption failed, result: " + decodedStr);
    testCount++;

    // ==== caesar's cipher ROT10 key flip test ====
    // checks if `code` is equal to `decode` with flipped keys and values
    Map<Character, Character> code = dec.getCode();
    if (!flipMap(code).equals(dec.getDecode()))
      throw new Exception("flipped map test failed");
    testCount++;

    // ==== null input test ====
    dec.setInputText(null);
    if (dec.getCode().size() != 0 || dec.getDecode().size() != 0)
      throw new Exception("null input test failed");
    testCount++;

    // ==== empty input test ====
    dec.setInputText("");
    if (dec.getCode().size() != 0 || dec.getDecode().size() != 0)
      throw new Exception("empty input test failed");
    testCount++;

    // ==== invalid input test ====
    dec.setInputText("Dupa");
    if (dec.getCode().size() != 0 || dec.getDecode().size() != 0)
      throw new Exception("invalid input test failed");
    testCount++;

    // ==== random cipher test ====
    String ciphered = "qF d VI Ddp JÍKIG fg•F≥dNUO èOG”Í KÍ VNDKN— g DdNrdN gèIVNDg DFrdN DJØI≥p g KNRF fF ØFrdDg?\nGIDg KÍ ≥FRaúN ØFgOG d RFè”F—c fg•F≥dNUI? πI ”dN ≥dNG IúN ∆I•FD”Í KÍJNU g fdNrdN,\nfPÍrI ”dN JFGÍ—úI•ND ”I≥NK fF ØFrdDg d UFRF FrØI∆IDg, GF∆NDg DFrdN FrØI∆If KÍfP fF ”I KF gID•O∆Íúd DFrdN IúN ”dN ”IDgNRF JIJdN∆I JFúIUI ”IDgNRF ØFèIUI ≥dNúUh FDFrp ,\nÊÍègdI• ydgÍUd, sDKØF”FGdd d Û”AFØGIKÍUd vKFDF≥I”NN\nd KIU ≥ÍVhKUF≥I d ≥I∆”h rF KF ”dN VNDK UKF— KIG KIUd DFrdN ∆N GF∆NDg RF DFrdN ≥Í—GdIc rF KIU fd Ddp JFèFrI ”dN ≥dNG ≥ VIUdNV KÍ Ddp ≥ÍfPF≥I•ND ØFègd”dN\nIúN fPÍrI KÍ ”dN ≥dNG ”dN ØFgOGdNDg fF KF VNDK ≥dIØI .\nÊIègdI• ydgIUd, sDKØF”FGdd d Û”AFØGIKIUd vKFDF≥I”NV FØIg ÊÍègdI• ydgÍUdC sDKØF”FGdd d Û”AFØGIKÍUd vKFDF≥I”NV FØIg ÊÍègdI• ydgÍUd, sÍKØF”FGdd d Û”AFØGIKÍUd vÍFDF≥I”NV\n\tÊÍègdI• ydgÍUd,   sDKØF”FGdd d\tÛ”AFØGIKÍUd vKFDF≥I”NV\n≥dèIf JFVpfdI F KÍG UdG rÍ• JIJdN∆ VI” JI≥N•2 VIU ”dN VNDKN—fdN ≥ JN•”d ØFg≥d”dpKN\nOGÍD•F≥F KF Ddp ”dN gIrdNØIVfdN gI KIUh FDFrp VIU FVfdNf D≥dpKÍ rF KF —≥dIèfgÍ F KÍG ∆N ”dN GIfdN\nfPÍrI ≥ èFGO UØgÍ∆I I”d VNè”NRF FrØIgI —≥dpKNRF ”dN fPFègd KOKIV F UF—fda• G”dN IúN ≥FRaúN FRaú”dN F gIDIèÍ ≥dIØÍ ∆NrÍ GdNc VIUhD\nRFè”F—c rF JIJdN∆ ”dUFRF ”dN FrØI∆I• I KÍ gI fF RF FrØI∆IDg fF? ";
    dec.setInputText(ciphered);
    resultMap = dec.getCode();
    expectedMap = stringToMap(
        "a=I, A=s, ≥=•, d=è, e=N, F=y, f=A, i=d, I=Û, j=V, k=U, m=G, n=”, o=F, r=Ø, s=D, S=v, t=K, W=Ê, w=≥, y=Í, z=g");
    if (!resultMap.equals(expectedMap))
      throw new Exception("random cipher test failed: " + resultMap.toString());
    testCount++;
    
    // ==== comma test ====
    String cip = "Wydzia≥ Fizyki Astronomii i Informatyki Stosowanej Wydzqa≥ Fqzykq, Astronomqq q Informatykq Stosowanej";
    dec.setInputText(cip);
    resultMap = dec.getCode();
    expectedMap = stringToMap(
    		"a=a, A=A, ≥=≥, d=d, e=e, F=F, f=f, i=q, I=I, j=j, k=k, m=m, n=n, o=o, r=r, s=s, S=S, t=t, W=W, w=w, y=y, z=z");
    if (!resultMap.equals(expectedMap))
        throw new Exception("random cipher test failed: " + resultMap.toString());
    testCount++;

    System.out.println("All " + testCount + " tests passed successfully");
  }
}