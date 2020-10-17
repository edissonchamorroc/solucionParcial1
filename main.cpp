#include <iostream>
#include<math.h>
using namespace std;

int main()
{


    return 0;
}
double distanciaentrecañones(double *arregloO,double *arregloD){

}
void sensorO(double *arregloO,int distancia){

}
void tiempo(double *arregloO,bool colision){
    double tiempo[1];
    while(*(arregloO+1)!=0 | colision==false){
        *(tiempo+0)+=0.1;
    }
}

void disparoOfensivo(double *datosofensivos, double *tiempo){
    double g=9.8,vytO=0.0;

    while(*tiempo>=0){
        *(datosofensivos+0)=*(datosofensivos+0)+cos(*(datosofensivos+4))*(*tiempo);
        vytO=*(datosofensivos+4)*sin(*(datosofensivos+3))-g*(*tiempo);
        *(datosofensivos+1)=*(datosofensivos+1)+vytO-(0.5)*g*(*tiempo);
    }
}
