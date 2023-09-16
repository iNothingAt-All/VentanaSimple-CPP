#include "eventos.hpp"
#include <windows.h>
#include <iostream>

UINT emisor(WPARAM interaccion) { return LOWORD(interaccion); }
UINT accion(WPARAM interaccion) { return HIWORD(interaccion); }
bool atrapa(UINT interaccion, DWORD tipo, UINT identificador) { return emisor(interaccion) == identificador && accion(interaccion) == tipo; }

LRESULT CALLBACK eventos(HWND ventana, UINT evento, WPARAM interaccion, LPARAM datos_interaccion)
{
    switch (evento) 
    {
        case WM_CLOSE: DestroyWindow(ventana); break;
        case WM_DESTROY: PostQuitMessage(0); break;
        case WM_COMMAND: 
        {
            
        }
    }

    return DefWindowProc(ventana, evento, interaccion, datos_interaccion);
}
