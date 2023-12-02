import java.util.*;
import java.math.*;

class Position2D implements Position {

	private final int col;
	private final int row;

	public Position2D(int col, int row) {
		this.col = col;
		this.row = row;
	}

	@Override
	public int getRow() {
		return row;
	}

	@Override
	public int getCol() {
		return col;
	}

	@Override
	public String toString() {
		return "[" + col + ", " + row + "]";
	}

	@Override
	public int hashCode() {
		return Objects.hash(col, row);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Position2D other = (Position2D) obj;
		return col == other.col && row == other.row;
	}
}


class BusLine implements BusLineInterface {
	static class LinesPair implements BusLineInterface.LinesPair {
		String name1, name2;
		
		LinesPair(String name1, String name2) {
			this.name1 = name1;
			this.name2 = name2;
		}
		
		public String toString() {
			return "[" + name1 + ", " + name2 + "]";
		}
		
		public String getFirstLineName() {
			return name1;
		}
		
		public String getSecondLineName() {
			return name2;
		}
	}
	
	
	class Line {
		String name;
		Position firstPoint, lastPoint;
		List<Position> points = new LinkedList<Position>();
		List<LineSegment> segments = new ArrayList<LineSegment>();
		List<Character> direction = new ArrayList<Character>();
		boolean added_Points = false;
		
		Line(String name, Position firstPoint, Position lastPoint) {
			this.name = name;
			this.firstPoint = firstPoint;
			this.lastPoint = lastPoint;
		}
	};
	public Map<String, Line> busLines = new HashMap<String, Line>();

	@Override
	public void addBusLine(String busLineName, Position firstPoint, Position lastPoint) {
		Line line = new Line(busLineName, firstPoint, lastPoint);
		busLines.put(busLineName, line);
	}

	@Override
	public void addLineSegment(String busLineName, LineSegment lineSegment) {
		Line line = busLines.get(busLineName);
		line.segments.add(lineSegment);
		try {
			throw new RuntimeException();			
		}
		catch(RuntimeException e) {
//			System.out.println(busLineName + "\n" + lineSegment);
			e.getMessage();
		}
	}
	
	void sortSegments(Line line) {
		for(int i = 0; i < line.segments.size(); i++) {
			if(line.segments.get(i).getFirstPosition().equals(line.firstPoint)) {
				LineSegment tmp1 = line.segments.get(0);
				LineSegment tmp2 = line.segments.get(i);
				
				line.segments.set(0, tmp2);
				line.segments.set(i, tmp1);
				break;
			}
		}
		
		for(int i = 1; i < line.segments.size(); i++) {
			for(int j = 1; j < line.segments.size(); j++) {
				if(line.segments.get(j).getFirstPosition().equals(line.segments.get(i - 1).getLastPosition())) {
					LineSegment tmp1 = line.segments.get(j);
					LineSegment tmp2 = line.segments.get(i);
					
					line.segments.set(i, tmp1);
					line.segments.set(j, tmp2);
					break;
				}
			}
		}
	}
	
	public void addPoints() {
		Set<Map.Entry<String, Line>> entries = busLines.entrySet();
		Iterator<Map.Entry<String, Line>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Map.Entry<String, Line> entry = iterator.next();
			Line currentLine = entry.getValue();
			if(currentLine.added_Points == true)
				continue;
			
			sortSegments(currentLine);
			
			for(int i = 0; i < currentLine.segments.size(); i++) {
				LineSegment lineSegment = currentLine.segments.get(i);
				
				int x1 = lineSegment.getFirstPosition().getCol();
				int y1 = lineSegment.getFirstPosition().getRow();
				
				int x2 = lineSegment.getLastPosition().getCol();
				int y2 = lineSegment.getLastPosition().getRow();
				
				int iterations = Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1));
				int dir_X, dir_Y;
				
				if(x2 == x1)
					dir_X = 0;
				else
					dir_X = ((x2 > x1) ? 1 : -1);
				
				if(y2 == y1)
					dir_Y = 0;
				else
					dir_Y = ((y2 > y1) ? 1 : -1);
				
