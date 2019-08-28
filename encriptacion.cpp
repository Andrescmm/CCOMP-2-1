 #include<iostream>
#include <string>

using namespace std;

int main(){
    string albe="abcdefghijklmnopqrstuvwxyz0123456789 ";
    
    //cout<<albe.size()<<endl;
    
    string mensaje;
    cout<<"Ingrese un mensaje: "<<endl;
    getline(cin,mensaje);
    //cout<<mensaje<<endl;
    cout<<"Ingresar "<<mensaje.size()<<" numeros menores que "<<albe.size()<<endl;
    string pos[36];
    string clave="";
    int a = 0;
    for(int i=0;i<mensaje.size();i++){
        cin>>a;
        pos[i]=to_string(a);
        clave.push_back(albe[a]);
    }
    
    
    int suma[mensaje.size()];
    for(int i=0;i<mensaje.size();i++){
        long m =albe.find(mensaje.at(i));
        long c=albe.find(clave.at(i));
        suma[i]=(m+c)%37;
        mensaje.at(i)=albe.at(suma[i]);
    }
    cout<<mensaje<<endl;
    return 0;
}
