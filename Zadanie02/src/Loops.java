import java.util.List;
import java.util.ArrayList;

class Loops implements GeneralLoops {
	private List<Integer> low = new ArrayList<Integer>();
	private List<Integer> up = new ArrayList<Integer>();
	private List<List<Integer>> result = new ArrayList<List<Integer>>();
	
	@Override
	public void setLowerLimits(List<Integer> limits) {
		low = limits;
	}

	@Override
	public void setUpperLimits(List<Integer> limits) {
		up = limits;
	}
	
	@Override
	public List<List<Integer>> getResult() {
		result.clear();
		int upper = up.size();
		int lower = low.size();
		
		System.out.println(lower + " " + upper);
		
		if(upper == 0 && lower == 0) {
			List<Integer> tmp = new ArrayList<Integer>();
			tmp.add(0);
			result.add(tmp);
			return result;
		}
		else {
			if(upper < lower) {
				for(int i = upper; i < lower; i++)
					up.add(0);
			}
			else if(upper > lower) {
				for(int i = lower; i < upper; i++)
					low.add(0);
			}
		}
		
		upper = up.size();
		lower = low.size();
		
		long max = 1;
		long[] freq = new long[upper];
		
		for(int i = 0; i < upper; i++) {
			freq[i] = max;
			max *= (up.get(upper - i - 1) - low.get(upper - i - 1) + 1);
		}
		for(long x : freq)
			System.out.println(x);

		for(int i = 0; i < max; i++) {
			List<Integer> tmp = new ArrayList<Integer>();
			for(int j = 0; j < upper; j++) {
				tmp.add(0);
			}
			result.add(tmp);
		}
		
		int r = 0;
		for(int i = upper - 1; i >= 0; i--) {
			int x = low.get(i);
			
			for(int j = 0; j < max; j++) {
				List<Integer> tmp = new ArrayList<Integer>();
				tmp = result.get(j);
				
				if(j % freq[r] == 0) {
					if(i == upper - 1) {
						tmp.set(i, x);
						if(x + 1 <= up.get(i))
							x++;
						else 
							x = low.get(i);
					}
					else {
						if(j != 0) {
							if(x + 1 <= up.get(i))
								x++;
							else
								x = low.get(i);
							tmp.set(i, x);
						}
						else
							tmp.set(i, x);
					}
				}
				else
					tmp.set(i, x);
			}
			r++;
		}
		
		return result;
	}
}
