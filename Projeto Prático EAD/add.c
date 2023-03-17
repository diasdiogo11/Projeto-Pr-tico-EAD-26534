#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


Clientes* inserir_cliente(Clientes* inicio, int NIF_, char nome_[], int idade_,char morada_[], int saldo) { // Fun��o que cria uma lista ligada para os clientes
	
	
		Clientes* Novo = malloc(sizeof(struct registo_clientes));
		if (Novo != NULL) {
			Novo->NIF = NIF_;
			Novo->idade = idade_;
			Novo->saldo = saldo;
			strcpy(Novo->nome, nome_);
			strcpy(Novo->morada, morada_);
			Novo->proximo_cliente = inicio;
			return Novo;
		}
		else {
			return inicio;
		}
} 

Clientes* imprimir_clientes(Clientes* inicio) { //Fun��o que imprime os dados inseridos na lista ligada para os clientes anteriormente criada

	while (inicio != NULL) {
		printf("%d %s %d %s %d\n",inicio->NIF, inicio->nome, inicio->idade, inicio->morada, inicio->saldo);
		inicio = inicio->proximo_cliente;
	}
}

Clientes* remover_clientes(Clientes* inicio, int code) { //Dado uma lista ligada, esta fun��o permite remover um determinado elemento da lista, dado o seu NIF
	
	
		Clientes* anterior = inicio, *atual = inicio, *aux;

		if (atual == NULL){
			return(NULL);
		}
		else if (atual->NIF == code) 
		{
			aux = atual->proximo_cliente;
			free(atual);
			return(aux);
		}
		else
		{
			for (atual; atual != NULL && atual->NIF != code;atual=atual->proximo_cliente){
				
				anterior = atual;
				
			}
				if (atual == NULL) {
					return(inicio);
				}
				else
				{
					anterior->proximo_cliente = atual->proximo_cliente;
					free(atual);
					return(inicio);
				}
		}
	
}


Veiculos* inserir_veiculos(Veiculos* inicio, int codigo_, int bateria_, char localizacao_[], int custo_, char tipo_[], int reserva_,int NIF_reserva_) { // Fun��o que cria uma lista ligada para os veiculos
	Veiculos* Novo = malloc(sizeof(struct registo_veiculos));

	if (Novo != NULL) {

		Novo->bateria = bateria_;
		Novo->codigo = codigo_;
		Novo->custo = custo_;
		Novo->reserva = reserva_;
		Novo->NIF_reserva = NIF_reserva_;
		strcpy(Novo->localizacao, localizacao_);
		strcpy(Novo->tipo, tipo_);
		Novo->proximo_veiculo = inicio;

		return Novo;
	}
	else {
		return inicio;
	}

}


Veiculos* imprimir_veiculos(Veiculos* inicio) { //Fun��o que imprime os dados inseridos na lista ligada para os veiculos anteriormente criada

	while (inicio != NULL) {
		
		printf("%d %d %s %d %s\n", inicio->codigo, inicio->bateria, inicio->localizacao, inicio->custo, inicio->tipo);
		inicio = inicio->proximo_veiculo;
	}
}

Veiculos* remover_veiculos(Veiculos* inicio, int code) { //Dado uma lista ligada, esta fun��o permite remover um determinado elemento da lista, dado o seu c�digo


	Veiculos* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) {
		return(NULL);
	}
	else if (atual->codigo == code)
	{
		aux = atual->proximo_veiculo;
		free(atual);
		return(aux);
	}
	else
	{
		for (atual; atual != NULL && atual->codigo != code; atual = atual->proximo_veiculo) {

			anterior = atual;
		}
		if (atual == NULL) {
			return(inicio);
		}
		else
		{
			anterior->proximo_veiculo = atual->proximo_veiculo;
			free(atual);
			return(inicio);
		}
	}

}


Veiculos* imprimir_reservas(Veiculos* inicio, int NIF) { //Fun��o que dado um NIF, imprime as reservas atuais de um utilizador

	Veiculos* current = inicio;

	for(current; current != NULL; current= current->proximo_veiculo) {
		if (current->NIF_reserva == NIF) {
			printf("%d %d %s %d %s\n", current->codigo, current->bateria, current->localizacao, current->custo, current->tipo);
		}

		
	}
}


