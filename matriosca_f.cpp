
#include<iostream>
#include<vector>
#include<set>



using namespace std;

const int N = 1e4+1;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<vector<int>> a(N);

        for(int i=0;i<n;i++){
            int x,y;scanf("%d %d",&x,&y);
            a[x].push_back(y);
        }

        multiset<int> cur;
        for(int i=0;i< N;i++){
            for(int y : a[i]){
                auto it = cur.lower_bound(y);
                if(it != cur.begin()) cur.erase(--it);
            }
            for(int y : a[i]) cur.insert(y);
        }
        printf("%ld\n", cur.size());

    }

    return 0;
}