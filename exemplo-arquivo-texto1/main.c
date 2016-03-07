#include <stdio.h>
#include <stdlib.h>

#define SIZE_TEXT 256
b
FILE * abrir_arquivo(char arq_name[], char arq_mode[]){
        FILE * arq;

        if(arq = fopen(arq_name,arq_mode)){
                return arq;
        }else{
            printf("Erro ao abrir o arquivo");
            return NULL;
        }
}

void ler_texto(char texto[]){
    printf("Digite um texto/frase de ate %d caracteres\n:",SIZE_TEXT);
    fscanf(stdin,"%[^\n]s",texto);
}

void gravar_arquivo(char arq_name[]){
    FILE * arq;
    char texto[SIZE_TEXT+1];

    arq = abrir_arquivo(arq_name,"r+");

    if(arq != NULL){
        ler_texto(texto);

        fputs(texto,arq);

        fclose(arq);
    }

}


void imprime_arquivo(char arq_name[]){
    FILE * arq;
    char ch;

    arq = abrir_arquivo(arq_name,"r+");

    if(arq != NULL){
        printf("\n\n------------------------------------------\n\n");

        fseek(arq,0,SEEK_SET);

        ch = fgetc(arq);

        while(!feof(arq)){
            putchar(ch);
            ch = fgetc(arq);

        }

        printf("\n\n------------------------------------------\n\n");
        fclose(arq);
    }
}



int main()
{

    imprime_arquivo("arquivo2.txt");

    gravar_arquivo("arquivo2.txt");

    imprime_arquivo("arquivo2.txt");



    return 0;
}
