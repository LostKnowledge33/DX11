#pragma once

class CProgram
{
private:
	CScene* scene;

	CMatrixBuffer* view;
	CMatrixBuffer* projection;
public:
	CProgram();
	~CProgram();

	void Update();
	void Render();

	void Create();
	void Delete();

private:
	void CreateProjection();
};