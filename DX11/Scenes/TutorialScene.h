#pragma once

class CTutorialScene : public CScene
{
private:
	vector<Vertex> vertices;

public:
	CTutorialScene();
	~CTutorialScene();

	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};