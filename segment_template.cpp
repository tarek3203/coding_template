                        
                        /****************************************************************/
                        /****************************************************************/
                        /**                                                            **/
                        /**                  BISMIintAHIR RAHMANIR RAHIM                **/
                        /**                ENLIVEN___BOY___TAREK   NEWBIE              **/ 
                        /**              MANARAT__lNTERNATIONAL__UNIVERSITY            **/
                        /**       DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING       **/
                        /**     INSHA-AintAH  I WIint BE ABLE TO CONFIRM MY DREAM JOB    **/
                        /**                                                            **/
                        /****************************************************************/
                        /****************************************************************/
                        
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define w(aa) ll tc;cin>>tc;while(tc--)
const int N = 1e6 + 9;
/*int abs(int x){
    return (x>0?x:-x);
}*/
/*  
    int a=6;
    int *p=&a;
    int **q=&p;
    int ***r=&q;
    cout<<*p<<endl;//6
    cout<<*q<<endl;//address of a or value of p
    cout<<*(*q)<<endl;//6
    cout<<*r<<endl;//address of p or value of q
    cout<<**r<<endl;//address of a or value of p
    cout<<***r<<endl;//6
*/
/*
   &a[i] or a+i 
   a[i] or *(a+i)
*/   
/*
      string s,s1;
      s.assign(n,'a');
      s1.assign(n,'b');
      sort(a+1,a+1+n);
      sort(v.begin()+1,v.end()+n+1);//vector<int>v(n+1)
*/
/*
   x=s[i]-'0'; if i need to get an integer from a character.
   x='0'+s[i]; if i need to get a character from an integer.
*/
/*
    const int *p or int const *p    //p++ is valid    //(*p)++ is invalid.
    int *const p   //p++ is invalid // (*p)++ is valid.
*/
//scanf(" %c",&ch);
/* int prime(int pp){
    for(int i=2;i*i<=pp;i++){
        if(pp%i==0)return false;
    }
    return true;
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int X_OR(int n){// this is the sum of getting x_or operation
    if(n%4==0)return n;
    else if(n%4==1)return 1;
    else if(n%4==2)return n+1;
    return 0;
} */
// vector<string>v(n,(n,'+'));
// A (X_OR) B = C OR A (X_OR) C = B ..
//A quadrilateral can be built when max(a,b,c,d)<a+b+c+d−max(a,b,c,d)..
//a+b=(a&b)+(a|b)// interesting
/* 
  auto st = clock();
  ......
  ........ code 
  .......
  cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
  */
int a[N];
int t[N*4];
void build(int node , int b , int e){
    if(b == e){
        t[node] = a[e];
        return;
    }
    int l_node = node * 2 , r_node = node * 2 + 1;
    int mid = (b + e) / 2;
    build(l_node , b , mid);
    build(r_node , mid + 1 , e);
    t[node] = t[l_node] + t[r_node];   
}
void upd(int node , int b , int e , int i , int v){
    if(i < b or i > e)return;
    if(b == e){
        t[node] = v;
        a[i] = v;
        return;
    }
    int l_node = node * 2 , r_node = node * 2 + 1;
    int mid = (b + e) / 2;
    upd(l_node , b , mid , i , v);
    upd(r_node , mid + 1 , e , i , v);
    t[node] = t[l_node] + t[r_node];
}
int sum(int node , int b , int e , int i , int j){
     if(j < b or i > e)return 0;
     if(i <= b and j >= e){
        return t[node]; 
     }
     int l_node = node * 2 , r_node = node * 2 + 1;
     int mid = (b + e) / 2;
     return  (sum(l_node , b , mid , i , j) + sum(r_node , mid + 1 , e , i , j));
}
 int main(){
    /*
     ios_base::sync_with_stdio(0);
      cin.tie(0)
    */
   int n , m , o , l , r;
   cin >> n >> m;// a = 1,2,3,4,5
   for (int i = 1; i <= n; i++){
       cin >> a[i];
   } 
   build(1 , 1 , n);
   
   while(m--){
       cin >> o >> l >> r;
       if(o == 1){
           upd(1 , 1 , n , l + 1 , r);
           /* for(int i = 1; i <= n; i++)cout << a[i] << " ";
           cout << endl;
           cout << t[1] << '\n'; */
       }
       else {
           cout << sum(1 , 1 , n , l + 1 , r) << '\n';
       }
   }
   
   //cout << sum(1 , 1 , n , 2 , 4) << endl;
   return 0;
}
