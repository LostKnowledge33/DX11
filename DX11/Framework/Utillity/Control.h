#pragma once

#define KEY_MAX 255

class CControl : public CSingleton<CControl>{
private:
	friend class CSingleton;

	enum { NONE, DOWN, UP, PRESS};

	BYTE curState[KEY_MAX];
	BYTE oldState[KEY_MAX];
	BYTE mapState[KEY_MAX];

	static CControl* instance;

	CControl();
	~CControl();

public:
	void Update();

	bool Down(UINT key) { return mapState[key] == DOWN; }
	bool Up(UINT key) { return mapState[key] == UP; }
	bool Press(UINT key) { return mapState[key] == PRESS; }
};