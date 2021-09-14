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

public:
	CTransform();
	
	void UpdateWorld();
	void SetParent(Matrix* matrix) { parent = matrix; }
	Matrix& GetWorld() { return matrix; }

};