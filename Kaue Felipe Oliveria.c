#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>

char usuario[100][30], senha[100][30], nome[100][30], funcao[100][100], horario[100][10], horario2[100][10], uso[50], vf='N', voluntario[100][30], consumidor[100][30], fmor[100][30], vfunc[100][30], vhr[100][6], planta[100][30], data[100][10], data2[100][10], chr[100][6], contato[100][30], pedido[100][30], endpedido[100][30];
int escolha, admcont=1, i=0, max=29, c, tf, m, contmo, fm, contv, contc, plantacont, horacont, hora2cont, datacont, data2cont;
void menu(void), admin(void), menuadm(void), lxmem(void), moradorv(void), moradorc(void);

int main()
{
	menu();
	return 0;
}

void menu() // Menu principal
{
	do
	{
		setlocale(LC_ALL,"");
	    printf("Seja bem-vindo a aplicação do controle da plantação!\n");
	    printf("====================================================\n");
	    printf("Digite a opcao desejada\n");
	    printf("[1] - Cadastro do morador voluntario\n");
	    printf("[2] - Cadastro do morador consumidor\n");
	    printf("[3] - Modo de admnistrador(Cadastro de horarios para a horta, novos \nprodutos e cadastro de novos admnistaradores\n");
	    printf("[4] - Finalizar\n\n");
	    scanf("%d", &escolha);
	    fgetc(stdin);
	    
	    switch(escolha)
		{
	        case 1:
	        	moradorv();
	            break;
	        
	        case 2:
	        	moradorc();
	            break;
	        
	        case 3:
	            admin();
	            break;
	        
	        case 4:
	        	printf("\n\n\n====================================================\n");
	        	printf("Tchau :)\n\n");
	            return 0;
	            break;
	        
	        default:
	            system("cls");
	            printf("OPÇÃO NÃO ENCONTRADA NO SISTEMA!!!\n\n\n");
	            break;
	        }
					    
	}while(escolha!=4);
	return 0;
}

void moradorv(void) // Cadastro de morador voluntario e o informe de todos os seus respectivos dados
{	
	printf("Informe o nome do morador a se voluntariar\n");
	lxmem(); strcpy(voluntario[contv], uso);
	printf("Qual funcao deseja ser atribuido(a)?\n");
	printf("[1] - Plantação\n");
	printf("[2] - Irrigação\n");
    printf("[3] - Colheita\n");
    printf("[4] - Distribuição\n\n");
	scanf("%d", &escolha);
	fgetc(stdin);
    contv++;
    
    switch(escolha)
    {
        case 1:
        	vfunc[contv]=="Plantacao";
        	printf("Digite a opcao de data desejada\n");
	
			for(i=0;i<datacont;i++)
			{
				printf("[%d] - %s\n", i+1, data[i]);
			}	
			scanf("%d", &escolha);
			fgetc(stdin);
			escolha--;
			strcpy(vhr[contv], data[escolha]);
			fflush(stdin);
            break;
        
        case 2:
        	vfunc[contv]=="Irrigacao";
        	printf("Digite a opcao do horario desejado\n");
	
			for(i=0;i<horacont;i++)
			{
				printf("[%d] - %s\n", i+1, horario[i]);
			}	
			scanf("%d", &escolha);
			fgetc(stdin);
			escolha--;
			strcpy(vhr[contv], horario[escolha]);
			fgetc(stdin);
			fflush(stdin);	
            break;
        
        case 3:
        	vfunc[contv]=="Colheita";
        	printf("Digite a opcao do horario desejado\n");
	
			for(i=0;i<hora2cont;i++)
			{
				printf("[%d] - %s\n", i+1, horario2[i]);
			}	
			scanf("%d", &escolha);
			fgetc(stdin);
			escolha--;
			strcpy(vhr[contv], horario2[escolha]);
			fflush(stdin);
            break;
        
        case 4:
        	vfunc[contv]=="Distribuicao";
        	printf("Digite a opcao de data desejada\n");
	
			for(i=0;i<data2cont;i++)
			{
				printf("[%d] - %s\n", i+1, data2[i]);
			}	
			scanf("%d", &escolha);
			fgetc(stdin);
			escolha--;
			strcpy(vhr[contv], data2[escolha]);
			fflush(stdin);
            break;
        
        default:
            system("cls");
            printf("OPÇÃO NÃO ENCONTRADA NO SISTEMA!!!\n\n\n");
            main();
            break;
    }
		
	for(i=3;i>=1;i--)
    {
		system("cls");  
        printf("Cadastro realizado com sucesso, voltando ao menu em %d", i);
        sleep(1);
    }
    system("cls");  
	main();	
}

