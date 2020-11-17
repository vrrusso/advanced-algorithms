

#include<iostream>
#include<vector>


using namespace std;


typedef struct {
    int w;
    int h;
}Doll;


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
        //for(int i=0;i<m;i++){
          //  printf("%d %d\n",dolls[i].w, dolls[i].h);
        //}
        //devo achar a maior sequência não incremental agora
        int count = 1;
        int aux_count=1;
        for(int i=1;i<m;i++){
            if(dolls[i].w <= dolls[i-1].w || dolls[i].h <= dolls[i-1].h)
                aux_count++;
            else{
                if(aux_count>count)
                    count = aux_count;
                aux_count = 1;
            }
        }
        if(aux_count>count)
            count = aux_count;
        printf("%d\n",count);
    }


    return 0;
}