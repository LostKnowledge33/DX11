#pragma once

class CSRTScene : public CScene {
private:
	CMatrixBuffer* worldBuffer;
	Matrix world;
	Matrix world2;

	Float2 position;
	Float2 scale;
	float angle, angle2;

	Float2 pivot;

public:
	CSRTScene();
	~CSRTScene();

	// CScene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
};