#pragma once

class Vector2 : public Float2 {
	XMVECTOR vector;

public:
	Vector2();
	Vector2(float x, float y);
	Vector2(Float2 value);

	Vector2 operator+ (const Vector2& value) const;
	Vector2 operator- (const Vector2& value) const;

	Vector2 operator* (const float& value) const;
	Vector2 operator/ (const float& value) const;

	void operator+= (const Vector2& value);
	void operator-= (const Vector2& value);

	void operator*= (const float& value);
	void operator/= (const float& value);

	float Length() const;

	void Normalize();
	Vector2 Normalized() const;
};