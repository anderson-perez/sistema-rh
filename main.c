#include <stdint.h>
#include "./include/menus.h"

#define SAIR    0

int main()
{
    uint8_t opcao;

    do {
        opcao = menu_principal();

        switch (opcao) {

            case 1: break;

            case 2: break;

            case 3: break;
        }


    } while (opcao != SAIR);

    return 0;
}
