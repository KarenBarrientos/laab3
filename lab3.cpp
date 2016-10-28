#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int menu();
void impresion(int***,int,int);

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

			int*** matriz = new int**[gradoAlto+1];
			for(int i = 0;i<gradoAlto+1;i++){
				matriz[i] = new int*[3];
				for(int j = 0;j < 3;j++){
					matriz[i][j] = new int[gradoAlto+1];
				}
			}
			for(int i = gradoAlto;i>=0;i--){
				cout<<"Ingrese el polinomio de grado x^"<<i<<": ";
				cin>>polinomio;
				matriz[0][0][contador] = polinomio;
				contador++;
			}
			cout<<"Ingrese a: ";
			cin>>a;

			for(int i=0;i<gradoAlto;i++){
				for(int j=0; j<2; j++){
					if(j == 0){
						matriz[i][1][0] = matriz[i][0][0];
						matriz[i][2][0] = matriz[i][0][0];
					}else{
						for(int k = 1; k<=gradoAlto; k++){
							matriz[i][j][k] = matriz[i][j+1][k-1] * a;
							matriz[i][j+1][k] = matriz[i][j-1][k] + matriz[i][j][k];
						}
					}
				}
			}
			cout<<endl<<"Residuo= "<<matriz[0][2][gradoAlto];
			impresion(matriz,a,gradoAlto);
			for(int i = 0;i<gradoAlto;i++){
				for(int j = 0;j < 3;j++){
					delete[] matriz[i][j];
				}
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

	}while(opcion = menu() != 4 && continuar == 's'||continuar == 'S');

	return 0;
}


void impresion(int*** matrix,int a,int grado){
	for(int i = 0;i< grado+1;i++){
		cout<<setfill('-')<<setw(20);
		for(int j = 0;j<3;j++ ){
			for(int k = 0;k<grado+1;k++){
				cout<<setfill(' ')<<setw(4)<<matrix[i][j][k];
			}
			if(j== 0){
				cout<<"|"<<a;
			}
			cout<<endl;
		}
		cout<<endl;
	}
}