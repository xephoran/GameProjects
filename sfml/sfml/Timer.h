#pragma once

class Timer
{
public:
	Timer();
	void           start();
	void           stop();
	void           reset();
	bool           isRunning();
	unsigned int  getTime();
	bool           isOver(unsigned int seconds);
private:
	bool           resetted;
	bool           running;
	unsigned int  begin;
	unsigned int  end;
};

