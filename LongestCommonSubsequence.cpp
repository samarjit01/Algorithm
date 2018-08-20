#include<bits/stdc++.h>
using namespace std;

int max(int x,int y){
  return (x>y)?x:y;
}

int lcs(char* A,char* B,int m,int n){
  int DP[m+1][n+1];

  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      if(i==0 || j ==0){      //base case
        DP[i][j]=0;
      }
      else if(A[i-1]==B[j-1]){
        DP[i][j]=1+DP[i-1][j-1];  //if equal then check for diagonally previous number
      }
      else{
        DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
      }
    }

  }

  int index=DP[m][n];
  char ANS[index+1];    //for printing
    ANS[index]='\0';    //last character
  int i=m,j=n;
  while(i>0 && j>0){
    if(A[i-1]==B[j-1]){
      ANS[index-1]=A[i-1];              //if equal then must be a part of answer
      i--;j--;index--;
    }
    else if(DP[i-1][j]>DP[i][j-1]){   //get the larger number
      i--;
    }else{
      j--;
    }
  }
  cout<<ANS<<" ";
  return DP[m][n];

}

int main(){

  char P[]="AGGTAB";
  char Q[]="GXTCAYB";
int m=strlen(P);
int n=strlen(Q);


  cout<<lcs(P,Q,m,n);
  return 0;
}
