#pragma once

class CTutorialScene : public CScene
{
private:
	vector<Vertex> vertices;

public:
	CTutorialScene();
	~CTutorialScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
};