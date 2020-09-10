#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 
 *  Victor Rodrigues Russo
 *  
 */

int main(void){
    int chambers;
    int count=1;
    while(cin>>chambers){
        int n_species;
        float mean = 0,imbalance = 0;
        cin>>n_species;
        vector<int> species_mass(2*chambers);
        for(int i=0;i<n_species;i++){
            cin>>species_mass[i];
            mean+=species_mass[i];
        }
        mean/=chambers;
        sort(species_mass.begin(),species_mass.end());
        cout<<"Set #"<<count<<endl;
        int i=0, j = 2 * chambers-1;
        for(int k=0;k<chambers;k++){
            cout<<" "<<k<<": ";
            if(species_mass[i]!=0)
                cout<<species_mass[i]<<" ";
            if(species_mass[j]!=0)
                cout<<species_mass[j];
            cout<<endl;
            imbalance+=abs(species_mass[i]+species_mass[j]-mean);
            i++;
            j--;
        }
        printf("IMBALANCE = %.5f\n\n",imbalance);
        count++;
    }
}