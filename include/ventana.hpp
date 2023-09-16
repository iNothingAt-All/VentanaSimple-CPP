#pragma once
#include <windows.h>
#include <vector>

struct Ventana
{
    void registrar_clase_ventana(HINSTANCE, LPCSTR, UINT);
    void crear_ventana(LPCSTR, UINT, UINT, UINT, UINT, UINT);
    void anyadir_widget(UINT, LPCSTR, DWORD, LPCSTR, UINT, UINT, UINT, UINT);
    void ejecutar_ventana();

private:
    WNDCLASS _clase_ventana {};
    HWND     _ventana {};

    std::vector<HWND> _widgets;
};