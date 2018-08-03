#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >>n ;
  int m, l=n.length();
  if (l>1)
    m=stoi(n.substr(l-2));
  else 
    m=n[l-1]-'0';
  cout<<
  (1+(int)pow(2,m%4)+(int)pow(-2,m%4) +(int)pow(-1,m%2))%5;
} 
