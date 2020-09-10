#include<vector>
#include<iostream>

/**
 *    Coin Collector Sultan's Problem
 *    Victor Russo
 *    
 *    Advanced Algorithm Classes 
 */

using namespace std;

int get_coins(vector<int> coins,int n){
    if(n==1)
        return n;
    int sum = 1;
    int count = 0;
    for(int i=1;i<n-1;i++){
        if(!(coins[i+1] <= sum+coins[i])){
            sum+=coins[i];
            count++;
        }
    }
    return count+2;
}


int main(void){

    int t;
    cin>>t;
    while( t > 0){
        t--;
        int n;
        cin>>n;
        vector<int> coins(n);
        for(int i=0;i<n;i++){
            cin>>coins[i];
        }
        cout<<get_coins(coins,n)<<endl;

    }



    return 0;
}
