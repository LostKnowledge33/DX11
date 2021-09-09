#include "Framework.h"

CRect::CRect(Float2 pos, Float2 size, wstring vsPath, wstring psPath)
{
	float left = pos.x - size.x * 0.5f;
	float right = pos.x + size.x * 0.5f;
	float top = pos.y - size.y * 0.5f;
	float bottom = pos.y + size.y * 0.5f;

	vertices.emplace_back(left, top, 0, 0);
	vertices.emplace_back(right, top, 1, 0);
	vertices.emplace_back(left, bottom, 0, 1);

	vertices.emplace_back(left, bottom, 0, 1);
	vertices.emplace_back(right, top, 1, 0);
	vertices.emplace_back(right, bottom, 1, 1);

	vs = new CVertexShader(vsPath, NULL);
	ps = new CPixelShader(psPath, NULL);

	vb = new CVertexBuffer((void*)vertices.data(), sizeof(Vertex), (UINT)vertices.size());

	ScratchImage image;
	LoadFromWICFile(L"Textures/airplane.png", WIC_FLAGS_NONE, nullptr, image);

	CreateShaderResourceView(DEVICE, image.GetImages(), image.GetImageCount(), image.GetMetadata(), &srv);

	D3D11_SAMPLER_DESC sd = {};
	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sd.MinLOD = 0;
	sd.MaxLOD = D3D11_FLOAT32_MAX;

	DEVICE->CreateSamplerState(&sd, &samplerState);
}

CRect::~CRect()
{
	delete vs;
	delete ps;
	delete vb;

	srv->Release();
	samplerState->Release();
}

void CRect::Render()
{
	vb->Set();

	DC->PSSetShaderResources(0, 1, &srv);
	DC->PSSetSamplers(0, 1, &samplerState);

	vs->Set();
	ps->Set();

	DC->Draw((UINT)vertices.size(), 0);
}
