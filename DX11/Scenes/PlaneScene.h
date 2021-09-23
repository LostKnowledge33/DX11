#pragma once

class CPlaneScene : public CScene {
private:

public:
	CPlaneScene();
	~CPlaneScene();


	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

};