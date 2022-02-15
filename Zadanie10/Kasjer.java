import java.util.*;
import java.util.function.Supplier;
import java.util.stream.Collectors;

class Kasjer implements KasjerInterface {
    public List<Pieniadz> kasa;
    public RozmieniaczInterface mojRozmieniacz;

    Kasjer() {
        kasa = new ArrayList<Pieniadz>();
    }

    @Override
    public List<Pieniadz> rozlicz(int cena, List<Pieniadz> pieniadze) {

        List<Pieniadz> rozmienialne = pieniadze.stream()
            .filter(typ -> typ.czyMozeBycRozmieniony() == true)
            .collect(Collectors.toList());
        
        rozmienialne.sort( (p1, p2) -> p2.wartosc() - p1.wartosc());
        
        List<Pieniadz> nierozmienialne = pieniadze.stream()
            .filter(typ -> typ.czyMozeBycRozmieniony() == false)
            .collect(Collectors.toList());

        nierozmienialne.sort( (p1, p2) -> p2.wartosc() - p1.wartosc() );

        int pozostało = cena;

        List<Pieniadz> tmp_NR = new ArrayList<Pieniadz>();
        for(int i = 0; i < nierozmienialne.size(); i++) {
            if(pozostało - nierozmienialne.get(i).wartosc() >= 0) {
                pozostało -= nierozmienialne.get(i).wartosc();
                tmp_NR.add(nierozmienialne.get(i));
            }
        }

        List<Pieniadz> tmp_R = new ArrayList<Pieniadz>();
        for(int i = 0; i < rozmienialne.size(); i++) {
            if(pozostało - rozmienialne.get(i).wartosc() >= 0) {
                pozostało -= rozmienialne.get(i).wartosc();
                tmp_R.add(rozmienialne.get(i));
            }
        }

        if(pozostało == 0) {
            kasa.addAll(tmp_NR);
            kasa.addAll(tmp_R);

            List<Pieniadz> reszta_lista = new ArrayList<Pieniadz>(pieniadze);
            reszta_lista.removeAll(tmp_NR);
            reszta_lista.removeAll(tmp_R);
            
            return reszta_lista;
        }

        else {
            nierozmienialne.removeAll(tmp_NR);
            rozmienialne.removeAll(tmp_R);

            if(rozmienialne.size() != 0) {
                // System.out.println("no moze tu");
                int reszta = -(pozostało - rozmienialne.get(0).wartosc());
                // kasa.add(rozmienialne.get(0));
                List<Pieniadz> tmp = new ArrayList<Pieniadz>();
                tmp.add(rozmienialne.get(0));

                while(true) {
                    int i;
                    for(i = 0; i < tmp.size(); ) {
                        tmp.addAll(mojRozmieniacz.rozmien(tmp.get(i)));
                        tmp.remove(tmp.get(i));
                        if(tmp.get(i).wartosc() == 1)
                            i++;
                    }
                    break;
                }

                System.out.println(reszta);
                List<Pieniadz> reszta_lista = new ArrayList<Pieniadz>();
                for(int i = 0; i < reszta; i++) {
                    reszta_lista.add(tmp.get(i));
                }

                // System.out.println(tmp.size() - reszta);
                for(int i = reszta; i < tmp.size(); i++) {
                    kasa.add(tmp.get(i));
                }
                kasa.addAll(tmp_NR);
                
                int stan_kasy = 0;
                for(int i = 0; i < kasa.size(); i++) {
                    stan_kasy += kasa.get(i).wartosc();
                }
                System.out.println(stan_kasy);

                return reszta_lista;
            }
            else {
                // System.out.println("huhu");
                nierozmienialne.removeAll(tmp_NR);
                int reszta = -(pozostało - nierozmienialne.get(0).wartosc());
                // System.out.println(reszta);

                while(true) {
                    int i;
                    for(i = 0; i < kasa.size(); ) {
                        kasa.addAll(mojRozmieniacz.rozmien(kasa.get(i)));
                        kasa.remove(kasa.get(i));
                        if(kasa.get(i).wartosc() == 1)
                            i++;
                    }
                    break;
                }

                if(kasa.size() > reszta) {
                    List<Pieniadz> reszta_lista = new ArrayList<Pieniadz>();

                    for(int i = 0; i < reszta; i++) {
                        reszta_lista.add(kasa.get(i));
                        kasa.remove(kasa.get(i));
                    }

                    reszta_lista.add(nierozmienialne.get(0));

                    return reszta_lista;
                }

                else {
                    List<Pieniadz> reszta_lista = new ArrayList<Pieniadz>();

                    for(int i = 0; i < kasa.size(); i++) {
                        if(kasa.get(i).czyMozeBycRozmieniony() == false && kasa.get(i).wartosc() == reszta) {
                            reszta_lista.add(kasa.get(i));
                            kasa.remove(kasa.get(i));
                            return reszta_lista;
                        }
                    }
                }
            }
        }
        
        return nierozmienialne;
    }

    @Override
    public List<Pieniadz> stanKasy() {
        // TODO Auto-generated method stub
        return kasa;
    }

    @Override
    public void dostępDoRozmieniacza(RozmieniaczInterface rozmieniacz) {
        mojRozmieniacz = rozmieniacz;
        // TODO Auto-generated method stub
    }

    @Override
    public void dostępDoPoczątkowegoStanuKasy(Supplier<Pieniadz> dostawca) {
        // TODO Auto-generated method stub
        Pieniadz pieniadz;
        while( (pieniadz = dostawca.get()) != null ) {
            kasa.add(pieniadz);
        }
    }
}