#pragma once

class CPlane : public CTransform {
private:
	CTexture* texture;
	CRect* rect;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

	vector<CMissile*> missiles;

	float speed = 100.f;

public:
	CPlane(Float2 position, Float4 color);
	~CPlane();

	void Update();
	void Render();
};