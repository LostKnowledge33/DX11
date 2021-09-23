#include "Framework.h"
#include "Texture.h"

map<wstring, CTexture*> CTexture::textures;

CTexture::CTexture(ID3D11ShaderResourceView* srv, ScratchImage& image)
	: srv(srv), image(move(image))
{
}

CTexture::~CTexture()
{
	srv->Release();
}

CTexture* CTexture::Add(wstring file)
{
	if (textures.count(file) > 0)
		return textures[file];

	ScratchImage image;
	LoadFromWICFile(file.c_str(), WIC_FLAGS_NONE, nullptr, image);

	ID3D11ShaderResourceView* srv;

	CreateShaderResourceView(DEVICE, image.GetImages(), image.GetImageCount(), image.GetMetadata(), &srv);

	CTexture* texture = new CTexture(srv, image);
	textures[file] = texture;

	return texture;
}

void CTexture::Delete()
{
	for (pair<wstring, CTexture*> texture : textures) {
		delete texture.second;
	}
}

void CTexture::Set(UINT slot)
{
	DC->PSSetShaderResources(slot, 1, &srv);
}

Vector2 CTexture::GetSize()
{
	return Vector2(image.GetMetadata().width, image.GetMetadata().height);
}
