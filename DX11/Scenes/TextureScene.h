#pragma once

class CTextureScene : public CScene {
private:
	CPlane* plane;

public:
	CTextureScene();
	~CTextureScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};