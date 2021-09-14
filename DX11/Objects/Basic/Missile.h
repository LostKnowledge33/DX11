#pragma once

class CMissile : public CTransform {
private:
	CTexture* texture;
	CRect* rect;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

public:
	CMissile(Float2 position, Float2 scale, Float4 color);
	~CMissile();

	void Render();
};