Gestores* inserir_gestores(Gestores* inicio, char email_[], char password_[]) {  // Fun��o que cria uma lista ligada para os gestores
	Gestores* Novo = malloc(sizeof(struct registo_gestores));

	if (Novo != NULL) {

		strcpy(Novo->email, email_);
		strcpy(Novo->password, password_);
		Novo->proximo_gestor = inicio;

		return Novo;
	}
	else {
		return inicio;
	}

}

Gestores* imprimir_gestores(Gestores* inicio) { //Fun��o que imprime os dados inseridos na lista ligada para os gestores anteriormente criada

	while (inicio != NULL) {
		printf("%s %s\n", inicio->email, inicio->password);
		inicio = inicio->proximo_gestor;
	}
}

Gestores* remover_gestores(Gestores* inicio, char email[]) { //Dado uma lista ligada, esta fun��o permite remover um determinado elemento da lista, dado o seu c�digo


	Gestores* anterior = inicio, * atual = inicio, * aux;
	
	if (atual == NULL) {
		return(NULL);
	}
	else if (atual->email == email)
	{
		aux = atual->proximo_gestor;
		free(atual);
		return(aux);
	}
	else
	{
		for (atual; atual != NULL && atual->email != email; atual = atual->proximo_gestor) {

			anterior = atual;

		}
		if (atual == NULL) {
			return(inicio);
		}
		else
		{
			anterior->proximo_gestor = atual->proximo_gestor;
			free(atual);
			return(inicio);
		}
	}

}

Clientes* saldo(Clientes* inicio, int NIF_procurado){ //Fun��o que dado o NIF de um utilizador, carrega o saldo no parametro saldo

	int valor;

	printf("Qual a quantia a adicionar?\n");
	scanf("%d", &valor);
	Clientes* current = inicio;

	
	for (current; current != NULL; current = current->proximo_cliente) {
		if (NIF_procurado == current->NIF) {
			current->saldo = current->saldo + valor;
			return current;
		}
		
		
}
	return inicio;


	
}

int login_gestores(Gestores* inicio, char* username, char* password) { //Esta fun��o percorre a lista ligada de gestores, verificando se o username e a password digitadas pelo utilizador encontram-se na lista, se sim o login d� certo
	Gestores* current = inicio;
	for (current; current != NULL; current = current->proximo_gestor) {
		if (strcmp(current->email, username) == 0 && strcmp(current->password, password) == 0) {
			return 1;
		}


	}
	return 0;
}

int login_clientes(Clientes* inicio, char* username, int* code[]) { //Esta fun��o percorre a lista ligada de clientes, verificando se o username e a password digitadas pelo utilizador encontram-se na lista, se sim o login d� certo
	Clientes* current = inicio;
	for (current; current != NULL; current = current->proximo_cliente) {
		if (strcmp(current->nome, username) == 0 && code == current->NIF) {
			return 1;
		}

	} return 0;
}


void ordena��o_veiculos(Veiculos* inicio) {

	Veiculos* pi = inicio;
	Veiculos* pj = NULL;
	int aux;


	for (pi; pi != NULL; pi = pi->proximo_veiculo) {
		for (pj = pi->proximo_veiculo; pj != NULL; pj = pj->proximo_veiculo) {
			if (pi->bateria < pj->bateria ) {
				aux = pi->bateria;
				pi->bateria = pj->bateria;
				pj->bateria = aux;
			}
		}
	}
}

void ordena��o_clientes(Clientes* inicio) {

	Clientes* pi = inicio;
	Clientes* pj = NULL;
	int aux;


	for (pi; pi != NULL; pi = pi->proximo_cliente) {
		for (pj = pi->proximo_cliente; pj != NULL; pj = pj->proximo_cliente) {
			if (pi->NIF > pj->NIF) {
				aux = pi->NIF;
				pi->NIF = pj->NIF;
				pj->NIF = aux;
			}
		}
	}
}


