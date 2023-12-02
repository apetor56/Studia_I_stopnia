import java.util.*;

public class Test {
    public static void main(String[] args) {
        /* PasswordCracker2 pc = new PasswordCracker2();

        int counter = 0;
        for(int i = 0; i < 10000; i++) {
            if(pc.getPassword("172.30.24.15", 8080) != "udalo sie") {
                counter++;
                break;
            }
        }

        if(counter == 0) {
            System.out.println("succeeded");
        }
        else {
            System.out.println("failure");
        } */

        PasswordCrackerInterface pc = new PasswordCracker();
        System.out.println(pc.getPassword("172.30.24.15", 8080));
    }
}