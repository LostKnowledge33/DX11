#pragma once

class CDevice : public CSingleton<CDevice>
{
private:
	friend class CSingleton;

	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* renderTargetView;

	CDevice();
	~CDevice();
public:
	void CreateDeviceAndSwapChain();
	void CreateBackBuffer();

	void Clear();
	void Present();

	ID3D11Device* GetDevice() { return device; }
	ID3D11DeviceContext* GetDeviceContext() { return deviceContext; }
};