void GuardarVeiculos(Veiculos* inicio)
{
	FILE* fp;
	fp = fopen("Veiculos.txt", "w");
	if (fp != NULL)
	{
		Veiculos* aux = inicio;
		for (aux; aux != NULL; aux = aux->proximo_veiculo) {
			fprintf(fp, "%d;%d;%s;%d;%s;%d;%d\n", aux->codigo, aux->bateria,
				aux->localizacao, aux->custo, aux->tipo, aux->reserva, aux->NIF_reserva);
		}
		fclose(fp);


	}

}

Veiculos* LerVeiculos() {
	FILE* fp;
	int code, bat, cust, reserva, NIF_reserva;
	char tipo[50], loca[50];
	Veiculos* aux = NULL;
	fp = fopen("Veiculos.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%d;%[^;];%d;%[^;];%d;%d\n", &code, &bat, loca, &cust, tipo, &reserva, &NIF_reserva);
			aux = inserir_veiculos(aux, code, bat, loca, cust, tipo, reserva, NIF_reserva);
		}
		fclose(fp);
	}
	return(aux);
}

void GuardarReservas(Reservas* inicio) {

	FILE* fp;
	fp = fopen("Reservas.txt", "w");

	if (fp == NULL)
	{
		printf("Ficheiro indisponivel.");
	}
	else
	{
		while (inicio != NULL)
		{
			fprintf(fp, "%d;%d;%d;%s;%d;%s;%d;%d", inicio->NIF, inicio->meio->codigo, inicio->meio->bateria, inicio->meio->localizacao, inicio->meio->custo, inicio->meio->tipo, inicio->meio->reserva, inicio->meio->NIF_reserva);
			inicio = inicio->seguinte;
		}
		fclose(fp);

	}
}



void GuardarVeiculos_Binario(Veiculos* inicio)
{
	FILE* fp;
	fp = fopen("Veiculos.bin", "wb");
	if (fp != NULL)
	{
		Veiculos* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Veiculos), 1, fp);
			aux = aux->proximo_veiculo;
		}
		fclose(fp);
	}
}


Veiculos* LerVeiculos_Binario()
{
	FILE* fp;
	Veiculos* aux = NULL;
	fp = fopen("Veiculos.bin", "rb");

	if (fp != NULL)
	{
		Veiculos current;
		while (fread(&current, sizeof(Veiculos), 1, fp) == 1)
		{
			aux = inserir_veiculos(aux, current.codigo, current.bateria, current.localizacao, current.custo, current.tipo, current.reserva, current.NIF_reserva);
		}
		fclose(fp);
	}
	return aux;

}

void GuardarGestores_Binario(Gestores* inicio)
{
	FILE* fp;
	fp = fopen("Gestores.bin", "wb");
	if (fp != NULL)
	{
		Gestores* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Gestores), 1, fp);
			aux = aux->proximo_gestor;
		}
		fclose(fp);
	}
}

Gestores* LerGestores_Binario()
{
	FILE* fp;
	Gestores* aux = NULL;
	fp = fopen("Gestores.bin", "rb");

	if (fp != NULL)
	{
		Gestores current;
		while (fread(&current, sizeof(Gestores), 1, fp) == 1)
		{
			aux = inserir_gestores(aux, current.email, current.password);
		fclose(fp);
	}
	return aux;

}
}

void GuardarClientes(Clientes* inicio)
{
	FILE* fp;
	fp = fopen("Clientes.txt", "w");
	if (fp != NULL)
	{
		Clientes* aux = inicio;
		for (aux; aux != NULL; aux = aux->proximo_cliente) {
			fprintf(fp, "%d;%s;%d;%s;%d\n", aux->NIF, aux->nome,aux->idade, aux->morada, aux->saldo);
		}
		fclose(fp);
		

	}
	
}

Clientes* LerClientes()
{
	FILE* fp;
	int NIF, idade, saldo;
	char nome[50], morada[50];
	Clientes* aux = NULL;
	fp = fopen("Clientes.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%[^;];%d;%[^;];%d\n", &NIF, nome, &idade, morada, &saldo);
			aux = inserir_cliente(aux, NIF, nome, idade, morada, saldo);
		}
		fclose(fp);
	}
	return(aux);
}

