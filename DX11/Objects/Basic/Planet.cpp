#include "Framework.h"

CPlanet::CPlanet(Float2 position, Float2 scale, float angle, Float4 color)
{
	rect = new CRect(position, Float2(200 * scale.x, 200 * scale.y));

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	colorBuffer->Set(color);
}

CPlanet::~CPlanet()
{
}

void CPlanet::Render()
{
	worldBuffer->Set(matrix);
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	rect->Render();
}
