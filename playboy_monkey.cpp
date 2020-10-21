#include<iostream>
#include<vector>

using namespace std;

void bb(vector<int> heights,int monkey_height,int left,int right){
    if(left>=right){
        int smaller_index = left;
        int greater_index = right;
        while(smaller_index>=0 && heights[smaller_index] >=monkey_height)
            smaller_index--;
        while(greater_index< (int)heights.size() && heights[greater_index]<= monkey_height)
            greater_index++;
        if(smaller_index>=0)
            cout<<heights[smaller_index]<<" ";
        else
            cout<<"X ";
        
        if(greater_index<(int)heights.size())
            cout<<heights[greater_index]<<endl;
        else
            cout<<"X"<<endl;
    
        return;    
    }

    int middle = (left+right)/2;
    if(heights[middle]>monkey_height)
        bb(heights,monkey_height,left,middle);
    else
        bb(heights,monkey_height,middle+1,right);
}

int main(void){
    int N;
    cin>>N;
    vector<int> heights(N);
    for(int i=0;i<N;i++)
        cin>>heights[i];
    int Q;
    cin>>Q;
    while(Q--){
        int monkey_height;
        cin>>monkey_height;
        bb(heights,monkey_height,0,N-1);
    }
    
}