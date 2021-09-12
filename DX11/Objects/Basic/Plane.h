#pragma once

class CPlane : public CRect {
private:
	CTexture* texture;

public:
	CPlane(Float2 pos, Float2 size, wstring vsPath, wstring psPath);
	~CPlane();

	void Render();
};