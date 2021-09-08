#pragma once

class CConstBuffer {
private:
	ID3D11Buffer* buffer;

	void* data;
	UINT dataSize;

public:
	CConstBuffer(void* data, UINT dataSize);
	virtual ~CConstBuffer();

	void SetVS(UINT slot);
	void SetPS(UINT slot);

	void Update();

};