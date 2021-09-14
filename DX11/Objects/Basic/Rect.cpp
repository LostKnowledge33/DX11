#include "Framework.h"

CRect::CRect(Float2 pos, Float2 size, wstring vsPath, wstring psPath)
{
	float left = pos.x - size.x * 0.5f;
	float right = pos.x + size.x * 0.5f;
	float top = pos.y - size.y * 0.5f;
	float bottom = pos.y + size.y * 0.5f;

	vertices.emplace_back(left, top, 0, 0);
	vertices.emplace_back(right, top, 1, 0);
	vertices.emplace_back(left, bottom, 0, 1);

	vertices.emplace_back(left, bottom, 0, 1);
	vertices.emplace_back(right, top, 1, 0);
	vertices.emplace_back(right, bottom, 1, 1);

	vs = new CVertexShader(vsPath, NULL);
	ps = new CPixelShader(psPath, NULL);

	vb = new CVertexBuffer((void*)vertices.data(), sizeof(Vertex), (UINT)vertices.size());
}

CRect::~CRect()
{
	delete vs;
	delete ps;
	delete vb;
}

void CRect::Render()
{
	vb->Set();

	vs->Set();
	ps->Set();

	DC->Draw((UINT)vertices.size(), 0);
}
