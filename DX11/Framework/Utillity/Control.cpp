#include "Framework.h"

CControl::CControl()
	: curState{}, oldState{}, mapState{}
{
}

CControl::~CControl()
{
}

void CControl::Update()
{
	memcpy(oldState, curState, sizeof(oldState));

	GetKeyboardState(curState);

	for (int i = 0; i < KEY_MAX; i++) {
		BYTE key = curState[i] & 0x80;
		curState[i] = key ? 1 : 0;

		int old = oldState[i];
		int cur = curState[i];

		if (old == 0 && cur == 1)
			mapState[i] = DOWN;
		else if (old == 1 && cur == 0)
			mapState[i] = UP;
		else if (old == 1 && cur == 1)
			mapState[i] = PRESS;
		else
			mapState[i] = NONE;
	}
}
