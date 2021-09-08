#pragma once

class CVertexBuffer {
private:
	ID3D11Buffer* buffer;

	UINT stride;
	UINT offset;

public:
	CVertexBuffer(void* data, UINT stride, UINT count);
	~CVertexBuffer();

	void Set(D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
};