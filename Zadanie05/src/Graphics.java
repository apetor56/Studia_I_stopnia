import java.util.*;

public class Graphics implements GraphicsInterface {
	CanvasInterface currentCanvas;
	
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
	
	@Override
	public void setCanvas(CanvasInterface canvas) {
		// TODO Auto-generated method stub
		currentCanvas = canvas;
	}

	int i = 0;
	Set<Position> coloredPos = new HashSet<Position>();
	@Override
	public void fillWithColor(Position startingPosition, Color color)
			throws GraphicsInterface.WrongStartingPosition, GraphicsInterface.NoCanvasException {
		Position currentPos = startingPosition;
		
		if(coloredPos.contains(currentPos))
			return;
		
		if(currentCanvas == null)
			throw new NoCanvasException();
		
		try {
			currentCanvas.setColor(currentPos, color);
		}
		catch(CanvasInterface.CanvasBorderException e) {
			if(i == 0)
				throw new WrongStartingPosition();
			else return;
		}
		catch(CanvasInterface.BorderColorException e) {
			try {
				currentCanvas.setColor(currentPos, e.previousColor);
				if(i != 0)
					return;
			}
			catch(Exception e2) {}
			if(i == 0)
				throw new WrongStartingPosition();
		}
		coloredPos.add(currentPos);
		i++;				
		
		int x = currentPos.getCol();
		int y = currentPos.getRow();
		
		fillWithColor(new Position2D(x + 1, y), color);
		fillWithColor(new Position2D(x - 1, y), color);
		fillWithColor(new Position2D(x, y + 1), color);
		fillWithColor(new Position2D(x, y - 1), color);
	}

}
