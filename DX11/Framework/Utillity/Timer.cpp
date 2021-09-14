#include "Framework.h"

CTimer::CTimer()
	: frameRate(0), frameCount(0), timeElapsed(0), oneSecCount(0), runTime(0),
	curTime(0), lastTime(0), timeScale(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

	timeScale = 1.0f / (float)periodFrequency;
}

CTimer::~CTimer()
{
}

void CTimer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
	timeElapsed = (float)(curTime - lastTime) * timeScale;

	lastTime = curTime;

	frameCount++;

	oneSecCount += timeElapsed;

	if (oneSecCount >= 1.0f) {
		frameRate = frameCount;
		frameCount = 0;
		oneSecCount = 0;
	}

	runTime += timeElapsed;
}
