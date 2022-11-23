#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

/*===============================================================*/
/*Sistema de cadastro de pacientes diagnosticados com Covid-19*/
/*===============================================================*/

/*===============================================================*/

/*Ap�s o cadastro, o sistema dever� calcular a idade e
verificar se o paciente possui alguma comorbidade e
se pertence ao grupo de risco (maiores de 65 anos).
Caso o paciente perten�a ao grupo de risco,
o sistema dever� salvar em um arquivo de texto: o cep e a idade do paciente
para que essa informa��o possa ser enviada para a central da Secretaria da Sa�de da cidade

/*===============================================================*/

/*=================================================================================*/
// struct de registro de Data
/*=================================================================================*/
typedef struct
{

    int dia;
    int mes;
    int ano;
} rgData;

/*=================================================================================*/
// fun��o do tipo rgData para entrada de dados
/*=================================================================================*/
rgData entrada(char msg[])
{
    rgData dt;
    printf("%s (dd/mm/aaaa): ", msg );
    scanf("%d/%d/%d", &dt.dia, &dt.mes, &dt.ano);

    return(dt);
}

/*=================================================================================*/
// fun��o que calcula idade
/*=================================================================================*/
int calculaIdade(rgData nasc, rgData hoje)
{
    int idade;
    idade = hoje.ano - nasc.ano;
    if((hoje.mes < nasc.mes) || ((hoje.mes == nasc.mes) && (hoje.dia < nasc.dia)))
        idade = idade - 1;

    return (idade);
}

/*=================================================================================*/
// struct endere�o
/*=================================================================================*/

typedef struct {
	char rua;
	int numero;
	char bairro;
	char cidade;
	char estado;
}endereco;

/*=================================================================================*/
// m�todo de endere�o completo
/*=================================================================================*/
endereco endCompleto(){

    endereco dados;
    char rua, bairro, cidade, estado;
	int numero;
	fflush(stdin);
    printf("Rua: ");
    scanf("%s", &dados.rua);
    fflush(stdin);
    printf("\n Informe o numero: \n");
    scanf("%i", &dados.numero);
    fflush(stdin);
   printf("\n Informe o bairro: \n");
   	scanf("%s", &dados.bairro);
   	fflush(stdin);
    printf("\n Informe a cidade: \n");
    scanf("%s", &dados.cidade);
    fflush(stdin);
    printf("\n Informe o estado: \n");
    scanf("%s", &dados.estado);
    fflush(stdin);

    return dados;
}
/*=================================================================================*/
// struct Paciente
/*=================================================================================*/
typedef struct Paciente // tipo de dados
{
    char nome[30]; // n deu pra definir o array porque o m�todo fopen() n�o est� aceitando
    char cpf[11];
    char telefone [11];
    rgData niver;
    char email[20];
    char cep[9];
    endereco enderCompl;
    char comorbidade;
    //time_t dataDiagnostico; // verificar a fun��o
};

/*=================================================================================*/
// fun��o para cadastro de paciente
/*=================================================================================*/
void cadastrarPaciente(){
    FILE *arquivo;

    char opcao;

    struct Paciente paciente;

    printf("Nome do paciente: ");
    scanf("%s",&paciente.nome);

    if (arquivo == NULL)
    {

        printf("Arquivo n�o encontrado");
    }
    else
    {

        system("cls");
        printf("\n  #=============================================================================================#");
        printf("\n  |                                         CADASTRO DE PACIENTE                                |");
        printf("\n  #=============================================================================================#\n");

        arquivo = fopen(&paciente.nome, "w"); // nomeia o arquivo

        fflush(stdin);
        printf("\nDigite o cpf do paciente: ");
        scanf("%s", &paciente.cpf);
        fflush(stdin);
        printf("Informe o telefone:");
        scanf("%s", &paciente.telefone);
        fflush(stdin);

        printf("\nInforme a data de nascimento: \n");
        printf("\n > Formato: ++/++/++++ \n\n > Nascimento: ");
        scanf("%s", &paciente.niver);

        printf("\nInforme o email: \n");
        scanf("%s", &paciente.email);

        printf("\nInforme o CEP: \n");
        printf("\n > Formato: *****-*** \n\n > CEP: ");
        scanf("%s", &paciente.cep);

	/*	printf("\nInforme o endere�o Completo: \n");
        endCompleto();
*/
		int opc;
      	char msg;
    	bool comorbidade = true;
        printf("\nO paciente possui comorbidade? (1. Sim / 2. N�o)\n");
        scanf("%i", &opc);
        if(opc == 1){
        printf("\nInforme a comorbidade\n");
	   	scanf("%s", &msg);
        }
        else{
            printf("\nO paciente n�o possui comorbidade.\n");
            comorbidade = false;
        }

        printf("\n  |       Nome      ---------- : %s", &paciente.nome);
        printf("\n  |       CPF       ---------- : %s", &paciente.cpf);
        printf("\n  |       Telefone  ---------- : %s", &paciente.telefone);
        printf("\n  |       DataNasc  ---------- : %s", &paciente.niver);
        printf("\n  |       Email     ---------- : %s", &paciente.email);
        printf("\n  |       CEP       ---------- : %s", &paciente.cep);


        rgData dtNasc, dtDiagnostico;
        if((comorbidade = false) && (calculaIdade(dtNasc, dtDiagnostico) <65)){

        printf("\nO paciente N�O pertence ao grupo de risco.\n");

        fclose(arquivo);
        return 0;
        }else{

        fprintf(arquivo, "\n    #==================== Dados do paciente ====================#");
        /*fprintf(arquivo, "\n    |       Nome      ---------- : %s", &paciente.nome);
        fprintf(arquivo, "\n    |       CPF       ---------- : %s", &paciente.cpf);
        fprintf(arquivo, "\n    |       Telefone  ---------- : %s", &paciente.telefone);
        fprintf(arquivo, "\n    |       DataNasc  ---------- : %s", &paciente.niver);
        fprintf(arquivo, "\n    |       Email     ---------- : %s", &paciente.email); */
        fprintf(arquivo, "\n    |       CEP       ---------- : %s", &paciente.cep);

        dtDiagnostico = entrada("\n\nPara confirmar, insira a data do diagn�stico:   \n\n");
        dtNasc = entrada("Data de nascimento: ");
        fprintf(arquivo, "\n    |       Idade do paciente -- : %d.", calculaIdade(dtNasc, dtDiagnostico));

        fprintf(arquivo, "\n    #========================================================#");
			}

        fclose(arquivo);
         return 0;
    }

}

