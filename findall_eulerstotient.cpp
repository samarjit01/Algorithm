#include<iostream>
using namespace std;


void fun(int n){
	int phi[n+1];
	for (int i=1;i<=n;i++){
		phi[i]=i;
	}	

	for (int i=2;i<=n;i++){
		if(phi[i]==i){
			phi[i]=i-1;

			for(int p=2*i;p<=n;p+=i){
				phi[p]=(phi[p]/i)*(i-1);
			}

		}
	}

	for (int i=1; i<=n; i++) 
      cout << "Totient of " << i << " is "
           << phi[i] << endl; 


}
int main(){

fun(10);
	return 0;
}