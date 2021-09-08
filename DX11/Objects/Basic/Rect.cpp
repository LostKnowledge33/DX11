#include "Framework.h"

CRect::CRect(Float2 pos, Float2 size)
{
	float left = pos.x - size.x * 0.5f;
	float right = pos.x + size.x * 0.5f;
	float top = pos.y + size.y * 0.5f;
	float bottom = pos.y - size.y * 0.5f;

	vertices.emplace_back(left, bottom, 0, 0, 0);
	vertices.emplace_back(right, bottom, 0, 0, 0);
	vertices.emplace_back(left, top, 0, 0, 0);

	vertices.emplace_back(left, top, 0, 0, 0);
	vertices.emplace_back(right, bottom, 0, 0, 0);
	vertices.emplace_back(right, top, 0, 0, 0);

	vs = new CVertexShader(L"Shaders/VertexShader/VertexColor.hlsl", NULL);
	ps = new CPixelShader(L"Shaders/PixelShader/PixelColor.hlsl", NULL);

	vb = new CVertexBuffer((void*)vertices.data(), sizeof(Vertex), vertices.size());
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

	DC->Draw(vertices.size(), 0);
}
