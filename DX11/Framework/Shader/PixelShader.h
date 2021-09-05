#pragma once

class CPixelShader {

private:
	ID3D11PixelShader* pixelShader;

public:
	CPixelShader(LPCWSTR psPath, DWORD flags);
	~CPixelShader();


};