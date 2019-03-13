#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Elaborar rotina computacional para solução de equações de 3º grau utilizando os métodos estudados até este ponto do capítulo.*/

float f(float x){
	return (pow(x,3)+(2*pow(x,2))-(3*x)+3);
}
float med(float a, float b){
	return ((a+b)/2);
}
float erro(float atual, float ant)
{
	return ((atual-ant)/atual);
}
float x_novo(float a, float b){
	return (((a*f(b))-(b*f(a)))/(f(b)-f(a)));
}
float derivada(float x){
	return ((3*pow(x,2))+(4*x)-3);
}
float Newton(float x){
	return (x-(f(x)/derivada(x)));
}


int main(int argc, char *argv[]) {
	float a, b, x, ant, TOL, erro_aprox;
	int n, i, it=0;
	char caractere;
	double tempo;
	clock_t tempo_inicio, tempo_fim;
	double var_tempo;
	tempo_inicio= clock();
	
	printf("Sendo a funcao 'x^3+2x^2-3x+3' Escolha o metodo que voce quer utilizar para a resolucao da equacao de 3º grau:\n");
	printf("Para o metodo da bissecao, digite 'B'.\nPara o metodo da falsa posicao, digite 'F'.\nPara o metodo de Newton-Raphson, digite 'N'.\n");
	caractere= getchar();
	
	
	if(caractere=='B'){	//Se o método escolhido for o da bissecção.
	
	printf("\nEstime o intervalo onde esta o zero da funcao:\nx1:");
	scanf("%f", &a);
	printf("x2:");
	scanf("%f", &b);
	printf("Digite a tolerancia para erro de zero da funcao (10^-TOL): ");
	scanf("%d", &n);
	
	TOL = pow(0.1,n);
	erro_aprox =erro(a,b);
	if(erro_aprox<0)
	erro_aprox*=-1;	

	system("cls");

	if(f(a)==0){
	printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: 0.0\nForam realizadas %d iteracoes.", a, a, f(a), it);
	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	exit(1);
	}
	if(f(b)==0){
	printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: 0.0\nForam realizadas %d iteracoes.", b, b, f(b), it);
	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	exit(1);
	}
	
	if(f(a)*f(b)>0){
		if(derivada(a)*derivada(b)<0){
			tempo_fim= clock();
			var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
			printf("\nTempo de processamento: %lf s.\n", var_tempo);
			printf("\n\nSupoe-se que nao ha zero da funcao no intervalo escolhido, pois f(%f)*f(%f)<0.\n", a,b);
			printf("Porem ha um(ns) ponto(s) de minimo ou maximo no intervalo escolhido. \nConsidere diminuir o intervalo proposto para melhor analisarmos se ha ou nao zero da funcao nesse intervalo.");
			printf("\nf(%f)=%f e f(%f)=%f", a, f(a), b, f(b));
			exit(1);
		}
		else{
			tempo_fim= clock();
			var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
			printf("\nTempo de processamento: %lf s.\n", var_tempo);
			printf("\n\nNao ha zero da funcao no intervalo escolhido !!!\n f(%f)=%f e f(%f)=%f", a, f(a), b, f(b));
			exit(1);
		}
	}
	else{
	printf("\nInicio: Intervalo=[a,b]; 	a=%f;	b=%f;	x=-------;	f(x)=-------;	Erro aproximado=%f", a, b, erro_aprox);
	while(erro_aprox>TOL){
		x= med(a,b);
		if(f(a)*f(x)<0)
		  b= x;
		if(f(b)*f(x)<0)
		  a= x;
		  it++;
		  
		erro_aprox =erro(a,b);
		if(erro_aprox<0)
		erro_aprox*=-1;			  
		printf("\nIteracao %d:  a=%f;	b=%f;	x=%f;	f(x)=%f;	Erro aproximado=%f",it, a, b, x, f(x), erro_aprox);
	}
	}	
	
		printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: %f\nForam realizadas %d iteracoes.", x, x, f(x), erro_aprox, it);


	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	}
	
	if(caractere=='F'){		//Se o método escolhido for o da falsa posição.
	
	printf("\nEstime o intervalo onde esta o zero da funcao:\nx1:");
	scanf("%f", &a);
	printf("x2:");
	scanf("%f", &b);
	printf("Digite a tolerancia para erro de zero da funcao (10^-TOL): ");
	scanf("%d", &n);
	
	TOL = pow(0.1,n);
	erro_aprox=erro(a,b);
	if(erro_aprox<0)
	erro_aprox*=-1;	
	
	system("cls");
	
	if(f(a)==0){
	printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: 0.0\nForam realizadas %d iteracoes.", a, a, f(a), it);
	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	exit(1);
	}
	if(f(b)==0){
	printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: 0.0\nForam realizadas %d iteracoes.", b, b, f(b), it);
	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	exit(1);
	}
	
	if(f(a)*f(b)>0){
			if(derivada(a)*derivada(b)<0){
			tempo_fim= clock();
			var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
			printf("\nTempo de processamento: %lf s.\n", var_tempo);
			printf("\n\nSupoe-se que nao ha zero da funcao no intervalo escolhido, pois f(%f)*f(%f)<0.\n", a,b);
			printf("Porem ha um(ns) ponto(s) de minimo ou maximo no intervalo escolhido. \nConsidere diminuir o intervalo proposto para melhor analisarmos se ha ou nao zero da funcao nesse intervalo.");
			printf("\nf(%f)=%f e f(%f)=%f", a, f(a), b, f(b));
			exit(1);
		}
		else{
			tempo_fim= clock();
			var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
			printf("\nTempo de processamento: %lf s.\n", var_tempo);
			printf("\n\nNao ha zero da funcao no intervalo escolhido !!!\n f(%f)=%f e f(%f)=%f", a, f(a), b, f(b));
			exit(1);
		}
	}
	else{
	ant=0;
	printf("\nInicio: Intervalo=[a,b]; 	a=%f;	b=%f;	x=-------;	f(x)=-------;	Erro aproximado=0", a, b);
	
	while(erro_aprox>TOL){
		x= x_novo(a,b);
		erro_aprox =erro(x,ant);
		if(erro_aprox<0)
		erro_aprox*=-1;	
		
		ant=x;
		if(f(a)*f(x)<0)
		  b= x;
		if(f(b)*f(x)<0)
		  a= x;
		  it++;
				  
		printf("\nIteracao %d:  a=%f;	b=%f;	x=%f;	f(x)=%f;	Erro aproximado=%f",it, a, b, x, f(x), erro_aprox);
	}
			
		printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: %f\nForam realizadas %d iteracoes.", x, x, f(x), erro_aprox, it);


	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
}
}	

	if(caractere=='N'){		//Se o método escolhido for o de Newton-Raphson.
	
	printf("\nEstime um x inicial para o zero da funcao:\nx1:");
	scanf("%f", &a);
	printf("Digite a tolerancia para erro de zero da funcao (10^-TOL): ");
	scanf("%d", &n);
	
	ant=0;
	TOL = pow(0.1,n);
	erro_aprox=erro(a,ant);
	if(erro_aprox<0)
	erro_aprox*=-1;	
	
	system("cls");
	
	if(f(a)==0){
	printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: 0.0\nForam realizadas %d iteracoes.", a, a, f(a), it);
	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
	exit(1);
	}
	
	else{
	printf("\nInicio: x=%f;	f(%f)=%f;	Erro aproximado=0", a, a, f(a));
	ant=a;
	while(erro_aprox>TOL){
		a= Newton(a);
		erro_aprox =erro(a,ant);
		if(erro_aprox<0)
		erro_aprox*=-1;	
		
		ant=a;
		it++;
				  
		printf("\nIteracao %d:	x=%f;	f(x)=%f;	Erro aproximado=%f",it, a, f(a), erro_aprox);
	}
			
		printf("\n\nO zero da funcao aproximado e: x=%f\nSendo f(%f): %f\nE o erro aproximado e: %f\nForam realizadas %d iteracoes.", a, a, f(a), erro_aprox, it);


	tempo_fim= clock();
	var_tempo= (double)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\nTempo de processamento: %lf s.\n", var_tempo);
}
}	
	return 0;
}

