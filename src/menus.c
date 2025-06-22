#include <stdio.h>
#include <stdint.h>
#include "../include/menus.h"
#include "../include/utils.h"

uint8_t menu_principal()
{
    uint8_t opcao;

    limpar_tela();

    printf("| MENU PRINCIPAL |\n");
    printf("------------------\n");
    printf("1.Cadastros\n");
    printf("2.Relatorios\n");
    printf("3.Consultas\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%hhi", &opcao);

    return opcao;
}

uint8_t menu_relatorios()
{

}

uint8_t menu_cadastros()
{

}