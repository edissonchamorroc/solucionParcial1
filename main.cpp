#include <iostream>
#include<math.h>
using namespace std;


double distanciaentrecanones(double *arregloO,double *arregloD);
double tiempo(double *arregloO,bool colision);
void disparoOfensivo(double *datosofensivos,double *, double tiempo);
void sensorO(double *arregloO,double *arregloD,int distancia);

int main()
{   double *arregloOfensivo=new double[4],*arregloDefensivo=new double[4],dato,tiempo=0.0,distancia;//x,y,angulo,velocidad
    bool colision=true;
    cout<<"Ingrese datos del canon ofensivo de la siguiente manera: posicion en x\nposicion en y\nvelocidad inicial de disparo\nangulo de disparo";
    for(int i=0;i<5;i++){
        cout<<"Dato"<<i+1<<": ";
        cin>>dato;
        arregloOfensivo[i]=dato;
    }
    cout<<"Ingrese datos del disparo ofensivo de la siguiente manera: posicion en x\nAltura de canon";
    for(int i=0;i<2;i++){
        cout<<"Dato"<<i+1<<": ";
        cin>>dato;
        arregloDefensivo[i]=dato;
    }

   distancia=distanciaentrecanones(arregloOfensivo,arregloDefensivo);
   disparoOfensivo(arregloOfensivo,arregloDefensivo,tiempo);




   return 0;
}
double distanciaentrecanones(double *arregloO,double *arregloD){
    double distancia;
    distancia=abs(*(arregloD+0)-*(arregloO+0));
    return distancia;
}
void sensorO(double *arregloO,double *arregloD,int distancia){
    double rango=*(arregloO+0)+0.025*distancia;
    //if(*(arregloD+0)>*(arregloO+0) & *(arregloD+0)<=rango){

    }


double tiempo(double *arregloO, bool colision){
    double time;
    if(*(arregloO+1)!=0 | colision==false){
        time+=0.1;

    }
    return time;
}

void disparoOfensivo(double *datosofensivos,double *datosdefensivos, double tiempo){
    double g=9.8,vytO=0.0,distancia;
    bool bandera=true;
    distancia=distanciaentrecanones(datosofensivos,datosdefensivos);
    sensorO(datosofensivos,datosdefensivos,distancia);
    while(tiempo>=0){

        *(datosofensivos+0)=*(datosofensivos+0)+cos(*(datosofensivos+4))*(tiempo);
        vytO=*(datosofensivos+4)*sin(*(datosofensivos+3))-g*(tiempo);
        *(datosofensivos+1)=*(datosofensivos+1)+vytO-(0.5)*g*(tiempo)*(tiempo);
     }
}
void infiltrado(double tiempo, double *datosofensivos, double *datoscontraataque){
    if(tiempo>=2.0){
       *(datoscontraataque+0)=*(datosofensivos+0);
        *(datoscontraataque+0)=*(datosofensivos+1);
        *(datoscontraataque+0)=*(datosofensivos+2);
        *(datoscontraataque+0)=*(datosofensivos+4);
      }
}
void disparodefensivo(double *datosdefensivos,double tiempo){
    double *datosof=new double[4];
    infiltrado(datosof,tiempo);
}
bool colision(bool bandera,double *datosofensivos, double *datosdefensivos, bool *ban){

    if(*(datosofensivos+1)==0 | (*(datosofensivos+0)==*(datosdefensivos+0) & *(datosofensivos+1)==*(datosdefensivos+1) )){*ban=false;}
    return ban;
}
