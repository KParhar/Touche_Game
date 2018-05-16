package main.input;

public class KeyInputDevice {
	
	boolean isPressed = false;
	
	public void setPressed(boolean pressed){
		isPressed = pressed;
	}
	
	public boolean getPressed(){
		return isPressed;
	}
}