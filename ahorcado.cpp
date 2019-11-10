#include <iostream>
#include <string>
using namespace std;



int mod(int x, int y){
    if(x>=0)return x-(x/y)*y;
    return x-((x/y)-1)*y;
}

int  generarale() {
 int num;
 srand(time(NULL));
 num=mod(rand(),14);
return num;
}

bool Ahorcado(char*(a)[100]){
    int tam1=strlen(*a);
    cout<<"La palabra tiene "<<tam1<<" letras"<<endl;
    char temp[tam1];
    for( char*i=temp;i<=(temp+tam1)-1;i++){
        *i='_';
    }
    int vidas=6;
    int tam2=strlen(temp);
    cout<<tam2<<endl;
    while(vidas>0){
        int comprobacion = 0;
        char letra;
        cout<<"Ingrese una posible letra"<<endl;
        cin>>letra;
        char*r=temp;
    for(char *j=*a;j<*a+tam2;j++,r++) {
              if (letra== *j) {
                  *r=letra;
                  comprobacion++;
                  }
    }
        
        bool valor=true;
        char*h=*a;
        for(char *r=temp;r<temp+tam2;r++,h++){
            if(*r!=*h){
                    valor=false;
                        break;
            }
        }
    
        if(valor){
            cout<<"You win"<<endl;
            cout<<temp<<endl;
            return true;
        }
        
        if (comprobacion==0){
            vidas--;
        }
        cout<<temp<<endl;
        cout<<"Vidas= "<<vidas<<endl;

       }
    
    return 0;
}

int main(){
    char *(a)[100]={"bosque","quinua","parlante","impuestos","ciencia","celular","derecha","creer","anciano","cera","etiqueta","figuritas","quesos","habito","cheque"};
    int aleatorio=generarale();
      //cout<<aleatorio<<endl;
      char **ptr=a+aleatorio;
      //cout<<*ptr<<endl;
    Ahorcado(ptr);
    return 0;
}
