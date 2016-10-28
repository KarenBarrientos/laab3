#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void imprimir(int**,int,int);

int main(int argc, char const *argv[]){
	int opcion;
	char continuar;
	do{
		cout<<endl;
		cout <<"***** MENU ***** "<< endl 
         << "1. Ejercicio1" << endl
         << "2. Ejercicio2" << endl
         << "3. Ejercicio3" << endl
         << "4. Salir" << endl;
         cin >> opcion;

		if (opcion == 1){
			int anio=1901;
			int final = 2000;
			int domingos = 0;
			int cantidadDias=1;
			int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
 			cout<<"-------------- EJERCICIO 1 --------------"<<endl;
			for(int i=anio; i<=final; i++){
				for(int j=0;j<12;j++){
					if(i>1901){
						if(cantidadDias%7==0){
							domingos++;
						}
					}
					int dias=0;
					if(j!=1 || i%4!=0 || (i%100==0 && i%400!=0)){ // comparando meses y el año divisible entre 4 y 400
						dias= meses[j];
					}
					else{ // febrero
						dias = 29;
					}
					cantidadDias += dias;
				}
			} //fin for
			cout<<"Hay "<<domingos+1 <<" domingos"<<endl;
			
		} // fin if 

		if (opcion==2){
			int gradoAlto,contador=0,polinomio;
			int a;
			cout<<"-------------- EJERCICIO 2 --------------"<<endl;
			cout<<"Ingrese el grado mas alto del polinomio: "<<endl;
			cin>>gradoAlto;

			int** matriz = new int*[3];			
 			for(int i=0;i<gradoAlto;i++){
 				matriz[i]=new int[gradoAlto];
 			}
 			for(int i=gradoAlto; i>=0; i--){
				cout<<"Polinomio de grado x^"<<i<<":";
				cout<<"Ingrese el polinomio x^"<<i<<": ";
 				cin>> matriz[0][contador];
 				contador++;
 			}
 
			cout<<"Ingrese a:";
			cin>>a;
			
			for(int i=0;i<2;i++){
				if(i==0){
					matriz[1][0]=matriz[0][0];
					matriz[2][0]=matriz[0][0];
					imprimir(matriz,a,gradoAlto);
				}else{
					for(int j=1;j<=gradoAlto;j++){
						matriz[i][j]=matriz[i+1][j-1];
						matriz[i+1][j]=matriz[i-1][j]+matriz[i][j];
						imprimir(matriz,a,gradoAlto);
					}
				}
			}
			cout<<"El Residuo es :"<<matriz[2][gradoAlto]<<"\n";

			imprimir(matriz,a,gradoAlto);

			for(int i = 0;i<gradoAlto;i++){
					delete[] matriz[i];
			}
			delete[] matriz;
			
		}// fin if2

		if (opcion==3){
			int numero;
			cout<<"Ingrese numero: "<<endl;
			cin>>numero;

			//int arreglo[];

		}

		cout<<"Desea Continuar[s/n]: ";
		cin>>continuar;

	}while(continuar == 's'||continuar == 'S');

	return 0;
}

void imprimir(int** matrix,int a,int grado){
	for(int i=0;i<3;i++){
		for(int j=0;j<grado+1;j++){
			cout<<" "<<matrix[i][j];
		}

		if(i<2){
			cout<<"| "<<a;
		}

		cout<<"\n";
		if(i==2){
			cout<<"------------------------ \n";
		}
	}
	cout<<"\n";
}