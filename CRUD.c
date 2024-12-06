#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct{
char nome[25];
char email[20];
char telefone[9];
char matricula[8];
char curso[30];
}aluno;


int main()
{
    int aux=0, samp;
    aluno estudante[30];
    bool sair = false;
    do{
    int sel;
    printf("\n Opcao: ");
    scanf("%d", &sel);
    fflush(stdin);
    switch(sel){
    case 1:
    cadastro(&estudante[aux], aux);
    aux++;
    break;
    case 2:
    samp = 0;
    printf("\nQual aluno vc quer listar ?: ");
    scanf("%d",&samp);
    printf("NOME: %s\n email: %s\n telefone: %s\n matricula: %s\n curso: %s",estudante[samp].nome, estudante[samp].email, estudante[samp].telefone,estudante[samp].matricula, estudante[samp].curso);
    break;
    case 3:
    printf("\nObrigado e volte sempre\n");
    sair = true;
    break;
    }}while(sair != true);


    return 0;
}
void show(){

    printf("===================================================\n");
    printf("===========SISTEMA DE CADASTRO DE ALUNOS===========\n");
    printf("===================================================\n");
    printf(" ANTONIO CREPALDI 21012485 ========================\n");
    printf("===================================================\n");
}
void cadastro(aluno* a, int i){
    printf("\n Cadastro do aluno %d\n",i);
    printf("\nDigite o nome: \n");
    fflush(stdin);
    gets(a->nome);

    printf("\nEmail: \n");
    fflush(stdin);
    gets(a->email);

    printf("\nTelefone: \n");
    fflush(stdin);
    gets(a->telefone);

    printf("\nTelefone: \n");
    fflush(stdin);
    gets(a->telefone);

    printf("\nRA: \n");
    fflush(stdin);
    gets(a->matricula);

    printf("\n Curso: \n");
    fflush(stdin);
    gets(a->telefone);

    printf("\nCADASTRO CONCLUIDO =D\n");
 }

