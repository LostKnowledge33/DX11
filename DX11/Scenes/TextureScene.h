#pragma once

class CTextureScene : public CScene {
private:
	CRect* rect;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

	Matrix world;

public:
	CTextureScene();
	~CTextureScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};