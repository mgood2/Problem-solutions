//#Name: Anonta Haque #Problm:
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mapii;
typedef map<int,bool> mapib;
typedef unsigned long long ULL;

short CC_;
#define sf scanf
#define fs first
#define sd second
#define pf printf
#define itr iterator
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//constants
const int SZ= 1E6;
const int INF= (1<<29);
const double EPS= 1E-9;
const double PI= 2*acos(0.0);

namespace{
template <class T>void DA(T i,T e){while(i!=e){cout<<"Con>>( "<<++CC_<<" ) "<<*i++<<endl;}}
template <class T>void DA(T* x, int l){for(int i=0; i<l;i++)cout<<"["<<i<<"]>> "<<x[i]<<endl;}
template <class T>inline void sary(T* st, T* nd){while(st<nd)cin>>*st++;/*sf("%d", st++);*/}
template <class T>void tobin(T n,char*bin){int pos= 1<<((int)log2(n));while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
template <class T>int strOccur(string&s,T&tgt){int oc= 0, p= s.find(tgt);while(p != string::npos){p = s.find(tgt, p+1);oc++;}return oc;}
template <class T>LL factorial(T n){LL f= n;while(--n){f*= n;}return f;}
template <class T>inline T LCM(T x,T y){return((x*y)/__gcd(x,y));}
LL todec(string& num, int b){LL dec=num[0]-(isupper(num[0])? 'A'-10: '0');for(int i=1;num[i];i++){if(num[i]>='A'&& num[i]<='Z')num[i]-='A'-10;else num[i]-='0';dec*= b;dec+= num[i];}return dec;}
int bigMod(int b,int e,int m){if(e==0)return 1;if(!e&1){int temp=bigMod(b,e/2,m)%m;return(temp*temp)%m;}else return((b%m)*(bigMod(b,e-1,m))%m)%m;}
inline LL POW(LL base, int exp){LL p= 1; while(exp-->0){p *= base;} return p;}
bool ispal(const string& str){int len= str.length();for(int i= 0; i<len/2; i++){if(str[i]==str[len-i-1]){}else return false;}return true;}
bool comp(const int& a,const int& b){return a>b;}
}

int mn;

int path(int* stair, int* stat, int pos, const int des, int cc){
    if(stat[pos] > 1 || cc >= mn) return INF;
    if(pos == des){
//        DC(ss);
        if(mn > cc) mn= cc;
        return cc;
    }
    
//    DD(pos)
    int t1= INF, t2= INF;
    
//        ss.push_back(pos);
    if(pos+1 <= des){
        stat[pos]++;
        t1= path(stair, stat, pos+1, des, cc+1);
        stat[pos]--;
    }
    
    if(pos+stair[pos] <= des && pos+stair[pos] >= 0){
        stat[pos+stair[pos]]++;
        t2= path(stair, stat, pos+stair[pos], des, cc+1);
        stat[pos+stair[pos]]--;
    }
//        ss.pop_back();
    
    
    return min(t1, t2);
}


void solve(void){
    int Tc;
    int n;
    
    cin>>Tc;
    cin.ignore();
    
    
    int stair[30];
    static int stat[30];
    
    for(int Case= 1; Case<=Tc; Case++)
    {
        cin>>n;
        for(int i= 0; i<30; i++){
            stat[i]= 0;
        }
        sary(stair, stair+n);
        mn= INF;
        
        cout<< path(stair, stat, 0, n, 0) <<endl;
    }

}



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
   
    return 0;
}
