#include <bits/stdc++.h> 
using namespace std; 
#define N 50
#define V 5 



bool gvisited[V]={false};
class Q{

public: 
	int f,r;int arr[N]={0};

	Q(){		
		 f=-1;r=-1;
	}

	void enqeue(int n){
		
		if(r==N){
			cout<<"Overflow";
		}else{
		if(f==-1){
			f++;
		}
		r++;
		arr[r]=n;

		}

	}

	int deqeue(){
		if(f==-1 || f>r ){
		cout<<"Underflow";f=-1 ;r = -1;
		return -1;
		}
		int temp=arr[f];
		arr[f]=0;
		f++;
		return temp;
	}

	bool isEmpty(){
		if(f==-1 || f>r )
			return true;
		return false;
	}

	void print(){
		cout<<"Q"<<endl;
		for(int i=f;i<=r;i++){
		cout<<arr[i]<<" ";

		}
		cout<<endl;


	}


};



class S{


public: 
	int t;int arr[N]={0};

	S(){
		t=-1;
	}
	void push(int n){
		t++;
		if(t==N){
			cout<<"Overflow"<<endl;

		}
		else{
			arr[t]=n;
		}

	}

	int pop(){
		if(t<0){
			cout<<"Underflow"<<endl;
		}
		else{
			int temp=arr[t];
			t--;
			return temp;
		}
	}

	int peek(){
		return arr[t];
	}
	bool isFull(){
		if(t==N){
			return true;
		}
		return false;
	}
	bool isEmpty(){
		if(t==-1){
			return true;
		}
		return false;
	}
	void print(){
		int x=t;
		while(x>-1){
			cout<<arr[x]<<" ";
			x--;
		}
		cout<<endl;
	}


};

void BFS(int G[V][V] , int s){
		Q x;
		bool visit[V]={false}	;
		visit[s]=true;
		x.enqeue(s);
		//x.print();
		while(!x.isEmpty()){
		//	x.print();
			int temp = x.deqeue();
			cout<<temp+1<<" ";
		for(int i=0;i<V;i++){
				if(G[temp][i] && visit[i]==false){
					x.enqeue(i);
					visit[i]=true;
				}
		}
	}


}

void DFS(int G[V][V] , int s){
	S x;
	bool visit[V]={false}; int entry[V]={0},exist[V]={0};
	visit[s]=true;gvisited[s]=true;
	x.push(s);
	while(!x.isEmpty()){
		int temp=x.pop();
		cout<<temp+1<<" ";

	
	for(int i=V-1;i>=0;i--){
				if(G[temp][i] && visit[i]==false){
					x.push(i);
					visit[i]=true;gvisited[i]=true;
				}
		}

	}

}

void Connected_Component(int G[V][V] , int s){
	int c=1;
	for(int i=0;i<V;i++){



		if(gvisited[i]==false){
			DFS(G,i);c++;
		}


	}
	cout<<" "<<c<<endl;


}

int main(){
	
int G[V][V];

cout<<" Graph :"<<endl;
for(int i=0;i<V;i++){
	for (int j=0;j<V;j++){
		cin >> G[i][j] ;
	}
}

cout<<"DFS : "<<endl;
DFS(G,0);
cout <<endl;
cout<<"BFS : "<<endl;
BFS(G,0);
cout<<"connected Component : "<<endl;
Connected_Component(G,0);

	
	return 0;
}


