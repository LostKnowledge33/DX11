#include "Framework.h"
#include "Texture.h"

CTexture::CTexture(wstring path)
{
	ScratchImage image;
	LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);

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

CTexture::~CTexture()
{
	srv->Release();
	samplerState->Release();
}

void CTexture::Set()
{
	DC->PSSetShaderResources(0, 1, &srv);
	DC->PSSetSamplers(0, 1, &samplerState);
}
