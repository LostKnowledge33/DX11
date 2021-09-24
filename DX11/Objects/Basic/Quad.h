#pragma once

class CQuad : public CTransform {
protected:
	vector<Vertex> vertices;
	vector<UINT> indices;

	CVertexShader* vs;
	CPixelShader* ps;

	CVertexBuffer* vb;
	CIndexBuffer* ib;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

	CTexture* texture;

public:
	CQuad(wstring file, Vector2 size);
	virtual ~CQuad();

	void Render();
};