#include "ventana.hpp"
#include "identificadores.hpp"

int WINAPI WinMain(HINSTANCE instancia, HINSTANCE anterior_instancia, PTSTR linea_comandos, int visibilidad) 
{   
    constexpr char TITULO[] {"Ventana"};
    constexpr UINT ANCHURA {600}, ALTURA {400};

    Ventana v;
    v.registrar_clase_ventana(instancia, "Monika", CS_OWNDC);
    v.crear_ventana(TITULO, WS_SYSMENU, ANCHURA, ALTURA, 0, 0);

    v.anyadir_widget(BOTON_1, "BUTTON", 0, "1", 50, 50, 0, 0);
    v.anyadir_widget(BOTON_2, "BUTTON", 0, "2", 50, 50, 0, 50);

    v.ejecutar_ventana();
    
    return EXIT_SUCCESS;
}