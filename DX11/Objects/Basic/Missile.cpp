#include "Framework.h"
#include "Missile.h"

CMissile::CMissile(Float2 position, Float2 scale, Float4 color)
{
	texture = new CTexture(L"Textures/missile.png");

	rect = new CRect(position, Float2(200 * scale.x, 200 * scale.y));

	worldBuffer = new CMatrixBuffer();
	//colorBuffer = new CColorBuffer();
}

CMissile::~CMissile()
{
}

void CMissile::Render()
{
	texture->Set();

	worldBuffer->Set(matrix);
	worldBuffer->SetVS(0);

	rect->Render();
}
