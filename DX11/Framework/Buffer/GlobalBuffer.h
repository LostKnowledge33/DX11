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

class CColorBuffer : public CConstBuffer {
private:
	struct Data {
		Float4 color;
	}data;

public:
	CColorBuffer() : CConstBuffer(&data, sizeof(Data)) {
		data.color = Float4(1, 1, 1, 1);
	};

	void Set(Float4 color) {
		data.color = color;
	}
};