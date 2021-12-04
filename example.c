#include <stdio.h>
#include <stdio.h>
#include "cripto.h"

int main(){
    int nav;

    while(nav != 7)
    {
        system("cls");
        printf("1. Criptografar Texto\n2. Descriptografar Texto\n3. Criptografar e Salvar\n4. Descriptografar e Salvar\n5. Criptografar a partir de um arquivo\n6. Descriptografar a partir de um arquivo\n7. Sair\nDigite para navegar: ");
        scanf("%d%*c", &nav);

        if(nav == 1)
        {
            char text[200];
            char result[200];
            int key;
            printf("Digite o texto que deseja criptografar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &text);
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            strcpy(result, CesarEncode(text, key));
            printf("Criptografado: %s\n", result);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else if(nav == 2)
        {
            char text[200];
            char result[200];
            int key;
            printf("Digite o texto que deseja descriptografar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &text);
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            strcpy(result, CesarDecode(text, key));
            printf("Descriptografado: %s\n", result);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else if(nav == 3)
        {
            char text[200];
            char result[200];
            char dir[250];
            int key;
            printf("Digite o texto que deseja criptografar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &text);
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            printf("Digite o diretorio com o nome do arquivo que deseja salvar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &dir);
            strcpy(result, CesarEncodeSave(text,key,dir));
            printf("Criptografado: %s\n", result);
            char cmd[260] = "start ";
            strcat(cmd, dir);
            system(cmd);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else if(nav == 4)
        {
            char text[200];
            char result[200];
            char dir[250];
            int key;
            printf("Digite o texto que deseja descriptografar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &text);
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            printf("Digite o diretorio com o nome do arquivo que deseja salvar: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &dir);
            strcpy(result, CesarDecodeSave(text,key,dir));
            printf("Descriptografado: %s\n", result);
            char cmd[260] = "start ";
            strcat(cmd, dir);
            system(cmd);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else if(nav == 5)
        {
            char result[200];
            char dir[250];
            int key;
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            printf("Digite o diretorio com o nome do arquivo: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &dir);
            strcpy(result, EncodeFromFile(dir,key,0));
            printf("Criptografado: %s\n", result);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else if(nav == 6)
        {
            char result[200];
            char dir[250];
            int key;
            printf("Digite a sua chave de criptografia: ");
            scanf("%d%*c", &key);
            printf("Digite o diretorio com o nome do arquivo: ");
            setbuf(stdin,NULL);
            scanf("%199[^\n]", &dir);
            strcpy(result, DecodeFromFile(dir,key,0));
            printf("Descriptografado: %s\n", result);
            printf("Digite para continuar...");
            setbuf(stdin, NULL);
            getchar();
        }
        else
            printf("\nSaindo.");
    }
    return 0;
}