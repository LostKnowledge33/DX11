#pragma once

class CMatrixBuffer : public CConstBuffer {
private:
	struct Data {
		Matrix matrix;
	}data;

public:
	CMatrixBuffer() : CConstBuffer(&data, sizeof(Data))
	{
		data.matrix = XMMatrixIdentity();
	};

	void Set(Matrix value)
	{
		data.matrix = XMMatrixTranspose(value);
	}
};