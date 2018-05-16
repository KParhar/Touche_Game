package main.input;

public class MouseInputDevice {
	
	boolean isPressed = false;
	
	int x, y;
	
	public void setPressed(boolean pressed){
		isPressed = pressed;
	}
	
	public boolean getPressed(){
		return isPressed;
	}
	
	public void setX(int X){ x = X; }
	public void setY(int Y){ y = Y; }
	
	public int getX(){ return x; }
	public int getY(){ return y; }
	
}
