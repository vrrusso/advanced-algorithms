#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


/**
 * Victor Russo 11218855
 * 
 * backtracking the maze
 * 
 */


//the steps the mice could do
int steps[] = {0, 1,
               1, 0,
               0,-1,
               -1,0};

/**
 * 
 * counts all the possibles ways to get the cheese
 * 
 */
void travel(int &count,int size,vector<vector<int>> maze,vector<vector<int>> visited,pair<int,int> current_position){
    if(current_position.first == size-1 && current_position.second == size-1){
        count++;
        return;
    }
    //cout<<"("<<current_position.first<<","<<current_position.second<<")"<<endl;
    visited[current_position.first][current_position.second] = 1;
    //take the four possible steps
    for(int i=0;i<8;i+=2){
        pair<int,int> next_tile;
        next_tile.first = current_position.first +steps[i];
        next_tile.second = current_position.second+steps[i+1];
        if(next_tile.first <size && next_tile.second <size && next_tile.first >-1 && next_tile.second > -1 && maze[next_tile.first][next_tile.second] == 0 && visited[next_tile.first][next_tile.second] == 0)
            travel(count,size,maze,visited,next_tile); 
    }


}

int main(void){
    int size;
    cin>>size;
    
    vector<vector<int>> maze(size,vector<int>(size));
    vector<vector<int>> visited(size,vector<int>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>maze[i][j];
            visited[i][j] = 0;
        }
    }
    int count = 0;
    pair<int,int> current_position;
    current_position.first = 0;
    current_position.second = 0;
    travel(count,size,maze,visited,current_position);
    cout<<count<<endl;
    return 0;
}