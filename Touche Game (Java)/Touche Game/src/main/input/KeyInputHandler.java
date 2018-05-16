package main.input;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyInputHandler implements KeyListener{
	
	public KeyInputDevice[] inputs = new KeyInputDevice[8];
	
	public KeyInputHandler(){
		inputs[0] = new KeyInputDevice();
		inputs[1] = new KeyInputDevice();
		inputs[2] = new KeyInputDevice();
		inputs[3] = new KeyInputDevice();
		inputs[4] = new KeyInputDevice();
		inputs[5] = new KeyInputDevice();
		inputs[6] = new KeyInputDevice();
		inputs[7] = new KeyInputDevice();
	}
	
	public KeyInputDevice[] getKeyInputs(){
		return inputs;
	}
	
	public void keyPressed(KeyEvent e) {
		setKeyPressed(e.getKeyCode(), true);
	}

	public void keyReleased(KeyEvent e) {
		setKeyPressed(e.getKeyCode(), false);
	}

	public void keyTyped(KeyEvent e) {
		
	}
	
	public void setKeyPressed(int keyCode, boolean pressed){
		if(keyCode == KeyEvent.VK_S){
			inputs[0].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_W){
			inputs[1].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_D){
			inputs[2].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_A){
			inputs[3].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_SPACE){
			inputs[4].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_ESCAPE){
			inputs[5].setPressed(pressed);
		}
		
		if(keyCode == KeyEvent.VK_ENTER){
			inputs[6].setPressed(pressed);
		}
		
		inputs[7].setPressed(pressed);
	}

}
