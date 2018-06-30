#include <stdlib.h>
#include <stdio.h>
#define tam 100

int tamPalavra(char *palavra){
	int i, cont=0;
	for(i=0; palavra[i]!='\0' && palavra[i]!='\n'; i++){
		cont++;
	}
	return cont;
}

void subpalavra(char *palavra, char *sub){
	printf("\n***********************************************\n");
	printf("\tSUBPALAVRA\n");
	int i, j, q=0,aux;

	q=0;
	for(i=0; i<tamPalavra(palavra); i++){
		if(q==-2){ //ja achou subpalavra entao o estado eh qf, e qf agora pode aceitar qualquer coisa e continuar nele mesmo
			printf("\n[Qf - %c] -> [Qf]", palavra[i]);
		}
		else if(q==-1){//ja passou a subpalavra e a palavra inteira entao ja pode quebrar o for
			break;
		}
		else if(palavra[i]!=sub[0]){
			printf("\n[Q0 - %c] -> [Q0]", palavra[i]);
		}else if(palavra[i]==sub[0]){
			aux = i;
			for(j=0; j<tamPalavra(sub); j++){
				if(palavra[aux]==sub[j]){

					if((sub[j+1]=='\n')&&(palavra[aux+1]=='\n')){
						printf("\n[Q%d - %c] -> [Qf]", q, palavra[aux]);
						q=-1;
            break;
					}else if((sub[j+1]=='\n')&&palavra[aux+1]!='\n'){
            printf("\n[Q%d - %c] -> [Qf]", q, palavra[aux]);
						i=aux;
						q=-2;
						break;
					}
					printf("\n[Q%d - %c] -> [Q%d]", q, palavra[aux],q+1);
					q++;
          aux++;

				}
        else{
          if(palavra[aux]=='\n'){
            break;
          }else{
          printf("\n[Q%d - %c] -> [Q0]", q, palavra[aux]);
          q=0;
          //i=aux;
          break;}
        }
			}
		}
	}

	if(q<0) printf("\nPalavra aceita! Subpalavra encontrada!\n", sub);
	else{
		printf("\nPalavra nao aceita! Subpalavra nao encontrada!\n", sub);	}
		printf("\n***********************************************\n");

}

void sufixo(char *palavra, char *sub){
	printf("\n***********************************************\n");
	printf("\tSUFIXO\n");
	int i,j,q=0,aux;

	for(i=0; i<tamPalavra(palavra); i++){
		if(q==-1){
			break;
		}
		else if(palavra[i]!=sub[0]){
			printf("\n[Q0 - %c] -> [Q0]", palavra[i]);	
		}else if(palavra[i]==sub[0]){
			aux = i;
			for(j=0; j<tamPalavra(sub); j++){
				if(palavra[aux] == sub[j]){
					if((palavra[aux+1]=='\n')&&(sub[j+1]=='\n')){
						printf("\n[Q%d - %c] -> [Qf]", q, palavra[aux]);
						q=-1;
						break;
					}
					printf("\n[Q%d - %c] -> [Q%d]", q, palavra[aux],q+1);
					q++;
					aux++;
				}else{
					if(palavra[aux] == '\n'){
						q=0;
						break;
					}else{
						printf("\n[Q%d - %c] -> [Q0]", q, palavra[aux]);
						q=0;
						break;
					}
				}
			}
		}
	}
	if(q<0) printf("\nPalavra aceita! Sufixo encontrado!\n");
	else{
		printf("\nPalavra nao aceita! Sufixo nao encontrado!\n");	}
		printf("\n***********************************************\n");
}

void prefixo(char *palavra, char *sub){
	printf("\n***********************************************\n");
	printf("\tPREFIXO\n");
	int i,aux,q=0,salva=0;
	if(palavra[0]==sub[0]){
		aux=0;
		for(i=0; i<tamPalavra(sub); i++){
			if(palavra[aux] == sub[i]){
				if(sub[i+1]=='\n'){
					printf("\n[Q%d - %c] -> [Qf]", q, palavra[aux]);
					q=-1;
					break;
				}
				printf("\n[Q%d - %c] -> [Q%d]", q, palavra[aux],q+1);
				q++;
				aux++;
			}else{
				printf("\n[Q%d - %c] -> [Q0]", q, palavra[aux]);
				q = -2;
				break;
			}
		}
	}else{
		for(i=0; i<tamPalavra(palavra); i++){
			printf("\n[Q0 - %c] -> [Q0]", palavra[i]);
		}
		printf("\nPalavra nao aceita! Prefixo nao encontrado!\n");
	}
	if(q==-2){
		for(i=aux+1;i<tamPalavra(palavra); i++){
			printf("\n[Q0 - %c] -> [Q0]", palavra[i]);
		}
		printf("\nPalavra nao aceita! Prefixo nao encontrado!\n");
	}else if(q==-1){
		if(palavra[aux+1]!='\n'){
			for(i=aux+1; i<tamPalavra(palavra); i++){
				printf("\n[Qf - %c] -> [Qf]", palavra[aux]);
			}
		}
		printf("\nPalavra aceita! Prefixo encontrado!\n");
	}
	printf("\n***********************************************\n");
}

int main(void){
	char palavra[tam];
	char sub[tam];
	int opc=-1;

	while(opc!=0){
	printf("\nDigite a palavra\n");
	fgets(palavra,tam,stdin);
	printf("\nDigite a substring\n");
	fgets(sub,tam,stdin);

	int menu=-1;

	while(menu!=0){
		printf("\n\tDigite o numero da opcao que deseja:\n");
		printf("\n1 - Achar prefixo\n");
		printf("\n2 - Achar sufixo\n");
		printf("\n3 - Achar subpalavra\n");
		printf("\n0 - Sair\n");
		scanf("%d", &menu);
		switch(menu){
			case 1:
			prefixo(palavra,sub);
			break;
			case 2:
			sufixo(palavra,sub);
			break;
			case 3:
			subpalavra(palavra,sub);
			break;
			case 0:
			break;

		}
	}
	printf("\n\nDeseja testar outra palavra? \n1 - Sim\n0- Nao\n");
	scanf("%d", &opc);
	getchar();
	}

	return 0;
}