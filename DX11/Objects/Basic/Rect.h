#pragma once

class CRect {
private:
	vector<Vertex> vertices;
	vector<UINT> indices;

	CVertexShader* vs;
	CPixelShader* ps;
	CVertexBuffer* vb;
	CIndexBuffer* ib;

public:
	CRect(Float2 pos, Float2 size, 
		wstring vsPath = L"Shaders/VertexShader/VertexColor.hlsl", 
		wstring psPath = L"Shaders/PixelShader/PixelColor.hlsl" );
	~CRect();

	void Render();
};