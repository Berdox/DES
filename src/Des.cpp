/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#include "Des.h"
#include "Table.h"
#include <string>
#include <iostream>

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
