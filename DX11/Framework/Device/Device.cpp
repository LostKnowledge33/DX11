#include "Framework.h"

CDevice* CDevice::instance = NULL;

CDevice::CDevice()
{
	CreateDeviceAndSwapChain();
	CreateBackBuffer();
}

CDevice::~CDevice()
{
	device->Release();
	deviceContext->Release();
	swapChain->Release();
	renderTargetView->Release();
}

void CDevice::CreateDeviceAndSwapChain()
{
    D3D_FEATURE_LEVEL fl = {
       D3D_FEATURE_LEVEL_11_0,
    };

    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount = 1;
    scd.BufferDesc.Width = (UINT)WIN_SIZE_X;
    scd.BufferDesc.Height = (UINT)WIN_SIZE_Y;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hWnd;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.Windowed = TRUE;

    D3D11CreateDeviceAndSwapChain(
        NULL, D3D_DRIVER_TYPE_HARDWARE,
        NULL, D3D11_CREATE_DEVICE_DEBUG,
        NULL, NULL, D3D11_SDK_VERSION,
        &scd, &swapChain, &device,
        NULL, &deviceContext);
}

void CDevice::CreateBackBuffer()
{
    ID3D11Texture2D* backBuffer = NULL;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, NULL, &renderTargetView);

    backBuffer->Release();

    deviceContext->OMSetRenderTargets(1, &renderTargetView, NULL);

    D3D11_VIEWPORT viewPort;
    viewPort.Width = (UINT)WIN_SIZE_X;
    viewPort.Height = (UINT)WIN_SIZE_Y;
    viewPort.MinDepth = 0.f;
    viewPort.MaxDepth = 1.f;
    viewPort.TopLeftX = 0.f;
    viewPort.TopLeftY = 0.f;

    deviceContext->RSSetViewports(1, &viewPort);
}

void CDevice::Clear()
{
    float clearColor[4] = { 0.f, 0.125f, 0.3f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
}

void CDevice::Present()
{
    swapChain->Present(0, 0);
}
