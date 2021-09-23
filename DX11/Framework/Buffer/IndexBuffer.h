#pragma once

class CIndexBuffer {
	ID3D11Buffer* buffer;

public:
	CIndexBuffer(void* data, UINT count);
	~CIndexBuffer();

	void Set();
};