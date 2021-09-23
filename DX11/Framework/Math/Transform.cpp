#include "Framework.h"

CTransform::CTransform()
	: scale(1, 1), parent(NULL)
{
	matrix = XMMatrixIdentity();
}

void CTransform::UpdateWorld()
{
	S = XMMatrixScaling(scale.x, scale.y, 1);
	R = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
	T = XMMatrixTranslation(position.x, position.y, 0.f);
	P = XMMatrixTranslation(pivot.x, pivot.y, 0.f);
	IP = XMMatrixInverse(NULL, P);

	matrix = IP * S * R * T * P;

	if (parent != NULL)
		matrix *= *parent;

	XMStoreFloat4x4(&matWorld, matrix);
	right = Vector2(matWorld._11, matWorld._12);
	up = Vector2(matWorld._21, matWorld._22);

}
