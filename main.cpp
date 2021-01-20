#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    struct nodo *izq; //declara mi estructura izq y dere
    struct nodo *der; //declara mi estructura dere y izq
};
typedef  struct nodo * ARBOL;
typedef struct nodo *lista_doble;


void menu1 ()
{
    cout << "\t\t*************LISTA DOBLEMENTE ENLAZADA*************"               <<endl;
    cout << "1. INSERTAR POR IZQUIERDA"                    <<endl;
    cout << "2. IMPRIMIR LISTA DOBLE POR IZQUIERDA"        <<endl;
    cout << "3. INSERTAR POR DERECHA"                      <<endl;
    cout << "4. IMPRIMIR LISTA DOBLE POR DERECHA"          <<endl;
    cout << "\t\t************** ARBOL *************"        <<endl;
    cout << "5. INSERTAR NODO           "                  <<endl;
    cout << "6. VER ARBOL               "                  <<endl;
    cout << "7. RECORRIO PREORDEN        "                 <<endl;
    cout << "8. RECORRIO POSTORDEN      "                  <<endl;
    cout << "9. RECORRIO INORDEN        "                  <<endl;
    cout << "10. LAS HOJAS SON           "                 <<endl;
    cout << "11.BORRA NODO"                                <<endl;
    cout << "0. SALIR"                                     <<endl;
    cout << "\n INGRESE OPCION :" ;
}


//********LISTA DOBLEMENTE ENLAZADA**************
//crear un funcion ultimo en vez de apuntar nodo 1
void insertarizq (lista_doble &cabeza ,lista_doble &ultimo , int valor)
{

    lista_doble nodo1;
    nodo1 = new(struct nodo);
    nodo1->dato =valor;
    nodo1->izq =NULL;
    nodo1->der =NULL;

    if (cabeza==NULL)
    { // si la cabeza no tiene datos ,cabeza apunta a mi nodo1
        nodo1->izq=cabeza;
        cabeza= nodo1;

        if (ultimo==NULL)
            ultimo = cabeza;
    }

    else
    {
        cabeza->der = nodo1;
        nodo1->izq = cabeza;
        cabeza = nodo1;

    }
}

void imprimirizq (lista_doble &cabeza)
{
    lista_doble lista_imprimir;
    lista_imprimir = cabeza;

    while (lista_imprimir !=NULL)
    {
        cout << "-" << lista_imprimir->dato <<endl;
        lista_imprimir = lista_imprimir->izq;

    }
}

void insertarder (lista_doble &cabeza ,lista_doble &ultimo , int valor)
{

    lista_doble nodo1;
    nodo1 = new(struct nodo);
    nodo1->dato =valor;
    nodo1->izq =NULL;
    nodo1->der =NULL;

    if (cabeza==NULL)
    { // si la cabeza no tiene datos ,cabeza apunta a mi nodo1
        nodo1->der=ultimo;
        ultimo= nodo1;

        if (ultimo==NULL)
            ultimo = cabeza;
    }

    else
    {
        cabeza->izq = nodo1;
        nodo1->der = ultimo;
        ultimo = nodo1;

    }
}

void imprimirder (lista_doble &cabeza)
{
    lista_doble lista_imprimir;
    lista_imprimir = cabeza;

    while (lista_imprimir !=NULL)
    {
        cout << "-" << lista_imprimir->dato <<endl;
        lista_imprimir = lista_imprimir->der;

    }
}

//********ARBOL BINARIO**************
ARBOL crearNodo(int x)
{

    ARBOL nuevoNodo = new (struct nodo);
    nuevoNodo->dato=x;
    nuevoNodo->izq=NULL;
    nuevoNodo->der=NULL;
    return nuevoNodo;
}

void insertar(ARBOL &arbol, int x)
    {
        if(arbol==NULL)
            arbol=crearNodo(x);
        else if (x < arbol->dato)
            insertar(arbol->izq ,x);
        else if (x > arbol->dato)
            insertar(arbol->der ,x);
     }

void preOrden (ARBOL &arbol)
{
        ARBOL temporal = new(struct nodo);
        temporal=arbol;
        if(temporal!=NULL)
        {
            cout << temporal->dato << " ";
            preOrden(temporal->izq);
            preOrden(temporal->der);
        }
}

void inOrden(ARBOL & arbol)
{
    ARBOL temporal = new(struct nodo);
    temporal=arbol;
    if(temporal!=NULL)
    {
        inOrden(temporal->izq);
        cout << temporal->dato << " ";
        inOrden(temporal->der);
    }
}


void posOrden (ARBOL & arbol)
{
    ARBOL temporal = new(struct nodo);
    temporal=arbol;
      if(temporal!=NULL)
      {
       posOrden(temporal->izq);
       posOrden(temporal->der);
       cout << temporal->dato << " ";
      }
}


void verArbol(ARBOL &arbol, int n)
{
ARBOL temporal = new(struct nodo);
temporal=arbol;

if (temporal==NULL)
return;

verArbol(temporal->der, n+1);
for (int i=0; i<n; i++)
        cout<<"  ";
cout << temporal->dato<<endl;
verArbol(temporal->izq,+n+1);
}




int contarHojas(ARBOL arbol)
{
    if (arbol==NULL)
            {
                    return 0;
            }
            if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
            {
                    return 1;
            }
            else
            {
                    return contarHojas(arbol->izq) + contarHojas(arbol->der);
            }
}

int borrarNodo(ARBOL arbol)
{
    if (arbol==NULL)
            {
                    return 0;
            }
            if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
            {
                    return 1;
            }
            else
            {
                    return borrarNodo(arbol->izq);
                    return borrarNodo(arbol->der);
            }
}
int main()
{
    //Lista doblemente enlazada
    lista_doble listaizq = NULL;
    lista_doble listader = NULL;

    //Arbol
    ARBOL arbol=NULL;


    int opcion; //para las opciones del menú
    int valor; // elemento a ingresar

    do{
        menu1(); cin>>opcion;
        switch(opcion)
        {
        case 1:
            cout << "\n NUMERO A INSERTAR POR IZQUIERDA:" ; cin >>valor;
            insertarizq (listaizq,listader,valor);
            break;


        case 2:
            cout << "\n\n ELEMENTOS LISTA DOBLE POR IZQUIERDA \n\n";
            imprimirizq(listaizq);
            break;

        case 3:
            cout << "\n NUMERO A INSERTAR POR DERECHA:" ; cin >>valor;
            insertarder (listader,listaizq,valor);
            break;


        case 4:
            cout << "\n\n ELEMENTOS LISTA DOBLE POR DERECHA \n\n";
            imprimirder(listader);
            break;

       case 5:
           cout << "\n INSERTAR NODO EN EL ARBOL: " ; cin>>valor;
           insertar (arbol ,valor);
           break;

       case 6:
          cout << "\n VER ARBOL \n\n";
          verArbol (arbol ,0);
          break;

       case 7:
          cout << "\n\n PreOrden: ";
          preOrden(arbol);
          break;

       case 8:
         cout << "\n\n PostOrden: ";
         posOrden(arbol);
         break;

      case 9:
         cout << "\n\n InOrden: ";
         inOrden(arbol);
         break;


       case 10:
          cout << "\n\n El numero de hojas es";
          int hojas;
          hojas=contarHojas(arbol);
          cout <<  hojas  <<    "  " ;
          break;

       case 11:
           cout << "\n\nBorrar nodo";
           int borrar;
           borrar=borrarNodo(arbol);
           cout << borrar << " ";
            break;



        }
    }while (opcion!=0);
    system ("pause");
    return 0;
}
