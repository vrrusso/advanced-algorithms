#include<iostream>
#include<cmath>



using namespace std;

#define F(p,q,r,s,t,u,x) (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)


double f(int p,int q,int r,int s,int t,int u,double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u; 
}

double bisection(int p,int q,int r,int s,int t,int u,double a, double b){
    double f_a = F(p,q,r,s,t,u,a);
    while(b-a> 1e-15){
        double center = (a+b)/2;
        if(f_a*F(p,q,r,s,t,u,center)<=0)
            b = center;
        else{
            a = center;
            f_a = F(p,q,r,s,t,u,a);
        }
    }
    return (a+b)/2;
}

int main(){
    int p,q,r,s,t,u;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(4);

    while(cin>>p){
        
        cin>>q>>r>>s>>t>>u;
        //cout<<p<<q<<r<<s<<t<<u;
        if(!p && !q && !r && !s && !t && !u){
            cout<<"0.0000"<<"\n";
            continue;
        }
        if(f(p,q,r,s,t,u,0)*f(p,q,r,s,t,u,1)>0){
            cout<<"No solution"<<"\n";
            continue;
        }

        cout<<fixed<<bisection(p,q,r,s,t,u,0,1)<<"\n";
       // printf("%.4lf\n",bisection(p,q,r,s,t,u,0,1));
    }
    return 0;
}