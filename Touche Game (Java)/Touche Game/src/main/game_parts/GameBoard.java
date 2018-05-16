package main.game_parts;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.ArrayList;

public class GameBoard {
	
	public final static int GRID_DIMENSIONS = 7;
	public static int GRID_SIZE;
	
	ArrayList<Pawn> pawns;
	
	public GameBoard(Dimension displaySize) {
		if(displaySize.getWidth() > displaySize.getHeight()) {
			GRID_SIZE = (int) (displaySize.getHeight() / GRID_DIMENSIONS);
		} else {
			GRID_SIZE = (int) (displaySize.getWidth() / GRID_DIMENSIONS);
		}
		
		pawns = new ArrayList<Pawn>();
		for(int i = 0; i < 7; i++) {
			if(i == 3) {
				continue;
			}
			pawns.add(new Pawn(0, i, GRID_SIZE, false));
			pawns.add(new Pawn(GRID_DIMENSIONS-1, i, GRID_SIZE, true));
		}
	}
	
	public void render(Graphics g) {
		g.setColor(new Color(0, 0, 0));
		for(int y = 0; y < GRID_DIMENSIONS; y++) {
			for(int x = 0; x < GRID_DIMENSIONS; x++) {
				if((y == 0 || y == GRID_DIMENSIONS-1) && (x > 0 && x < GRID_DIMENSIONS-1)) {
					continue;
				}
				g.drawRect(x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE);
			}
		}
		
		for(int i = 0; i < pawns.size(); i++) {
			pawns.get(i).render(g);
		}
	}
	
}
