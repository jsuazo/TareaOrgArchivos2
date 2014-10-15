// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{
    ofstream out(nombre_archivo.c_str());//Abrimos el archivo

    for(list<Cumpleanios*>::iterator i = cumpleanios.begin();
    i!=cumpleanios.end();
    i++) //Recorre la lista
    {
        out<<(*i)->cumpleaniero;
        out<<" ";
        out<<(*i)->mes;
        out<<" ";
        out<<(*i)->dia;
        out<<" "<<endl; //Escritura del cumpleaniero, mes y dia de cumpleaños
    }
    out.close();//Cerramos
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
list<Cumpleanios*> leer(string nombre_archivo)
{
    list<Cumpleanios*>cumpleanios;

     ifstream in(nombre_archivo.c_str()); //Apertura del archivo

    string cumpleaniero;
    int mes;
    int dia; // Variables para guardar datos

    while(in>>cumpleaniero) //Mientras hayan cumpleañeros
    {
        in>>mes;
        in>>dia; //se extrae el mes y el dia

        cumpleanios.push_back(new Cumpleanios(cumpleaniero,dia,mes)); //se inserta a la lista
    }

    return cumpleanios;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
