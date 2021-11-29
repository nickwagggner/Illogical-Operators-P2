#include <iostream>
#include <list>

using namespace std;


int main(int argc, char * argv[] )
{
  list<string> L1{"0", "1"};	// initiate first list
  list<string> L2;		// initiate second list
  int nbit=1;			// bit size for our grey code sequence
  
  // while the grey code is not in 6-bit values
  while(nbit<6)
  {
    // every value in the second list will be the reverse of the first
    for (list<string>::iterator i=L1.begin(); i!=L1.end(); i++)
      L2.push_front(*i);
    
    // add a '0' to the beginning of each value in the first list
    for (list<string>::iterator i=L1.begin(); i!=L1.end(); i++)
      *i = "0" + *i;
    
    // add a '1' to the beginning of each value in the second list
    for (list<string>::iterator i=L2.begin(); i!=L2.end(); i++)
      *i = "1" + *i;
    
    // add the values into one list
    L1.merge(L2);
    
    // increment the bit size
    nbit++;
  }
  
  // a little something to help see where we are in the list ...
  int pos=1;
  
  // want to actually see our gray code
  for (list<string>::iterator i=L1.begin(); i!=L1.end(); i++)
  {
    // just an extra something to make everything line up easily
    if (pos<10)
      cout << pos << ":  " << *i << endl;
    else
      cout << pos << ": " << *i << endl;
    // changing our current position in the list
    pos++;
  }
  
  return 0;
}
