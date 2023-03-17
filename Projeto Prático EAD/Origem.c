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

	char usuario[50], password[50], nome[50], morada[50], localizacao[50], tipo[50],novo_nome[50], nova_morada[50], gestor1[50], email[50];
	int NIF, idade, opcao, NIF_, opcao1, codigo,opcao2,opcao3,opcao6, bateria, custo, quantia, saldo_inicial = 0, reserva = 0, NIF_reserva = 0;

	Clientes* clientes = NULL;
	Veiculos* veiculos = NULL;
	Gestores* gestores = NULL;
	Reservas* reservas = NULL;

	clientes = LerClientes_Binario();
	veiculos = LerVeiculos_Binario();
	gestores = LerGestores_Binario();
	gestores = inserir_gestores(gestores, "diogo1234", "lesi");





	do {
		menu_principal();
		printf("OPCAO:\n");
		scanf("%d", &opcao);
		
		if (opcao == 1) {
			clear();
			cabeçalho_registar();
			printf("NIF:\n");
			scanf("%d", &NIF);
			if (verificar_registo_clientes(clientes, NIF)) {
				scanf("%*c");
				printf("Nome:\n");
				gets(nome);
				printf("Idade:\n");
				scanf("%d", &idade);
				scanf("%*c");
				printf("Morada:\n");
				gets(morada);
				clientes = inserir_cliente(clientes, NIF, nome, idade, morada, saldo_inicial);
				GuardarClientes_Binario(clientes);
				GuardarClientes(clientes);
				clear();
				printf("Registo efetuado com sucesso!\n");
				
			}
			else {
				clear();
				printf("Utilizador ja se encontra registado\n");
				
			}
				
				
			

		}

		else if (opcao == 2) {
			
			clear();
			menu_login();
			printf("OPCAO:\n");
			scanf("%d", &opcao1);
			clear();
			if (opcao1 == 1) {
				cabeçalho_admin();
				printf("Email:\n");
				scanf("%s", usuario);
				printf("Password:\n");
				scanf("%s", password);
				
					if (login_gestores(gestores, usuario, password)) {
						printf("Bem-vindo, %s!\n", usuario);
						clear();
						do {
							menu_gestores();
							scanf("%d", &opcao2);


							if (opcao2 == 1) {
								clear();
								printf("NIF:\n");
								scanf("%d", &NIF);
								if (verificar_registo_clientes(clientes, NIF)) {
									scanf("%*c");
									printf("Nome:\n");
									gets(nome);
									printf("Idade:\n");
									scanf("%d", &idade);
									scanf("%*c");
									printf("Morada:\n");
									gets(morada);
									clientes = inserir_cliente(clientes, NIF, nome, idade, morada, saldo_inicial);
									GuardarClientes_Binario(clientes);
									GuardarClientes(clientes);
									clear();
									printf("Registo efetuado com sucesso!\n");
								}
								else {
									clear();
									printf("Utilizador ja se encontra registado\n");
								}

							}

							else if (opcao2 == 2) {
								clear();
								printf("NIF do utilizador a remover do sistema\n");
								scanf("%d", &NIF_);
								if (!verificar_registo_clientes(clientes, NIF_)){
									clientes = remover_clientes(clientes, NIF_);
									GuardarClientes_Binario(clientes);
									GuardarClientes(clientes);
									clear();
									printf("Utilizador removido com sucesso\n");
								}
								else {
									clear();
									printf("Utilizador nao registado no nosso sistema\n");
								}
								
							}
							else if (opcao2 == 3) {
								clear();
								ordenação_clientes(clientes);
								imprimir_clientes(clientes);


							}
							else if (opcao2 == 4) {
								clear();
								printf("Codigo:\n");
								scanf("%d", &codigo);
								if (verificar_registo_veiculos(veiculos, codigo)) {
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
									veiculos = inserir_veiculos(veiculos, codigo, bateria, localizacao, custo, tipo, reserva, NIF_reserva);
									GuardarVeiculos_Binario(veiculos);
									GuardarVeiculos(veiculos);
									clear();
									printf("Registo efetuado com sucesso!\n");
								}
								else {
									clear();
									printf("Este veiculo ja se encontra registado\n");
								}
							}
							else if (opcao2 == 5) {
								clear();
								printf("Codigo do veiculo a remover do sistema\n");
								scanf("%d", &codigo);
								if (!verificar_registo_veiculos(veiculos, codigo)) {
									veiculos = remover_veiculos(veiculos, codigo);
									GuardarVeiculos_Binario(veiculos);
									GuardarVeiculos(veiculos);
									clear();
									printf("Veiculo removido com sucesso\n");
								
								}
								else {
									clear();
									printf("Veiculo nao registado no nosso sistema\n");
								}
							}
							else if (opcao2 == 6) {
								clear();
								ordenação_veiculos(veiculos);
								imprimir_veiculos(veiculos);
							}
							else if (opcao2 == 7) {
								clear();
								if (strcmp(usuario, "diogo1234") == 0) {
									menu_mastergestor();
									scanf("%d", &opcao6);
									clear();
									if (opcao6 == 1) {
										clear();
										printf("Digite o email do novo gestor\n");
										scanf("%s", email);
										if (verificar_registo_gestores(gestores, email)) {
											printf("Digite a password do novo gestor\n");
											scanf("%s", password);
											gestores = inserir_gestores(gestores, email, password);
											GuardarGestores_Binario(gestores);
											clear();
											printf("Registo efetuado com sucesso!\n");
										}
										else {
											clear();
											printf("Este gestor ja se encontra registado\n");
										}
										
										
									}
									else if (opcao6 == 2) {
										clear();
										printf("Digite o email do gestor a remover do sistema\n");
										scanf("%s", email);
										if (!verificar_registo_gestores(gestores, email)) {
											if (strcmp(gestores->email, usuario) == 1) {
												gestores = remover_gestores(gestores, email);
												GuardarGestores_Binario(gestores);
												clear();
												printf("Gestor removido com sucesso\n");
											}
											else {
												clear();
												printf("Gestor impossivel de remover\n");
											}
											
										}
										else {
											clear();
											printf("Gestor nao registado no nosso sistema\n");
										}
										
									}
									else if (opcao6 == 3) {
										printf("Qual o gestor a alterar dados\n");
										scanf("%s", usuario);
										AlterarDadosGestores(gestores, usuario);
										GuardarGestores_Binario(gestores);
									}
									
								}
								else {
									printf("ACESSO NAO AUTORIZADO\n");
								}

							}
						} while (opcao2 != 0);
					}
					
					
					
					else {
						clear();
						printf("Nome de usuario ou senha incorretos.\n");
					}
					
				

					
					
				
				
			}
			else {
				cabeçalho_cliente();
				printf("NIF:\n");
				scanf("%d", &NIF);
				scanf("%*c");
				printf("Nome:\n");
				gets(usuario);
				
				if (login_clientes(clientes, usuario, NIF)) {
						printf("Bem vindo %s\n", usuario);
						do {
							menu_clientes();
							scanf("%d", &opcao3);
							if (opcao3 == 1) {


								ordenação_veiculos(veiculos);
								LocalizarVeiculos(veiculos);
								
								if (Reservar_Veiculo(veiculos,NIF)) {
									printf("Reserva bem sucedida\n");
									GuardarVeiculos_Binario(veiculos);
									GuardarVeiculos(veiculos);
									GuardarReservas(reservas);
									printf("*--------------------------------------------*\n");
									printf("|              DADOS ATUALIZADOS             |\n");
									printf("|                 FACA LOGIN!!!              |\n");
									printf("*--------------------------------------------*\n");
									break;
								}
								else {
									printf("Veiculo indisponivel\n");

								}
								
								

							}
							else if (opcao3 == 2) {
								if (Cancelar_Reserva(veiculos, NIF)) {
									GuardarVeiculos_Binario(veiculos);
									GuardarVeiculos(veiculos);
									break;
								}
								else {
									printf("*---------------------------------------------*\n");
									printf("|   ESTE VEICULO JA SE ENCONTRA DISPONIVEL    |\n");
									printf("*---------------------------------------------*\n");
								}
								
								
								
							}
							else if (opcao3 == 3) {

								clientes = saldo(clientes, NIF);
								GuardarClientes_Binario(clientes);
								GuardarClientes(clientes);
								imprimir_clientes(clientes);
								break;

							}
							else if (opcao3 == 4) {
								clear();
								AlterarDados(clientes, NIF);
								GuardarClientes_Binario(clientes);
								GuardarClientes(clientes);
								
								
							}
							else if (opcao3 == 5) {
								veiculos = imprimir_reservas(veiculos, NIF);


							}
							else if (opcao3 == 6) {

								

							

							}
						} while (opcao3 != 0);
						


					}
					else {
						printf("Nome de usuario ou NIF incorretos.\n");
					}
				
				

			}

		}
		else if (opcao == 0) {
			printf("Obrigado pela sua visita...\n");

		}


	} while (opcao != 0);






	return 0;

}



