#include<iostream>
#include<vector>
#include<bitset>

using namespace std;


typedef long long ll;


#define MAX 35

typedef struct{
    int primeFactors[MAX];
}FactorVector;

/*bool isPrime(ll N){
    if(N>2 && N%2 == 0) return false;
    for(ll i =3;i*i<=N;i+=2)
        if(N%i == 0) return false;
    return true;
}*/

vector<int> primes;
ll sieve_size;
bitset<10000010> bs;

void sieve(ll upperbound){
    sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i =2;i<=sieve_size;i++)
        if(bs[i]){
            for(ll j = i*i; j<= sieve_size;j+=i) bs[j] = 0;
            primes.push_back((int)i);
        }
}


void assembleTable(FactorVector *numbers){
    for(int i=2;i<101;i++){
        for(int j=0;j<35;j++){
            numbers[i].primeFactors[j] = -1;
        }
    }
    numbers[2].primeFactors[0]=1;
    sieve(149);

    for(int i=3;i<101;i++){
        int number = i;
        int prime_index = 0;
        FactorVector current;
        for(int j=0;j<35;j++){
            current.primeFactors[j] = -1;
        }
        while(number>1){
            current.primeFactors[prime_index]=0;
            while(number%primes[prime_index] == 0){
                current.primeFactors[prime_index] = current.primeFactors[prime_index]+1;
                number/=primes[prime_index];
            }
            prime_index++;
        }
        /*int l=0;
        printf("%d :",i);
        while(l<35){
            printf("%d ",current.primeFactors[l]);
            l++;
        }
        printf("\n");*/

        int l = 0;
        while(l < 35){
            if(current.primeFactors[l] != -1 && numbers[i-1].primeFactors[l] != -1)
                numbers[i].primeFactors[l] = current.primeFactors[l]+numbers[i-1].primeFactors[l];
            else if(current.primeFactors[l] != -1 && numbers[i-1].primeFactors[l] == -1)
                numbers[i].primeFactors[l] = current.primeFactors[l];
            else
                numbers[i].primeFactors[l] = numbers[i-1].primeFactors[l];
            
            //printf("%d %d\n",current.primeFactors[l],numbers[i-1].primeFactors[l]);
            //numbers[i].primeFactors[l] = numbers[i-1].primeFactors[l] == -1? current.primeFactors[l]:numbers[i-1].primeFactors[l]+current.primeFactors[l];
            l++;
        }

        /*int k=0;
        printf("%d :",i);
        while(k<35){
            printf("%d ",numbers[i].primeFactors[k]);
            k++;
        }
        printf("\n");*/
    }
}

int main(){

    int n;
    FactorVector numbers[101];

    //monta a tabela de todos os números entre 2 e 100
    assembleTable(numbers);
    while(true){
        scanf("%d",&n);
        if(n == 0)
            return 0;
        printf("%3d! =",n);
        int i=0;
        int line_counter = 0;
        while(numbers[n].primeFactors[i] != -1){
            printf("%3d",numbers[n].primeFactors[i]);
            line_counter++;
            if(line_counter == 15 && numbers[n].primeFactors[i+1]!=-1){
                printf("\n      ");
                line_counter = 0;
            }
            i++;
        }
        printf("\n");
        
    }

    return 0;
}