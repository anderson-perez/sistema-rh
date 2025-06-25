#include "../include/arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/cadastros.h"

void salvar_registros_rh_arquivo_binario(string nome_arq, no_t *ptr_lista_rh)
{
    FILE *fp;

    // Abre arquivo
    fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while (ptr_lista_rh) {
        fwrite(ptr_lista_rh, sizeof(no_t), 1, fp);
        ptr_lista_rh = ptr_lista_rh->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

void ler_registros_rh_arquivo_binario(string nome_arq, lista_t *lista_rh)
{
 FILE *fp;

 fp = fopen(nome_arq, "rb");

 if(!fp) {
    printf("Falha ao abrir o arquivo!\n");
    return;
 }

 while(!feof) {
    no_t *aux = (no_t*)malloc(sizeof(no_t));
    fread(aux, sizeof(no_t), 1, fp); 
    insere_registro_inicio_rh(aux, lista_rh);
 }

 fclose(fp);
}