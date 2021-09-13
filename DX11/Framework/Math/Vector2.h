#pragma once

class Vector2 : public Float2 {
	XMVECTOR vector;

public:
	Vector2();
	Vector2(float x, float y);
	Vector2(Float2 value);

	
};