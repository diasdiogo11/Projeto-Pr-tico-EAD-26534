#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>



typedef struct registo_clientes {

	int idade;
	int NIF;
	int saldo;
	char morada[50];
	char nome[50];
	char password[50];
	struct registo_clientes* proximo_cliente;

}Clientes;

typedef struct registo_gestores {

	char email[50];
	char password[50];
	struct registo_gestores* proximo_gestor;

}Gestores;

typedef struct registo_veiculos {

	int codigo;
	int bateria;
	int custo;
	int reserva;
	int NIF_reserva;
	char localizacao[50];
	char tipo[50];
	struct registo_veiculos* proximo_veiculo;

}Veiculos;

typedef struct registo_reservas {
	int NIF;
	Veiculos* meio;
	struct registo_reservas* seguinte;

}Reservas;




Clientes* inserir_cliente(Clientes* inicio, int NIF_, char nome_[], int idade_, char morada_[], int saldo); //Inserção de novos clientes
Clientes* imprimir_clientes(Clientes* inicio); //Imprime os clientes registados
Clientes* remover_clientes(Clientes* inicio, int code); //Remove um cliente através do seu NIF
Veiculos* inserir_veiculos(Veiculos* inicio, int codigo_, int bateria_, char localizacao_[], int custo_, char tipo_[]); // Inserção de novos veiculos
Veiculos* imprimir_veiculos(Veiculos* inicio); //Imprimie os veiculos disponiveis
Gestores* inserir_gestores(Gestores* inicio, char email_[], char password_[]); //Inserção dos gestores
int Reservar_Veiculo(Veiculos* inicio, Clientes* inicio1, int NIF_reserva);
void Historico_reservas(Veiculos* inicio);