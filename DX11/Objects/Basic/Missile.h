#pragma once

class CMissile : public CQuad {
private:
	Vector2 direction;

	bool isActive;

public:
	CMissile(Float2 position, Vector2 scale);
	~CMissile();

	void Update();
	void Render();

	bool GetActive() { return isActive; }
	void SetActive(bool active) { isActive = active; }

};