void moradorc(void) // Cadastro do morador consumidor e o informe de todos os seus respectivos dados
{    
	printf("Informe o nome do morador a solicitar o produto\n");
	lxmem(); strcpy(consumidor[contv], uso);
	printf("\nInforme o produto a ser solicitado\n");
	contc++;
	
	for(i=0;i<plantacont;i++)
	{
		printf("[%d] - %s\n", (i+1), planta[i]);	
	}
	scanf("%d", &escolha);
	printf("Informe o endereco de entrega\n");
	lxmem(); strcpy(endpedido[contc], uso);
	fgetc(stdin);
	
	for(i=3;i>=1;i--)
    {
		system("cls");  
        printf("Cadastro realizado com sucesso, voltando ao menu em %d", i);
        sleep(1);
    }
    system("cls");  
	main();	
}

void admin(void) //Registro do primeiro admnistrador e sistema de login 
{    
	system("cls");
	setlocale(LC_ALL,"");
	
    if(vf=='N')
    {
    	vf='S';
        printf("Insira o nome de usuario do primeiro admnistrador:\n");
        lxmem(); strcpy(usuario[1], uso);
        printf("\nInsira a senha do primeiro admnistrador:\n");
        lxmem(); strcpy(senha[1], uso);
    }
    system("cls");
    printf("Insira o seu nome de usuario:\n");
    lxmem(); strcpy(usuario[0], uso);
    printf("\nInsira a sua senha:\n");
    lxmem(); strcpy(senha[0], uso);
    
    for(i=1;i<100;i++)
    {
        
        if((strncmp(senha[0], senha[i], 29)==0) && (strncmp(usuario[0], usuario[i], 29)==0))
        {
        	menuadm();
            break; 
        }
    }
	system("cls");  
    printf("REGISTRO INEXISTENTE NO SISTEMA\n\n");
    sleep(2);
    main(); 
}

void menuadm(void) //Menu do admnistrador, onde se haverá o gerenciamento e monitoramento da aplicação por admnistradores ja cadastrados
{
	setlocale(LC_ALL,"");
    system("cls");
    printf("Digite a opcao desejada\n");
    printf("[1] - Cadastro de horario para irrigação\n");   
    printf("[2] - Cadastro de sementes/plantas\n");
    printf("[3] - Cadastro de data  para a plantação\n");
    printf("[4] - Cadastro de data  para a distribuição\n");
    printf("[5] - Cadastro de novo admnistrador\n");
    printf("[6] - Cadastro de horario para colheita\n");
    printf("[7] - Voltar ao menu\n");
    scanf("%d", &escolha);
    fgetc(stdin);
    
    switch(escolha)
    {
        case 1:    	
        	printf("Digite um horario a ser cadastrado\n");
        	lxmem(); strcpy(horario[horacont], uso);
        	horacont++;
        	menuadm();
            break;
            
        case 2:        	
        	printf("Informe a planta a ser cadastrada\n");
        	lxmem(); strcpy(planta[plantacont], uso);
        	plantacont++;
        	menuadm();
            break;
        
        case 3:            
            printf("Informe a data a ser cadastrada\n");
        	lxmem(); strcpy(data[datacont], uso);
        	datacont++;
        	menuadm();
            break;
        
        case 4:
        	printf("Informe a data a ser cadastrada\n");
        	lxmem(); strcpy(data2[data2cont], uso);
        	data2cont++;
        	menuadm();
            break;
        		
			
        case 5:
            printf("REGISTRO DE ADMNISTRADOR\n");
            printf("Escolha um nome de usuario:\n");
            lxmem(); strcpy(usuario[admcont], uso);
            printf("\nEscolha uma senha:");
            lxmem(); strcpy(senha[admcont], uso);
            admcont++;
            menuadm();
            break;
              
        case 6:
            printf("Digite um horario a ser cadastrado\n");
        	lxmem(); strcpy(horario2[hora2cont], uso);
        	hora2cont++;
        	menuadm();
            break;
            
        case 7:
	        menu();
	        break;
        
        default:
            system("cls");
            printf("OPÇÃO NÃO ENCONTRADA NO SISTEMA!!!\n\n\n");
            menuadm();
            break;
    }
}

void lxmem(void) //Apago de lixo de memoria (devido a falta de segurança e estabilidade do uso da função gets, utilizei a função fgets, e esse void é responsável por ler as strings e apagar qualquer traco de memoria/buffer existente)
{				 
  setlocale(LC_ALL,"");
  char string[29];
  fgets(string, 29, stdin);
  int length = strlen(string);
  string[strlen(string) - 1] = '\0';
  strcpy(uso, string);
}
