#include<bits/stdc++.h>
using namespace std;
#define lli long long int
//MODULAR EXPONENTIATION

lli expo(lli x, lli y, lli m) 
{ 
    if (y == 0) 
        return 1; 
    lli p = expo(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
