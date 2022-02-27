#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tamanho(char letra[]){
	int resultado = 0;
	for(int n = 0; letra[n] != '\0'; n++){
		resultado += 1;
	} 
	return resultado;
}

void addWord(){
	FILE *file;
	file = fopen("words.txt", "a");
	if(file){
		int n=0;
		char *palavra = (char *) malloc(sizeof(char)*20);
		printf("Infome quantas palavras deseja adicionar: ");
		scanf(" %d", &n);
		for(int aux = 0; aux < n; aux++){
			printf("Infome a palavra %d: ", aux+1);
			scanf(" %s", palavra);
			fprintf(file, "%s\n", palavra);
		}
		fclose(file);
	}
	else{
		puts("ERRO 01");
	}
}

int tamanhoFile(FILE *file){
	if(file){
		fseek(file, 0, SEEK_END);
		int tam = ftell(file);
		if(tam != -1){
			return tam;
		}
	}
	return 0;
}

void listar(){
	FILE *file;
	file =  fopen("words.txt", "r");
	if(file){
		int tamanhoArq = tamanhoFile(file);
		if(tamanhoArq != 0){
			rewind(file);
			char *word = (char *) malloc(sizeof(char)*50);
			while(fgets(word, 50, file) != NULL){
				printf("%s", word);
			}	
		}
		else{
			puts("Nao ha palavras cadastradas");
		}
	}
	else puts("ERRO 01");
}

void removeN(char vetor[50]){
	int i = 0;
	while(vetor[i] != '\n'){
		i++;
	}
	vetor[i] = '\0';
}

int verificaPalavras(char v1[50], char v2[50]){
	int i = 0;
	while(v1[i] != '\0'){
		if(v1[i] != v2[i]) return 1;
		i++;
	}
	if(v2[i] == '\0') return 0;
	else return 1;
}

void excluirWord(){
	FILE *file = fopen("words.txt", "r");
	int tamanhoArq = tamanhoFile(file);
	if(tamanhoArq == 0){
		puts("Nao ha palavras para serem excluidas");
		return;
	}
	fclose(file);
	char n = '0';
	puts("1 - Excluir a lista toda");
	puts("2 - Excluir palavra expecifica");
	while(n != '1' && n != '2'){
		scanf(" %c", &n);
	}	
	if(n == '1'){
		file = fopen("words.txt", "w");
		fclose(file);
	}
	else
		if(n == '2'){
			file = fopen("words.txt", "r");
			if(file){
				char palavra[50], palavraRetorno[50];
				printf("Qual palavra deseja remover? \n");
				while(fgets(palavraRetorno,50,file) != NULL){
					printf("%s", palavraRetorno);
				}
				scanf(" %s", palavra);
				FILE *fileTemporario;
				fileTemporario = fopen("Temporario.txt", "w");
				fclose(file);
				file = fopen("words.txt", "r");
				while(fgets(palavraRetorno, 50, file) != NULL){
					removeN(palavraRetorno);//remove o \n adicionado pelo fgets;
					if(verificaPalavras(palavra, palavraRetorno)){
						fprintf(fileTemporario, "%s\n", palavraRetorno);
					}
				}
				remove("words.txt");
				fclose(file);
				rename("Temporario.txt", "words.txt");
				fclose(fileTemporario);
			}else
				puts("ERRO 01");
		}
}

void desenhar(int i, int tamanho, char todasLetras[26]){
	switch(i){
		case 0:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|				Letras usadas: %s\n", todasLetras);
			puts("|");
			puts("|");
			puts("|");
			puts("|");
			break;
		}
		case 1:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);		
			puts("|");
			puts("|");
			puts("|");
			puts("|");
			break;
		}
		case 2:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);
			puts("|        |");
			puts("|");
			puts("|");
			puts("|");
			break;
		}
		case 3:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);
			puts("|       /|");
			puts("|");
			puts("|");
			puts("|");
			break;
		}
		case 4:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);
			puts("|       /|\\");
			puts("|");
			puts("|");
			puts("|");
			break;
		}
		case 5:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);
			puts("|       /|\\");
			puts("|       / ");
			puts("|");
			puts("|");
			break;
		}
		case 6:
		{
			puts("_________");
			printf("|        |			Quantidade de letras: %d\n", tamanho);
			printf("|       ( )			Letras usadas: %s\n", todasLetras);
			puts("|       /|\\");
			puts("|       / \\");
			puts("|");
			puts("|");
			break;
		}
	}
}

int verificaPalavras2(char vet1[], char vet2[]){ //depois comparar com o verifica 1 para saber quem vai ficar;
	int i = 0;
	while(vet1[i] != '\0'){
		if(vet1[i] >= 65 && vet1[i] <= 90){
			if(vet1[i] != vet2[i]){
				if(vet1[i] != vet2[i] - 32) return 0;
			}
		}
		else{
			if(vet1[i] != vet2[i]){
				if(vet1[i] != vet2[i] + 32) return 0;
			}
		}
		i++;
	}
	return 1;
}

