// function and procedur example

#include <iostream>
using namespace std;

//sample of function
int addition (int a, int b)
{
  int r;
  r = a+b;
  return r;
}

//sample of procedure
void printarray (int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main ()
{
  int z;
  int array[] = {2, 4, 6, 8, 10};

  z = addition (5,3);
  cout << "The result is " << z << endl;
  printarray (array, 5);

  return 0;
}