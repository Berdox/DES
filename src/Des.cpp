/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
 #include "Des.h"
 #include "Table.h"
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <bitset>
 #include <sstream>

 Des::Des() {

 }

void Des::encryption(std::string plain, std::string key) {
  std::string keyp;
  Des d;
  // gets it into 64 bits
//  plain64 = d.splitplain(plain);
  //std::cout << plain64 << std::endl;
  // gets all the 8th bits out
  keyp = d.keyperm(key);
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
  d.plaind = d.plainperm(plain);
  //std::cout << perm << std::endl;

  for(int num = 0; num < 16; num++) {

  //splits the plain text into two halves
  d.halfplain(d.plaind, d);
  //std::cout << d.left << std::endl << d.right << std::endl;

  // does the expansion permutation to the right half
  d.expandright(d);
  //std::cout << d.right << "\n";

  // XOR the expanded right and subkeys
  d.xorR(d, num);
  //std::cout << d.xorRight[0] << "\n";

  // gets the six bits from the XOR results
  d.sixthbits(d);
  //std::cout << "0,0  " <<  d.sixth[0][0];

  d.sBox(d, num);
  //std::cout << d.sBoxresult[0][7] << std::endl;

  d.combineSBox(d);
  //std::cout << d.newright[3] << std::endl;

  d.permSBox(d);
  //std::cout << d.newright[0] << std::endl;

  d.finalxor(d);
  //std::cout << d.finalright[0] << std::endl;

  d.reverse(d);
  //std::cout << d.final64[3] << std::endl;
  }

  d.finalPerm(d);

  std::cout << d.end << std::endl;

  d.string_hex(d);
}

void Des::dencryption(std::string plain, std::string key) {
  std::string keyp;
  Des d;
  // gets it into 64 bits
//  plain64 = d.splitplain(plain);
  //std::cout << plain64 << std::endl;
  // gets all the 8th bits out
  keyp = d.keyperm(key);
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
  d.plaind = d.plainperm(plain);
  //std::cout << perm << std::endl;

  for(int num = 15; num == -1; num--) {

  //splits the plain text into two halves
  d.halfplain(d.plaind, d);
  //std::cout << d.left << std::endl << d.right << std::endl;

  // does the expansion permutation to the right half
  d.expandright(d);
  //std::cout << d.right << "\n";

  // XOR the expanded right and subkeys
  d.xorR(d, num);
  //std::cout << d.xorRight[0] << "\n";

  // gets the six bits from the XOR results
  d.sixthbits(d);
  //std::cout << "0,0  " <<  d.sixth[0][0];

  d.sBox(d, num);
  //std::cout << d.sBoxresult[0][7] << std::endl;

  d.combineSBox(d);
  //std::cout << d.newright[3] << std::endl;

  d.permSBox(d);
  //std::cout << d.newright[0] << std::endl;

  d.finalxor(d);
  //std::cout << d.finalright[0] << std::endl;

  d.reverse(d);
  //std::cout << d.final64[3] << std::endl;
  }

  d.finalPerm(d);

  d.string_hex(d);
}

 std::string Des::splitplain(std::string s) {
   std::string a;
   for(int i = 0; i < (s.size()/2); i++) {
     a += s[i];
   }
   return a;
 }

 std::string Des::keyperm(std::string plain) {
   std::string temp;
Table t;
int a;

for(int i = 0; i < 56; i++) {
  a = t.ktb[i];
  temp = temp + plain[a];
}
return temp;
 }

void Des::keysplit(std::string key, Des& d) {
   std::string temp, temp2;
for(int i = 0; i < 28; i++) {
  temp = temp + key[i];
}
d.left = temp;
for(int i = 28; i < 56; i++) {
  temp2 = temp2 + key[i];
}
d.right = temp2;
d.OriRight = temp2;
 }

void Des::subkey(Des& d) {
   for(int j = 0; j < 16; j++) {
   d.leftkeys[j] = leftshift(j, d.left);
   }
   for(int j = 0; j < 16; j++) {
     d.rightkeys[j] = leftshift(j, d.right);
   }
   combkeys(d);
 }

std::string Des::leftshift(int num, std::string& key) {
  Des d;
  std::string temp;
  for(int i = 0; i < d.shift[num]; i++) {
    for (int j = 1; j < 28; j++) {
           temp = temp + key[j];
       }
       temp = temp + key[0];
       key = temp;
       temp = "";
   }
   return key;
}

void Des::combkeys(Des& d) {
  for(int i = 0; i < 16; i++) {
    d.keys[i] = d.leftkeys[i] + d.rightkeys[i];
  }
}

void Des::finalkeys(Des& d) {
  Table t;
  int a;
  std::string b, temp;
  for(int j = 0; j < 16; j++) {
    b = d.keys[j];
  for(int i = 0; i < 48; i++) {
     a = t.subtab[i];
     temp = temp + b[a-1];
   }
   d.subkeys[j] = temp;
   temp = "";
 }
}

std::string Des::plainperm(std::string plain) {
  std::string temp;
Table t;
int a;

for(int i = 0; i < plain.size(); i++) {
  a = t.tb1[i];
  temp = temp + plain[a-1];
}
return temp;
}

