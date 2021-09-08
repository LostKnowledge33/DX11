#pragma once

class CPixelShader {

private:
	ID3D11PixelShader* pixelShader;
	ID3DBlob* blob;

public:
	CPixelShader(LPCWSTR psPath, DWORD flags);
	~CPixelShader();

	void Set();
};