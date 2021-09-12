#pragma once

using namespace std;
using namespace DirectX;

#define WIN_START_X 350
#define WIN_START_Y 150

#define WIN_SIZE_X 1920
#define WIN_SIZE_Y 1080

#define WIN_CENTER_X (WIN_SIZE_X * 0.5f) 
#define WIN_CENTER_Y (WIN_SIZE_Y * 0.5f)

#define DEVICE CDevice::Get()->GetDevice()
#define DC CDevice::Get()->GetDeviceContext()

#define KEY_DOWN(k) CControl::Get()->Down(k)
#define KEY_UP(k) CControl::Get()->Up(k)
#define KEY_PRESS(k) CControl::Get()->Press(k)

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;

typedef XMMATRIX Matrix;

extern HWND hWnd;
extern Float2 mousePos;
