#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"
#include "utils.h"

void listar_todos_registros_rh(no_t *ptr_lista_rh);
void mostrar_dados_registro_rh(no_t *registro);
void relatorio_faixa_salarial(no_t *ptr_lista_rh, float minSal, float maxSal);
void mostrar_funcionarios_ativos(no_t *ptr_lista_rh);


#endif
