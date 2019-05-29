#include<iostream>
using namespace std;

void fun(int set[] , int n  , int num){

	int A[n][num+1] = {0};
	cout<<endl;
	for (int i=0;i<n;i++){
		for(int j=0;j<=num;j++){
			A[i][j]=0;
		}
	
	}

	for (int i=0;i<n;i++){
		A[i][0]=1;	
	}
	for (int i=0;i<=num;i++){
		if(i== set[0]){
			A[0][i]=1;
		}
	}
	for (int i=1;i<n;i++){
		for(int j=1;j<=num;j++){
			if(set[i] > j){
				A[i][j]=A[i-1][j];
			}
			else{
				A[i][j] = A[i-1][j-set[i]] || A[i-1][j];
			}

		}
	}
	cout<<endl;
	for (int i=0;i<n;i++){
		for(int j=0;j<=num;j++){
			cout<< A[i][j] << " ";
		}
		cout<<endl;


	}
	cout << A[n-1][num];




}
int main(){

int n=5;
int set[5] = {2,3,7,10,12};


int num ;
cin >> num;
fun(set,n,num);

	return 0;
}