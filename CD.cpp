#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


/**
 * Victor Russo 11218855
 * Backtracking
 * 
 */

typedef struct tape_{
    vector<int> tracks;
    int sum;
}tape;

void copy_tape(tape &best,tape aux){
    while(best.tracks.empty() == false)
        best.tracks.pop_back();
    best.sum = aux.sum;
    for(int track:aux.tracks)
        best.tracks.push_back(track);
}

void organize_tracks(int index,int N,int number_tracks,vector<int> tracks,tape &best,tape aux){
    //add the current track in the work tape
    int current_track = tracks[index];
    aux.tracks.push_back(current_track);
    aux.sum+=current_track;

    //checks if the work tape is better than the best tape so far
    //if positive, copies the work tape to the best tape
    if(aux.sum > best.sum){
        copy_tape(best,aux);
    }

    for(int i = index+1;i<number_tracks;i++){
        if(aux.sum+tracks[i]<=N)
            organize_tracks(i,N,number_tracks,tracks,best,aux);
    }

    aux.tracks.pop_back();
    aux.sum-=current_track;
}

int main(void){
    int N;
    while(cin>>N){
        int number_tracks;
        cin>>number_tracks;
        vector<int> tracks(number_tracks);
        for(int i=0;i<number_tracks;i++)
            cin>>tracks[i];
        tape best, aux;
        best.sum = 0;
        for(int i=0;i<number_tracks;i++){
            aux.sum = 0;
            organize_tracks(i,N,number_tracks,tracks,best,aux);
        }
        for(int track : best.tracks)
            cout<<track<<" ";
        cout<<"sum:"<<best.sum<<endl;
    }
}