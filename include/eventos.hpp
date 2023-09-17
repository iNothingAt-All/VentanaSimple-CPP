#pragma once
#include <windows.h>

UINT emisor(WPARAM);
UINT accion(WPARAM);

LRESULT CALLBACK eventos(HWND, UINT, WPARAM, LPARAM);