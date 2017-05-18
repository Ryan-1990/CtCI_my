#include <iostream>

using namespace std;

long countWaysOpt(int n,int *mem)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    
    if(mem[n]) return mem[n];
    else 
    {
        mem[n]=countWaysOpt(n-1,mem)+countWaysOpt(n-2,mem)+countWaysOpt(n-3,mem);
        return mem[n];     
    }
}

long countWays(int n)
{
    int mem[n+1];
    for(int i=0;i<n+1;i++) mem[i]=0;
    return countWaysOpt(n,mem);
}

int main()
{
    int total;
    cout<<"input total:"<<endl;
    cin>>total;
    cout<<countWays(total);
    cout<<endl;
    return 0;
}