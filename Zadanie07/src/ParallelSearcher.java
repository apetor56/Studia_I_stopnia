import java.util.ArrayList;
import java.util.List;

class ParallelSearcher implements ParallelSearcherInterface {
	double counter = 0.0;
	
	class MultiThreading extends Thread {
		HidingPlaceSupplier currentHidingPlaceSupplier;
		final static String block = "some block";
		
		MultiThreading(HidingPlaceSupplier HPS) {
			currentHidingPlaceSupplier = HPS;
		}
		
		public void run() {
			HidingPlaceSupplier.HidingPlace currentHidingPlace = currentHidingPlaceSupplier.get();
			
			while(currentHidingPlace != null) {
				synchronized(currentHidingPlace) {
					if(currentHidingPlace.isPresent()) {
						synchronized(block) {
							counter += currentHidingPlace.openAndGetValue();							
						}
					}					
				}
				currentHidingPlace = currentHidingPlaceSupplier.get();
			}
		}
	}
	
	@Override
	public void set(HidingPlaceSupplierSupplier supplier) {
		HidingPlaceSupplier currentHidingPlaceSupplier = supplier.get(0.0);
		
		while(currentHidingPlaceSupplier != null) {
			int threadsAmount = currentHidingPlaceSupplier.threads();
			Thread[] threads = new MultiThreading[threadsAmount];
			// List<Thread> threads = new ArrayList<>();
			
			for(int i = 0; i < threadsAmount; i++) {
				threads[i] = new MultiThreading(currentHidingPlaceSupplier);
				threads[i].start();
			}
			
			for(int i = 0; i < threadsAmount; i++) {
				try {
					threads[i].join();					
				}
				catch(Exception e) {}
			}
			
			currentHidingPlaceSupplier = supplier.get(counter);
			counter = 0.0;
		}
	}
}


