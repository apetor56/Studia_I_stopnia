
public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int i = 1;
		try {
			if(i == 0)
				throw new Exception();
			return;
		}
		catch(Exception e) {
			System.out.println("No siema pedaly");
		}
		
		System.out.println("ty skurwysynie");
	}

}
