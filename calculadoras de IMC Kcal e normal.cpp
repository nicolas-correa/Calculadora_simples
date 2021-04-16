#include<iostream>
#include<conio.h>
#include<locale.h>

int main() {
	
	//"Puxando" a biblioteca de lingua portuguesa
	setlocale(LC_ALL, "Portuguese");

	//Declaração de variaveis
	double  peso, altura, num1, num2, resultadoIMC, resultadoCalcu, resultadoKcal, gasto, tempoKcal, pesoKcal;
	int operador, escolha, opcaoKcal, i, rc, rimc, rkcal,rp,rest;
	/** as variaveis : peso,altura,resultadoIMC(pertencem a calculadora de IMC)
	    as variaveis : operador,num1,num2,resultadoCalcu(pertencem a caculadora normal)
		as variaveis : gasto,tempoKcal,pesoKcal,opcaoKcal(pertence a calculadora de Kcal)
		escolha é a variavel primaria do programa
		rc.rimc,rkcal,rp,i(sçao variaveis para o comando while para reiniciar o programa o qual se encontra)**/
	
	i = 0; rc = 0; rimc = 0; rkcal = 0; rp = 0;
    
	//mensagens primarias e leitura de variavel
	printf("			_____________________\n");
	printf("			____Calculadoras_____\n");
	printf("			_____________________\n\n");
	do{
		printf("\nPara calcular o IMC digite 1\n");
		printf("Para calculadora normal digite 2\n");
		printf("Para calcular a quantidade de caloria gasta no exercicio digite 3\n\n");
		printf("Opção : ");
		std::cin >> escolha;

	
		//encontrando a opção escolhida
		switch (escolha) {

			//IMC
		case 1:
			do {

				printf("\n___Calculadora de IMC___\n");
				//recebendo variaveis
				printf("\nDigite o seu peso = ");
				std::cin >> peso;
				printf("Digite sua altura em centimetros = ");
				std::cin >> altura;

				//calculo do IMC
				resultadoIMC = (peso) / ((altura * altura) / 10000.0);

				printf("\nSeu IMC é %.2lf\n\nTabela de IMC :\nMenor que 16,0 - Magreza moderada\n", resultadoIMC);
				printf("16,0 até 17,0 - Magreza moderada\n17,0 até 18,5 - Magreza leve\n18,5 até 25,0 - Saudável\n");
				printf("25,0 até 30,0 - Sobrepeso\n30,0 até 35,0 - Obesidade grau 1\n35,0 até 40,0 - Obesidade severa\n");
				printf("Acima de 40,0 - Obesidade mórbita");
				//sair da calculadora de imc
				printf("\n\nPara sair da calculadora de IMC digite 1 : ");
				std::cin >> rimc;
			} while (rimc != 1);
			break;

			//Calculadora normal
		case 2:
		do{	
			printf("\n___Calculadora Simples___\n");
			/** Escolha de operador =
			+ -- 1
			- -- 2
			* -- 3
			/ -- 4  **/
			do {
				printf("\nPara\n'+' Digite 1\n'-' Digite 2\n'*' Digite 3\n'/' Digite 4\nOpção : ");
				std::cin >> operador;

				// Recebendo o valor das variaveis 
				printf("\nVariavel 1 = ");
				std::cin >> num1;
				printf("Variavel 2 = ");
				std::cin >> num2;

				//Caculando
				if (operador == 1) {
					resultadoCalcu = num1 + num2;
					printf("\n%.f + %.f = %.f\n", num1, num2, resultadoCalcu);
					rc = 1;
				}
				else if (operador == 2) {
					resultadoCalcu = num1 - num2;
					printf("\n%.f - %.f = %.f\n", num1, num2, resultadoCalcu);
					rc = 1;
				}
				else if (operador == 3) {
					resultadoCalcu = num1 * num2;
					printf("\n%.f * %.f = %.f\n", num1, num2, resultadoCalcu);
					rc = 1;
				}
				else if (operador == 4) {
					//verificar se é divição por 0
					if (num2 == 0) {
						printf("\nDivição por zero não capaz de ser realizada\n");
						rc = 1;
					}
					else {
						resultadoCalcu = num1 / num2;
						printf("\n%.f / %.f = %.f\n", num1, num2, resultadoCalcu);
						rc = 1;
					}
				}
				else {
					printf("Algo deu errado , por favor digite 0 para reiniciar a Calculadora : ");
					std::cin >> rc;
				}
			} while (rc != 1);
			printf("\n\nPara sair da calculadora digite 1 : ");
			std::cin >> rp;
		} while (rp != 1);

			break;

			//Calculadora de Kcal
		case 3:
		
			/** capitura de dados para o calculo de Kcal **/
			do {
				printf("Qual esporte gostaria de calcular o gasto médio ?\n\n");
				printf("1-Caminhada\n2-Corrida\n3-Ciclismo\n4-Pular Corda\n5-Musculação\n\nOpção: ");
				std::cin >> opcaoKcal;

				printf("\n\nDigite seu peso : ");
				std::cin >> pesoKcal;

				printf("Digite o tempo de exercicío(em minutos) : ");
				std::cin >> tempoKcal;

				//adicionando os valores respectivos de gastos

				if (opcaoKcal == 1) { gasto = 4.1; }
				if (opcaoKcal == 2) { gasto = 8.3; }
				if (opcaoKcal == 3) { gasto = 5.0; }
				if (opcaoKcal == 4) { gasto = 8.2; }
				if (opcaoKcal == 5) { gasto = 3.5; }
				//total=((calor*PESO)/50)*tempo
				resultadoKcal = ((gasto * pesoKcal) / 50.0) * tempoKcal;
				printf("Seu gasto médio nesse execicío é de %.0f Kcal\n", resultadoKcal);

				printf("Para sair da calculadora de Kcal digite 1 : ");
				std::cin >> rkcal;
			} while (rkcal != 1);
		
			break;

		default:if (escolha != 1 && escolha != 2 && escolha != 3) {do{
			printf("opção inexistente,digite 1 para sair do programa : ");
			std::cin >> rest;
			}while (rest != 1);
		}
		}
		printf("\nPara sair do programa digite 1 = ");
		std::cin >> i;
	} while (i != 1);
}