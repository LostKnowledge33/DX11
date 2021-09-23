#pragma once

class CQuad : public CTransform {
protected:
	vector<Vertex> vertices;
	vector<UINT> indices;

	CVertexShader* vs;
	CPixelShader* ps;

	CVertexBuffer* vb;
	CIndexBuffer* ib;

	CTexture* texture;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

public:
	CQuad(wstring file);
	virtual ~CQuad();

	void Render();
};