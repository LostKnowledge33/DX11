#pragma once

class CSolarSystemScene : public CScene {
private:
	CPlanet* sun;
	CPlanet* earth;
	CPlanet* moon;

public:
	CSolarSystemScene();
	~CSolarSystemScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

};