void Des::halfplain(std::string plain, Des& d) {
  std::string temp, temp2;
for(int i = 0; i < 32; i++) {
  temp = temp + plain[i];
}
d.left = "";
d.left = temp;
for(int i = 32; i < 64; i++) {
  temp2 = temp2 + plain[i];
}
d.right = "";
d.right = temp2;
}

void Des::expandright(Des& d) {
  std::string temp;
Table t;
int a;

for(int i = 0; i < 48; i++) {
  a = t.expan[i];
  temp = temp + d.right[a-1];
}
d.right = temp;
}

void Des::xorR(Des& d, int num) {
std::string temp, a, b, f, g;
    a = d.right;
    b = d.subkeys[num];
    for(int i = 0; i < 48; i++) {
      f = a[i];
      g = b[i];
      if( f == g) {
        temp = temp + "0";
      }else {
        temp = temp + "1";
      }
    }
    d.xorRight = temp;
    temp = "";
}

void Des::sixthbits(Des& d) {
  std::string temp;
  int a = 0;
  temp = d.xorRight;
  for(int j = 0; j < 8; j++) {
    for(int i = 0; i < 6; i++) {
      d.sixth[j] = d.sixth[j] + temp[a];
      a++;
    }
  }
  a = 0;
}

void Des::sBox(Des& d, int num) {
  std::string temp, temp2, temp4;
  int row, col, temp3;
  Table t;
  for(int i = 0; i < 8; i++) {
    temp = d.sixth[i];
    temp2 = temp[0];
    temp2 = temp2 + temp[5];
    std::bitset<2> a(temp2);
    row = a.to_ulong();
    //std::cout << row << std::endl;
    temp2 = temp + temp[1];
    temp2 = temp + temp[2];
    temp2 = temp + temp[3];
    temp2 = temp + temp[4];
    std::bitset<4> b(temp2);
    col = b.to_ulong();
    //std::cout << col << std::endl;

    switch (num) {
    case 0: {
        temp3 = t.s1[row][col];
        std::bitset<4> k(temp3);
        temp2 = k.to_string();
        d.sBoxresult[i] = temp2 + d.sBoxresult[i];
        //std::cout << temp2 << std::endl;
    break;
  }
  case 1: {
      temp3 = t.s2[row][col];
      std::bitset<4> k(temp3);
      temp2 = k.to_string();
      d.sBoxresult[i] = temp2 + d.sBoxresult[i];
      //std::cout << temp2 << std::endl;
  break;
}
case 2: {
    temp3 = t.s3[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
//    std::cout << temp2 << std::endl;
break;
}
case 3: {
    temp3 = t.s4[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
//  std::cout << temp2 << std::endl;
break;
}
case 4: {
    temp3 = t.s5[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
  //  std::cout << temp2 << std::endl;
break;
}
case 5: {
    temp3 = t.s6[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
//  std::cout << temp2 << std::endl;
break;
}
case 6: {
    temp3 = t.s7[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
  //  std::cout << temp2 << std::endl;
break;
}
case 7: {
    temp3 = t.s8[row][col];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();
    d.sBoxresult[i] = temp2 + d.sBoxresult[i];
  //  std::cout << temp2 << std::endl;
break;
}
  }
    }
}

void Des::combineSBox(Des& d) {
  std::string temp;

    for(int i = 0; i < 8; i++) {
      temp = temp + d.sBoxresult[i];
    }
    d.newright = d.newright + temp;
    temp = "";
}

void Des::permSBox(Des& d) {
  std::string temp, temp2;
Table t;
int a;
for(int i = 0; i < 32; i++) {
  a = t.tb3[i];
  temp2 = d.newright;
  temp = temp + temp2[a-1];
}
d.newright = temp;
temp = "";
}

void Des::finalxor(Des& d) {
  std::string temp, a, b, f, g;
      a = d.left;
      b = d.newright;
      for(int i = 0; i < 32; i++) {
        f = a[i];
        g = b[i];
        if( f == g) {
          temp = temp + "0";
        }else {
          temp = temp + "1";
        }
      }
      d.finalright = temp;
      temp = "";
}

void Des::reverse(Des& d) {
  std::string temp, temp2;
  for(int j = 0; j < 16; j++) {
    temp = d.finalright;
    for(int i = 0; i < 32; i++) {
      temp2 = temp + d.left;
    }
    d.plaind = temp2;
    temp2 = "";
  }
}

void Des::finalPerm(Des& d) {
  std::string temp, temp2;
Table t;
int a;
for(int i = 0; i < 64; i++) {
  a = t.tb4[i];
  temp2 = d.plaind;
  temp = temp + temp2[a-1];
}
d.end = temp;
temp = "";
}

void Des::string_hex(Des& d) {
  std::string a;
  char b;
  int num = 0;
  for(int j = 0; j < 8; j++) {
  for(int i = 0; i < 8; i++) {
      a = a + end[num];
      num++;
  }
    //std::cout << a << std::endl;
std::bitset<8> c(a);
    b = c.to_ulong();
std::cout << std::hex << (int)b << std::endl;
a = "";
}
}
