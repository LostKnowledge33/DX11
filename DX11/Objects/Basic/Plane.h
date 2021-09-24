#pragma once

class CPlane : public CQuad {
private:
	vector<CMissile*> missiles;

	float speed = 100.f;

public:
	CPlane(Float2 position, Vector2 scale);
	~CPlane();

	void Update();
	void Render();

	void Fire();
};