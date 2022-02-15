import java.util.*;

class Rozmieniacz implements RozmieniaczInterface {

    @Override
    public List<Pieniadz> rozmien(Pieniadz pieniadzDoRozmienienia) {
        List<Pieniadz> rozmienione = new ArrayList<Pieniadz>();

        for(int i = 0; i < pieniadzDoRozmienienia.wartosc(); i++) {
            rozmienione.add(new Pieniadz(Nominal.Zł1, Rozmienialnosc.TAK));
        }

        return rozmienione;
    }
    
}
public class Main {
    public static void main(String[] args) {
        Kasjer kasjer = new Kasjer();
        kasjer.mojRozmieniacz = new Rozmieniacz();

        kasjer.kasa.add(new Pieniadz(Nominal.Zł2, Rozmienialnosc.TAK));
        List<Pieniadz> costam = List.of(new Pieniadz(Nominal.Zł10, Rozmienialnosc.NIE), new Pieniadz(Nominal.Zł10, Rozmienialnosc.TAK));
        System.out.println(kasjer.rozlicz(19, costam));

        /* kasjer.kasa.add(new Pieniadz(Nominal.Zł5, Rozmienialnosc.NIE));
        List<Pieniadz> costam = List.of(new Pieniadz(Nominal.Zł50, Rozmienialnosc.NIE), new Pieniadz(Nominal.Zł20, Rozmienialnosc.TAK));
        System.out.println(kasjer.rozlicz(65, costam)); */
    }
}