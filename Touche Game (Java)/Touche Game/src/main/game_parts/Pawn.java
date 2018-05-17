package main.game_parts;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.util.ArrayList;

public class Pawn {
	
	public final static int pawnBorder = 5;
	
	int gridX, gridY;
	int gridSize;
	boolean isRound;
	boolean isRed;
	
	int turnCount;
	
	ArrayList<Point> moves;
	
	public Pawn(int x, int y, int gS, boolean r) {
		gridX = x;
		gridY = y;
		isRound = r;
		gridSize = gS;
		isRed = !isRound;
		turnCount = 0;
	}
	
	public void render(Graphics g) {
		((Graphics2D)g).setStroke(new BasicStroke(5));
		if(isRound) {
			g.drawOval((gridX * gridSize) + pawnBorder, (gridY * gridSize) + pawnBorder, gridSize-(2*pawnBorder), gridSize-(2*pawnBorder));
		} else {
			g.drawRect((gridX * gridSize) + pawnBorder, (gridY * gridSize) + pawnBorder, gridSize-(2*pawnBorder), gridSize-(2*pawnBorder));
		}
		
		g.setColor(new Color(255, 0, 0));
		if(isRed) {
			g.fillOval((gridX * gridSize) + (3 * pawnBorder), (gridY * gridSize) + (3 * pawnBorder), gridSize-(6*pawnBorder), gridSize-(6*pawnBorder));
		}
		g.setColor(new Color(0, 0, 0));
	}
	
	public void calculateMoves(GameBoard b) {
		
	}
	
	public void renderMoves(Graphics g) {
		g.setColor(new Color(0x00, 0xFF, 0x00, 0xFF/4));
		for(int i = 0; i < moves.size(); i++) {
			g.fillRect((int)moves.get(i).getX() * gridSize, (int)moves.get(i).getY() * gridSize, gridSize, gridSize);
		}
		g.setColor(new Color(0, 0, 0));
	}
	
	public void move(int x, int y) {
		gridX = x;
		gridY = y;
		turnCount++;
	}
	
	public boolean checkMouseInput(int x, int y) {
		int cGridX = x / gridSize;
		int cGridY = y / gridSize;
		
		if(cGridX == gridX && cGridY == gridY) {
			return true;
		}
		return false;
	}
	
	public int getGridX() {
		return gridX;
	}
	
	public int getGridY() {
		return gridY;
	}
	
	public void flip() {
		isRed = !isRed;
	}
	
}
