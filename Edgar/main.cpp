#include <vector>//size push_back []
#include <math.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>//ordena datos
using namespace std;
typedef int (*fptr)(int);

int f(int n)
{
	return 5;
}	

int fibo(int n)
{
	if(n<2)
		return n;
	else 
		return fibo(n-1)+fibo(n-2);
}	

int fun(int n)
{
	n=n*n+1;
	return n;
}	

//Paso por valor y por referencia
int prueba(int &value)
{
	value=value*value;
	return 1;
}	

//cuando no retornas nada se pone void
void imprimirVector(vector<int> vr )
{
	//se puede recorrer con iterador y con indices
	for(int i=0;i<vr.size();i++)
		cout<<vr[i]<<" ";
	cout<<endl;	
}	

int main()
{
	int vectore[10];//gasta poca memoria
	vector<int> vec;//gasta memoria
	map<int,fptr> mapfun;
	//cout<<vec.size()<<endl;
	string nombre="edgar";
	mapfun[0]=f;
	mapfun[1]=fibo;
	mapfun[2]=fun;
	for(int i=0;i<mapfun.size();i++)
	{
		cout<<mapfun[i](3)<<endl;
	}	
	string cadena="Edgar Condori Pozo";//operar cadena de caracters
	cout<<cadena<<endl;
	cout<<"Mi nombre tiene: "<<cadena.size()<<" caracteres"<<endl;	
	
	
	int n;
	cout<<"Ingresar tamanio de vector:"<<endl;
	cin>>n;
	int i=0;
	while(i<n)
	{
		int local;
		cin>>local;
		vec.push_back(local);
		i++;//controlador por sentinela
	}	
	
	imprimirVector(vec);
	cout<<"paso de parametros "<<endl;
	sort(vec.begin(),vec.end());//ordenar el vector desde el inicio al final
	imprimirVector(vec);
	prueba(n);
	cout<<"El valor de n es:"<<n<<endl;
	return 1;
}	

