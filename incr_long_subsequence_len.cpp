#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fun (vector<int> A){
	int n = A.size();
	vector<int> B(n,1);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(A[j]<A[i]){
				//cout << A[i] << A[j] <<endl;
				B[i]=max ( B[i],B[j]+1);
			}
		}
	}
	cout<<endl;
	int m=B[0];
	for(int i=0;i<n;i++){

		cout<<B[i]<<" ";
		if(m<B[i]){
			m=B[i];
		}
	}
	cout<<endl;
	cout<<"Max:"<<m<<endl;


}


int main(){

vector<int> A;int p;
int n;
cin >> n;
while(n--){
	cin>>p;
	A.push_back(p);
}

fun(A);


	return 0;
}