#include "Framework.h"
#include "Plane.h"

CPlane::CPlane(Float2 position, Vector2 scale)
	: CQuad(L"Textures/airplane.png", scale)
{
	this->position = position;
}

CPlane::~CPlane()
{

}

void CPlane::Update()
{
	if (KEY_PRESS('D'))
		rotation.z += DELTA;
	if (KEY_PRESS('A'))
		rotation.z -= DELTA;
	if (KEY_PRESS('W'))
		position += Right() * speed * DELTA;
	if (KEY_PRESS('S'))
		position += Left() * speed * DELTA;

	Vector2 direction = mousePos - position;
	//rotation.z = atan2(direction.y, direction.x);

	if (KEY_DOWN(VK_LBUTTON)) {
		Fire();
	}

	UpdateWorld();
}

void CPlane::Render()
{
	CQuad::Render();
}

void CPlane::Fire() {
	
	for (auto missile : missiles) {
		if (!missile->GetActive()) {
			
		}
	}
	missiles.emplace_back(new CMissile(Float2(position.x, position.y), Float2(50, 20), Float4(1, 1, 1, 1), direction, rotation.z));

}