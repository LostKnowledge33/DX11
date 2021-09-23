#include "Framework.h"

Vector2::Vector2()
	: Float2(0, 0)
{

}

Vector2::Vector2(float x, float y)
	: Float2(x, y)
{
	//vector = XMLoadFloat2(&Float2(x, y));
}

Vector2::Vector2(Float2 value)
	: Float2(value)
{
	//vector = XMLoadFloat2(&value);
}

Vector2 Vector2::operator+(const Vector2& value) const
{
	return Vector2(x + value.x, y + value.y);
}

Vector2 Vector2::operator-(const Vector2& value) const
{
	return Vector2(x - value.x, y - value.y);
}

Vector2 Vector2::operator*(const float& value) const
{
	return Vector2(x * value, y * value);
}

Vector2 Vector2::operator/(const float& value) const
{
	return Vector2(x / value, y / value);
}

void Vector2::operator+=(const Vector2& value)
{
	x += value.x;
	y += value.y;
}

void Vector2::operator-=(const Vector2& value)
{
	x -= value.x;
	y -= value.y;
}

void Vector2::operator*=(const float& value)
{
	x *= value;
	y *= value;
}

void Vector2::operator/=(const float& value)
{
	x /= value;
	y /= value;
}

float Vector2::Length() const
{
	return sqrt(x * x + y * y);
}

void Vector2::Normalize()
{
	float length = Length();

	x /= length;
	y /= length;
}

Vector2 Vector2::Normalized() const
{
	float length = Length();

	return Vector2(x / length, y / length);
}
