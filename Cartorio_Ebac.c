#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro ()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale (LC_ALL, "Portuguese");
	
	//Inicio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf ("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf ("%s", cpf); // %s referese a string
	
	strcpy (arquivo, cpf);// responsavel por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen (arquivo, "w");   //cria o arquivo e o "w" significa escrever
	fprintf (file, cpf); //salvo o valor da variavel
	fclose (file); // fecha o arquivo
	
	file = fopen (arquivo, "a");
	fprintf (file, "," );
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	system ("pause");
	
}


 int consultar ()
 {
     setlocale (LC_ALL, "Portuguese");
 	
 	char cpf[40];
 	char conteudo [200];
 	
 	printf ("Digite o CPF a ser consultado: ");
 	scanf ("%s", cpf);
 	
 	FILE *file;
 	file = fopen (cpf,"r"); // o "r" significa ler
 	
 	if(file == NULL) // if � uma condicional (se) , == � o mesmo que , NULL � nulo
 	{
 		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!");
 		printf ("\n\n");
	 }
	 
	 while (fgets(conteudo, 200, file) != NULL) // while � uma condicional ( enquanto)
	 {
	 	printf ("\n Essas s�o as informa��es do usu�rio: ");
	 	printf ("%s", conteudo);
	 	printf ("\n\n");
	 }
	  
	  system ("pause");
 }

int deletar ()
{
	char cpf [40];
	
	printf (" Digite o n�mero de CPF a ser deletado: ");
	scanf ("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL );
	{
		printf ("O usu�rio n�o se encontra no sitema!\n");
		system ("pause");
	}
}

int main ()
{
	  int opcao=0;//Definindo vari�veis
	  int laco=1;
	  
	  for (laco=1;laco=1;)
	  {
	  
	     system ("cls"); // respons�vel por limpar a tela
	
	     setlocale (LC_ALL, "Portuguese");//Definindo a linguagem
	   
	      printf ("### Cart�rio da Ebac ### \n\n");// Inicio do menu
	      printf ("Escolha a op��o desejada do menu: \n\n");
	      printf ("\t1 - Registrar nomes\n");
	      printf ("\t2 - Consultar nomes\n");
	      printf ("\t3 - Deletar nomes\n\n");
	      printf ("Op��o:  ");// Final do menu
	   
	   scanf ("%d", &opcao);// armazenando a escolha do usu�rio
	   
	   system ("cls");
	   
	   
	     switch (opcao) // inicio da sele��o do menu
	     {
	     	case 1:
	     		registro(); // chamada de fun��es
	            break;
	             
	        case 2:
	            consultar ();
	            break;
	             
	        case 3:
	            deletar ();
	  	        break;
	  	                  
	  	    default:
	  	    	printf ("Essa op��o n�o est� dispon�vel!\n");
	  	        system ("pause");
	  	        break;
		 }
	   
	     
	 }
}
