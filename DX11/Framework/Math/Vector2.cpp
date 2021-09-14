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
