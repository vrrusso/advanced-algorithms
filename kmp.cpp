#include<iostream>


using namespace std;

#define MAX 1000

void calculateLps(string pattern,int *lps, int n){
    int i = 0, j =-1;lps[0] = -1;

    while(i < n){
        while(j>-1 && pattern[i] != pattern[j])
            j = lps[j];
        i++;j++;
        lps[i] = j;
        //cout<<lps[i]<<" ";
    }
    

}


void kmpSearch(string pattern,string text,int *lps,int text_size,int pattern_size){
    int i=0,j=0;
    while(i < text_size){
        while(j>=0 && text[i] != pattern[j])
            j = lps[j];
        i++;j++;
        if(j == pattern_size){
            cout<< "O padrao foi encontrado na posicao "<<i-j<<endl;
            j = lps[j];
        }
    }

}


int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);

    text.pop_back();
    pattern.pop_back();

    int lps[MAX];
    int n = pattern.length();
    calculateLps(pattern,lps,n);

    kmpSearch(pattern,text,lps,text.length(),n);



    //cout<<text<<endl<<pattern;

}