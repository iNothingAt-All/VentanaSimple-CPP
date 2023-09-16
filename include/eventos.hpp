#pragma once
#include <windows.h>

UINT emisor(WPARAM);
UINT accion(WPARAM);
bool atrapa(UINT, DWORD, UINT);

LRESULT CALLBACK eventos(HWND, UINT, WPARAM, LPARAM);