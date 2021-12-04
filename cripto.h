#ifndef CRIPTO_H
#define CRIPTO_H
#endif // CRIPTO_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char* CesarEncode(char value[200], int key)
{
    char ascii[208];
    char* result = (char *)malloc(strlen(value)*sizeof(char));

    for(int i=0; i<=207; i++)
        ascii[i] = ' ' + i;

    int cont=0; 

    for(int i=0; i< strlen(value); i++)
    {
        for(int j=0; j < sizeof(ascii); j++)
        {
            if(value[i] == ascii[j])
            {
                int aux = j+key;
                while(aux > 207)
                    aux -= 207;
                
                result[cont] = ascii[aux];
                cont++;
            }
        }
    }
    return result;
}

char* CesarDecode(char value[200], int key)
{
    char ascii[208];
    char* result = (char *)malloc(strlen(value)*sizeof(char));

    for(int i=0; i<=207; i++)
        ascii[i] = ' ' + i;

    int cont=0; 
    for(int i=0; i< strlen(value); i++)
    {
        for(int j=0; j < sizeof(ascii); j++)
        {
            if(value[i] == ascii[j])
            {
                int aux = j-key;
                while(aux < 0)
                    aux += 207;
    
                result[cont] = ascii[aux];
                cont++;
            }
        }
    }

    return result;
}

char* CesarEncodeSave(char value[200], int key, char dir[250])
{
    char* result = (char *)malloc(strlen(value)*sizeof(char));
    result = CesarEncode(value, key);
    FILE *arq;
    arq = fopen(dir, "w");
    fprintf(arq, result);
    fclose(arq);
    return result;
}

char* CesarDecodeSave(char value[200], int key, char dir[250])
{
    char* result = (char *)malloc(strlen(value)*sizeof(char));
    result = CesarDecode(value, key);
    FILE *arq;
    arq = fopen(dir, "w");
    fprintf(arq, result);
    fclose(arq);
    return result;
}

char* EncodeFromFile(char dir[250], int key, int debug)
{
    char value[200];
    FILE *arq;
    arq = fopen(dir, "r");
    
    if(arq == NULL)
        if(debug)
        {
            printf("Arquivo nao encontrado.\n");
            return 0;
        }
    fgets(value, 200, arq);
    char* result = (char *)malloc(strlen(value)*sizeof(char));
    result = CesarEncode(value, key);
    fclose(arq);
    return result;

}

char* DecodeFromFile(char dir[250], int key, int debug)
{
    if(debug)
        printf("Iniciando\n");
    char value[200];
    FILE *arq;
    arq = fopen(dir, "r");
    
    if(arq == NULL)
        if(debug)
        {
            printf("Arquivo nao encontrado.\n");
            return 0;
        }

    fgets(value, 200, arq);
    if(debug)
        printf("Valor lido: %s\n", value);
    char* result = (char *)malloc(strlen(value)*sizeof(char));
    result = CesarDecode(value, key);
    fclose(arq);
    return result;
    
}