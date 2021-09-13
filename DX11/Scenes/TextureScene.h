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

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};