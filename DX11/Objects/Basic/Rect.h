#pragma once

class CRect {
private:
	vector<Vertex> vertices;

	CVertexShader* vs;
	CPixelShader* ps;
	CVertexBuffer* vb;

public:
	CRect(Float2 pos, Float2 size, 
		wstring vsPath = L"Shaders/VertexShader/VertexColor.hlsl", 
		wstring psPath = L"Shaders/PixelShader/PixelColor.hlsl" );
	~CRect();

	void Render();
};