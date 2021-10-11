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

 Des::Des() {

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

void Des::xorR(Des& d) {
std::string temp, a, b, f, g;
  for(int j = 0; j < 16; j++) {
    a = d.right;
    b = d.subkeys[j];
    for(int i = 0; i < 48; i++) {
      f = a[i];
      g = b[i];
      if( f == g) {
        temp = temp + "0";
      }else {
        temp = temp + "1";
      }
    }
    d.xorRight[j] = temp;
    temp = "";
  }
}

void Des::sixthbits(Des& d) {
  std::string temp;
  int a = 0;
for(int n = 0; n < 16; n++) {
  temp = d.xorRight[n];
  for(int j = 0; j < 8; j++) {
    for(int i = 0; i < 6; i++) {
      d.sixth[n][j] = d.sixth[n][j] + temp[a];
      a++;
    }
  }
  a = 0;
}
}

void Des::sBox(Des& d) {
  std::string temp, temp2, temp4;
  int row, col, num = 0, temp3;
  Table t;
for(int j = 0; j < 16; j++) {
  for(int i = 0; i < 8; i++) {
    temp = sixth[j][i];
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
        temp3 = t.s1[col][j];
        std::bitset<4> k(temp3);
        temp2 = k.to_string();;
        //std::cout << temp2 << std::endl;
    break;
  }
  case 1: {
      temp3 = t.s2[col][j];
      std::bitset<4> k(temp3);
      temp2 = k.to_string();;
      std::cout << temp2 << std::endl;
  break;
}
case 2: {
    temp3 = t.s3[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
//    std::cout << temp2 << std::endl;
break;
}
case 3: {
    temp3 = t.s4[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
//  std::cout << temp2 << std::endl;
break;
}
case 4: {
    temp3 = t.s5[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
  //  std::cout << temp2 << std::endl;
break;
}
case 5: {
    temp3 = t.s6[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
//  std::cout << temp2 << std::endl;
break;
}
case 6: {
    temp3 = t.s7[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
  //  std::cout << temp2 << std::endl;
break;
}
case 7: {
    temp3 = t.s8[col][j];
    std::bitset<4> k(temp3);
    temp2 = k.to_string();;
  //  std::cout << temp2 << std::endl;
break;
}
  }
  num++;
    }
  num = 0;
  }


  /*int a = 0;
  temp = d.sixth[0][4];
  std::cout << temp << std::endl;
  temp3 = "0";//temp[0];
  temp3 = temp3 + "0";//temp[5];
  temp3 = temp3 + "1";
  temp3 = temp3 + "1";
  std::cout << temp3 << std::endl;
  std::bitset<4> temp4(temp3);
  a = temp4.to_ulong();
  std::cout << a << std::endl;*/
}