void GuardarClientes_Binario(Clientes* inicio)
{
	FILE* fp;
	fp = fopen("Clientes.bin", "wb");
	if (fp != NULL)
	{
		Clientes* aux = inicio;
		while (aux != NULL)
		{
			fwrite(aux, sizeof(Clientes), 1, fp);
			aux = aux->proximo_cliente;
		}
		fclose(fp);
	}
}

Clientes* LerClientes_Binario()
{
	FILE* fp;
	Clientes* aux = NULL;
	fp = fopen("Clientes.bin", "rb");

	if (fp != NULL)
	{
		Clientes current;
		while (fread(&current, sizeof(Clientes), 1, fp) == 1)
		{
			aux = inserir_cliente(aux, current.NIF, current.nome, current.idade, current.morada, current.saldo);
		}
		fclose(fp);
	}
	return aux;

}


void menu_principal() {
	int opcao;
	printf("*---------------- MENU PRINCIPAL ----------------*\n");
	printf("| 1.REGISTAR                                     |\n");
	printf("| 2.LOGIN                                        |\n");
	printf("| 0.EXIT                                         |\n");
	printf("*------------------------------------------------*\n");
	

}
int cabe�alho_registar() {
	
	printf("*------------------------------------*\n");
	printf("|               REGISTO              |\n");
	printf("*------------------------------------*\n");

	
}

void menu_login() {


	
		printf("*--------------------------------------*\n");
		printf("| 1.ADMINISTRADOR                      |\n");
		printf("| 2.CLIENTE                            |\n");
		printf("*--------------------------------------*\n");
		
		
	
}
void menu_gestores() {

	
	printf("*---------------- MENU GESTORES ----------------*\n");
	printf("| 1.INSERIR CLIENTE                             |\n");
	printf("| 2.REMOVER CLIENTE                             |\n");
	printf("| 3.LISTAR CLIENTES                             |\n");
	printf("| 4.INSERIR VEICULO                             |\n");
	printf("| 5.REMOVER VEICULO                             |\n");
	printf("| 6.LISTAR VEICULOS                             |\n");
	printf("| 7.GESTOR MASTER (ACESSO RESTRITO)             |\n");
	printf("| 0.EXIT                                        |\n");
	printf("*-----------------------------------------------*\n");
	
}

void menu_mastergestor() {
	printf("*---------------- MENU GESTORES ----------------*\n");
	printf("| 1.ADICIONAR GESTOR                             |\n");
	printf("| 2.REMOVER GESTOR                              |\n");
	printf("| 3.ALTERAR DADOS GESTOR                        |\n");
	printf("| 0.VOLTAR                                      |\n");
	printf("*-----------------------------------------------*\n");



}
void menu_clientes() {
	
	printf("*---------------- MENU CLIENTES ----------------*\n");
	printf("| 1.RESERVAR VEICULO                            |\n");
	printf("| 2.CANCELAR RESERVA                            |\n");
	printf("| 3.CARREGAR SALDO                              |\n");
	printf("| 4.DEFINICOES                                  |\n");
	printf("| 5.RESERVAS ATIVAS                             |\n");
	printf("| 6.HISTORICO RESERVAS                          |\n");
	printf("| 0.EXIT                                        |\n");
	printf("*-----------------------------------------------*\n");
	
	
}

void menu_definicoes() {

	
	printf("*---------------- DEFINICOES ----------------*\n");
	printf("| 1.ALTERAR NOME DE USUARIO                  |\n");
	printf("| 2.ALTERAR MORADA                           |\n");
	printf("| 0.VOLTAR MENU CLIENTES                     |\n");
	printf("*--------------------------------------------*\n");

}

void cabe�alho_admin() {
	printf("*------------------------------------*\n");
	printf("|            ADMINISTRADOR           |\n");
	printf("*------------------------------------*\n");
}

void cabe�alho_cliente() {
	printf("*------------------------------------*\n");
	printf("|               CLIENTE              |\n");
	printf("*------------------------------------*\n");
}

int verificar_registo_clientes(Clientes* inicio, int NIF) {



	for (inicio; inicio != NULL; inicio = inicio->proximo_cliente) {
		if (inicio->NIF == NIF) {
			return 0;
		}
		
			
		
	}
	return 1;
}

