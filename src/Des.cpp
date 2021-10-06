/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#include "Des.h"
#include "Table.h"
#include <string>
#include <iostream>
#include <fstream>

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
  int a, c = 0;

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
  for(int i = 0; i < 27; i++) {
    temp = temp + key[i];
  }
  left = temp;
  for(int i = 28; i < 56; i++) {
    temp2 = temp2 + key[i];
  }
  right = temp2;
}

bool Des::leftnum (int a) {
  if (a == 1 || a == 2 ||a == 9 ||a == 16) {
    return true;
  }
  return false;
}

void Des::subkey(std::string key) {
  std::string left, right, temp, temp2;
    std::string lefta [16];
  splitkey(key, left, right);
  std::cout << left << std::endl;
  for(int j = 0; j < 16; j++) {
  for(int i = 0; i < 27; i++) {
   if (leftnum(i)) {
    temp2 = left[i + 1];
    if (temp2 == "1") {
      temp = temp + "1";
    } else {
      temp = temp + "0";
    }
    temp2 = left[i + 2];
    if (temp2 == "1") {
      temp = temp + "1";
    } else {
      temp = temp + "0";
    }
  }
  }
  lefta [j] = temp;
}

 std::cout << lefta[1] << std::endl;
}
