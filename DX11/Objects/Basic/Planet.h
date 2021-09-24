#pragma once

class CPlanet : public CTransform {
private:

public:
	CPlanet(Float2 position, Float2 scale, float angle, Float4 color);
	~CPlanet();

	void Render();

}; 