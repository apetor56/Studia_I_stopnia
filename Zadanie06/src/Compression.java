import java.util.*;
import java.math.*;


class Compression implements CompressionInterface {
	int size;
	List<String> words;
	public Map<String, Integer> counter;
	Map<String, String> header;
	
	Compression() {
		words = new ArrayList<String>();
		counter = new HashMap<String, Integer>();
		header = new HashMap<String, String>();
	}
	
	@Override
	public void addWord(String word) {
		words.add(word);
		
		if(!counter.containsKey(word)) {
			counter.put(word, 1);
			size = word.length();
		}
		else {
			Set<Map.Entry<String, Integer>> entries = counter.entrySet();
			Iterator<Map.Entry<String, Integer>> iterator = entries.iterator();
			
			while(iterator.hasNext()) {
				Map.Entry<String, Integer> entry = iterator.next();
				if(entry.getKey().equals(word)) {
					entry.setValue(entry.getValue() + 1);
					break;
				}
			}
		}
	}
	class Word {
		public String s;
		public int n;
		
		Word(String s, int n) {
			this.s = s;
			this.n = n;
		}
		
		public String toString() {
			return s + " " + n;
		}
	}
	Word findMax() {
		int max = 0;
		String key = new String();
		
		Set<Map.Entry<String, Integer>> entries = counter.entrySet();
		Iterator<Map.Entry<String, Integer>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Map.Entry<String, Integer> entry = iterator.next();
			if(entry.getValue() > max) {
				max = entry.getValue();
				key = entry.getKey();
			}
		}
		
		counter.remove(key);
		return new Word(key, max);
	}
	
	List<String> maxList = new ArrayList<String>();
	@Override
	public void compress() {
		int compression = 0;
		int max = 0;
		List<String> binaryList = new ArrayList<String>();
		List<String> finalList = new ArrayList<String>();
		
		List<String> copy = new ArrayList<String>(words);
		while(!counter.isEmpty()) {
			int profit = 0;
			int loss = 0;
			
			Word word = findMax();
			max += word.n;
			maxList.add(word.s);
			
			String binary = Integer.toBinaryString(maxList.size() - 1);
			if(binary.charAt(0) == '1')
				binary = "0" + binary;
			
			profit = (size - binary.length()) * max;
			loss = words.size() - max;
			loss += (size + binary.length()) * maxList.size();
			
			if(profit - loss > compression) {
				finalList.add(word.s);
				compression = profit - loss;
			}
		}
		for(int i = 0; i < finalList.size(); i++) {
			binaryList.add(Integer.toBinaryString(i));
			if(binaryList.get(i).charAt(0) == '1')
				binaryList.set(i, "0" + binaryList.get(i));
		}
		for(int i = 0; i < finalList.size(); i++) {
			while(binaryList.get(i).length() != binaryList.get(binaryList.size() - 1).length()) {
				binaryList.set(i, "0" + binaryList.get(i));
			}
		}

		for(int i = 0; i < copy.size(); i++) {
			for(int j = 0; j < finalList.size(); j++) {
				if(copy.get(i).equals(finalList.get(j))) {
					copy.set(i, binaryList.get(j));
				}
			}
			if(copy.get(i).length() == size) {
				copy.set(i, "1" + copy.get(i));
			}
		}
		
		words = copy;
		for(int i = 0; i < binaryList.size(); i++) {
			header.put(binaryList.get(i), finalList.get(i));
		}
	}

	@Override
	public Map<String, String> getHeader() {
		return header;
	}

	int index = 0;
	@Override
	public String getWord() {
		String s = words.get(index);
		index++;
		return s;
	}

}
