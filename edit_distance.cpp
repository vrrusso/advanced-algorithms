#include<iostream>


using namespace std;


int min3(int x,int y, int z){
    return min(min(x,y),z);
}

int findMinimum(string a, string b){
    int a_length = a.length();
    int b_length = b.length();

    int memo[101][101] = {0};

    
    
    for(int i=b_length-1;i>-1;i--){
        memo[a_length][i] = memo[a_length][i+1]+b[i]-'a'+1;
    }
    for(int i=a_length-1;i>-1;i--){
        memo[i][b_length] = memo[i+1][b_length]+a[i]-'a'+1;
    }

    for(int j=b_length-1;j>-1;j--){
        for(int i=a_length-1;i>-1;i--){
            memo[i][j] = min3(memo[i][j+1]+b[j]-'a'+1,memo[i+1][j]+a[i]-'a'+1,abs(a[i]-b[j])+memo[i+1][j+1]);
        }
    }
    
    return memo[0][0];
}

int main(){

    string a,b;


    //scanf("%s %s",a,b);

    cin>>a>>b;

    printf("%d\n",findMinimum(a,b));


    return 0;
}