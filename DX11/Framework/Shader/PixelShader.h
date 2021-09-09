#pragma once

class CPixelShader {

private:
	ID3D11PixelShader* pixelShader;
	ID3DBlob* blob;

public:
	CPixelShader(wstring psPath, DWORD flags);
	~CPixelShader();

	void Set();
};