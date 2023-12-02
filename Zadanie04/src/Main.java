import java.util.*;

public class Main {

	public static void main(String[] args) {
		BusLine b = new BusLine();
		
		b.addBusLine("a", new Position2D(-3, 0), new Position2D(3, 0));
		b.addLineSegment("a", new LineSegment(new Position2D(-1, 0), new Position2D(3, 0)));
		b.addLineSegment("a", new LineSegment(new Position2D(-3, 0), new Position2D(-1, 0)));
		
		b.addBusLine("b", new Position2D(0, -3), new Position2D(0, 3));
		b.addLineSegment("b", new LineSegment(new Position2D(0, -3), new Position2D(0, 3)));
		
		b.addBusLine("c", new Position2D(-1, -1), new Position2D(1, 1));
		b.addLineSegment("c", new LineSegment(new Position2D(-1, -1), new Position2D(1, 1)));
		
		b.addBusLine("d", new Position2D(-1, 1), new Position2D(1, -1));
		b.addLineSegment("d", new LineSegment(new Position2D(-1, 1), new Position2D(1, -1)));
		
		b.findIntersections();
		System.out.println(b.getIntersectionPositions());
		System.out.println(b.getIntersectionsWithLines());
	}

}








