#pragma once

class CTutorialScene : public CScene
{
private:
	CRect* rect;
	CRect* rect2;

	CMatrixBuffer* world;

	XMFLOAT4X4 worldMatrix;
	XMFLOAT4X4 worldMatrix2;

	XMFLOAT4X4 viewMatrix;

public:
	CTutorialScene();
	~CTutorialScene();

	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};