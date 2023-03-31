 #include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //função responsável por cadastrar os usuários no sistema
{
	
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digitar o CPF a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", cpf);  //%s refere-se a strings
	
	strcpy(arquivo, cpf);  //copiar valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);  //salvar valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma vírgula após inserir o cpf
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", nome);  //%s serve para coletar a strings
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, nome);  //salvar valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma vírgula após o nome
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informações do usuário
	scanf("%s", sobrenome);  //%s refere-se a strings
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, sobrenome);  //salvar valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, ",");  //colaca uma vírgula após o sobrenome
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informações do usuário
	scanf("%s", cargo);  //%s refere-se a strings
	
	file = fopen(arquivo, "a");  //file é a instância da função FILE, fopen é a função de abrir o arquivo e "a" significa atualizar
	fprintf(file, cargo);  //salvar valor da variável
	fclose(file);  //fecha o arquivo
	
	system("pause");  //pausa a tela
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
	//criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser consultado: ");  //comando em texto informando usuário para inserir cpf a ser consultado
	scanf("%s", cpf);  //%s refere-se a strings
	
	FILE *file;  //instância do arquivo
	file = fopen(cpf, "r");  //abre o arquivo e "r" significa read
	
	if(file == NULL)  //se o arquivo for NULO, apresenta a frase do printf
	{
		printf("Não foi possível abrir o arquivo. Arquivo não localizado.\n");  //frase a ser apresentada caso o arquivo seja nulo
	}
	
	while(fgets(conteudo, 200, file) != NULL)  //enquando o arquivo for diferente de nulo, são apresentados os dados a seguir
	{
		printf("\nEssas são as informações do usuário: ");  //mensagem apresentada na tela
		printf("%s", conteudo);  //%s refere-se a string conteúdo
		printf("\n\n");  //apenas para quebrar linhas
		
	}
	
	system("pause");  //pausa o sistema na tela
	
	
}

int deletar()  //função de deletar
{
	
	char cpf[40];  //variável
	printf("Digite o cpf do usuário a ser deletado: ");  //mensagem
	scanf("%s", cpf);  //%s refere-se a string
	
	remove(cpf);  //remove o cpf cadastrado
	
	FILE *file;  //instância de abrir o arquivo
	file = fopen(cpf, "r");  //abrindo o arquivo e lendo o arquivo aberto
	
	if(file == NULL)  //se o arquivo for NULO, apresenta a mensagem a seguir
	{
		printf("O usuário não se encontra no sistema!.\n");  //mensagem apresentada em caso de arquivo nulo
		system("pause");  // pausa no sistema na tela
	}
	else  //mensagem caso o usuário seja deletado do sistema
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
}

int main()  //função principal
{
	
	int opcao=0;  //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");  //definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n");  //início do menu
		printf("Escolha a opção desejado do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");	  
		printf("\t4 - Sair do sistema\n\n");//final do menu
		printf("Opção:  ");
	
		scanf("%d", &opcao);  //armazenando escolha do usuário
	
		system("cls");  //limpar a tela
		
		
		switch(opcao)  //opções que o usuário pode escolher
		{
			case 1:  //chama a função registro
			registro();
			break;
			
			case 2:  //chama a função consulta
			consulta();
			break;
			
			case 3:  //chama a função deletar
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:  //se colocar outro número diferente, apresenta a mensagem de opção não disponível
			printf("Opção não está disponível!\n");
			system("pause");
			break;
		}
		
	}
}
