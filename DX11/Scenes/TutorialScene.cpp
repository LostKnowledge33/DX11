#include "Framework.h"

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

    rect = new CRect(Float2(0, 0), Float2(50, 50));

    world = new CMatrixBuffer();
    view = new CMatrixBuffer();
    projection = new CMatrixBuffer();

    Matrix orthographic = XMMatrixOrthographicOffCenterLH(
        0.f, WIN_SIZE_X, 
        WIN_SIZE_Y, 0.f, 
        -1.f, 1.f);

    projection->Set(orthographic);

    worldMatrix._11 = 1;
    worldMatrix._22 = 1;
    worldMatrix._33 = 1;
    worldMatrix._44 = 1;
}

CTutorialScene::~CTutorialScene()
{
    delete rect;

    delete world;
    delete view;
    delete projection;
}

void CTutorialScene::Update()
{
    worldMatrix._41 = mousePos.x;
    worldMatrix._42 = mousePos.y;

    Matrix temp = XMLoadFloat4x4(&worldMatrix);
    world->Set(temp);
}

void CTutorialScene::Render()
{
    world->SetVS(0);
    view->SetVS(1);
    projection->SetVS(2);

    rect->Render();
}
