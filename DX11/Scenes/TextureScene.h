#pragma once

class CTextureScene : public CScene {
private:
	CPlane* plane;

	CTransform* transform;

	CMatrixBuffer* worldBuffer;
	CColorBuffer* colorBuffer;

	float speed = 100;

public:
	CTextureScene();
	~CTextureScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};