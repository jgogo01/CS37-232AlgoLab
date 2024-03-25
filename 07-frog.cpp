#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int jump_frog_jump(char s[])
{
  int n = strlen(s);
  int d = 0;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'R')
    {
      d = i + 1;
    }
    else
    {
      ans = max(ans, (i + 1) - d);
    }
  }
  return ans + 1;
}

int main()
{
  int t;
  cin >> t;

  if (t == 0)
  {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < t; i++)
  {
    char s[10000];
    cin >> s;
    cout << jump_frog_jump(s) << endl;
  }
  return 0;
}