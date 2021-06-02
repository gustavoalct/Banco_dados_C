
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Gustavo Antonio C. de Alcantara */

 #define TAM 100
 
 // necessario ter os arquivos
 
 
typedef struct aluno{
	char nome[30]; // nome aluno
	int codigo;
	int telefone;
}Taluno[TAM];

typedef struct professor{
	char nome[30];
	int codigo ;
	int telefone; 
}Tprof[TAM];

// inicializa
void Inicializa(Taluno aluno, Tprof professor){
	char sub[30] ="";
	for(int i=0; i<TAM;i++){
		strcpy( aluno[i].nome, "");
		//aluno[i].nome = sub;
		aluno[i].codigo=0;
		aluno[i].telefone=0; 
		professor[i].codigo=0;
		strcpy( professor[i].nome, "");
		professor[i].telefone=0;
	}

}
// void iniciar banco 
void mostra(Taluno aluno, Tprof professor){
	char sub[30] ="";
	int tam=0;
	printf("\nAlunos \n");
	for(int i =0; i<TAM;i++){
		if(strcmp(aluno[i].nome, sub) != 0){
			printf("\n nome: %s  Cod: %d  tel: %d ", aluno[i].nome, aluno[i].codigo, aluno[i].telefone);	
		}
		
	}
	printf("\n \n Professores \n");
	//printf("%d", tam); 
	for(int i =0; i<TAM;i++){
		if(strcmp(professor[i].nome, sub) != 0){
			printf("\n nome: %s  Cod: %d  tel: %d ", professor[i].nome, professor[i].codigo, professor[i].telefone);	
		}
		
	}
	
	printf("\n \n ");
	system("pause");
	system("cls");
}


void Inicia(Taluno aluno, Tprof professor){
	int codigo, telefone, i=0;
	char nome[30];
	// le aluno
	FILE *file ;
	file = fopen("alunos.txt", "r"); // r para ler  e W para excrever
	if (file == NULL){
		printf("Arquivo nao encontrado");
		//system(exit(1));
	}else{
		// ler arquivo encontrado
		// for percorrer o nome
		while(!feof(file)){
			//if(!feof(file))
				fscanf(file, "%s %d %d", &aluno[i].nome, &aluno[i].codigo, &aluno[i].telefone );
				i++;
				//fscanf(file, "%s %d %d", &nome,&codigo, &telefone );
				//printf("Nome: %s  \n", aluno.nome);
				}
				
	}	
 	//getchar();	
 	i=0;
 	
 	// le professor
 	
	file = fopen("professor.txt", "r"); // r para ler  e W para excrever
	if (file == NULL){
		printf("Arquivo nao encontrado");
		//system(exit(1));
	}else{
		// ler arquivo encontrado
		// for percorrer o nome
		while(!feof(file)){
			//if(!feof(file))
				fscanf(file, "%s %d %d", &professor[i].nome, &professor[i].codigo, &professor[i].telefone);
				i++;
				//printf("Nome: %s           Codigo: %d\n", aluno.nome, aluno.codigo);
				}
			
	}	
 	//getchar();
	i=0;
	
}

// void insere no banco

void insere(Taluno aluno, Tprof professor, int opcao){
	char sub[30] ="";
	int codigo, telefone;
	char nome[30];
	int tam=0;
	tam = sizeof(struct aluno);
	//printf("alunos: %s ", aluno.nome);
	int op = opcao;
	
	printf("\nDigite o codigo: ");
	scanf("%d", &codigo);
	printf("\nDigite o nome: ");
	scanf("%s", &nome);
	printf("\nDigite o telefone: ");
	scanf("%d",&telefone);
	printf("\n");
	system("cls");
	
	
	
	// if veriricar qual tabela pertence
	if(opcao == 1){ // tabela aluno
		
		for(int i=0; i<TAM;i++ ){
			if(strcmp(aluno[i].nome, sub) == 0){ // so deixa inserir em lugar vazzio
				strcpy( aluno[i].nome, nome);
				aluno[i].codigo = codigo;
				aluno[i].telefone=telefone;
				i=TAM; // para o laço
			}
		}
		
	}else if(opcao == 2) { // tabela professor  
			for(int i=0; i<TAM;i++ ){
			if(strcmp(professor[i].nome, sub) == 0){ // so deixa inserir em lugar vazio
				strcpy( professor[i].nome, nome);
				professor[i].codigo = codigo;
				professor[i].telefone = telefone;
				i=TAM; // para o laço
			}
		}
	}
	
	// chamar funcao atualizar arquivo
	//AtualizaArquivo( op );	

		
}

void excluir (Taluno aluno, Tprof professor, int opcao){
	char sub[30] ="";
	int cod=0,cont=0;
	printf("Digite o codigo da pessoa a ser excluida: ");
	scanf("%d", &cod);
	printf("\n");
	system("cls");
	if(opcao == 1){ // excluir aluno
		for(int i=0; i<TAM;i++){
			if(aluno[i].codigo == cod){
				aluno[i].codigo =0;
				strcpy( aluno[i].nome, "");
				aluno[i].telefone=0;
				cont=1;
			}
		}
	}else if(opcao == 2){ // excluir professor
		for(int i=0; i<TAM;i++){
			if(professor[i].codigo == cod){
				professor[i].codigo =0;
				strcpy( professor[i].nome, "");
				professor[i].telefone=0;
				cont=1;
			}
		}
	}

	if(cont == 1){
		printf("Usuario excluido com sucesso ...\n");	
	}else{
		printf("Usuario nao encontrado...\n");
	}
	cont=0;
	system("pause");
	system("cls");
}

