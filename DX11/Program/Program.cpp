#include "Framework.h"
#include "Scenes/TutorialScene.h"
#include "Scenes/SRTScene.h"
#include "Scenes/SolarSystemScene.h"
#include "Scenes/TextureScene.h"

CProgram::CProgram()
{
	Create();

	//scene = new CTutorialScene();
	//scene = new CSRTScene();
	//scene = new CSolarSystemScene();
	scene = new CTextureScene();
}

CProgram::~CProgram()
{
	delete scene;
	Delete();
}

void CProgram::Update()
{
	CControl::Get()->Update();
	CTimer::Get()->Update();

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
	CControl::Get();
	CTimer::Get();
	
	CreateProjection();
}

void CProgram::Delete()
{
	CDevice::Delete();
	CControl::Delete();
	CTimer::Delete();

	delete view;
	delete projection;
}

void CProgram::CreateProjection() {
	view = new CMatrixBuffer();
	projection = new CMatrixBuffer();

	Matrix orthographic = XMMatrixOrthographicOffCenterLH(
		0.f, WIN_SIZE_X,
		WIN_SIZE_Y, 0.f,
		-1.f, 1.f);

	projection->Set(orthographic);

	view->SetVS(1);
	projection->SetVS(2);
}