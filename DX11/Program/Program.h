#pragma once

class CProgram
{
private:
	CScene* scene;

public:
	CProgram();
	~CProgram();

	void Update();
	void Render();

	void Create();
	void Delete();
};