#include "Framework.h"
#include "Plane.h"

CPlane::CPlane(Float2 pos, Float2 size, wstring vsPath, wstring psPath)
	:CRect(pos, size, vsPath, psPath)
{
	texture = new CTexture(L"Textures/airplane.png");
	
}

CPlane::~CPlane()
{

}

void CPlane::Render()
{
	texture->Set();

	CRect::Render();
}
