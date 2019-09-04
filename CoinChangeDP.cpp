#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int D=0;
  int N=0;



  cout << "Enter N (the total amount to be changed)" << '\n';
  cin >> N;
  cout << "Enter D (number of denominations)" << '\n';
  cin >> D;
  int c[D];
  for (int i = 0; i < D; i++)
  {
    cout << "Enter next denomination" << '\n';
    cin >> c[i];
  }

  int X[N+1][D+1];
  for (int t= 0; t <= N; t++)
  {
    for (int i = 0; i <= D; i++)
    {
      X[t][i]=0;
    }
  }
  for (size_t t = 0; t <=N ; t++)
  {
    X[t][0]=t;

  }
  for (int t= 1; t <= N; t++)
  {
    for (int i = 1; i <= D; i++)
    {
      if (t>=c[i-1])
      {
        X[t][i]=min(X[t][i-1],(X[t-c[i-1]][i]+1));
        // c[i-1] since we started the i from 1, not zero
      }
      else
      {
        X[t][i]=X[t][i-1];
      }


    }
  }

  cout<<"**** Table of Dynamic Programming Method ****"<< '\n';

  for (int t= 0; t <= N; t++)
  {
    for (int i = 0; i <= D; i++)
    {
      cout<< X[t][i]<< '\t';

    }
    cout<< '\n';
  }

  cout<<"**** The End ****"<< '\n';

  return 0;
}

int min(int a, int b)
{
  if (a<=b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
