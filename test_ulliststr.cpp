#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat1;
  ULListStr dat2;
  ULListStr dat3;

  for (int i=0;i<12;i++){
    dat1.push_back(to_string(9)); //testing for all possible cases
  }
  
  for (int i=0;i<12;i++){
    cout << dat1.get(i) << endl; //checking
  }

  for (int i=0;i<12;i++){
    dat2.push_front(to_string(11)); //testing for all possible cases
  }

  for (int i=0;i<12;i++){
    cout << dat2.get(i) << endl; //checking
  }

  cout << dat3.size() << endl;

  dat3.pop_back();
  dat3.pop_front(); //checking for empty cases

  cout << dat3.size() << endl;

  for (int i=0;i<12;i++){
    dat3.push_back(to_string(11));
  }

  for (int i=0;i<12;i++){
    cout << dat3.get(i) << endl; //checking
  }

  dat3.set(0,dat1.back());
  dat3.set(1,dat1.front());

  for (int i=0;i<12;i++){
    cout << dat3.get(i) << endl; //checking
  }

  cout << dat3.size() << endl;

  for (int i=0;i<12;i++){
    dat3.pop_back(); // checking for all cases
  }

  cout << dat3.size() << endl;

}