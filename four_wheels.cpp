#include<queue>
#include<iostream>

using namespace std;

/**
 *    Four Wheels Problem
 *    Victor Russo
 *    
 *    Advanced Algorithm Classes 
 */


typedef struct {
    int w1;
    int w2;
    int w3;
    int w4;
}WheelsState;

bool equal_state(WheelsState a, WheelsState b){
    if(a.w1 == b.w1 && a.w2 == b.w2 && a.w3 == b.w3 && a.w4 == b.w4)
        return true;
    return false;
}

int insert_adjacent_states_queue(WheelsState base,WheelsState target,int forbidden[10][10][10][10],queue<WheelsState> &next){
    int base_depth = forbidden[base.w1][base.w2][base.w3][base.w4];

    if(forbidden[(base.w1-1+10)%10][base.w2][base.w3][base.w4] == 0){
        base.w1= (base.w1-1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w1= (base.w1+1+10)%10;
        forbidden[(base.w1-1+10)%10][base.w2][base.w3][base.w4] = base_depth+1;
    }
    if(forbidden[(base.w1+1+10)%10][base.w2][base.w3][base.w4] == 0){
        base.w1 = (base.w1+1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w1 = (base.w1-1+10)%10;
        forbidden[(base.w1+1+10)%10][base.w2][base.w3][base.w4] = base_depth+1;
    }
    if(forbidden[base.w1][(base.w2-1+10)%10][base.w3][base.w4] == 0){
        base.w2=(base.w2-1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w2=(base.w2+1+10)%10;
        forbidden[base.w1][(base.w2-1+10)%10][base.w3][base.w4] = base_depth+1;
    }
    if(forbidden[base.w1][(base.w2+1+10)%10][base.w3][base.w4] == 0){
        base.w2= (base.w2+1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w2= (base.w2-1+10)%10;
        forbidden[base.w1][(base.w2+1+10)%10][base.w3][base.w4] = base_depth+1;
    }
    if(forbidden[base.w1][base.w2][(base.w3-1+10)%10][base.w4] == 0){
        base.w3=(base.w3-1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w3=(base.w3+1+10)%10;
        forbidden[base.w1][base.w2][(base.w3-1+10)%10][base.w4] = base_depth+1;
    }
    if(forbidden[base.w1][base.w2][ (base.w3+1+10)%10 ][base.w4] == 0){
        base.w3 = (base.w3+1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w3= (base.w3-1+10)%10;
        forbidden[base.w1][base.w2][ (base.w3+1+10)%10 ][base.w4] = base_depth+1;
    }
    if(forbidden[base.w1][base.w2][base.w3][ (base.w4-1+10)%10] == 0){
        base.w4=(base.w4-1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w4 = (base.w4+1+10)%10;
        forbidden[base.w1][base.w2][base.w3][ (base.w4-1+10)%10] = base_depth+1;
    }
    if(forbidden[base.w1][base.w2][base.w3][ (base.w4+1+10)%10 ] == 0){
        base.w4 = (base.w4+1+10)%10;
        next.push(base);
        if(equal_state(base,target))
            return base_depth;
        base.w4 = (base.w4-1+10)%10;
        forbidden[base.w1][base.w2][base.w3][ (base.w4+1+10)%10 ] = base_depth+1;
    }
    return 0;
}

int bfs(WheelsState initial, WheelsState target, int forbidden[10][10][10][10]){
    if(equal_state(initial,target))
        return 0;
    queue<WheelsState> next;
    forbidden[initial.w1][initial.w2][initial.w3][initial.w4] = 1;
    if(insert_adjacent_states_queue(initial,target,forbidden,next) != 0)
        return 1;
    forbidden[initial.w1][initial.w2][initial.w3][initial.w4]=1;
    while(!next.empty()){
        WheelsState current = next.front();next.pop();
        int found = insert_adjacent_states_queue(current,target,forbidden,next);
        if(found!=0)
            return found;
        //cout<<current.w1<<current.w2<<current.w3<<current.w4<<endl;
    }
    return -1;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        WheelsState initial,target,faux;
        int n;
        int forbidden[10][10][10][10] = {0};
        
        cin>>initial.w1>>initial.w2>>initial.w3>>initial.w4;
        cin>>target.w1>>target.w2>>target.w3>>target.w4;
        
        
        cin>>n;
        
        while(n--){
            cin>>faux.w1>>faux.w2>>faux.w3>>faux.w4;
            forbidden[faux.w1][faux.w2][faux.w3][faux.w4] = -1;
        }

        cout<<bfs(initial,target,forbidden)<<endl;



    }


    return 0;
}