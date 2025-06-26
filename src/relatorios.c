#include "../include/relatorios.h"
#include <stdio.h>

void listar_todos_registros_rh(no_t *ptr_lista_rh)
{
    limpar_tela();

    msg_cabecalho("Relatorio de Funcionarios");

    while (ptr_lista_rh) {
        mostrar_dados_registro_rh(ptr_lista_rh);
        ptr_lista_rh = ptr_lista_rh->proximo;
    }
    msg_press_enter();
}

void mostrar_dados_registro_rh(no_t *registro)
{
    
    printf("Codigo.....................: %hhi\n", registro->dados.codigo);
    printf("Nome da pessoa.............: %s\n", registro->dados.nome);
    printf("Email da pessoa............: %s\n", registro->dados.email);
    printf("CPF da pessoa..............: %s\n", registro->dados.cpf);
    printf("Funcao.....................: %s\n", registro->dados.funcao);
    printf("Salario....................: %.2f\n", registro->dados.salario);
    printf("Data da admissao...........: %hhd/%hhd/%hhd\n", registro->dados.admissao.dia, registro->dados.admissao.mes, registro->dados.admissao.ano);
    if (registro->dados.status == INATIVO) {
        printf("Data da demissao...........: %hhd/%hhd/%hhd\n", registro->dados.demissao.dia, registro->dados.demissao.mes, registro->dados.demissao.ano);
    }
    printf("Status.....................: %d\n", registro->dados.status);

}
