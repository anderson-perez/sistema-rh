#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "./include/menus.h"
#include "./include/types.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/arquivos.h"
#include "./include/consultas.h"

#define SAIR    0

int main(int argc, char** argv)
{
    uint8_t opcao, sub_menu, politica_insercao;
    no_t *aux = NULL;
    float salario_minimo, salario_maximo;
    string nome_arq, nome_arquivo_dados, nome_pessoa, funcao;
    char resposta;
    data_t data;

    if (argc < 3) {
        printf("./rh <nome_arq> -fim -inicio\n");
        exit(0);
    }

    if (strcmp(argv[2], "-inicio") == 0) {
        politica_insercao = 1;
    }
    if (strcmp(argv[2], "-fim") == 0) {
        politica_insercao = 2;
    }

    printf("%d\n", politica_insercao);
    msg_press_enter();

    strcpy(nome_arquivo_dados, argv[1]);


    lista_t lista_rh;

    // Criar a lista
    inicializa_lista_rh(&lista_rh);

    // Carrega dados arquivo
    ler_registros_rh_arquivo_binario(nome_arquivo_dados, &lista_rh);

    //ordenar_em_ordem_alfabetica(&lista_rh);


    do {
        opcao = menu_principal();

        switch (opcao) {

            case 1: 
                    do {
                        sub_menu = menu_cadastros();
                        switch (sub_menu) {
                            
                            case 1: break;
                            
                            case 2: aux = novo_registro_rh();                                    
                                    if (politica_insercao == 1) {
                                        insere_registro_inicio_rh(aux, &lista_rh);
                                    }
                                    if (politica_insercao == 2) {
                                        insere_registro_fim_rh(aux, &lista_rh);
                                    }
                                    break;

                            case 3: 
                                    ordenar_em_ordem_alfabetica(&lista_rh);    
                                    break;

                            case 4: limpar_tela();
                                    printf("Qual o nome do funcionario? ");
                                    fgets(nome_pessoa, T_STR, stdin);
                                    retirar_enter(nome_pessoa);
                                    to_upper(nome_pessoa);

                                    // aux = consulta_pessoa_por_nome(nome_pessoa, lista_rh.cabeca);
                                    aux = consulta_pessoa_por_nome_recursiva(nome_pessoa, lista_rh.cabeca);

                                    if (aux) {
                                        mostrar_dados_registro_rh(aux);
                                        printf("\nConfirma a inativacao do funcionario (S/N)? ");
                                        scanf("%c", &resposta);
                                        if (resposta == 'S' || resposta == 's') {
                                            printf("Informe a data do desligamento: ");
                                            scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
                                            inativar_funcionario(aux, data);
                                        }
                                    }
                                    else {
                                        printf("%s nao esta cadastrado!\n", nome_pessoa);
                                        msg_press_enter();
                                    }
                                    break;

                            case 5: limpar_tela();
                                    printf("Qual o nome do funcionario a ser excluído? ");
                                    fgets(nome_pessoa, T_STR, stdin);
                                    retirar_enter(nome_pessoa);
                                    to_upper(nome_pessoa);

                                    // aux = consulta_pessoa_por_nome(nome_pessoa, lista_rh.cabeca);
                                    aux = consulta_pessoa_por_nome_recursiva(nome_pessoa, lista_rh.cabeca);

                                    if (aux) {
                                        mostrar_dados_registro_rh(aux);
                                        printf("\nConfirma a exclusao do funcionario (S/N)? ");
                                        scanf("%c", &resposta);
                                        if (resposta == 'S' || resposta == 's') {
                                            excluir_registro_rh(aux, &lista_rh);
                                        }
                                    }
                                    else {
                                        printf("%s nao esta cadastrado!\n", nome_pessoa);
                                        msg_press_enter();
                                    }
                                    break;


                            
                        }
                    } while (sub_menu != SAIR);

                    break;

            case 2: do {
                        sub_menu = menu_relatorios();
                        switch (sub_menu) {
                                    
                            case 1: break;

                            case 2: listar_todos_registros_rh(lista_rh.cabeca);
                                    break;
                            
                            case 3:                                 

                                    printf("\n=== RELATORIO DE FAIXA SALARIAL ===\n");
                                    printf("Digite o salario minimo: ");
                                    scanf("%f", &salario_minimo);

                                    printf("Digite o salario maximo: ");
                                    scanf("%f", &salario_maximo);
                                    getchar();
                                    if(salario_minimo > salario_maximo)
                                    {
                                        printf("Erro, salario minimo maior que o maximo!\n");
                                        msg_press_enter();
                                        break;
                                    }
                                    
                                    relatorio_faixa_salarial(lista_rh.cabeca, salario_minimo, salario_maximo);
                                    msg_press_enter();
                                    break;
                                
                            case 4: mostrar_funcionarios_ativos(lista_rh.cabeca);
                                    break;

                            case 5: limpar_tela();
                                    printf("Qual a funcao? ");
                                    fgets(funcao, T_STR, stdin);
                                    retirar_enter(funcao);
                                    to_upper(funcao);
                                    listar_funcionarios_por_funcao(funcao, lista_rh.cabeca);
                                    break;        
                            
                        }

                    } while (sub_menu != SAIR);
                    break;

            case 3: do {
                        sub_menu = menu_consultas();
                        switch (sub_menu) {
                            
                            case 1: limpar_tela();
                                    printf("Qual o nome do funcionario? ");
                                    fgets(nome_pessoa, T_STR, stdin);
                                    retirar_enter(nome_pessoa);
                                    to_upper(nome_pessoa);

                                    // aux = consulta_pessoa_por_nome(nome_pessoa, lista_rh.cabeca);
                                    aux = consulta_pessoa_por_nome_recursiva(nome_pessoa, lista_rh.cabeca);

                                    if (aux) {
                                        mostrar_dados_registro_rh(aux);
                                        msg_press_enter();
                                    }
                                    else {
                                        printf("%s nao esta cadastrado!\n", nome_pessoa);
                                        msg_press_enter();
                                    }

                            }                         

                        
                    } while (sub_menu != SAIR);
            
                    break;

            case 4: do {
                        sub_menu = manipulacao_arquivos();

                        switch (sub_menu) {

                            case 1: limpar_tela();
                                    msg_cabecalho("Exportar dados para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);

                                    exportar_dados_para_arquivo_texto(nome_arq, lista_rh.cabeca);

                                    break;

                            case 2: limpar_tela();
                                    msg_cabecalho("Exportar dados para arquivo do tipo texto\n");
                                    printf("Qual o nome do arquivo de saida (extensao .csv)? ");
                                    fgets(nome_arq, T_STR, stdin);
                                    retirar_enter(nome_arq);
                                    exportar_dados_para_arquivo_csv(nome_arq, lista_rh.cabeca);
                                    break;
                        }

                    } while (sub_menu != SAIR);
        }


    } while (opcao != SAIR);

    if (!is_lista_rh_vazia(lista_rh.cabeca)) {
        salvar_registros_rh_arquivo_binario(nome_arquivo_dados, lista_rh.cabeca);
    }

    return 0;
}
