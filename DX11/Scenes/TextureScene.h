#pragma once

class CTextureScene : public CScene {
private:
	CPlane* plane;

	CTransform* transform;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

public:
	CTextureScene();
	~CTextureScene();

	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};