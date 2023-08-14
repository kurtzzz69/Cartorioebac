#include<stdio.h>// biblioteca de comunicação com o usúario 
#include<stdlib.h>// biblioteca de alocação de espaço em memória 
#include<locale.h>// biblioteca de texto por região 
#include<string.h>// biblioteca responsável por cuidar das strings

int registro() // responsável por cadastrar usuários no sistema 
{
	// inicio criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final da criação de variáveis/string
	
	printf ("Digite o CPF a ser cadastrado:");// coletando informações do usuário
	scanf ("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores do string 
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, "\nCPF:"); 
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\nNOME:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\nSOBRENOME:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado :");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\nCARGO:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado :");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,".\n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! .\n");
	}
   
    printf("\nEssas são as informações do usuário:\n");

		while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf(" Digite o CPF do usuário a ser deletado : ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado\n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		fclose(file);
		remove(cpf);
		printf(" Usuário deletado : \n");
		system("pause");
	}
}

int main()
   {
	
	int opcao=0; // Definindo variaveis 
                  	
	int laco=1;
					
	for(laco=1;laco=1;) 
	{
		system("cls");
					  			  
		setlocale(LC_ALL, "Portuguese");   // Definindo linguagem            
				 
		printf("### Cartório da EBAC ###\n\n");  // Inicio do menu
       	printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Opção :"); // fim do menu
                  
		scanf("%d", &opcao); // Armazenando a escolha do usuário 
                  
        system ("cls");// responsável por limpar a tela 
                  
        switch(opcao)
        {
		
        	case 1:
			registro();// chamada de função 
			break;

        	case 2:
			consulta();
			break;
					  
			case 3:
			deletar();
			break;
					  
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}//fim da seleção
		
	}	
			     
}
