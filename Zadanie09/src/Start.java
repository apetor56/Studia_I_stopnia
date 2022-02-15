import java.util.*;
import java.util.List;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;

class Load implements ActionListener {
	List<Node> nodes;
	List<Edge> edges;
	String chosenFile;
	
	Load() {
		this.nodes = Start.nodes;
		this.edges = Start.edges;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JFileChooser file_chooser = new JFileChooser();
		File currentFile = new File(System.getProperty("user.dir"));
		file_chooser.setCurrentDirectory(currentFile);
		
		int r = file_chooser.showOpenDialog(null);
		if(r == JFileChooser.APPROVE_OPTION) {
			chosenFile = file_chooser.getSelectedFile().toString();
			load();
			Start.Window.panel.repaint();
		}
	}
	
	void load() {
		if(Start.nodes != null && Start.edges != null) {
			Start.nodes.clear();
			Start.edges.clear();
		}
		
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File(chosenFile));
		} catch (FileNotFoundException exp) {
			exp.printStackTrace();
		}
		
		int n = scanner.nextInt();
		int x, y;
		
		for(int i = 0; i < n; i++) {
			x = scanner.nextInt();
			y = scanner.nextInt();
			nodes.add(new Node(x, y));
		}
		
		int node1, node2;
		int index1, index2;
		int scale;
		
		n = scanner.nextInt();
		for(int i = 0; i < n; i++) {
			index1 = scanner.nextInt() - 1;
			index2 = scanner.nextInt() - 1;
			scale = scanner.nextInt();
			
			node1 = index1;
			node2 = index2;
			
			edges.add(new Edge(node1, node2, scale));
		}
	}
	
}

class Node {
	int x;
	int y;
	
	Node(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public Node(Node node) {
		x = node.x;
		y = node.y;
	}

	public String toString() {
		return "[" + x + ", " + y + "]";
	}
}

class Edge {
	int node1;
	int node2;
	float scale;
	
	Edge(int node1, int node2, float scale) {
		this.node1 = node1;
		this.node2 = node2;
		this.scale = scale;
	}
	
	public String toString() {
		return node1 + " " + node2 + ", " + scale;
	}
}

class MyPanel extends JPanel {
	List<Node> nodes;
	List<Edge> edges;
	
	MyPanel() {
		nodes = Start.nodes;
		edges = Start.edges;
	}
	
	int diameter = 24;
	int x_margin = 40;
	int y_margin = 40;
	int old_w = Start.Window.width, old_h = Start.Window.height;
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D)g;
		
		g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		
		g2d.setColor(Color.black);
				
		int _width = Start.Window.width - 2 * x_margin;
		int _height = Start.Window.height - 2 * y_margin;
		double ratio = (double)_height / _width;
		
		if(_width + 2 * x_margin > Start.Window.c_width) {
			_width = Start.Window.c_width - 2 * x_margin;
			
			_height = (int)((double)760 / 560 * _width) + y_margin / 2;
//			System.out.println(_width + " " + _height);
			Start.Window.diff1 = 0;
			Start.Window.diff2 = ((Start.Window.c_height - _height) - y_margin) / 2 - 12;
		}
		else if(_height + 2 * y_margin > Start.Window.c_height) {
			_height = Start.Window.c_height - 2 * y_margin;
			_width = (int)((double)560 / 760 * _height) - 12;
//			System.out.println(_height + " " + _width);
			
			Start.Window.diff1 = ((Start.Window.c_width - _width)) / 2 - 25 - 12;
			Start.Window.diff2 = 0;
		}
		else {
			Start.Window.width = 600;
			Start.Window.height = 800;
			x_margin = 40;
			y_margin = 40;
			
			_width = Start.Window.width - 2 * x_margin;
			_height = Start.Window.height - 2 * y_margin;
		}
		
		
		
		ArrayList<Node> edgePoints = new ArrayList<Node>();
		for(int i = 0; i < 4; i++) {
			try {
				edgePoints.add(new Node(nodes.get(0)));				
			}
			catch(Exception e) {}
		}
		
		for(Node n : nodes) {
			if(n.y < edgePoints.get(0).y)
				edgePoints.set(0, n);		// up
			
			if(n.y > edgePoints.get(1).y)
				edgePoints.set(1, n);		// down
			
			if(n.x < edgePoints.get(2).x)
				edgePoints.set(2, n);		// left
			
			if(n.x > edgePoints.get(3).x)
				edgePoints.set(3, n);		// right
		}
		
