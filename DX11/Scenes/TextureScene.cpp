#include "Framework.h"
#include "TextureScene.h"

CTextureScene::CTextureScene()
{
	plane = new CPlane(Float2(300, 300), Float2(50, 50), Float4(1, 1, 1, 1));
}

CTextureScene::~CTextureScene()
{
	delete plane;
}

void CTextureScene::Update()
{
	plane->Update();
}

void CTextureScene::Render()
{
	plane->Render();
}
