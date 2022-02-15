import java.util.List;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		Loops loop = new Loops();
		List<Integer> low = new ArrayList<Integer>();
		List<Integer> up = new ArrayList<Integer>();
		
		low.add(-1);
		low.add(-1);
		low.add(-2);
		
		loop.setLowerLimits(low);
		loop.setUpperLimits(up);
		
		System.out.println("Low: " + low + "\nUp:  " + up);
		System.out.println("Output: " + loop.getResult());
	}

}
