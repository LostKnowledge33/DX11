#pragma once

class CMatrixBuffer;

class CTransform
{
public:
	Vector2 position;
	Float3 rotation;
	Vector2 scale;

protected:
	Matrix matrix;
	Matrix* parent;

	Vector2 pivot;
	
	Matrix S, R, T, P, IP;

	Vector2 right;
	Vector2 up;

	XMFLOAT4X4 matWorld;

public:
	CTransform();
	
	void UpdateWorld();
	void SetParent(Matrix* matrix) { parent = matrix; }
	Matrix& GetWorld() { return matrix; }


	Vector2 Right() { return right.Normalized(); }
	Vector2 Up() { return up.Normalized(); }

	Vector2 Left() { return Right() * -1.f; }
	Vector2 Down() { return Up() * -1.f; }
};