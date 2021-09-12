#include "Framework.h"
#include "TextureScene.h"

CTextureScene::CTextureScene()
{
	rect = new CRect(Float2(100, 100), Float2(100, 100),
		L"Shaders/VertexShader/VertexUV.hlsl", 
		L"Shaders/PixelShader/PixelUV.hlsl");

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	world = XMMatrixIdentity();
}

CTextureScene::~CTextureScene()
{
	delete rect;
}

void CTextureScene::Update()
{
	if(KEY_PRESS)
}

void CTextureScene::Render()
{
	worldBuffer->Set(world);
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	rect->Render();
}
