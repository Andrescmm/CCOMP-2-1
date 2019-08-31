#include<iostream>
using namespace std ;



int sum(int x,int y,int z) {
    int a = x%z;
    int b = y%z;
    int c= a+b;
    
    if (c<0){
        cout<< "La suma es "<<c*-1<<endl;
    }
    else{
        cout<<"La suma es "<< c<<endl;}

    return 0;
}

int res(int x,int y,int z){
    int a = x%z;
    int b = y%z;
    int c= a-b;
    
    if (c<0){
        cout<< "La resta es "<<c*-1<<endl;
    }
    else{
        cout<<"La resta es "<< c<<endl;}
    
    return 0;
    
}


int multi(int x, int y, int z){
    int a = x%z;
    int b = y%z;
    int c= a*b;
    
    if (c<0){
        cout<< "La multiplicacion es "<<c*-1<<endl;
    }
    else{
        cout<<"La multiplicacion es "<< c<<endl;}
    
    return 0;
    
}
int test(int a, int b)
{
    if (a == 0)
        return b;
    return test(b%a, a);
}

int inversa(int a , int m){
    int m0 = m;
    int y = 0, x = 1;
    int g = test(a, m);
    
    if (g != 1){
        cout << "El inverso no existe "<<endl;
    }
    
    else
    {
        if (m == 1){
            cout<< "0"<<endl;}
        
    else{
      while (a > 1)
      {
        // q es un cociente
        int q = a / m;
        int t = m;
        // Euclid's algo
        m = a % m; a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    }
        if (x < 0){
            x += m0;
            cout<<"El inverso modular es "<<x<<endl;}
    }

    return 0;
}

int main(){
    int a,b,c;
    cout <<"Ingrese dos numeros"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Ingrese el modulo que desea calcular"<<endl;
    cin>>c;
    sum(a,b,c);
    res(a,b,c);
    multi(a,b,c);
    cout<<endl;
    int x,y;
    cout<<"Ingresar un numero y el modulo para calcular la inversa"<<endl;
    cin>>x;
    cin>>y;
    inversa(x,y);
    
    
    return 0;
}