void insereTodasLetras(char todasLetras[], int *tam, char resposta[]){
	int i = 0;
	for(;todasLetras[i] != '\0' && todasLetras[i] != resposta[0]; i++);
	if(todasLetras[i] == '\0'){
		if(i == *tam || i + 2 == *tam || i + 3 == *tam){
			todasLetras = (char *) realloc(todasLetras, sizeof(char) * (*tam) + 6);
			*tam = *tam + 6;
		}
		todasLetras[i] = resposta[0];
		todasLetras[i+1] = ' ';
		todasLetras[i+2] = '\0';
	}
}

void jogo(){
	FILE *file;
	file = fopen("words.txt", "r");
	if(file){
		int tamanhoArq = tamanhoFile(file);
		if(tamanhoArq == 0){
			puts("Nao ha palavras cadastradas\nCadastre algumas palavras para jogar");
			return;
		}
		rewind(file); 
		srand(time(NULL));
		int max = 0;
		char word[50];
		while(fgets(word, 50, file) != NULL){
			max = max + 1;
		}
		fclose(file);
		int aleatorio = rand() % max;
		file = fopen("words.txt", "r");
		if(file){
			for(int i = 0;i < aleatorio && word != NULL; i++){
				fgets(word, 50, file);
			}
			removeN(word);
			int tam  = tamanho(word);
			char *resposta = (char *) malloc(sizeof(char) * tam); 
			char *letrasAcerto = (char *) malloc(sizeof(char) * tam);
			char verifica = 'i';
			max = 3; //max agora vai servir como tamanho maximo do vetor todasLetras;
			char *todasLetras = (char *) malloc(sizeof(char) * 3);
			todasLetras[0] = '\0';
			int erro = 0, errado = 2;
			for(int i = 0; i < tam; i++){
				letrasAcerto[i] = '0';
			}

			while(verifica != 'f'){
				desenhar(erro, tam, todasLetras);
				for(int i = 0; letrasAcerto[i] != '\0'; i++){
					if(letrasAcerto[i] != '0'){
						printf("%c ", letrasAcerto[i]);
					}
					else{
						printf("__ ");
					}	
				}

				if(verificaPalavras2(letrasAcerto, word) || erro > 5){
					if(erro > 5){
						puts("Errou");
					}
					else{
						puts("\nAcertou");
					}
					verifica = 'f';
				}
				else{
					printf("\nDigite uma letra ou uma palavra: ");
					scanf(" %s", resposta); //fgets(resposta, tam, stdin); <--- verificar isso;
					errado = 2;
					if(resposta[1] == '\0'){
						insereTodasLetras(todasLetras, &max, resposta);
						todasLetras[max] = resposta[0];
						todasLetras[max+1] = '\0';
						max++;
						for(int i = 0; word[i] != '\0'; i++){
							if(word[i] == resposta[0] || resposta[0] + 32 == word[i] || resposta[0] - 32 == word[i]){
								letrasAcerto[i] = word[i];
								errado = 1;
							}
							else{
								if(errado != 1) errado = 0;
							}
						}
					}
					else{
						if(verificaPalavras2(resposta, word)){
							desenhar(erro, tam, todasLetras);
							for(int i = 0; resposta[i] != '\0'; i++){
								printf("%c ", resposta[i]);
							}
							puts("");
							verifica = 'f';
						}
						else errado =0;
					}
					if(errado == 0){
						erro = erro + 1;
						errado = 2;
					}
				}
			}
			fclose(file); file = NULL;
			free(resposta); resposta = NULL;
			free(letrasAcerto); letrasAcerto = NULL;
			free(todasLetras); todasLetras = NULL;
		}
		else
			puts("ERRO 01");
	}
	else
		puts("ERRO 01");
}

int main(){
	char resposta = '0';
	int max = 0;
	while(resposta != 'f'){
		puts("Menu do jogo");
		puts("1 - Ver lista de palavras cadastrada");
		puts("2 - Inserir palavras");
		puts("3 - Excluir palavras");
		puts("4 - Começar jogo");
		puts("5 - Sair");
		puts("Resposta: ");
		scanf(" %c", &resposta);
		switch (resposta){
			case '1':
				listar();
				break;
			case '2':
				addWord();
				break;
			case '3':
				excluirWord();
				break;
			case '4':
				jogo();
				break;
			case '5':
				resposta = 'f';
				break;
			default:
				puts("Escolha entre as opcoes: 1, 2, 3, 4, 5");
				break;
		}
	}
}
