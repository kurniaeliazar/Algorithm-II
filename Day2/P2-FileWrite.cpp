//source : http://www.cplusplus.com/doc/tutorial/files/
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("myfile.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}