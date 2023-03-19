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

typedef struct registo_chefe {
	int NIF;
	Veiculos* meio;
	struct registo_chefe* seguinte;

}Reservas;




Clientes* inserir_cliente(Clientes* inicio, int NIF_, char nome_[], int idade_, char morada_[], int saldo); //Inser��o de novos clientes
Clientes* imprimir_clientes(Clientes* inicio); //Imprime os clientes registados
Clientes* remover_clientes(Clientes* inicio, int code); //Remove um cliente atrav�s do seu NIF
Veiculos* inserir_veiculos(Veiculos* inicio, int codigo_, int bateria_, char localizacao_[], int custo_, char tipo_[]); // Inser��o de novos veiculos
Veiculos* imprimir_veiculos(Veiculos* inicio); //Imprimie os veiculos disponiveis
Veiculos* remover_veiculos(Veiculos* inicio, int code);
Gestores* inserir_gestores(Gestores* inicio, char email_[], char password_[]); //Inser��o dos gestores
int Reservar_Veiculo(Veiculos* inicio, Clientes* inicio1, int NIF_reserva);
void Historico_reservas(Veiculos* inicio);
Veiculos* imprimir_reservas(Veiculos* inicio, int NIF);
Gestores* remover_gestores(Gestores* inicio, char email[]);
int saldo(Clientes* inicio, int NIF_procurado);
int login_gestores(Gestores* inicio, char* username, char* password);
int login_clientes(Clientes* inicio, char* username, int* code[]);
void ordena��o_veiculos(Veiculos* inicio);
void ordena��o_clientes(Clientes* inicio);
void GuardarVeiculos(Veiculos* inicio);
Veiculos* LerVeiculos();
void GuardarReservas(Reservas* inicio);
void GuardarVeiculos_Binario(Veiculos* inicio);
Veiculos* LerVeiculos_Binario();
void GuardarGestores_Binario(Gestores* inicio);
Gestores* LerGestores_Binario();
void GuardarClientes(Clientes* inicio);
Clientes* LerClientes();
void GuardarClientes_Binario(Clientes* inicio);
Clientes* LerClientes_Binario();
void menu_principal();
int cabe�alho_registar();
void menu_login();
void menu_gestores();
void menu_mastergestor();
void menu_clientes();
void menu_definicoes();
void cabe�alho_admin();
void cabe�alho_cliente();
int verificar_registo_clientes(Clientes* inicio, int NIF);
int verificar_registo_veiculos(Veiculos* inicio, int codigo);
int verificar_registo_gestores(Gestores* inicio, char email[]);
void AlterarDados(Clientes* inicio, int NIF_procurado);
int Reservar_Veiculo(Veiculos* inicio, int NIF_reserva);
int Cancelar_Reserva(Veiculos* inicio, int NIF_reserva);
void clear();
int LocalizarVeiculos(Veiculos* inicio);
void AlterarDadosGestores(Gestores* inicio, char email_procurado[]);

