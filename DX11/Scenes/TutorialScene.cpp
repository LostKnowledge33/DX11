#include "Framework.h"
#include "TutorialScene.h"

CTutorialScene::CTutorialScene()
{
    /*
    vs = new CVertexShader(L"Shaders/Tutorial.hlsl", NULL);
    ps = new CPixelShader(L"Shaders/Tutorial.hlsl", NULL);

    int degree = 1;

    for (int i = 0; i < 360 / degree; i++) {
        float temp = degree * i;

        cout << (float)cosf(XMConvertToRadians(degree * i)) << endl;
        cout << (float)sinf(XMConvertToRadians(degree * i)) << endl;

        vertices.emplace_back(0, 0, 0, 0, 0);
        vertices.emplace_back(cosf(XMConvertToRadians(temp + degree)) * 0.5f, sinf(XMConvertToRadians(temp + degree)) * 0.5f, 1, 1, 0);
        vertices.emplace_back(cosf(XMConvertToRadians(temp)) * 0.5f, sinf(XMConvertToRadians(temp)) * 0.5f, 1, 1, 0);
    }

    vb = new CVertexBuffer((void*)vertices.data(), sizeof(Vertex), vertices.size());
    */

    world = new CMatrixBuffer();

    worldMatrix._11 = 1;
    worldMatrix._22 = 1;
    worldMatrix._33 = 1;
    worldMatrix._44 = 1;

    worldMatrix2._11 = 1;
    worldMatrix2._22 = 1;
    worldMatrix2._33 = 1;
    worldMatrix2._44 = 1;

    viewMatrix._11 = 1;
    viewMatrix._22 = 1;
    viewMatrix._33 = 1;
    viewMatrix._44 = 1;
}

CTutorialScene::~CTutorialScene()
{
    delete world;
}

void CTutorialScene::Update()
{
    worldMatrix._41 = mousePos.x;
    worldMatrix._42 = mousePos.y;

    if (GetAsyncKeyState(VK_RIGHT))
        worldMatrix2._41 += 0.1f;
    if (GetAsyncKeyState(VK_LEFT))
        worldMatrix2._41 -= 0.1f;
    if (GetAsyncKeyState(VK_UP))
        worldMatrix2._42 -= 0.1f;
    if (GetAsyncKeyState(VK_DOWN))
        worldMatrix2._42 += 0.1f;

    if (GetAsyncKeyState('D'))
        viewMatrix._41 -= 0.1f;
    if (GetAsyncKeyState('A'))
        viewMatrix._41 += 0.1f;
    if (GetAsyncKeyState('W'))
        viewMatrix._42 += 0.1f;
    if (GetAsyncKeyState('S'))
        viewMatrix._42 -= 0.1f;
}

void CTutorialScene::Render()
{

}
