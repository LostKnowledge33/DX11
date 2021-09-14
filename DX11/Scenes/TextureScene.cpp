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
	if (KEY_PRESS('D'))
		transform->position.x += speed * DELTA;
	if (KEY_PRESS('A'))
		transform->position.x -= speed * DELTA;
	if (KEY_PRESS('W'))
		transform->position.y -= speed * DELTA;
	if (KEY_PRESS('S'))
		transform->position.y += speed * DELTA;

	Vector2 direction = mousePos - transform->position;

	transform->rotation.z = atan2(direction.y, direction.x);

	transform->UpdateWorld();
}

void CTextureScene::Render()
{
	worldBuffer->Set(transform->GetWorld());
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	plane->Render();
}
