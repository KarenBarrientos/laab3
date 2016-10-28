#include <iostream>

using namespace std;

int menu();
int*** crearMatriz(int);


int main(int argc, char const *argv[]){
	int opcion;
	while ( (opcion = menu()) != 4){

		if (opcion == 1){
			int[] meses={31,0,31,30,31,30,31,31,30,31,30,31};
			int anio=1901, domingos=0;
			int CantidadMeses=0,CantidadDias=0;

			for (int i = 1; i <= 7; ++i){ 
				if (anio > 2000){
					cout<<domingos;
					return;
				}

				if (i == 1){ // para febrero
					if (anio%4 == 0 && anio%100 !=0){
						meses[1]=29;
					}
					if (anio%4 == 0 && anio%100 == 0){
						meses[1]=28;
					}
					if (anio%4 != 0 && anio%400 !=0){
						meses[1]=28;
					}
				}



			}// fin for
			
 
		} // fin if 

		if (opcion==2){
			int gradoAlto;
			cout<<"-------------- EJERCICIO 2 --------------"<<endl;
			cout<<"Ingrese el grado mas alto del polinomio: "<<endl;
			cin>>gradoAlto;
			crearMatriz(gradoAlto);
			for (int i = 0; i < gradoAlto; ++i){
				
			}

		}// fin if2

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
