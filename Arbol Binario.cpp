#include<iostream>
#include<stdio.h>
#include<fstream>
#include<malloc.h>
#include<windows.h>
using namespace std;
struct AB{
	char dato;
	AB *izquierda;
	AB *derecha;
};
char datos[100];
int tomarDatos();
AB *crearArbol(char,char,char, AB *);
void crearNodo(char,char,AB *);
void Mostrar(AB *,int);
void MostrarHorizontal(AB *,int);
int auxX=0;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
int main(){
	AB *raiz=NULL;
	int h=0,f,cont=0;
	char padre,posicion,hijo;
	system("color 1F");
	int numero;
	numero=tomarDatos();
	f=numero;
	f=f/3;
	char coordenadas[f][3];
	for(int i=0;i<f;i++){
		for(int y=0;y<3;y++){
			coordenadas[i][y]=datos[h];
			h++;
		}
	}
	raiz = (AB* )malloc (sizeof(AB));
	raiz->dato=coordenadas[0][0];
	raiz->izquierda=NULL;
	raiz->derecha=NULL;
	AB *r=NULL;
	for(int i=0;i<f;i++){
		padre=coordenadas[i][0];
		posicion=coordenadas[i][1];
		hijo=coordenadas[i][2];
		r=crearArbol(padre,posicion,hijo,raiz);
	}
	cout<<"\t Arbol Binario:"<<endl;
	Mostrar(raiz,cont);
	//MostrarHorizontal(raiz,cont);
	return 0;
}
AB *crearArbol(char padre,char posicion,char hijo,AB *raiz){
	if(raiz==NULL){
		return 0;
	}else if(padre==raiz->dato){
		crearNodo(posicion,hijo,raiz);
	}else{
		crearArbol(padre,posicion,hijo,raiz->izquierda);
		crearArbol(padre,posicion,hijo,raiz->derecha);
	}
}
void crearNodo(char posicion,char hijo,AB *raiz){
	AB *nodoHijo=NULL;
	if(posicion=='I' || posicion=='i'){
		nodoHijo = (AB* )malloc (sizeof(AB));
		nodoHijo->dato=hijo;
		raiz->izquierda=nodoHijo;
		nodoHijo->derecha=NULL;
		nodoHijo->izquierda=NULL;
	}else if(posicion=='D' || posicion=='d'){
		nodoHijo = (AB* )malloc (sizeof(AB));
		nodoHijo->dato=hijo;
		raiz->derecha=nodoHijo;
		nodoHijo->derecha=NULL;
		nodoHijo->izquierda=NULL;
	}else{
		cout<<"\t...COORDENADA NO VALIDA..."<<endl;
		cout<<"Revise que en el archivo no hayan letras diferentes a: D o I"<<endl;
		exit(1);
	}
}
void MostrarHorizontal(AB* raiz,int auxY){
	if(raiz!=NULL){
		MostrarHorizontal(raiz->derecha,auxY+1);
		for(int i=0;i<auxY;i++){
			cout<<"   ";
		}
		cout<<raiz->dato<<endl;
		MostrarHorizontal(raiz->izquierda,auxY+1);
	}
}
void Mostrar(AB* raiz,int auxY){	
    if(raiz == NULL){//Arbol vacio nada que mostrar
        return;
    }
    auxX += 4;//variable que permite posicionarse en el eje X
    Mostrar(raiz -> izquierda,auxY+2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
    gotoxy(1+auxX-auxY , 1+auxY);//posiciona el nodo segun sus variables en X y en Y
    cout << raiz -> dato << endl << endl;//Muestra el dato del nodo respectivo
    Mostrar(raiz ->derecha,auxY+2);
	return;
}
int tomarDatos(){
	ifstream archivo;
	string texto;
	int u=0;
	archivo.open("Programacion.txt",ios::in);
	while(!archivo.eof()){
		archivo>>datos[u];
		u++;
	}
	archivo.close();
	return u;
}

