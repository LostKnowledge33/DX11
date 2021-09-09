#include "Framework.h"
#include "SolarSystemScene.h"

CSolarSystemScene::CSolarSystemScene()
{
	sun = new CPlanet(Float2(0, 0), Float2(1,1), 0, Float4(1, 0, 0, 1));
	earth = new CPlanet(Float2(0, 0), Float2(0.5f, 0.5f), 0, Float4(0, 0, 1, 1));
	moon = new CPlanet(Float2(0, 0), Float2(0.25f, 0.25f), 0, Float4(0.3f, 0.3f, 0.3f, 1));

	earth->SetParent(&sun->getWorld());
	moon->SetParent(&earth->getWorld());

	sun->position.x = WIN_CENTER_X;
	sun->position.y = WIN_CENTER_Y;

	earth->position.x = 200;
	earth->position.y = 200;

	moon->position.x = 100;
	moon->position.y = 100;
}

CSolarSystemScene::~CSolarSystemScene()
{
	delete sun;
	delete earth;
}

void CSolarSystemScene::Update()
{
	sun->rotation.z += 0.0001f;
	earth->rotation.z += 0.0001f;
	moon->rotation.z -= 0.0001f;
	
	sun->UpdateWorld();
	earth->UpdateWorld();
	moon->UpdateWorld();
}

void CSolarSystemScene::Render()
{
	sun->Render();
	earth->Render();
	moon->Render();
}
