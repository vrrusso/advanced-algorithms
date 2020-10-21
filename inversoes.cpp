#include<iostream>

using namespace std;
#define MAX 10000


int merge(int *vet,int left,int middle,int right){
	int n_left = middle-left+1;
	int n_right = right-middle;
	int left_aux[n_left];
	int right_aux[n_right];
	for(int i=0;i<n_left;i++)
		left_aux[i]=vet[left+i];
	for(int i=0;i<n_right;i++)
		right_aux[i]=vet[middle+1+i];

	int i=0,j=0,k=0;
	int count=0;
	while(i<n_left && j<n_right){
		if(left_aux[i]<=right_aux[j]){
			vet[left+k] = left_aux[i];
			i++;
		}
		else{
			vet[left+k] = right_aux[j];
			j++;

			count+=(middle+1-i-left);
			
		}
		k++;
	}
	while(j<n_right){
		vet[left+k]=right_aux[j];
		j++;
		k++;
	}
	while(i<n_left){
		vet[left+k]=left_aux[i];
		i++;
		k++;
	}

	

	return count;
}

int sort_count(int *vet,int left,int right){
	if(left>=right)
		return 0;
	int middle = (left+right)/2;
	int count_left = sort_count(vet,left,middle);
	int count_right = sort_count(vet,middle+1,right);
	int count_merge = merge(vet,left,middle,right);

	//cout<<count_left<<" "<<count_right<<" "<<count_merge<<endl;

	return count_left+count_right+count_merge;

}




int main(void){
    int N;
    cin>>N;
    while(N--){
        int c;
        cin>>c;
        int vet[MAX];
        for(int i =0 ;i<c;i++)
            cin>>vet[i];
		int count = sort_count(vet,0,c-1);
        /*for(int i=0;i<c;i++)
            cout<<vet[i]<<" ";*/
        cout<<count<<endl;
    }
}