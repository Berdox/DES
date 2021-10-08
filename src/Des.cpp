/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#include "Des.h"
#include "Table.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

 Des::Des() {

 }

std::string Des::bitremove(std::string in) {
  std::string temp;
  for (int i = 0; i < 7; i++) {
    temp = temp + in[i];
  }
  for (int i = 8; i < 15; i++) {
    temp = temp + in[i];
  }
  for (int i = 16; i < 23; i++) {
    temp = temp + in[i];
  }
  for (int i = 24; i < 31; i++) {
    temp = temp + in[i];
  }
  for (int i = 32; i < 39; i++) {
    temp = temp + in[i];
  }
  for (int i = 40; i < 47; i++) {
    temp = temp + in[i];
  }
  for (int i = 48; i < 55; i++) {
    temp = temp + in[i];
  }
  for (int i = 56; i < 63; i++) {
    temp = temp + in[i];
  }
  return temp;
}

std::string Des::tp(std::string b) {
  std::string temp;
  Table t;
  int a;

 for(int i = 0; i < b.size(); i++) {
    a = t.tb(i);
    temp = temp + b[a-1];
  }
 return temp;
}

void Des::split(std::string beg, std::string& left, std::string& right) {
  std::string temp, temp2;
  for(int i = 0; i < 32; i++) {
    temp = temp + beg[i];
  }
  left = temp;
  for(int i = 32; i < 64; i++) {
    temp2 = temp2 + beg[i];
  }
  right = temp2;
/*  std::ofstream f;
  f.open("output.txt");
  f << right;
  f.close();*/
}

void Des::splitkey(std::string key, std::string& left, std::string& right) {
  std::string temp, temp2;
  for(int i = 0; i < 28; i++) {
    temp = temp + key[i];
  }
  left = temp;
  for(int i = 28; i < 56; i++) {
    temp2 = temp2 + key[i];
  }
  right = temp2;
}

void Des::subkey(std::string key, Des& alg) {
  std::string left, right;
  splitkey(key, left, right);
  std::cout << left << std::endl;
   std::ofstream f;
    f.open("output.txt");
    f << "left origin key = " << left << "\n";
  for(int j = 0; j < 16; j++) {
  alg.leftkeys[j] = leftshift(j, left);
     f << "l" << j+1 << " = " << alg.leftkeys[j] << "\n";
  }
  for(int j = 0; j < 16; j++) {
    alg.rightkeys[j] = leftshift(j, right);
     f << "R" << j+1 << " = " << alg.rightkeys[j] << "\n";
  }
      f.close();
    combkeys(alg);
}

std::string Des::leftshift(int num, std::string& key) {
  std::string temp;
  for(int i = 0; i < shift[num]; i++) {
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
  std::ofstream f;
   f.open("com.txt");
  for(int i = 0; i < 16; i++) {
    keys[i] = leftkeys[i] + rightkeys[i];
    f << keys[i] << std::endl;
  }
  f.close();
}


void Des::finalkeys(Des& alg) {
  Table t;
  int a;
  std::string b, temp;
  std::ofstream f;
   f.open("sub.txt");
  for(int j = 0; j < 16; j++) {
    b = keys[j];
  for(int i = 0; i < 48; i++) {
     a = t.subtab1(i);
     temp = temp + b[a-1];
   }
   subkeys[j] = temp;
   f << subkeys[j] << std::endl;
   temp = "";
 }
 f.close();
}
