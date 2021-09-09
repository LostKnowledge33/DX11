#pragma once

class CSolarSystemScene : public CScene {
private:
	CPlanet* sun;
	CPlanet* earth;
	CPlanet* moon;

public:
	CSolarSystemScene();
	~CSolarSystemScene();

	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

};