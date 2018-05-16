package system.main.navigation;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import system.main.GUI.SchematicPanel;

public class Schematic {

	int width;
	int height;
	boolean collisionMap[][];
	
	int startX, startY;
	int endX, endY;
	
	List nodePath;
	
	SchematicPanel schemPanel;
	
	public Schematic(BufferedImage schem, SchematicPanel panel) {
		startX = -1;
		startY = -1;
		endX = -1;
		endY = -1;
		loadMapFromImg(schem);
		nodePath = new LinkedList();
		schemPanel = panel;
	}
	
	private void loadMapFromImg(BufferedImage schem) {
		width = schem.getWidth();
		height = schem.getHeight();
		collisionMap = new boolean[height][width];
		
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				
				String hexcode = Integer.toHexString(schem.getRGB(x,y));
				
				if(!hexcode.equals("ffffffff")) {
					collisionMap[y][x] = true;
					schem.setRGB(x, y, Color.black.getRGB());
					System.out.print(1);
				} else {
					collisionMap[y][x] = false;
					System.out.print(0);
				}
			}
			System.out.print("\n");
		}
	}
	
	public void setStartPos(int sX, int sY) {
		if(!collisionMap[sY][sX]) {
			startX = sX;
			startY = sY;
			if(endX != -1 && endY != -1) { 
				search();
			}
		}
	}
	
	public void setEndPos(int eX, int eY) {
		if(!collisionMap[eY][eX]) {
			endX = eX;
			endY = eY;
			if(startX != -1 && startY != -1) {
				search();
			}
		}
	}
	
	public void search() {
		
		LinkedList openNodes = new LinkedList();
		LinkedList closedNodes = new LinkedList();
		
		Node startNode = new Node(startX, startY);
		Node endNode = new Node(endX, endY);
		
		startNode.setParent(null);
		
		openNodes.add(startNode);
		
		while(!openNodes.isEmpty()) {
			
			Node node = (Node)openNodes.removeFirst();
			
			if(node.equalsNode(endNode)) {
				nodePath = constructPath(node);
				schemPanel.repaint();
				return;
			}
			else {
				closedNodes.add(node);
				Iterator i = node.getChildren(width, height).iterator();
				while(i.hasNext()) {
					Node neighborNode = (Node)i.next();
					if (!neighborNode.inList(openNodes) &&
					     !neighborNode.inList(closedNodes)) 
					{
						if(!collisionMap[neighborNode.getY()][neighborNode.getX()]) {
							neighborNode.setParent(node);
							openNodes.add(neighborNode);
						} else {
							closedNodes.add(neighborNode);
						}
					}
				}
			}
		}
	}
	
	protected List constructPath(Node node) {
		LinkedList path = new LinkedList();
		while (node.getParent() != null) {
			path.addFirst(node);
			node = node.getParent();
		}
		return path;
	}
	
	public boolean[][] getCollisionMap() {
		return collisionMap;
	}
	
	public int getWidth() {
		return width;
	}
	
	public int getHeight() {
		return height;
	}
	
	public List getNodePath() {
		return nodePath;
	}
	
	public int getStartX() { return startX; }
	public int getStartY() { return startY; }
	public int getEndX() { return endX; }
	public int getEndY() { return endY; }
}
