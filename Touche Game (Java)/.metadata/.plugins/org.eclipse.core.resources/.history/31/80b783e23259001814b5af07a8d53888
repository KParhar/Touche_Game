package main.game_states;

import java.awt.Color;
import java.awt.Graphics;
import main.input.KeyInputDevice;
import main.input.MouseInputDevice;

public abstract class GameState {
	
	public static final int GAMEPLAY_STATE = 0;
	
	public static final int WIDTH = 1920, HEIGHT = 1080;
	protected boolean renderLoad = false;
	protected int switchState = -1;
	
	protected String playerType;
	
	public abstract void render(Graphics g);
	public abstract void tick();
	public abstract void init();
	public abstract void input(KeyInputDevice[] keys, MouseInputDevice[] mousebuttons);
	
	public int getSwitchState(){
		return switchState;
	}
	
}
