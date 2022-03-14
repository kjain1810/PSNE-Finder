#include <bits/stdc++.h>
#include <ctime>
#include <random>

using namespace std;

int n, S[1000000]; 
map<vector<int>, vector<int>> U;
mt19937 mt(time(NULL));

void printU(int p, vector<int> &strats)
{
  if(p == -1)
    for (auto s: U[strats])
      cout << s << " ";
    /* cout << U[strats] << " "; */
  else
    for(int a = 0; a < S[p]; a++)
    {
      strats[p] = a;
      printU(p - 1, strats);
    }
}

void output()
{
  cout << n << endl;
  for(int a = 0; a < n; a++)
    cout << S[a] << " ";
  cout << endl;
  vector<int> vec(n, 0);
  printU(n - 1, vec);
}

void makeU(int p, vector<int> &strats)
{
  if(p == n)
  {
    vector<int> newU(n, 0);
    for(int a = 0; a < n; a++)
      newU[a] = ( abs((int)mt()) % 10 ) * ( (abs((int)mt()) % 2) * 2 - 1);
    /* int here = abs( (int)mt() ) % 10; */
    /* here *= here * ((int)mt() * 2 - 1); */
    U[strats] = newU;
  }
  else
  {     
    for(int a = 0; a < S[p]; a++)
    {
      strats.push_back(a);
      makeU(p + 1, strats);
      strats.pop_back();
    }
  } 
}

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    cout << "Usage: ./a.out <output file name>" << endl;
    return 0;
  }
  freopen(argv[1], "w", stdout);
  n = 15;
  for(int a = 0; a < 15; a++)
    S[a] = 2;
  vector<int> vec;
  /* cout << "U are to be made" << endl; */
  makeU(0, vec);
  /* cout << "U are made" << endl; */
  output();
  return 0;
}
