#pragma once

class CTimer : public CSingleton<CTimer> {
private:
	friend class CSingleton;

	float timeScale;
	float timeElapsed;

	__int64 curTime;
	__int64 lastTime;
	__int64 periodFrequency;

	int frameRate;
	int frameCount;

	float oneSecCount;
	float runTime;

	CTimer();
	~CTimer();

public:
	void Update();
	
	int GetFPS() { return frameRate; }

	float GetDeltaTime() { return timeElapsed; }
	float GetRunTime() { return runTime; }

};