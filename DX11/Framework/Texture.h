#pragma once

class CTexture {
private:
	ID3D11ShaderResourceView* srv;
	ID3D11SamplerState* samplerState;

public:
	CTexture(wstring path);
	~CTexture();
	
	void Set();
};