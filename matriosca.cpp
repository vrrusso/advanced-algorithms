

#include<iostream>
#include<vector>
#include<set>



using namespace std;


typedef struct {
    int w;
    int h;
}Doll;


bool operator<(Doll a, Doll b){
    if(a.w<b.w)
        return true;
    return false;
}

int main(){


    int t;
    scanf("%d",&t);
    while(t--){
        int m;
        scanf("%d",&m);
        vector<Doll> dolls(m);
        for(int i=0;i<m;i++){
            Doll aux;
            scanf("%d %d",&aux.w,&aux.h);
            int j = i-1;
            while(j>0 && (dolls[j].w > aux.w || (dolls[i].w == aux.w && dolls[i].h < aux.h ))){
                dolls[j+1].w = dolls[j].w;
                dolls[j+1].h = dolls[j].h;
                j--;
            }
            dolls[j+1].w = aux.w;
            dolls[j+1].h = aux.h;
        }



       /*vector<Doll> base;
       for(Doll cur : dolls){
            int i = base.size()-1;
            while(i>=0 && (base[i].w >= cur.w || base[i].h >= cur.h))
                i--;
            if(i==-1){
                base.push_back(cur);
            }
            else{
                base[i].w = cur.w;
                base[i].h = cur.h;
            }
       }
       printf("%d\n",(int)base.size());*/
       

       multiset<Doll> base;
       for(Doll cur : dolls){
           auto it = base.lower_bound(cur);
           if(it != base.begin()) base.erase(--it);

           base.insert(cur);
        }
        printf("%ld\n",base.size());
    
    
    }


    return 0;
}