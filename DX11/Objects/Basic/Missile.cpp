#include "Framework.h"
#include "Missile.h"

CMissile::CMissile(Float2 position, Vector2 scale)
	: CQuad(L"Textures/missile.png", scale)
{
	this->position = position;
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	position.x += direction.x * DELTA;
	position.y += direction.y * DELTA;

	UpdateWorld();
}

void CMissile::Render()
{


}
