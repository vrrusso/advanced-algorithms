
/**
 * Victor R. Russo 
 * 
 */

#include<vector>
#include<iostream>
#include<cstdio>
#include<set>
#include<deque>
#include<algorithm>

using namespace std;

set<pair<int,int>> stable_matching(int n,vector<vector<int>> men_preferencies,vector<vector<int>> women_preferencies){
    set<pair<int,int>> couples;
    deque<int> single_men;
    vector<int> women_status(n);
    for(int i=1;i<=n;i++)
        single_men.push_back(i);

    while(single_men.empty() != true){
        int man = single_men.front();
        int woman = men_preferencies[man-1].back();
        men_preferencies[man-1].pop_back();
        
        //if the woman is single
        if(women_status[woman-1] == 0){
            pair<int,int> p;p.first = man;p.second = woman;
            couples.insert(p);
            women_status[woman-1] = man;
            single_men.pop_front();
        }
        else{
            int husband = women_status[woman-1];
            //if the woman would rather the bravous one than her current husband
            if(find(women_preferencies[woman-1].begin(),women_preferencies[woman-1].end(),man) < find(women_preferencies[woman-1].begin(),women_preferencies[woman-1].end(),husband)){
                pair<int,int> p;p.first = husband;p.second = woman;
                set<pair<int,int>>::iterator it;

                //in computer world divorces are much more simpler
                it=find(couples.begin(),couples.end(),p);
                couples.erase(it);
                
                
                p.first = man;
                couples.insert(p);
                women_status[woman-1] = man;
                single_men.pop_front();
                single_men.push_back(husband);
            }
        }

    }
    return couples;
}


//this is a little algorithm for determining stable matchs between partners

int main(void){

    //number of executions
    int cont;
    cin>>cont;

    while( cont-- >0){
        int n, dump;
        cin>>n;
        vector<vector<int>> men_preferencies(n,vector<int>(n));
        vector<vector<int>> women_preferencies(n,vector<int>(n));
        for(int i=0;i<n;i++){
            cin>>dump;
            for(int j=0;j<n;j++){
                cin>>women_preferencies[i][j];
            }
        }

        for(int i=0;i<n;i++){
            cin>>dump;
            for(int j=0;j<n;j++){
                cin>>men_preferencies[i][j];
            }
            reverse(men_preferencies[i].begin(),men_preferencies[i].end());
        }

        set<pair<int,int>> couples = stable_matching(n,men_preferencies,women_preferencies);

        //print the couples       
        for(pair<int,int> p : couples){
            cout<<p.first<<" "<<p.second<<endl;
        }   

    }
    return 0;
}