/*===============================================================*/
/*Colaborador: Dev Rafael*/
/*===============================================================*/
typedef struct
{
    char login[30]; // vetor login da struct pessoa

    char senha[30]; // vetor senha da struct pessoa

} pessoa;
pessoa p[1]; // diminuindo o nome da struct para "p" e o "[1]" � o m�ximo de pessoas com logins e senhas


int main()
{
    setlocale(LC_ALL, "portuguese");


    /*===============================================================*/
    /*Colaborador: Dev Rafael*/
    /*===============================================================*/



printf("Bem vindo ao sistema!\n\n\n");

        char login[30]; // respons�vel por armazenar a senha inserida pelo usu�rio

        char senha[30]; // respons�vel por armazenar a senha inserida pelo usu�rio

        strcpy(p[0].login, "UNIP");

        strcpy(p[0].senha, "123456");

        printf("\n===============================================================\n");
        printf("login:");
        scanf("%s", login); // armazenando os dados inseridos pelo usu�rio para o vetor login que est� dentro da fun��o main
        printf("\n===============================================================\n");
        printf("senha:");
        scanf("%s", senha); // armazenando os dados inseridos pelo usu�rio para o vetor senha que est� dentro da fun��o main
        printf("\n===============================================================\n");
        if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0))  // A fun��o strcmp � respons�vel por comparar string com string
        {

            printf("Usu�rio logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da fun��o main, usu�rio ser� logado.


        }
        else
        {

            printf("Login e/ou senha incorretos"); // sen�o, login ou senha incorreta.

        }


        /*===============================================================*/


    bool continua = true;

    do
    {

        system("cls");
        printf("\n  #====================   Sistema para cadastro de pacientes com COVID-19   ====================#");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                       Menu Principal                                        |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |           1 - Cadastrar                                                                     |");
        printf("\n  |           0 - Sair                                                                          |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |           PIM IV - Universidade Paulista                                                    |");
        printf("\n  |                                                                                             |");
        printf("\n  |                                                                                             |");
        printf("\n  |           Gerente de Projetos:        Ricardo Bastos Dominguez       RA: 0606660            |");
        printf("\n  |           Eng� de Software:           Daniel Lincoln M. F. Silva     RA: 0616297            |");
        printf("\n  |           Arq� de Software:           Henrique Alves de Lima         RA: 0612163            |");
        printf("\n  |           Analista de Requisitos:     Gabriel Tavares Lopes          RA: 0610868            |");
        printf("\n  |           Desenvolvedor:              Rafael de Assis Oliveira       RA: 0600717            |");
        printf("\n  |           Desenvolvedor:              Daniel Lincoln M. F. Silva     RA: 0616297            |");
        printf("\n  |                                                                                             |");
        printf("\n  #=============================================================================================#\n");

        int opcao;
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:

            cadastrarPaciente();

            break;

        case 0:
            printf("Sistema encerrado");
            break;

        default:
            printf("Op��o inv�lida! Tente novamente");

        }

    }
    while(continua = false);

    return 0;
}
