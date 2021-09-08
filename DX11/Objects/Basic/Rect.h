#pragma once

class CRect{
private:
	vector<Vertex> vertices;

	CVertexShader* vs;
	CPixelShader* ps;
	CVertexBuffer* vb;

public:
	CRect(Float2 pos, Float2 size);
	~CRect();

	void Render();
};