#include "Framework.h"
#include "Scenes/TutorialScene.h"

CProgram::CProgram()
{
	Create();

	scene = new CTutorialScene();
}

CProgram::~CProgram()
{
	delete scene;
	Delete();
}

void CProgram::Update()
{
	scene->Update();
	
}

void CProgram::Render()
{
	CDevice::Get()->Clear();
	scene->Render();

	CDevice::Get()->Present();
}

void CProgram::Create()
{
	CDevice::Get();
}

void CProgram::Delete()
{
	CDevice::Delete();
}
