#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define quantidade 999

/*Crie um software com 4 funcionalidades para um sistema de gestão de recursos humanos.*/

// Cadastrar funcionários, demitir funcionários, listar nome dos funcionários, avaliar funcionários, sair do menu

struct funcionarios
{

    char nome[quantidade][101];
    char cargo[quantidade][101];
    float salario[quantidade];
    char rendimento[quantidade][101];
};

void cabecalho()
{
    printf("\n\n========== SISTEMA DE RH ==========\n\n");
    printf("=---------------------------------=\n");
    printf("=   1- Cadastrar Funcionário(a)   =\n");
    printf("=   2- Demitir Funcionário(a)     =\n");
    printf("=   3- Avaliar Funcionário(a)     =\n");
    printf("=   4- Listar os Funcionários(as) =\n");
    printf("=   5- Sair do menu de RH         =\n");
    printf("=---------------------------------=\n\n");
    printf("===================================\n");
};

void limpaTela()
{

    fflush(stdin);
    system("cls || clear");
}

struct funcionarios cadastramento(struct funcionarios cadastroFuncionarios, int contadorCadastro)
{

    fflush(stdin);
    printf("Insira o nome do funcionário:\n");
    gets(cadastroFuncionarios.nome[contadorCadastro]);
    fflush(stdin);

    fflush(stdin);
    printf("Insira o cargo do funcionário:\n");
    gets(cadastroFuncionarios.cargo[contadorCadastro]);
    fflush(stdin);

    printf("Insira o salário do funcionário:\n");
    scanf("%f", &cadastroFuncionarios.salario[contadorCadastro]);

    return cadastroFuncionarios;
}

struct funcionarios demissao(struct funcionarios demissaoFuncionarios)
{
    int i;
    char nomeDemitido[101];

    fflush(stdin);
    printf("Insira o nome do funcionário que queira demitir:\n");
    gets(nomeDemitido);
    fflush(stdin);

    for (i = 0; i < quantidade; i++)
    {
        if (strcmp(nomeDemitido, demissaoFuncionarios.nome[i]) == 0)
        {

            strcpy(demissaoFuncionarios.cargo[i], "Ex-funcionário(a)");
        }
    }

    return demissaoFuncionarios;
}

struct funcionarios avaliacao(struct funcionarios avaliacaoFuncionarios)
{
    int i;
    char nomeAvaliado[101];

    fflush(stdin);
    printf("Insira o nome do funcionário que queira avaliar:\n");
    gets(nomeAvaliado);
    fflush(stdin);

    printf("Avalie entre: Bom, Regular ou Ruim:\n");

    for (i = 0; i < quantidade; i++)
    {
        if (strcmp(avaliacaoFuncionarios.nome[i], nomeAvaliado) == 0)
        {

            fflush(stdin);
            gets(avaliacaoFuncionarios.rendimento[i]);
            fflush(stdin);
        }
    }

    return avaliacaoFuncionarios;
}

void listagem(struct funcionarios listagemFuncionarios, int contadorEmpregados)
{
    int i;

    printf("Lista dos funcionários(as): \n\n");
    for (i = 0; i < contadorEmpregados; i++)
    {
        printf("\nNome do(a) %dº funcionário(a): %s", i + 1, listagemFuncionarios.nome[i]);
        printf("\nCargo do(a) %dº funcionário(a): %s", i + 1, listagemFuncionarios.cargo[i]);
        printf("\nSalário do(a) %dº funcionário(a): R$ %.2f", i + 1, listagemFuncionarios.salario[i]);
        printf("\nRendimento do(a) %dº funcionário(a): %s", i + 1, listagemFuncionarios.rendimento[i]);
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct funcionarios empregados;
    int codigo, contadorFuncionarios = 0;

    do
    {
        cabecalho();

        printf("Insira o item desejado:\n");
        scanf("%d", &codigo);

        switch (codigo)
        {
        case 1:
            empregados = cadastramento(empregados, contadorFuncionarios);
            contadorFuncionarios++;
            break;

        case 2:
            empregados = demissao(empregados);
            break;

        case 3:
            empregados = avaliacao(empregados);
            break;

        case 4:

            listagem(empregados, contadorFuncionarios);
            break;

        case 5:

            break;
        default:
            printf("Código inválido, digite novamente!!\n");
            Sleep(3000);
            limpaTela();

            break;
        }

    } while (codigo != 5);

    return 0;
}
