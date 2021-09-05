#pragma once

using namespace std;
using namespace DirectX;

#define WIN_START_X 350
#define WIN_START_Y 150

#define WIN_SIZE_X 1920
#define WIN_SIZE_Y 1080

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;

extern HWND hWnd;

struct Vertex { //정점 : 3차원 공간에서의 한점
    Float3 position;
    Float4 color;

    Vertex(float x, float y, float r, float g, float b)
    {
        position = Float3(x, y, 0);
        color = Float4(r, g, b, 1);
    }
};