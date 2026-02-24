#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Deposito_de_Palavras.h"
#include <stdlib.h>
#include <windows.h>

#include "Deposito_de_Palavras.h"

typedef struct {
    char *palavra;
    int distancia;
} Resultado;

int MIN(int a,int b,int c) {
    int min=a;
    if (b<min){min=b;}
    if (c<min){min=c;}
    return min;

}

int tabela(char *dicionario[],char *palavra,int k) {
    int pa=strlen(palavra),pb=strlen(dicionario[k]);
    int matriz[pa+1][pb+1];

    for (int i=0;i<=pa;i++) {
        matriz[i][0]=i;//cria linhas de acordo com o numero de caracteres da palavra
    }
    for (int i=0;i<=pb;i++) {
        matriz[0][i]=i;//cria colunas de acordo com o numero de caracteres da palavra escolhida
    }
    for (int i=1;i<=pa;i++) {
        for (int j=1;j<=pb;j++) {
            int custo=1;
            if (palavra[i-1]==dicionario[k][j-1]) {
                custo=0;
            }
            matriz[i][j]=MIN(
            matriz[i-1][j]+1,
            matriz[i][j-1]+1,
            matriz[i-1][j-1]+custo
            );
        }

    }

    return matriz[pa][pb];
}

int main(void) {
    setlocale(LC_ALL,"pt_BR.UTF-8" );
    SetConsoleOutputCP(CP_UTF8);  // Muda a Code Page de saída do Windows para UTF-8
    SetConsoleCP(CP_UTF8);  // Muda a Code Page de entrada do Windows para UTF-8

    char palavra[25];

    printf("Digite uma palavra que começa com j\n");
    fgets(palavra,25,stdin);//absrove a palavra
    palavra[strcspn(palavra, "\n")] = '\0';//isso ser pra não dar bug no strlen, sem isso a palavr gato retornaria 5 carateres
    int total = sizeof(dicionario) / sizeof(dicionario[0]);
    int limite =3 ;

    Resultado resultados[1012];
    int count = 0;

    for (int k = 0; k < total; k++) {
        int dist = tabela(dicionario, palavra, k);

        if (dist <= limite) {
            resultados[count].palavra = dicionario[k];
            resultados[count].distancia = dist;
            count++;
        }
    }

    //Bubble sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (resultados[j].distancia > resultados[j+1].distancia) {

                Resultado temp = resultados[j];
                resultados[j] = resultados[j+1];
                resultados[j+1] = temp;
            }
        }
    }

    printf("Input: %s\n", palavra);

    printf("Sugestões: [ ");

    int maxSugestoes;

    if (count < 10) {
        maxSugestoes = count;
    } else {
        maxSugestoes = 10;
    }

    for (int k = 0; k < maxSugestoes; k++) {
        printf("%s (%d) ", resultados[k].palavra, resultados[k].distancia);
    }
    printf("]");

    return 0;
}
