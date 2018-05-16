package main;

public class Timer {
	
	private boolean pause;
	private boolean timerDone;
	private int tickduration;
	private int currentTick;
	
	public Timer(int duration, boolean startTimer){
		pause = !startTimer;
		tickduration = duration;
		timerDone = false;
		currentTick = 0;
	}
	
	public void tick(){
		if((currentTick <= tickduration && !timerDone) && !pause){
			currentTick++;
		}else if((!(currentTick <= tickduration) && !timerDone) && !pause){
			timerDone = true;
			currentTick = 0;
		}
	}
	
	public void start(){
		pause = false;
	}
	
	public void pause(){
		pause = true;
	}
	
	public void reset(){
		timerDone = false;
		currentTick = 0;
	}
	
	public boolean timeOver(){
		return timerDone;
	}
}
