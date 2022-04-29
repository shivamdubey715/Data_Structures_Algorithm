#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f,x;
    cin>>a>>b>>c>>d>>e>>f>>x;
    int d1 = 0;
    int tim=x;
    while(tim>0){
        d1 += b*(min(tim, a));
        tim -= a;
        if(tim <=0){
            break;
        }
        else{
            tim -= c;
        }
    }
    tim = x;
    int d2 = 0;
    while(tim>0){
        d2 += e*(min(tim, d));
        tim -= d;
        if(tim <=0){
            break;
        }
        else{
            tim -= f;
        }
    }
    if(d1==d2){
        cout <<"Draw"<<endl;
    }
    else if(d1<d2){
        cout<<"Aoki"<<endl;
    }
    else{
        cout<<"Takahashi"<<endl;
    }
}
// }