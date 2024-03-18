#include <stdio.h>
#include <math.h>

float f(float x);
float simpson(float (*)(float), float , float ,int );
float trapezio(float (*)(float), float , float , int );

int main(){

  float a,b,accuratezza, inSimpson1, inSimpson2, inTrap1, inTrap2;
  int nS = 2, nT=1;

  printf("Definire gli estremi dell'intervallo: ");
  scanf("%f %f",&a,&b);

  if(a > b){
    float temp = a;
    a = b;
    b = temp;
  }

  if(a == b){
    printf("ERRORE: gli estremi devono essere diversi!\n");
    return 1;
  }

  printf("Definire l'accuratezza: ");
  scanf("%f", &accuratezza);

  if(accuratezza <= 0){
    printf("ERRORE: l'accuratezza deve essere positiva!\n");
    return 1;
  }

    while(1){
      inSimpson1 = simpson(f,a,b,nS);
      inSimpson2 = simpson(f,a,b,nS*2);
      if(fabs(inSimpson1 - inSimpson2) < accuratezza) break;
      nS = 2*nS;
    }


    while (1){
      inTrap1 = trapezio(f,a,b,nT);
      inTrap2 = trapezio(f,a,b,2*nT);
      if(fabs(inTrap1 - inTrap2) < accuratezza) break;
      nT= 2*nT;
    }

    printf("L'integrale calcolato col metdodo di Simpson con %d sottointervalli vale: %.4f\n", nS,inSimpson2);
    printf("L'integrale calcolato col metdodo dei trapezi con %d sottointervalli vale: %.4f\n", nT,inTrap2);

    return 0;
  }

  float f(float x){
    return sqrt(sin(x));
  }

  float simpson(float funzione(float), float a, float b,int n){
    float somma = 0;
    float h,xi;

    h=(b-a)/n;

    for(int i = 0; i <= n; i++){
      xi = a + i*h;

      if(i == 0 || i == n)
        somma += funzione(xi);
      else{
        if(i % 2 == 0)
        somma += 2*funzione(xi);
      else
        somma += 4*funzione(xi);
      }
    }

    somma = somma*h/3;

    return somma;
  }

  float trapezio(float funzione(float), float a, float b, int n){
    float somma = 0;
    float h,xi;

    h=(b-a)/n;

    for(int i = 0; i <= n; i++){
      xi = a + i*h;

      if(i == 0 || i == n)
        somma += 0.5*funzione(xi);
      else
        somma += funzione(xi);
    }

    somma = somma*h;

    return somma;

  }
