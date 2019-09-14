#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int inversa(int a , int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
            }
    }
    return 0;
}


int funcionM (int x, int y){
    if(x>=0){return x-(x/y)*y;};
    return x-((x/y)-1)*y;
}

void cifrado(string txt){
    string mensaje="";
    string copia="";
    ifstream entrada(txt);
    ofstream salida("texto1.txt");
    while (getline(entrada, copia)) {
        string temp = copia;
        mensaje += temp;
        mensaje.push_back('-');
        cout<<temp<<endl<<mensaje<<endl;
    }

    int tam=mensaje.length();
int claveprivada;
int clavepublica;
    cout<<"Ingresar tu clave privada"<<endl;
    cin>>claveprivada;
    int e=inversa(claveprivada,256);
    if (claveprivada==0){
        cout<<"No existe el cifrado"<<endl;
    }
    else{
    if( e==0){
        cout<<"No existe el cifrado"<<endl;
    }
    }
    for (int i=0;i<tam;i++){
        int r=mensaje.at(i);
        r=(claveprivada*r)%256;
        mensaje.at(i)=r;
    }

cout<<"La clave publica "<<e<<endl;

    salida << mensaje << endl;
    salida.close();
    entrada.close();

}



void descifrado(string txt,int clavepublica){
     string mensaje1;
    string copia1;
    ifstream entrada1( txt);
    ofstream salida1 ("texto3.txt");
    while (getline (entrada1,copia1)) {
        string temp=copia1;
        cout<<"copia "<<copia1<<endl;
        mensaje1.append(copia1);
    }
    int tam=mensaje1.length();

    for(int i=0;i<tam;i++){
int r=mensaje1.at(i);
r=(r*clavepublica)%256;
mensaje1.at(i)=r;
}
    for (int i=0;i<tam;i++){
        if(mensaje1.at(i)=='-'){
            salida1<<endl;
        }
        else{
            salida1 << mensaje1[i];
        }
    }
    salida1.close();
    entrada1.close();
}




int main(){
    cifrado("texto2.txt");
    int clave;
    cin>>clave;
    descifrado("texto1.txt",clave);
}

