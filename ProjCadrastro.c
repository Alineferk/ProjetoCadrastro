#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct cadastra{
    int codigop,codigof,quantidade;
    char nome[30];
    char gerente[30];
    float preco;
};

struct cadastra cad[MAX];
int quantp=0;

void cadastraProjeto(struct cadastra projeto){
    cad[quantp]=projeto;
    quantp++;
}


struct cadastra leDados(){
    struct cadastra auxiliar;
    srand(time (NULL));
    fflush(stdin);
    printf("Digite o nome do projeto\n");
    scanf("%s",auxiliar.nome);
    auxiliar.codigop = 1 + rand()%100;
    printf("Codigo do projeto %d\n",auxiliar.codigop);
    fflush(stdin);
    printf("Quantide de projetos \n");
    scanf("%d",&auxiliar.quantidade);
    fflush(stdin);
    printf("Nome do gerente\n");
    scanf("%s",auxiliar.gerente);
    auxiliar.codigof = 1 + rand()%100;
    printf("Codigo do gerente %s eh %d\n",auxiliar.gerente, auxiliar.codigof);
    fflush(stdin);
    system("CLS");
return auxiliar;
}
void buscar(){
    int i,opica;
    char nome[30];
        do{
            printf("MENU DE BUSCA\n");
            printf("1- Mostrar lista de projeos\n");
            printf("2- Buscar pelo nome projeto ou pelo nome do gerente\n");;
            printf("3- Sair do menu busca\n");
            printf("Digite o numero da opicao desejada \n");
            scanf("%d",&opica);
            system("CLS");
            switch(opica){
                case 1:
                    printf("Lista de projeto cadastrados\n");
                    for(i=0;i<quantp;i++){
                        printf("Projeto %d \n",i+1);
                        printf("+++++++++++++++++++++++\n");
                        printf("Nome do projeto:       %s\n",cad[i].nome);
                        printf("Codigo do projeto:     %d\n",cad[i].codigop);
                        printf("Quantidade no sistema: %d\n",cad[i].quantidade);
                        printf("Nome do gerente:    %s\n",cad[i].gerente);
                        printf("Codigo do gerente:  %d\n",cad[i].codigof);
                        printf("+++++++++++++++++++++++\n");
                    }
                    break;
                case 2:
                    printf("Digite o nome do projrto ou nome do gerente\n");
                    scanf("%s",&nome);
                    for(i=0;i<quantp;i++){
                        if((strcmp (nome, cad[i].nome) == 0) || strcmp (nome, cad[i].gerente) == 0) {
                            printf("+++++++++++++++++++++++\n");
                            printf("Nome do projeto:       %s\n",cad[i].nome);
                            printf("Codigo do projeto:     %d\n",cad[i].codigop);
                            printf("Quantidade no sistema: %d\n",cad[i].quantidade);
                            printf("Nome do gerente:    %s\n",cad[i].gerente);
                            printf("Codigo do gerenter:  %d\n",cad[i].codigof);
                            printf("+++++++++++++++++++++++\n");
                        }
                    }
                    break;
                case 3:
                    break;
            }
        }while(opica!=3);
        system("CLS");
}
void Afazer (){
    int i;
    char nome[30];
    fflush(stdin);
    printf("Digite o nome do projeto que deseja ver: ");
    scanf("%s",&nome);
    for(i=0;i<quantp;i++){
        if(strcmp (nome, cad[i].nome) == 0){
            fflush(stdin);
            printf("Digite o nome do projeto\n");
            scanf("%s",&cad[i].nome);
            cad[i].codigop = 1 + rand()%10;
            printf("Codigo do projeto %d\n",cad[i].codigop);
            fflush(stdin);
            printf("Quantide de projeto no sistema\n");
            scanf("%d",&cad[i].quantidade);
            fflush(stdin);
            printf("Nome do gerente\n");
            scanf("%s",&cad[i].gerente);
            cad[i].codigof = 1 + rand()%10;
            printf("Codigo do gerente %s eh %d\n",cad[i].gerente, cad[i].codigof);
            fflush(stdin);
        }
    }
    system("CLS");
}
void fazendo(){
    int i;
    char nome[30];
    fflush(stdin);
    printf("Digite o nome do projeto que esta  fazendo: ");
    scanf("%s",&nome);
    for(i=0;i<quantp;i++){
        if(strcmp (nome, cad[i].nome) == 0){
            fflush(stdin);
            printf("Digite o nome do projeto\n");
            scanf("%s",&cad[i].nome);
            cad[i].codigop = 1 + rand()%10;
            printf("Codigo do projeto %d\n",cad[i].codigop);
            fflush(stdin);
            printf("Quantide de projeto no sistema\n");
            scanf("%d",&cad[i].quantidade);
            fflush(stdin);
            printf("Nome do gerente\n");
            scanf("%s",&cad[i].gerente);
            cad[i].codigof = 1 + rand()%10;
            printf("Codigo do gerente %s eh %d\n",cad[i].gerente, cad[i].codigof);

            fflush(stdin);
        }
    }
    system("CLS");
}

void remover () {    			// Função remover
	int i,cont=0;
	int codigo_busc;
	printf("veja numero do projeto que você deseja remover\n");
	buscar();                   // Chama a função listar para que seja visto qual codigo relacionado ao projeto
	printf("Informe o Codigo do Projeto que se Deseja Excluir: "); // Pede o codigo para busca
	scanf("%i",&codigo_busc);
	for(i = 0 ; i < quantp ; i++){

		if (cad[i].codigop == codigo_busc) {  // Compara o codigo relacionado e exclui

			cad[i] = cad[i+1];                // Realoca a Memória

            quantp--;                         // decrementa o indice do vetor para que ocupe o cadastro removido
            cont++;

		}
	}
	if(cont>0){
        printf ("\n\nPROJETO EXCLUIDO COM SUCESSO !");
        printf ("\nPressione ENTER Para Continuar !");
        setbuf(stdin,NULL);
        getchar ();
        system ("cls");
    }else {
        printf("Esse numero de codigo nao existe\n");
    }
}
int main (){
    int opicao;
    struct cadastra novoProjeto;
    do{
        printf("MENU DE OPICAO\n");
        printf("1 - Cadastrar\n");
        printf("2 - buscar\n");
        printf("3 - Afazer\n");
        printf("4 - fazendo\n");
        printf("5 - Remover\n");
        printf("Digite o numero da opcao desejada \n");
        scanf("%d",&opicao);
        system("CLS");
        switch(opicao){
            case 1:
                novoProjeto=leDados();
                cadastraProjeto(novoProjeto);
                break;
            case 2:
                buscar();
                break;
            case 3:
                Afazer();
                break;
            case 4:
                fazendo ();
            case 5:
            	remover();
            	break;
            case 6:
                printf("Obrigado!\n");
                break;
            default:
                printf("Opcao invalida!\nTente novamente:\n");
                break;
        }
    }while(opicao!=5);

system("PAUSE");
return 0;
}