#include <iostream>
#include <string>
using namespace std;

int largo(string romano){
    int cont=0;
    for(int i=0;romano[i]!='\0';i++,cont++);
    return cont;
}

int buscador(string simbolo, char c){
    for (int i=0;i< largo(simbolo);i++){
        if(simbolo[i]==c){
            return i;
        }
    }
    return 0;
}
void Decimal (string numRomano){
    int valor[] = {1000, 500, 100, 50, 10, 5, 1};
    string simbolo = "MDCLXVI";
    char c;
    int resultado=0;
    int i=0;
    int j=0;
    int ultimovalor=0;
    bool valido=true;
    while(valido && (i < largo(numRomano))){
        c = numRomano[i];
        j = buscador(simbolo,c);
        if(j>=0){
            resultado += valor[j];
            if(valor[j] > ultimovalor){
                resultado -= 2 * ultimovalor;
            }
            ultimovalor = valor[j];
        }
        else{
            valido = false;
            resultado = -1;
        }
        i++;
    }
    cout<<resultado<<endl;
}

int main()
{
    string  numeroRomano;
    cout<<"Ingrese un numero Romano"<<endl;
    cin>>numeroRomano;
    Decimal(numeroRomano);
    return 0;
}
