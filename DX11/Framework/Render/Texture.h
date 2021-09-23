#pragma once

class CTexture {
private:
	ScratchImage image;

	ID3D11ShaderResourceView* srv;

	static map<wstring, CTexture*> textures;

	CTexture(ID3D11ShaderResourceView* srv, ScratchImage& image);
	~CTexture();

public:
	static CTexture* Add(wstring file);
	static void Delete();

	void Set(UINT slot = 0);

	Vector2 GetSize();
};