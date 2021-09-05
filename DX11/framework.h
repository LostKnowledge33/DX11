// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//
#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <iostream>

#include <d3d11.h>
#include <d3dcompiler.h> //Shader
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

//FrameWork Header Files
#include "Defines.h"

#include "Scenes/Scene.h"
#include "Scenes/TutorialScene.h"

#include "Framework/Device/Device.h"
#include "Framework/Shader/VertexShader.h"
#include "Framework/Shader/PixelShader.h"

#include "Program/Program.h"


