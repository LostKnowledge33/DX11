#pragma once

struct Vertex { //���� : 3���� ���������� ����
    Float3 position;
    Float4 color;

    Vertex(float x, float y, float r, float g, float b)
    {
        position = Float3(x, y, 0);
        color = Float4(r, g, b, 1);
    }
};