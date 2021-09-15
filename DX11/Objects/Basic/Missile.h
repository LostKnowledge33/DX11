#pragma once

class CMissile : public CTransform {
private:
	CTexture* texture;
	CRect* rect;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

	Vector2 direction;

public:
	CMissile(Float2 position, Float2 scale, Float4 color, Vector2 direction);
	~CMissile();

	void Update();
	void Render();
};