#include "Framework.h"

CQuad::CQuad(wstring file, Vector2 scale)
{
	texture = CTexture::Add(file);

	Vector2 size = texture->GetSize();
	size.x *= scale.x;
	size.y *= scale.y;


	float left = -size.x;
	float right = size.x;
	float top = -size.y;
	float bottom = size.y;

	vertices.emplace_back(left, top, 0, 0);
	vertices.emplace_back(right, top, 1, 0);
	vertices.emplace_back(left, bottom, 0, 1);
	vertices.emplace_back(right, bottom, 1, 1);

	indices = { 0, 1, 2,
				2, 1, 3 };

	vs = new CVertexShader(L"Shaders/VertexShader/VertexUV.hlsl", NULL);
	ps = new CPixelShader(L"Shaders/PixelShader/PixelUV.hlsl", NULL);

	vb = new CVertexBuffer((void*)vertices.data(), sizeof(Vertex), (UINT)vertices.size());
	ib = new CIndexBuffer((void*)indices.data(), (UINT)indices.size());

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	colorBuffer->Set(Float4(1, 1, 1, 1));
}

CQuad::~CQuad()
{
	delete vs;
	delete ps;
	delete vb;
	delete ib;
	delete worldBuffer;
	delete colorBuffer;
}

void CQuad::Render()
{
	worldBuffer->Set(matrix);
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	vb->Set();
	ib->Set();

	texture->Set();

	vs->Set();
	ps->Set();

	DC->DrawIndexed((UINT)indices.size(), 0, 0);
}
