#include<iostream>
#include<vector>


using namespace std;

#define MAX 200

int min3(int x,int y, int z){
    return min(min(x,y),z);
}

int findMinimum(int *a, int *b,int N){
    int a_length = N;
    int b_length = N;

    int memo[MAX][MAX];
    //vector<vector<int>> memo(N,vector<int>(N));

    for(int i=0;i<=a_length;i++){
        for(int j=0;j<=b_length;j++){

            if(i == 0){
                memo[i][j] = j;
            }


            else if(j==0){
                memo[i][j] = i;
            }

            else if(a[i-1] == b[j-1]){
                memo[i][j]= memo[i-1][j-1];
            }

            else{
                memo[i][j] = 1+min(memo[i][j-1],memo[i-1][j]);

            }


        }

    }
    /*
    for(int i=0;i<=a_length;i++){
        for(int j=0;j<=b_length;j++){
            printf("%d ",memo[i][j]);
        }
        printf("\n");
    }*/

    return memo[a_length][b_length];
}

int main(){
    int t;
    scanf("%d ",&t);
    for(int i=1;i<=t;i++){
        int a[MAX], b[MAX];
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
            scanf("%d",&a[j]);
        for(int j=0;j<N;j++)
            scanf("%d",&b[j]);
        
        printf("Case %d: %d\n",i,findMinimum(a,b,N));
 
    }

    return 0;
}