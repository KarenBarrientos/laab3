#include <iostream>
#include <string>

using namespace std;

int menu();
int*** crearMatriz(int);
void imprimir(int** matrix,int Dividiendo,int grado);

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
			int a;
			cout<<"-------------- EJERCICIO 2 --------------"<<endl;
			cout<<"Ingrese el grado mas alto del polinomio: "<<endl;
			cin>>gradoAlto;

			int** matriz = new int*[3];

			for(int i=0;i<gradoAlto;i++){
				matriz[i]=new int[gradoAlto];
			}
			for(int i=gradoAlto; i>=0; i--){
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

			//efectuarDivision(matriz, tamanio);
			//crearMatriz(matriz,gradoAlto);

		}// fin if2

		if (opcion==3){
			int numero;
			cout<<"Ingrese numero: "<<endl;
			cin>>numero;

			//int arreglo[];

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

void imprimir(int** matrix,int Dividiendo,int grado){
	for(int i=0;i<3;i++){
		for(int j=0;j<grado+1;j++){
			cout<<" "<<matrix[i][j];
		}
		if(i<2){
			cout<<"| "<<Dividiendo;
		}
			
		cout<<"\n";
		if(i==2){
			cout<<"------------------------ \n";
		}
	}
	cout<<"\n";
	
}