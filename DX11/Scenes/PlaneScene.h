#pragma once

class CPlaneScene : public CScene {
private:
	CPlane* plane;

public:
	CPlaneScene();
	~CPlaneScene();


	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

};