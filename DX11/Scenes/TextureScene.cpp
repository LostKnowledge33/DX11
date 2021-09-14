#include "Framework.h"
#include "TextureScene.h"

CTextureScene::CTextureScene()
{
	plane = new CPlane(Float2(0, 0), Float2(50, 50), 
		L"Shaders/VertexShader/VertexUV.hlsl",
		L"Shaders/PixelShader/PixelUV.hlsl");

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	transform = new CTransform();

	transform->position.x = 500.f;
	transform->position.y = 500.f;


}

CTextureScene::~CTextureScene()
{
	delete plane;
}

void CTextureScene::Update()
{
	if(KEY_PRESS)
	if (GetAsyncKeyState('D'))
		transform->position.x += 0.05f;
	if (GetAsyncKeyState('A'))
		transform->position.x -= 0.05f;
	if (GetAsyncKeyState('W'))
		transform->position.y -= 0.05f;
	if (GetAsyncKeyState('S'))
		transform->position.y += 0.05f;

	float angle = atan2(mousePos.y - transform->position.y, mousePos.x - transform->position.x);

	transform->rotation.z = angle;

	transform->UpdateWorld();
}

void CTextureScene::Render()
{
	worldBuffer->Set(transform->getWorld());
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	plane->Render();
}
