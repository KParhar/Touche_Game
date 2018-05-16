#include "Animation.h"



Animation::Animation()
{
}


bool Animation::init(int speed, bool startPlayingAnimation)
{
	playingAnimation = startPlayingAnimation;
	animationTimer.initTimer(speed);
	animationTimer.startTimer();
	currentFrame = 0;
	return true;
}

void Animation::addFrame(int frame)
{
	frames.push_back(frame);
}

void Animation::update()
{
	animationTimer.checkTimer();
	if (animationTimer.isTimerDone())
	{
		currentFrame++;
		if (currentFrame >= frames.size())
		{
			currentFrame = 0;
		}
		animationTimer.timerReset();
	}
}

void Animation::updateIndividualAnimation()
{
	if (playingAnimation)
	{
		animationTimer.checkTimer();
		if (animationTimer.isTimerDone())
		{
			currentFrame++;
			if (currentFrame >= frames.size())
			{
				currentFrame = 0;
				playingAnimation = false;
			}
			animationTimer.timerReset();
		}
	}
}

void Animation::startIndividualAnimation()
{
	playingAnimation = true;
}



int Animation::getFrame()
{
	if (frames.size() < 1)
	{
		return NULL;
	}
	return frames.at(currentFrame);
}

int Animation::getDefaultFrame()
{
	return frames.at(0);
}

Animation::~Animation()
{
}
