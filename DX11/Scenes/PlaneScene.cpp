#include "Framework.h"
#include "PlaneScene.h"

CPlaneScene::CPlaneScene()
{
	plane = new CPlane(Float2(350, 350), Vector2(0.2f, 0.2f));
}

CPlaneScene::~CPlaneScene()
{
	delete plane;
}

void CPlaneScene::Update()
{
	plane->Update();
}

void CPlaneScene::Render()
{
	plane->Render();
}
