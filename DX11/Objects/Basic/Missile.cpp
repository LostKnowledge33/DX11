#include "Framework.h"
#include "Missile.h"

CMissile::CMissile(Float2 position, Float2 size, Float4 color, Vector2 direction)
	: direction(direction)
{
	texture = new CTexture(L"Textures/missile.png");

	rect = new CRect(position, Float2(size.x, size.y),
		L"Shaders/VertexShader/VertexUV.hlsl", L"Shaders/PixelShader/PixelUV.hlsl");

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	colorBuffer->Set(color);
}

CMissile::~CMissile()
{
	delete worldBuffer;
	delete colorBuffer;
}

void CMissile::Update()
{
	position.x += direction.x * DELTA;
	position.y += direction.y * DELTA;

	UpdateWorld();
}

void CMissile::Render()
{
	texture->Set();

	worldBuffer->Set(matrix);
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	rect->Render();
}
