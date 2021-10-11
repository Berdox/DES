#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {
std::string input = "0123456789abcdef", plain, plain64, key, perm;
Des d;
Table t;
//plain64 = t.hextobin(input);
char a;
for(int i = 0; i < input.size(); i++){
plain = plain + t.char_to_str(input[i]);
}
//std::cout << plain << std::endl;
// gets it into 64 bits
plain64 = d.splitplain(plain);
//std::cout << plain64 << std::endl;
// gets all the 8th bits out
key = d.keyperm(plain64);
//std::cout << key << std::endl;
// splits the key in half
d.keysplit(key, d);
//std::cout << d.left << "\n" << d.right << "\n";
// does leftshifts and combines the left and right keys
d.subkey(d);
//std::cout << d.keys[0];
d.finalkeys(d);
//std::cout << d.subkeys[0];
//done with the keysplit


// Does the intial permutation to the plaintext
perm = d.plainperm(plain64);
//std::cout << perm << std::endl;

//splits the plain text into two halves
d.halfplain(perm, d);
//std::cout << d.left << std::endl << d.right << std::endl;

// does the expansion permutation to the right half
d.expandright(d);
//std::cout << d.right << "\n";

// XOR the expanded right and subkeys
d.xorR(d);
//std::cout << d.xorRight[0] << "\n";

// gets the six bits from the XOR results
d.sixthbits(d);
//std::cout << "0,0  " <<  d.sixth[0][0];

d.sBox(d);




/*
for(int i = 0; i<< plain64.size(); i++) {
p = plain64[i];
p =p+ plain64[i + 1];
p =p+ plain64[i+ 2];
p =p+ plain64[i + 3];
p =p+ plain64[i+ 4];
p =p+ plain64[i+ 5];
p =p+ plain64[i + 6];
p =p+ plain64[i+ 7];
std::cout << p << std::endl;
a = t.str_to_char("01100000");
q = q + a;9
std::cout << q << std::endl;
}
a = t.str_to_char(p);
std::cout << t.str_to_char(p) << std::endl;
*/
char c;
std::cin >> c;
  return 0;
}
