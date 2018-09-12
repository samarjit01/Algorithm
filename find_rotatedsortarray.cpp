#include <bits/stdc++.h> 
#include<vector>
using namespace std;

int findPivot(vector<int>A , int l ,int h){
	if(h<l){
		return 0;
	}

	if(h==l){
		return l;
	}

	int m = l+(h-l)/2;
	if(m < h && A[m+1]<A[m]){
		return m+1;
	}

	if(m < h && A[m-1]>A[m]){
		return m;
	}

	if(A[h]>A[m])
		return findPivot(A,l,m-1);
	return  findPivot(A,m+1,h);

}

int bsearch(vector<int>A , int l, int h , int num){
	
		if(l<=h){
			int m=l+(h-l)/2;

			if(num==A[m])
				return m;
			if(num>A[m])
				return bsearch(A,m+1,h,num);
			else
				return bsearch(A,l,m-1,num);

		}

		return -1;

}


void find(vector<int>A,int num){

		int p = findPivot(A,0,A.size()-1);
		
		int x=bsearch(A,0,p-1,num);
		
		int y=bsearch(A,p,A.size()-1,num);
		
		if(x==-1 && y!=-1)
			cout<< y;
		else if(y==-1 && x!=-1)
			cout<< x;
		else
			cout<<"Not found";


} 
  
int main(){
	
	vector <int> A={6,7,8,9,1,2,3,4,5};

	int num =8;
	cin>>num;
	find(A,num);
	

	return 0;
}


