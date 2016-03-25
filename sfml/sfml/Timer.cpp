#include "Timer.h"
#include <conio.h>
#include <time.h>

Timer::Timer()
{
	resetted = true;
	running = false;
	begin = 0;
	end = 0;
}

void Timer::start() {
	if (!running) {
		if (resetted)
			begin = (unsigned int)clock();
		else
			begin -= end - (unsigned int)clock();
		running = true;
		resetted = false;
	}
}


void Timer::stop() {
	if (running) {
		end = (unsigned int)clock();
		running = false;
	}
}


void Timer::reset() {
	bool wereRunning = running;
	if (wereRunning)
		stop();
	resetted = true;
	begin = 0;
	end = 0;
	if (wereRunning)
		start();
}


bool Timer::isRunning() {
	return running;
}


unsigned int Timer::getTime() {
	if (running)
		return ((int)clock() - begin) / CLOCKS_PER_SEC;
	else
		return end - begin;
}


bool Timer::isOver(unsigned int seconds) {
	return seconds >= getTime();
}
