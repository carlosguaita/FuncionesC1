#include <stdio.h>
#include <math.h>

double calcularDistancia(double x1, double x2, double y1, double y2);
double calcularHipotenusa(double x, double y);
double calculoAreaSombreada(double a, double b, double c);

int main (int argc, char *argv[]) {

    double P1x, P1y, P2x, P2y, P3x, P3y, e, d ,f, a, b, c, As;

    printf("Ingrese el primer punto X Y: ");
    scanf("%lf %lf",&P1x,&P1y);

    printf("Ingrese el segundo punto X Y: ");
    scanf("%lf %lf",&P2x,&P2y);

    printf("Ingrese el tercer punto X Y: ");
    scanf("%lf %lf",&P3x,&P3y);

    e=calcularDistancia(P1x,P2x,P1y,P2y);
    f=calcularDistancia(P2x,P3x,P2y,P3y);
    d=calcularDistancia(P1x,P3x,P1y,P3y);

  

    if(e<(f+d) || f<(e+d) || d<(e+f)){
          
        if(pow(e,2)==(pow(f,2)+pow(d,2))){
            a=e;
            if(f>=d){
                c=f;
                b=d;
            }else{
                c=d;
                b=f;
            }
        }else if(pow(f,2)==(pow(e,2)+pow(d,2))){
            a=f;
            if(e>=d){
                c=e;
                b=d;
            }else{
                c=d;
                b=e;
            }
        }else if(pow(d,2)==(pow(f,2)+pow(e,2))){
            a=d;
            if(f>=e){
                c=f;
                b=e;
            }else{
                c=e;
                b=f;
            }
        }else{
            printf("No es un triangulo rectangulo");
            return 0;
        }
        printf("e:%lf f:%lf d:%lf\n",e,f,d);
        
        As = calculoAreaSombreada(a,b,c);
        printf("El area sombreada es igual a: %lf",As);
    }


    return 0;
}

double calcularDistancia(double x1, double x2, double y1, double y2){
    double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return dist;
}

double calcularHipotenusa(double x, double y){
    double dist = sqrt(pow(x,2)-pow(y,2));
    return dist;
}


double calculoAreaSombreada(double a, double b, double c){
    double h1, z, w, h2, x, As;
    
    h1=b*a/c;
    z=sqrt(pow(b,2)-pow(h1,2));
    w=sqrt(pow(a,2)-pow(h1,2));
    h2=h1*w/a;
    x=sqrt(pow(h1,2)-pow(h2,2));
    //printf("a:%lf b:%lf c:%lf\n",a,b,c);
    //printf("h1:%lf h2:%lf w:%lf\n",h1,h2,w);
    As=x*h2/2;
    return As;
}