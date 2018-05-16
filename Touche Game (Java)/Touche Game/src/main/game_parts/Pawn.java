package main.game_parts;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Pawn {
	
	public final static int pawnBorder = 5;
	
	int gridX, gridY;
	int gridSize;
	boolean isRound;
	boolean isRed;
	
	public Pawn(int x, int y, int gS, boolean r) {
		gridX = x;
		gridY = y;
		isRound = r;
		gridSize = gS;
		isRed = !isRound;
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
	
	public void flip() {
		isRed = !isRed;
	}
	
}