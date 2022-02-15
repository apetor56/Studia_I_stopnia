import java.util.*;

class Shop implements ShopInterface {
	Map<String, Integer> currentProducts;
	Map<String, String> blocks;
	
	Shop() {
		currentProducts = new HashMap<String, Integer>();
		blocks = new HashMap<String, String>();
	}
	
	@Override
	public void delivery(Map<String, Integer> goods) {
		Set<Map.Entry<String, Integer>> entries = goods.entrySet();
		Iterator<Map.Entry<String, Integer>> iterator = entries.iterator();
		
		String deliveryProduct;
		Integer deliveryNumber;
		Map.Entry<String, Integer> entry;
		
		while(iterator.hasNext()) {
			entry = iterator.next();
			deliveryProduct = entry.getKey();
			deliveryNumber = entry.getValue();
			
			synchronized(this) {		
				if(currentProducts.get(deliveryProduct) == null) {
					currentProducts.put(deliveryProduct, deliveryNumber);
					if(blocks.get(deliveryProduct) == null)
						blocks.put(deliveryProduct, deliveryProduct + " block");
				}
				else {
					Integer currentNumber = currentProducts.get(deliveryProduct);
					currentProducts.put(deliveryProduct, currentNumber + deliveryNumber);
				}
			}
			
			synchronized(blocks.get(deliveryProduct)) {
				blocks.get(deliveryProduct).notifyAll();
			}
		}
	}

	@Override
	public boolean purchase(String productName, int quantity) {
		if(blocks.get(productName) == null) {
			blocks.put(productName, productName + " block");
		}
		synchronized(blocks.get(productName)) {
			Integer currentNumber = currentProducts.get(productName);
			if(currentNumber != null && currentNumber >= quantity) {
				currentProducts.put(productName, currentNumber - quantity);
				return true;
			}
			else {
				try {
					blocks.get(productName).wait();
				}
				catch(Exception e) {}
			}
			
			currentNumber = currentProducts.get(productName);
			if(currentNumber != null && currentNumber >= quantity) {
				currentProducts.put(productName, currentNumber - quantity);
				return true;
			}
		}
		return false;
	}

	@Override
	public Map<String, Integer> stock() {
		return currentProducts;
	}

}
