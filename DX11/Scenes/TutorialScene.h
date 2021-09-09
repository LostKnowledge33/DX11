#pragma once

class CTutorialScene : public CScene
{
private:
	CRect* rect;

	CMatrixBuffer* world;
	CMatrixBuffer* view;
	CMatrixBuffer* projection;

	XMFLOAT4X4 worldMatrix;

public:
	CTutorialScene();
	~CTutorialScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};