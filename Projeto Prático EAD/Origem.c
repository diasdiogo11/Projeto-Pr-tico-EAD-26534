#define _CRT_SECURE_NO_WARNINGS
#define TAM 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "structs.h"
#include "add.c"

void main() {

	char usuario[50], password[50], nome[50], morada[50], localizacao[50], tipo[50];
	int NIF, idade, opcao, NIF_, opcao1, codigo,opcao2,opcao3, bateria, custo, quantia, saldo_inicial = 0, reserva = 0, NIF_reserva = 0;

	Clientes* clientes = NULL;
	Veiculos* veiculos = NULL;
	Gestores* gestores = NULL;



	clientes = LerClientes();
	veiculos = LerVeiculos();
	clientes = imprimir_clientes(clientes);
	gestores = inserir_gestores(gestores, "diogo", "lesi");
	gestores = inserir_gestores(gestores, "diogo", "lesi");




	do {
		menu_principal();
		scanf("%d", &opcao);

		if (opcao == 1) {
			clear();
			cabeçalho_registar();
			printf("NIF:\n");
			scanf("%d", &NIF);
			scanf("%*c");
			printf("Nome:\n");
			gets(nome);
			printf("Idade:\n");
			scanf("%d", &idade);
			scanf("%*c");
			printf("Morada:\n");
			gets(morada);
			clientes = LerClientes();
			clientes = inserir_cliente(clientes, NIF, nome, idade, morada, saldo_inicial);
			GuardarClientes(clientes);

		}

		else if (opcao == 2) {
			
			clear();
			menu_login();
			scanf("%d", &opcao1);
			if (opcao1 == 1) {
				system("cls");
				printf("Email:\n");
				scanf("%s", usuario);
				printf("Password:\n");
				scanf("%s", password);
				do {
					if (login_gestores(gestores, usuario, password)) {
						clear();
						printf("Bem-vindo, %s!\n", usuario);
						menu_gestores();
						scanf("%d", &opcao2);
						if (opcao2 == 1) {
							printf("NIF:\n");
							scanf("%d", &NIF);
							scanf("%*c");
							printf("Nome:\n");
							gets(nome);
							printf("Idade:\n");
							scanf("%d", &idade);
							scanf("%*c");
							printf("Morada:\n");
							gets(morada);
							clientes = LerClientes();
							clientes = inserir_cliente(clientes, NIF, nome, idade, morada, saldo_inicial);
							GuardarClientes(clientes);


						}

						else if (opcao2 == 2) {
							printf("NIF do utilizador a remover do sistema\n");
							scanf("%d", &NIF_);
							clientes = LerClientes();
							clientes = remover_clientes(clientes, NIF_);
							GuardarClientes(clientes);
						}
						else if (opcao2 == 3) {

							clientes = LerClientes();
							ordenação_clientes(clientes);
							clientes = imprimir_clientes(clientes);

						}
						else if (opcao2 == 4) {
							printf("Codigo:\n");
							scanf("%d", &codigo);
							printf("Bateria:\n");
							scanf("%d", &bateria);
							scanf("%*c");
							printf("Localizacao:\n");
							gets(localizacao);
							printf("Custo:\n");
							scanf("%d", &custo);
							scanf("%*c");
							printf("Tipo:\n");
							gets(tipo);
							veiculos = LerVeiculos();
							veiculos = inserir_veiculos(veiculos, codigo, bateria, localizacao, custo, tipo, reserva, NIF_reserva);
							GuardarVeiculos(veiculos);

						}
						else if (opcao2 == 5) {
							printf("NIF do utilizador a remover do sistema\n");
							scanf("%d", &NIF_);
							veiculos = LerVeiculos();
							veiculos = remover_veiculos(clientes, NIF_);
							GuardarVeiculos(veiculos);

						}
					}
					else {
						printf("Nome de usuario ou senha incorretos.\n");
					}
				} while (opcao2 != 0);
				
			}
			else {
				clear();
				printf("NIF:\n");
				scanf("%d", &NIF);
				scanf("%*c");
				printf("Nome:\n");
				gets(usuario);
				clientes = LerClientes();
				clear();
				do {
					if (login_clientes(clientes, usuario, NIF)) {
						printf("Bem vindo %s\n", usuario);
						menu_clientes();
						scanf("%d", &opcao3);
						if (opcao3 == 1) {
							veiculos = LerVeiculos();
							clientes = LerClientes();
							if (Reservar_Veiculo(veiculos, clientes, NIF)) {
								GuardarVeiculos(veiculos);
							}
							else {
								printf("Veiculo impossivel de reservar\n");
							}

						}
						else if (opcao3 == 2) {
							veiculos = LerVeiculos();
							Cancelar_Reserva(veiculos, NIF);
							GuardarVeiculos(veiculos);

						}
						else if (opcao3 == 3) {

							clientes = LerClientes();
							saldo(clientes, NIF);
							GuardarClientes(clientes);
							imprimir_clientes(clientes);

						}
						else if (opcao3 == 4) {
							clear();
							menu_definicoes();
							scanf("%d", &opcao1);
							if (opcao1 == 1) {
								clientes = LerClientes();
								AlterarNome(clientes, NIF);
								GuardarClientes(clientes);
								clientes = imprimir_clientes(clientes);
							}
							else if (opcao1 == 2) {
								clientes = LerClientes();
								AlterarMorada(clientes, NIF);
								GuardarClientes(clientes);
								clientes = imprimir_clientes(clientes);
							}
						}
						else if (opcao3 == 5) {
							veiculos = LerVeiculos();
							veiculos = imprimir_reservas(veiculos, NIF);


						}
						else if (opcao3 == 6) {

							Historico_Reservas(veiculos, NIF);

						}


					}
					else {
						printf("Nome de usuario ou NIF incorretos.\n");
					}
				} while (opcao3 != 0);
				

			}

		}
		else if (opcao == 0) {
			printf("Obrigado pela sua visita...\n");

		}


	} while (opcao != 0);






	return 0;

}



