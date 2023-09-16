#include "ventana.hpp"
#include "eventos.hpp"

void Ventana::registrar_clase_ventana(HINSTANCE instancia, LPCSTR nombre_clase, UINT estilos_clase)
{
	_clase_ventana.style         = estilos_clase; 
    _clase_ventana.lpszClassName = nombre_clase;
    _clase_ventana.hInstance     = instancia;
    _clase_ventana.lpfnWndProc   = eventos;
    RegisterClass(&_clase_ventana);
}

void Ventana::crear_ventana(LPCSTR titulo_ventana, UINT estilos_ventana, UINT anchura, UINT altura, UINT pos_x, UINT pos_y)
{
	_ventana = CreateWindowEx(0, _clase_ventana.lpszClassName, // nombre de la clase registrada
		titulo_ventana, 
		estilos_ventana | WS_VISIBLE | WS_OVERLAPPED, 
		pos_x, pos_y, 
		anchura, altura,
        nullptr, nullptr, _clase_ventana.hInstance, nullptr);
}

void Ventana::anyadir_widget(UINT indetificador, LPCSTR tipo_widget, DWORD estilos_widget, LPCSTR titulo, UINT anchura, UINT altura, UINT pos_x, UINT pos_y)
{
	_widgets.push_back(CreateWindowEx(0,
        tipo_widget, titulo,
        estilos_widget | WS_VISIBLE | WS_CHILD | WS_BORDER,
        pos_x, pos_y, anchura, altura, 
        _ventana, (HMENU)indetificador, _clase_ventana.hInstance, nullptr)
	);
}


void Ventana::ejecutar_ventana()
{
    MSG mensaje {};

    //control de eventos o "mensaje"
    while (GetMessage(&mensaje, NULL, 0, 0))
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }
}