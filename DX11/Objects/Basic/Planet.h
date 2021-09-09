#pragma once

class CPlanet : public CTransform {
private:
	CRect* rect;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

public:
	CPlanet(Float2 position, Float2 scale, float angle, Float4 color);
	~CPlanet();

	void Render();

}; 