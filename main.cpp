#include <iostream>
#include<math.h>
using namespace std;


double distanciaentrecanones(double *arregloO,double *arregloD);
double time(double *arregloO,bool colision);
void disparoOfensivo(double *datosofensivos,double *, double tiempo,bool *);
void sensorO(double *arregloO,double *arregloD,int distancia);
void infiltrado( double *datosofensivos, double *datoscontraataque);
void disparodefensivo(double *datosdefensivos,double *datosinfiltrado,double tiempo,bool *);
bool colision(double *datosofensivos, double *datosdefensivos, bool *ban);
int main()
{   double *arregloOfensivo=new double[4],*arregloDefensivo=new double[4], *datosinfiltrado=new double[4],dato,tiempo=0.0,distancia;//x,y,angulo,velocidad
    bool colision=true;
    bool *coli=&colision;
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
    infiltrado(arregloOfensivo,datosinfiltrado);
   while(colision==true){
       tiempo=time(arregloOfensivo,coli);
       disparoOfensivo(arregloOfensivo,arregloDefensivo,tiempo,coli);
       disparodefensivo(arregloDefensivo,datosinfiltrado,tiempo,coli);
   }







   return 0;
}
double distanciaentrecanones(double *arregloO,double *arregloD){
    double distancia;
    distancia=abs(*(arregloD+0)-*(arregloO+0));
    return distancia;
}



double time(double *arregloO, bool *colision){
    double time;
    if(*(arregloO+1)!=0 | *colision==false){
        time+=0.1;
    }
    return time;
}

void disparoOfensivo(double *datosofensivos,double *datosdefensivos, double tiempo,bool *bandera){
    double g=9.8,distancia;

    distancia=distanciaentrecanones(datosofensivos,datosdefensivos);
    while(tiempo>=0){

        *(datosofensivos+0)=*(datosofensivos+0)+(*(datosofensivos+3))*cos(*(datosofensivos+3))*(tiempo);
        *(datosofensivos+1)=*(datosofensivos+1)+(*(datosofensivos+3))*sin((*(datosofensivos+2)))-(0.5)*g*(tiempo)*(tiempo);
        colision(datosofensivos,datosdefensivos,bandera);
     }
}
void infiltrado( double *datosofensivos, double *datoscontraataque){

       *(datoscontraataque+0)=*(datosofensivos+0);
        *(datoscontraataque+0)=*(datosofensivos+1);
        *(datoscontraataque+0)=*(datosofensivos+2);
        *(datoscontraataque+0)=*(datosofensivos+4);

}
void disparodefensivo(double *datosdefensivos,double *datosinfiltrado,double tiempo,bool *bandera){
    double g=9.8,vytD=0.0,distancia;

    if(tiempo>=2.5){
    while(tiempo>=0){
        *(datosdefensivos+0)=*(datosdefensivos+0)+(*(datosdefensivos+3))*cos(*(datosdefensivos+3))*(tiempo);
        *(datosdefensivos+1)=*(datosdefensivos+1)+(*(datosdefensivos+3))*sin((*(datosdefensivos+2)))-(0.5)*g*(tiempo)*(tiempo);
        colision(datosdefensivos,datosdefensivos,bandera);

     }
    }}


bool colision(double *datosofensivos, double *datosdefensivos, bool *ban){
    if(*(datosofensivos+1)==0 | (*(datosofensivos+0)==*(datosdefensivos+0) & *(datosofensivos+1)==*(datosdefensivos+1) )){*ban=false;}
    return ban;
}