// consulta banco

void consultar (Taluno aluno, Tprof professor, int opcao){
	char sub[30] ="";
	int cod=0,cont=0,cont1=0, indexalu=0, indexprof=0;
	printf("Digite o codigo da pessoa a ser colsultada: ");
	scanf("%d", &cod);
	printf("\n");
	system("cls");
	if(opcao == 1){ // colsunta aluno
		for(int i=0; i<TAM;i++){
			if(aluno[i].codigo == cod){
				aluno[i].codigo =0;
				indexalu=i;
				cont=1;
			}
		}
	}else if(opcao == 2){ // consulta professor
		for(int i=0; i<TAM;i++){
			if(professor[i].codigo == cod){
				indexprof=i;
				cont1=1;
			}
		}
	}
	
	
	if (cont==1 ){ // PRINTA ALUNO
		printf("Nome Aluno: %s \n", aluno[indexalu].nome);
		printf("Codigo Aluno: %d \n", cod);
		printf("Telefone aluno: %d \n",aluno[indexalu].telefone);
		
	}else if (cont1==1){
		printf("Nome Professor: %s \n", professor[indexprof].nome);
		printf("Codigo Professor: %d \n", cod);
		printf("Telefone professor: %d \n",professor[indexprof].telefone);
	}else{
		printf("\n\n codigo inexistente ...");
	}
	system("pause");
	system("cls");
	
}

void AtualizaArquivo(Taluno aluno,Tprof professor){ 
	// pegar o arquivo, limpar e escrever os dados de acordo com a struct


    char sub[30] ="";
    // escrever o arquivo aluno
	    char url[]="alunos.txt";
	    FILE *arq; 
	 	arq = fopen(url, "w");
	 	 if(arq == NULL)
	   		printf("Erro, nao foi possivel abrir o arquivo\n");
		 else{
		  for(int i=0; i<TAM; i++){
		  	if(strcmp(aluno[i].nome, sub) != 0){
				fprintf(arq, "%s %d %d \n", aluno[i].nome, aluno[i].codigo, aluno[i].telefone);
			}
		  }
		  
		 }
		 fclose(arq);	
		 // retornar menu

	
}

void AtualizaProfessor(Taluno aluno, Tprof professor){
	   char sub[30] ="";
	   
	   char url[]="professor.txt";
	    FILE *arq; 
	 	arq = fopen(url, "w");
	 	 if(arq == NULL)
	   		printf("Erro, nao foi possivel abrir o arquivo\n");
		 else{
		  for(int i=0; i<TAM; i++){
		  	if(strcmp(professor[i].nome, sub) != 0){
				fprintf(arq, "%s %d %d \n", professor[i].nome, professor[i].codigo, professor[i].telefone);
			}
		  }
		  
		 }
		 fclose(arq);
}

main(){
	
	Taluno aluno;
	Tprof professor;
	Inicializa(aluno,professor);
	Inicia(aluno, professor);
	
	int op=0, opcao=1;
	

	
	do{
		printf("----------------Trabalho ED1 -----------------\n");
		printf("Escolha uma opcao:  \n");
		printf("1 - Inserir Registro \n");
		printf("2 - Excluir registro \n");
		printf("3 - Consultar Registro\n");
		printf("4 - Mostrar todos registros\n");
		printf("0 - sair \n");
		scanf("%d",&op);
		system("cls");
		if(op == 1){ // insere
			printf("Escolha uma opcao\n");
			printf("1 - inserir aluno\n ");
			printf("2 - inserir professor\n");
			printf("0 - sair\n");
			scanf("%d", &opcao);
			
			if(opcao == 1){
				insere(aluno, professor, opcao);
				AtualizaArquivo( aluno, professor);	
			}else{
				insere(aluno,professor, opcao);
				AtualizaProfessor(aluno,professor);
			}
			
			
		}else if (op == 2){
			printf("Escolha uma opcao\n");
			printf("1 - excluir aluno\n ");
			printf("2 - excluir professor\n");
			printf("0 - sair\n");
			scanf("%d", &opcao);
			if(opcao==1){
				excluir(aluno, professor, opcao);
				AtualizaArquivo( aluno, professor);	
			}else{
				excluir(aluno, professor, opcao);
				AtualizaProfessor(aluno, professor);
			}
		
		}else if(op == 3){
			printf("Escolha uma opcao\n");
			printf("1 - Consultar aluno\n ");
			printf("2 - Consultar professor\n");
			printf("0 - sair\n");
			scanf("%d", &opcao);
			consultar(aluno, professor, opcao);
		}else if(op==4){
			mostra(aluno,professor);
		}
				
	}while(op!=0);
	
	
	
}