				for(int j = 0; j <= iterations; j++) {
					if((dir_X == 1 && dir_Y == 1) || (dir_X == -1 && dir_Y == -1)) {
						currentLine.direction.add('/');
					}
					else if((dir_X == 1 && dir_Y == -1) || (dir_X == -1 && dir_Y == 1)) {
						currentLine.direction.add('\\');
					}
					else if((dir_X == -1 || dir_X == 1) && dir_Y == 0) {
						currentLine.direction.add('-');
					}
					else if((dir_Y == -1 || dir_Y == 1) && dir_X == 0) {
						currentLine.direction.add('|');
					}
					currentLine.points.add(new Position2D(x1, y1));
					
					x1 += dir_X;
					y1 += dir_Y;
				}
			}
			currentLine.added_Points = true;
		}
	}
	
	public Map<String, List<Position>> getLinesMap = new HashMap<String, List<Position>>();
	public Map<String, List<String>> getIntersectionsWithLinesMap = new HashMap<String, List<String>>();
	public Map<String, List<Position>> getIntersectionPositionsMap = new HashMap<String, List<Position>>();
	public Map<BusLineInterface.LinesPair, Set<Position>> getIntersectionOfLinesPairMap = new HashMap<BusLineInterface.LinesPair, Set<Position>>();
	public Map<String, List<Position>> empty = new HashMap<String, List<Position>>();
	
	@Override
	public void findIntersections() {
		getLinesMap.clear();
		getIntersectionOfLinesPairMap.clear();
		getIntersectionPositionsMap.clear();
		getIntersectionOfLinesPairMap.clear();
		empty.clear();
		
		Set<Map.Entry<String, Line>> entriess = busLines.entrySet();
		Iterator<Map.Entry<String, Line>> iteratore = entriess.iterator();
		while(iteratore.hasNext()) {
			Line dupa = iteratore.next().getValue();
			dupa.direction.clear();
			dupa.points.clear();
			dupa.added_Points = false;
		}
		
		addPoints();
		Set<Map.Entry<String, Line>> entries = busLines.entrySet();
		Iterator<Map.Entry<String, Line>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Line lineA = iterator.next().getValue();
			List<Position> pointsA = lineA.points;
			List<Position> intersections = new ArrayList<Position>();
			List<String> with_which_line = new ArrayList<String>();
			boolean hasIntersection = false;
			
			for(int i = 1; i < pointsA.size() - 1; i++) {
				Set<Map.Entry<String, Line>> entriesLoop = busLines.entrySet();
				Iterator<Map.Entry<String, Line>> iteratorLoop = entriesLoop.iterator();
				
				while(iteratorLoop.hasNext()) {
					Line lineB = iteratorLoop.next().getValue();
					List<Position> pointsB = lineB.points;
					
					if(pointsB.contains(pointsA.get(i))) {
						if(lineA.name.equals(lineB.name)) {
							Position posA = pointsA.get(i);
							int x = posA.getCol();
							int y = posA.getRow();
							
							Position N = new Position2D(x, y + 1);
							Position S = new Position2D(x, y - 1);
							Position W = new Position2D(x - 1, y);
							Position E = new Position2D(x + 1, y);
							if(pointsA.contains(N) && pointsA.contains(W) && pointsA.contains(S) && pointsA.contains(E)) {
								char dir_N = lineA.direction.get(pointsA.indexOf(N));
								char dir_S = lineA.direction.get(pointsA.indexOf(S));
								char dir_W = lineA.direction.get(pointsA.indexOf(W));
								char dir_E = lineA.direction.get(pointsA.indexOf(E));
								
								int outcome = (dir_N + dir_S) * (dir_W + dir_E);
								if(outcome == 22320) {
									hasIntersection = true;
									intersections.add(posA);
									with_which_line.add(lineA.name);									
								}
							}
							
							Position Nw = new Position2D(x - 1, y + 1);
							Position Ne = new Position2D(x + 1, y + 1);
							Position Sw = new Position2D(x - 1, y - 1);
							Position Se = new Position2D(x + 1, y - 1);
							if(pointsA.contains(Nw) && pointsA.contains(Ne) && pointsA.contains(Sw) && pointsA.contains(Se)) {
								char dir_Nw = lineA.direction.get(pointsA.indexOf(Nw));
								char dir_Ne = lineA.direction.get(pointsA.indexOf(Ne));
								char dir_Sw = lineA.direction.get(pointsA.indexOf(Sw));
								char dir_Se = lineA.direction.get(pointsA.indexOf(Se));
								
								int outcome = (dir_Nw + dir_Se) * (dir_Ne + dir_Sw);
								if(outcome == 17296) {
									hasIntersection = true;
									intersections.add(posA);
									with_which_line.add(lineA.name);									
								}
							}
							
						}
						else {
							if(pointsA.get(i).equals(pointsB.get(0)) || pointsA.get(i).equals(pointsB.get(pointsB.size() - 1))) {
								continue;
							}
							int currentPos_B = pointsB.indexOf(pointsA.get(i));
							int old = currentPos_B - 1;

							while(pointsB.get(currentPos_B).equals(pointsA.get(i))) {
								int prevPos_B = currentPos_B - 1;
								int nextPos_B = currentPos_B + 1;
								
								char prevB = lineB.direction.get(prevPos_B).charValue();
								char nextB = lineB.direction.get(nextPos_B).charValue();
								
								char prevA = lineA.direction.get(i - 1).charValue();
								char nextA = lineA.direction.get(i + 1).charValue();
								
								int outcome = (prevA + nextA) * (prevB + nextB);
								if(outcome == 17296 || outcome == 22320) {
									hasIntersection = true;
									intersections.add(pointsA.get(i));
										with_which_line.add(lineB.name);
									break;
								}
								currentPos_B++;
							}				
						}
					}
				}
			}
			if(hasIntersection) {
				getLinesMap.put(lineA.name, lineA.points);
				getIntersectionPositionsMap.put(lineA.name, intersections);
				getIntersectionsWithLinesMap.put(lineA.name, with_which_line);
			}
			else {
				empty.put(lineA.name, new ArrayList<Position>());
			}
		}
	}
	

	@Override
	public Map<String, List<Position>> getLines() {
//		if(getLinesMap.equals(null))
//			findIntersections();
		Map<String, List<Position>> correctMap = new HashMap<String, List<Position>>();
		Set<Map.Entry<String, List<Position>>> entries = getLinesMap.entrySet();
		Iterator<Map.Entry<String, List<Position>>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Map.Entry<String, List<Position>> entry = iterator.next();
			String name = entry.getKey();
			List<Position> tmp = entry.getValue();
			
			for(int i = 0; i < tmp.size() - 1; i++) {
				if(tmp.get(i).equals(tmp.get(i + 1)))
					tmp.remove(i);
			}
			correctMap.put(name, tmp);
		}
		return correctMap;
	}

	@Override
	public Map<String, List<Position>> getIntersectionPositions() {
//		if(getIntersectionOfLinesPairMap.equals(null))
//			findIntersections();
		Map<String, List<Position>> correctPosition = new HashMap<String, List<Position>>();
		Map<String, List<Position>> tmp = new HashMap<String, List<Position>>(getIntersectionPositionsMap);
		
		
		Set<Map.Entry<String, List<Position>>> entries = tmp.entrySet();
		Iterator<Map.Entry<String, List<Position>>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Map.Entry<String, List<Position>> entry = iterator.next();
//			if(entry.getValue().size() != 0)
				correctPosition.put(entry.getKey(), entry.getValue());
		}
		
		return correctPosition;
	}

	@Override
	public Map<String, List<String>> getIntersectionsWithLines() {
//		if(getIntersectionOfLinesPairMap.equals(null))
//			findIntersections();
		return getIntersectionsWithLinesMap;
	}

	@Override
	public Map<BusLineInterface.LinesPair, Set<Position>> getIntersectionOfLinesPair() {
//		if(getIntersectionPositionsMap.equals(null))
//			findIntersections();
		Map<String, List<Position>> tmp = new HashMap<String, List<Position>>(getIntersectionPositions());
		if(empty.size() != 0)
			tmp.putAll(empty);
		Set<Map.Entry<String, List<Position>>> entries = tmp.entrySet();
		Iterator<Map.Entry<String, List<Position>>> iterator = entries.iterator();
		
		while(iterator.hasNext()) {
			Map.Entry<String, List<Position>> entry = iterator.next();
			String nameA = entry.getKey();
			List<Position> posA = entry.getValue();
			Set<Position> setA = new HashSet<Position>(posA);
			
			Set<Map.Entry<String, List<Position>>> entriesLoop = tmp.entrySet();
			Iterator<Map.Entry<String, List<Position>>> iteratorLoop = entriesLoop.iterator();
			
			while(iteratorLoop.hasNext()) {
				Map.Entry<String, List<Position>> entryLoop = iteratorLoop.next();
				String nameB = entryLoop.getKey();
				List<Position> posB = entryLoop.getValue();
				Set<Position> setB = new HashSet<Position>(posB);

				Set<Position> addSet = new HashSet<Position>();
				for(Position pos : setA) {
					if(setB.contains(pos))
						addSet.add(pos);
				}
				if(setB.size() != 0) {
					if(nameA.equals(nameB)) {
						Line l = busLines.get(nameA);
						Set<Position> tmpSet = new HashSet<Position>();
						
						for(Position pos : l.points) {
							int x = pos.getCol();
							int y = pos.getRow();
							
							Position N = new Position2D(x, y + 1);
							Position S = new Position2D(x, y - 1);
							Position W = new Position2D(x - 1, y);
							Position E = new Position2D(x + 1, y);
							
							if(l.points.contains(N) && l.points.contains(S) &&
									l.points.contains(W) && l.points.contains(E)) {
								tmpSet.add(pos);
							}
							
							Position Nw = new Position2D(x - 1, y + 1);
							Position Ne = new Position2D(x + 1, y + 1);
							Position Sw = new Position2D(x - 1, y - 1);
							Position Se = new Position2D(x + 1, y - 1);
							
							if(l.points.contains(Nw) && l.points.contains(Ne) &&
									l.points.contains(Sw) && l.points.contains(Se)) {
								tmpSet.add(pos);
							}
						}
						if(tmpSet.size() != 0)
							getIntersectionOfLinesPairMap.put(new LinesPair(nameA, nameB), tmpSet);
						else
							getIntersectionOfLinesPairMap.put(new LinesPair(nameA, nameB), new HashSet<Position>());
					}
					else
						getIntersectionOfLinesPairMap.put(new LinesPair(nameA, nameB), addSet);
				}
				else {
					getIntersectionOfLinesPairMap.put(new LinesPair(nameA, nameB), new HashSet<Position>());
				}
			}
		}
		empty.clear();
		return getIntersectionOfLinesPairMap;
	}
}
