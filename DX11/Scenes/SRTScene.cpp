#include "Framework.h"
#include "SRTScene.h"

CSRTScene::CSRTScene() 
	:position(0, 0), scale(1, 1), angle(0), angle2(0), pivot(50, 50)
{
	worldBuffer = new CMatrixBuffer();

	world = XMMatrixIdentity();
	world2 = XMMatrixIdentity();
}

CSRTScene::~CSRTScene()
{
	delete worldBuffer;
}

void CSRTScene::Update()
{
	if (GetAsyncKeyState(VK_RIGHT))
		position.x += 0.1f;
	if (GetAsyncKeyState(VK_LEFT))
		position.x -= 0.1f;
	if (GetAsyncKeyState(VK_UP))
		position.y -= 0.1f;
	if (GetAsyncKeyState(VK_DOWN))
		position.y += 0.1f;

	if (GetAsyncKeyState('D'))
		scale.x += 0.001f;
	if (GetAsyncKeyState('A'))
		scale.x -= 0.001f;
	if (GetAsyncKeyState('W'))
		scale.y -= 0.001f;
	if (GetAsyncKeyState('S'))
		scale.y += 0.001f;

	if (GetAsyncKeyState('Q'))
		angle -= 0.001f;
	if (GetAsyncKeyState('E'))
		angle += 0.001f;

	angle2 += 0.0001f;
	world2 = XMMatrixRotationZ(angle2);

	Matrix S = XMMatrixScaling(scale.x, scale.y, 1);
	Matrix R = XMMatrixRotationZ(angle);
	Matrix T = XMMatrixTranslation(position.x, position.y, 0.f);

	Matrix P = XMMatrixTranslation(pivot.x, pivot.y, 0.f);
	Matrix IP = XMMatrixInverse(NULL, P);

	//world = temp * world2;
	world = IP * S * R * T * P;
}

void CSRTScene::Render()
{
	worldBuffer->Set(world);
	worldBuffer->SetVS(0);

	//worldBuffer->Set(world2);
	//worldBuffer->SetVS(0);
	//rect->Render();
}


/*							   x  y  z
	11 12 13 14		Scale	 : 11 22 33
	21 22 23 24		Position : 41 42 43
	31 32 33 34				   
	41 42 43 44		Rotate	 : 22 11 11
							   23 13 12
							   32 31 21
							   33 33 22
*/