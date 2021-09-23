#pragma once

class CProgram
{
private:
	CScene* scene;

	CMatrixBuffer* view;
	CMatrixBuffer* projection;

	ID3D11SamplerState* samplerState;

public:
	CProgram();
	~CProgram();

	void Update();
	void Render();

	void Create();
	void Delete();

private:
	void CreateProjection();
	void CreateSamplerState();
};