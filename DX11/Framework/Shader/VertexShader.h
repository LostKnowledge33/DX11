#pragma once

class CVertexShader {

private:
	ID3D11VertexShader* vertexShader;
	ID3D11InputLayout* inputLayout;
	ID3D11Buffer* vertexBuffer;

	ID3DBlob* blob;

public:
	CVertexShader(LPCWSTR vsPath, DWORD flags);
	~CVertexShader();

	void Set();
};