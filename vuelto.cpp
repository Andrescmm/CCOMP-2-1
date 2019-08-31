#include <iostream>

using namespace std;

int billetes[8]={200,100,50,20,10,5,2,1};
int coins[3]={5,2,1};

void Vuelto (float cantidad){
    int integer=cantidad;
    float decimalFloat= cantidad*10;
    int decimal=decimalFloat-(integer*10);

    for(int i=0; i<8 && cantidad>0;i++){
        int  temp = integer/billetes[i];
        
        if(i<5){
            if (temp==0){
            }
            else{
                cout<<temp<<" billetes de "<<billetes[i]<<endl;
            }
            integer= integer%billetes[i];
        }
           else{
               if (temp==0){
               }
               else{
                    cout<<temp<<" monedas de "<<billetes[i]<<endl;
               }
               integer= integer%billetes[i];
            }
}
    
    for(int i=0;i<3&& cantidad>0;i++){
        int temp1=decimal/coins[i];
        
        if(temp1==0){
        }
        else{
            cout<<temp1<<" monedas de "<<"0."<<coins[i]<<endl;
            decimal=decimal%coins[i];
        }
    }
}
int main(){
    float numero;
    cout<<"Ingrese un monto "<<endl;
    cin>>numero;
    Vuelto(numero);

    return 0;
}
