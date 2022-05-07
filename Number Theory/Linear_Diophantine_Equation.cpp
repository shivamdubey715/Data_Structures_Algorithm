#include<bits/stdc++.h>
using namespace std;


int GCD(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
bool Diophantine(int a, int b, int c){
    if (( c % GCD(a, b)) == 0)
    {
        return true;
    }
    return false;
    
}
int main(){
    if(Diophantine(3, 6, 8)){
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Not Possible" << endl;
    return 0;
}