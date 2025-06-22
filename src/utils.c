#include "../include/utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void retirar_enter(string str)
{
    *(str+strlen(str)-1) = '\0';
}

void to_upper(string str) 
{
    for (size_t i = 0; i < strlen(str); i++) {
        *(str+i) = toupper(*(str+i));
    }
}

void limpar_tela()
{
    system("clear");
}