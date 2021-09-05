#pragma once

class CScene
{
public:
	virtual ~CScene() {}

	virtual void Update() = 0;
	virtual void Render() = 0;
};