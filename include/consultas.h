#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "types.h"

no_t *consulta_pessoa_por_nome(string nome, no_t *lista);
no_t *consulta_pessoa_por_nome_recursiva(string nome, no_t *lista);

#endif