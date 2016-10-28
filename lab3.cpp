#include <iostream>
#include <string>

using namespace std;

int menu();
int*** crearMatriz(int);


int main(int argc, char const *argv[]){
	int opcion;
	while ( (opcion = menu()) != 4){

		if (opcion == 1){
			int anio=1901;
			int final = 2000;
			int domingos = 0;
			int cantidadDias=1;
			int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
 
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
			int gradoAlto,contador=0;
			cout<<"-------------- EJERCICIO 2 --------------"<<endl;
			cout<<"Ingrese el grado mas alto del polinomio: "<<endl;
			cin>>gradoAlto;

			int** matriz = new int*[3];
			
			for(int i=0;i<gradoAlto;i++){
				matriz[i]=new int[gradoAlto];
			}
			for(int i=gradoAlto; i>=0; i--){
				cout<<"Polinomio de grado x^"<<i<<":";
				cin>> matriz[0][contador];
				contador++;
			}

			//efectuarDivision(matriz, tamanio);
			//crearMatriz(matriz,gradoAlto);

		}// fin if2

		if (opcion==3){
			
		}

	}// fin while

	return 0;
}

int menu(){
    cout<<endl;
    cout <<"***** MENU ***** "<< endl 
         << "1. Ejercicio1" << endl
         << "2. Ejercicio2" << endl
         << "3. Ejercicio3" << endl
         << "4. Salir" << endl;
    int opcion;
    do{
        cin >> opcion;
        if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
            cerr << "Introduzca un valor correcto" << endl;
    }while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

    return opcion;
}

int*** crearMatriz(int size){
	int*** matriz=new int**[size];
	for (int i = 0; i < size; ++i){
		matriz[i]=new int*[3];
	}
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < 3; ++j){
			matriz[i][j]= new int[size];
		}
	}
	return matriz;

}
