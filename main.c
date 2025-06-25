#include <stdint.h>
#include "./include/menus.h"
#include "./include/types.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"

#define SAIR    0

int main()
{
    uint8_t opcao, opcao_cadastro, opcao_relatorios;

    lista_t lista_rh;
    no_t *aux = NULL;

    // Criar a lista
    inicializa_lista_rh(&lista_rh);


    do {
        opcao = menu_principal();

        switch (opcao) {

            case 1: 
                    do {
                        opcao_cadastro = menu_cadastros();
                        switch (opcao_cadastro) {
                            case 1: aux = novo_registro_rh();
                                    insere_registro_inicio_rh(aux, &lista_rh);
                                    break;

                            case 2: break;
                        }
                    } while (opcao_cadastro != 0);

                    break;

            case 2: do {
                        opcao_relatorios = menu_relatorios();
                        switch (opcao_relatorios) {
                                    
                            case 1: listar_todos_registros_rh(lista_rh.cabeca);
                                    break;

                            case 2: break;
                        }

                    } while (opcao_relatorios != 0);
                    break;

            case 3: break;
        }


    } while (opcao != SAIR);

    if (!is_lista_rh_vazia(lista_rh.cabeca)) {
        salvar_registros_rh_arquivo_binario("dados_rh.bin", lista_rh.cabeca);
    }

    return 0;
}
