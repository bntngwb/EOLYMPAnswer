#include<stdio.h>
#include<queue>
#include<functional>

using namespace std;

#define ll long long
#define gc getchar_unlocked

template <typename T> void Getnum(T &val){
    char ch; bool bo = 0; val = 0;
    for (ch = gc();ch<'0'||'9'<ch;ch = gc()) if (ch=='-') bo =1;
    for (;'0'<=ch && ch <= '9';val = (val<<3) + (val<<1) + ch - 48, ch = gc());
    if (bo) val = -val;
    
}
priority_queue<ll, vector<ll>, greater<ll> >pq;

int main(int argc, char const *argv[])
{
    ll n,num,res,i;
    Getnum<ll>(n);
    for (res = i = 0;i<n;i++)
    {
        Getnum<ll>(num),pq.push(num);
    }
    while (pq.size() > 1)
    {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a+b);
        res += a+b;
    }
    printf("%lld\n",res);
    return 0;
}