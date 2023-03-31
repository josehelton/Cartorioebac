 #include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digitar o CPF a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //%s refere-se a strings
	
	strcpy(arquivo, cpf);  //copiar valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);  //salvar valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma v�rgula ap�s inserir o cpf
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", nome);  //%s serve para coletar a strings
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, nome);  //salvar valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma v�rgula ap�s o nome
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informa��es do usu�rio
	scanf("%s", sobrenome);  //%s refere-se a strings
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, sobrenome);  //salvar valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma v�rgula ap�s o sobrenome
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informa��es do usu�rio
	scanf("%s", cargo);  //%s refere-se a strings
	
	file = fopen(arquivo, "a");  //file � a inst�ncia da fun��o FILE, fopen � a fun��o de abrir o arquivo e "a" significa atualizar
	fprintf(file, cargo);  //salvar valor da vari�vel
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa a tela
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
	//cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: ");  //comando em texto informando usu�rio para inserir cpf a ser consultado
	scanf("%s", cpf);  //%s refere-se a strings
	
	FILE *file;  //inst�ncia do arquivo
	file = fopen(cpf, "r");  //abre o arquivo e "r" significa read
	
	if(file == NULL)  //se o arquivo for NULO, apresenta a frase do printf
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado.\n");  //frase a ser apresentada caso o arquivo seja nulo
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //enquando o arquivo for diferente de nulo, s�o apresentados os dados a seguir
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");  //mensagem apresentada na tela
		printf("%s", conteudo);  //%s refere-se a string conte�do
		printf("\n\n");  //apenas para quebrar linhas
		
	}
	
	system("pause");  //pausa o sistema na tela
	
	
}

int deletar()  //fun��o de deletar
{
	
	char cpf[40];  //vari�vel
	printf("Digite o cpf do usu�rio a ser deletado: ");  //mensagem
	scanf("%s", cpf);  //%s refere-se a string
	
	remove(cpf);  //remove o cpf cadastrado
	
	FILE *file;  //inst�ncia de abrir o arquivo
	file = fopen(cpf, "r");  //abrindo o arquivo e lendo o arquivo aberto
	
	if(file == NULL)  //se o arquivo for NULO, apresenta a mensagem a seguir
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");  //mensagem apresentada em caso de arquivo nulo
		system("pause");  // pausa no sistema na tela
	}
	else  //mensagem caso o usu�rio seja deletado do sistema
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
}

int main()  //fun��o principal
{
	
	int opcao=0;  //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");  //in�cio do menu
		printf("Escolha a op��o desejado do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");	  
		printf("\t4 - Sair do sistema\n\n");//final do menu
		printf("Op��o:  ");
	
		scanf("%d", &opcao);  //armazenando escolha do usu�rio
	
		system("cls");  //limpar a tela
		
		
		switch(opcao)  //op��es que o usu�rio pode escolher
		{
			case 1:  //chama a fun��o registro
			registro();
			break;
			
			case 2:  //chama a fun��o consulta
			consulta();
			break;
			
			case 3:  //chama a fun��o deletar
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:  //se colocar outro n�mero diferente, apresenta a mensagem de op��o n�o dispon�vel
			printf("Op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
		
	}
}
