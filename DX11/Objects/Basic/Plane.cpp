#include "Framework.h"
#include "Plane.h"

CPlane::CPlane(Float2 position, Float4 color)
{
	texture = CTexture::Add(L"Textures/airplane.png");
	Vector2 size = texture->GetSize();

	rect = new CRect(Float2(0, 0), Float2(size.x, size.y),
		L"Shaders/VertexShader/VertexUV.hlsl", L"Shaders/PixelShader/PixelUV.hlsl");

	worldBuffer = new CMatrixBuffer();
	colorBuffer = new CColorBuffer();

	colorBuffer->Set(color);

	this->position = position;
}

CPlane::~CPlane()
{
	delete worldBuffer;
	delete colorBuffer;
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
		missiles.emplace_back(new CMissile(Float2(position.x, position.y), Float2(50, 20), Float4(1, 1, 1, 1), direction, rotation.z));
	}

	for (int i = 0; i < missiles.size(); i++) {
		missiles[i]->Update();
	}

	UpdateWorld();
}

void CPlane::Render()
{
	texture->Set();

	worldBuffer->Set(matrix);
	worldBuffer->SetVS(0);

	colorBuffer->SetPS(0);

	rect->Render();

	for (int i = 0; i < missiles.size(); i++) {
		missiles[i]->Render();
	}

}