		int left = 0, right = 0, down = 0, up = 0;
		try {
			left = edgePoints.get(2).x;
			right = edgePoints.get(3).x;
			down = edgePoints.get(1).y;
			up = edgePoints.get(0).y;			
		}
		catch(Exception e) {}
		
		int distance_h = 0, distance_w = 0;
		try {
			distance_h = (_height + edgePoints.get(1).y - edgePoints.get(0).y) - y_margin - diameter / 2; 
			distance_w = (_width + edgePoints.get(3).x - edgePoints.get(2).x) - x_margin - diameter / 2;			
		}
		catch(Exception e) {}
		
		int x, y;
		int ovalStroke = 12;
		List<Node> nodes_line = new ArrayList<Node>();
		for(Node n : nodes) {
			g2d.setStroke(new BasicStroke(ovalStroke));
			
			x = (int)((double)(n.x - left) / (right - left) * distance_w);
			y = (int)((double)(down - n.y) / (down - up) * distance_h);
			
			nodes_line.add(new Node(x + x_margin + diameter / 2 + Start.Window.diff1, y + y_margin - ovalStroke + Start.Window.diff2));
			
			g2d.drawOval(x + x_margin + Start.Window.diff1, y + y_margin - diameter / 2 - ovalStroke + Start.Window.diff2, diameter, diameter);
		}		
		
		float min_scale = 0.0f, max_scale = 0.0f;
		for(Edge e : edges) {
			if(min_scale > e.scale)
				min_scale = e.scale;
			
			if(max_scale < e.scale)
				max_scale = e.scale;
		}
		float diff = (max_scale == min_scale) ? -1.0f : max_scale - min_scale;
		
		int node1, node2;
		float scale;
		float min_thickness = 1.0f, max_thickness = 16.0f;
		float lineStroke = 20;
		
		for(Edge e : edges) {
			node1 = e.node1;
			node2 = e.node2;
			if(diff == -1.0f)
				scale = 1.0f;
			else
				scale = 15 / diff * e.scale + 1.0f;
			
			g2d.setColor(Color.black);
			g2d.setStroke(new BasicStroke(scale));
			g2d.drawLine(nodes_line.get(node1).x, nodes_line.get(node1).y, nodes_line.get(node2).x, nodes_line.get(node2).y);
			
			g2d.setColor(Color.white);
			for(Node n : nodes_line)
				g2d.fillOval(n.x - (diameter - ovalStroke) / 2, n.y - (diameter - ovalStroke) / 2, diameter - ovalStroke, diameter - ovalStroke);
		}
	}
}

public class Start {
	static List<Node> nodes = new ArrayList<Node>();
	static List<Edge> edges = new ArrayList<Edge>();
	
	public static void main(String[] arg) {
		Window window = new Window(600, 800);
		window.addComponentListener(new ComponentAdapter() {
		    public void componentResized(ComponentEvent componentEvent) {
		    	int width = componentEvent.getComponent().getSize().width;
		    	int height = componentEvent.getComponent().getSize().height;
		    	window.setPreferredSize(new Dimension(width, height));

		          window.c_width = width;
		          window.c_height = height;
		    	  Start.Window.panel.repaint();
		    	  window.diff1 = (width - window.width) / 2;
		    	  window.diff2 = (height - window.height) / 2;
		    }
		});
	}
	
	static class Window extends JFrame {
		static int width;
		static int height;
		static int diff1 = 0, diff2 = 0;
		static int c_width, c_height;
		JButton button;
		static MyPanel panel;
		
		Window(int width, int height) {
			super();
			Start.Window.width = width;
			Start.Window.height = height;
			Start.Window.c_width = width;
			Start.Window.c_height = height;
			
			setSize(width, height);
			setTitle("Graph");
			setLocationRelativeTo(null);
			setMinimumSize(new Dimension(30, 70));
			
			button = new JButton("load file");
			button.addActionListener(new Load());
			
			panel = new MyPanel();
			add(panel);
			
			getContentPane().add(BorderLayout.NORTH, button);
			getContentPane().add(BorderLayout.CENTER, panel);
			
			setVisible(true);
			setDefaultCloseOperation(EXIT_ON_CLOSE);
		}
	}
}