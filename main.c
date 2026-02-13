#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Deposito_de_Palavras.h"
void tabela(char *dicionario[],char *palavra,int k) {
    int pa=strlen(palavra),pb=strlen(dicionario[k]);
    int matriz[pa+1][pb+1];
    for (int i=0;i<=pa;i++) {
        for (int j=0;j<=pb;j++) {
            matriz[i][j]=0;//enche a matriz de 0
        }
    }
    for (int i=0;i<=pa;i++) {
        matriz[i][0]=i;//cria linhas de acordo com o numero de caracteres da palavra
    }
    for (int i=0;i<=pb;i++) {
        matriz[0][i]=i;//cria colunas de acordo com o numero de caracteres da palavra escolhida
    }
    for (int i=0;i<=pa;i++) {
        for (int j=0;j<=pb;j++) {
            printf("[%d]",matriz[i][j]);//mostra a matriz
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    setlocale(LC_ALL,"portuguese" );
    char palavra[25];

    printf("Digite uma palavra que começa com j\n");
    fgets(palavra,25,stdin);//absrove a palavra
    palavra[strcspn(palavra, "\n")] = '\0';//isso ser pra não dar bug no strlen, sem isso a palavr gato retornaria 5 carateres
    printf("\n %d \n",strlen(palavra));

    //aqui a gente definirá a letra usada e o dicionário de palavras que a gente vai criar

    int total = sizeof(dicionario) / sizeof(dicionario[0]);

    printf("\n");
    for (int k=0;k<total;k++) {
        tabela(dicionario,palavra,k);
    }
    return 0;
}
