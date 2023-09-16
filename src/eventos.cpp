#include "eventos.hpp"
#include "identificadores.hpp"
#include <windows.h>


UINT emisor(WPARAM interaccion) { return LOWORD(interaccion); }
UINT accion(WPARAM interaccion) { return HIWORD(interaccion); }

LRESULT CALLBACK eventos(HWND ventana, UINT evento, WPARAM interaccion, LPARAM datos_interaccion)
{
    switch (evento) 
    {
        case WM_CLOSE: DestroyWindow(ventana); break;
        case WM_DESTROY: PostQuitMessage(0); break;
        case WM_COMMAND: 
        {
            if(emisor(interaccion) == BOTON_1 && accion(interaccion) == BN_CLICKED)
            {
                HWND boton_2 = GetDlgItem(ventana, BOTON_2);
                SetWindowText(boton_2, "Hola");
            }
            else 
            if(emisor(interaccion) == BOTON_2 && accion(interaccion) == BN_CLICKED)
            {
                HWND boton_1 = GetDlgItem(ventana, BOTON_1);
                SetWindowText(boton_1, "Hola");
            }
        }
    }

    return DefWindowProc(ventana, evento, interaccion, datos_interaccion);
}
