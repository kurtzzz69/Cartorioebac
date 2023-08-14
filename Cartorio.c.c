#include<stdio.h>// biblioteca de comunica��o com o us�ario 
#include<stdlib.h>// biblioteca de aloca��o de espa�o em mem�ria 
#include<locale.h>// biblioteca de texto por regi�o 
#include<string.h>// biblioteca respons�vel por cuidar das strings

int registro() // respons�vel por cadastrar usu�rios no sistema 
{
	// inicio cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final da cria��o de vari�veis/string
	
	printf ("Digite o CPF a ser cadastrado:");// coletando informa��es do usu�rio
	scanf ("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores do string 
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, "\nCPF:"); 
	fprintf(file,cpf); // salva o valor da vari�vel
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n");
	}
   
    printf("\nEssas s�o as informa��es do usu�rio:\n");

		while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf(" Digite o CPF do usu�rio a ser deletado : ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado\n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		fclose(file);
		remove(cpf);
		printf(" Usu�rio deletado : \n");
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
				 
		printf("### Cart�rio da EBAC ###\n\n");  // Inicio do menu
       	printf("Escolha a op��o desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Op��o :"); // fim do menu
                  
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio 
                  
        system ("cls");// respons�vel por limpar a tela 
                  
        switch(opcao)
        {
		
        	case 1:
			registro();// chamada de fun��o 
			break;

        	case 2:
			consulta();
			break;
					  
			case 3:
			deletar();
			break;
					  
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}//fim da sele��o
		
	}	
			     
}