int verificar_registo_veiculos(Veiculos* inicio, int codigo){



	for (inicio; inicio != NULL; inicio = inicio->proximo_veiculo) {
		if (inicio->codigo == codigo){
			return 0;
		}



	}
	return 1;
}

int verificar_registo_gestores(Gestores* inicio, char email[]) {



	for (inicio; inicio != NULL; inicio = inicio->proximo_gestor) {
		if (strcmp(inicio->email, email) == 0) {
			return 0;
		}



	}
	return 1;
}

void AlterarDados(Clientes* inicio, int NIF_procurado) {

	int opcao;
	char novo_nome[50], nova_morada[50];
	Clientes* current = inicio;

	menu_definicoes();

	printf("Que parametro deseja alterar?\n");
	scanf("%d", &opcao);

	if (opcao == 1) {
		scanf("%*c");
		printf("Digite o novo nome de usuario\n");
		gets(novo_nome);
		for (current; current != NULL; current = current->proximo_cliente) {
			if (NIF_procurado == current->NIF) {
				strcpy(current->nome, novo_nome);
			}
		
		}
	}
	else if (opcao == 2) {
		scanf("%*c");
		printf("Digite a sua nova morada\n");
		gets(nova_morada);
		for (current; current != NULL; current = current->proximo_cliente) {
			if (NIF_procurado == current->NIF) {
				strcpy(current->morada, nova_morada);
			}
			
		}
	}
	
	

}


int Reservar_Veiculo(Veiculos* inicio, int NIF_reserva) {
	int code;

	printf("Qual o codigo do veiculo\n");
	scanf("%d", &code);

	Veiculos* current = inicio;

	for (current; current != NULL; current = current->proximo_veiculo) {
		if (current->codigo == code && current->reserva == 0 && current->NIF_reserva == 0) {
			
			current->reserva = 1;
			current->NIF_reserva = NIF_reserva;
			return 1;
		}
	}
	return 0;
		
	}


int Cancelar_Reserva(Veiculos* inicio, int NIF_reserva) {

	int code;
	
	printf("Qual o codigo do veiculo\n");
	scanf("%d", &code);

	Veiculos* current = inicio;

	for (current; current != NULL; current = current->proximo_veiculo) {
		if (current->reserva == 1 && current->codigo == code && current->NIF_reserva == NIF_reserva) {
			printf("%d %d %s %d %s\n", current->codigo, current->bateria, current->localizacao, current->custo, current->tipo);
			current->reserva = 0;
			current->NIF_reserva = 0;
			return 1;
		}
		else if (current->reserva == 0 && current->NIF_reserva == 0) {
			return 0;
		}
	
		
	}
}



void clear() {

	system("@cls || clear");
}


Veiculos* LocalizarVeiculos(Veiculos* inicio) {

	char localizacao_pretendida[TAM];

	Veiculos* current = inicio;
	
	scanf("%*c");
	printf("Onde deseja encontrar veiculos?\n");
	gets(localizacao_pretendida);

	for (current; current != NULL; current = current->proximo_veiculo) {

		if ((strcmp(current->localizacao, localizacao_pretendida) == 0)) {
			printf("%d %d %s %d %s\n", current->codigo, current->bateria, current->localizacao, current->custo, current->tipo);
			 
		}

	}
}

void AlterarDadosGestores(Gestores* inicio, char email_procurado[]) {
	int opcao;
	char novo_email[50], nova_password[50];
	Gestores* current = inicio;


	printf("Que parametro deseja alterar?\n");
	scanf("%d", &opcao);

	if (opcao == 1) {
		scanf("%*c");
		printf("Digite o novo email\n");
		gets(novo_email);
		for (current; current != NULL; current = current->proximo_gestor) {
			if (strcmp(current->email, email_procurado) == 0) {
				strcpy(current->email, novo_email);
			}

		}
	}
	else if (opcao == 2) {
		scanf("%*c");
		printf("Digite a sua nova password\n");
		gets(nova_password);
		for (current; current != NULL; current = current->proximo_gestor) {
			if (strcmp(current->email, email_procurado) == 0) {
				strcpy(current->password, nova_password);
			}

		}
	}

}
