#include "Framework.h"
#include "Scenes/TutorialScene.h"
#include "Scenes/SRTScene.h"
#include "Scenes/SolarSystemScene.h"
#include "Scenes/TextureScene.h"
#include "Scenes/PlaneScene.h"

CProgram::CProgram()
{
	Create();

	//scene = new CTutorialScene();
	//scene = new CSRTScene();
	//scene = new CSolarSystemScene();
	//scene = new CTextureScene();
	scene = new CPlaneScene();
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
	CreateSamplerState();
}

void CProgram::Delete()
{
	CDevice::Delete();
	CControl::Delete();
	CTimer::Delete();
	CTexture::Delete();

	delete view;
	delete projection;

	samplerState->Release();
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

void CProgram::CreateSamplerState()
{
	D3D11_SAMPLER_DESC sd = {};
	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sd.MinLOD = 0;
	sd.MaxLOD = D3D11_FLOAT32_MAX;

	DEVICE->CreateSamplerState(&sd, &samplerState);

	DC->PSSetSamplers(0, 1, &samplerState);
}
