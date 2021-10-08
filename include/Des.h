/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#ifndef DES_H
#define DES_H

#include <string>
#include <vector>

class Des {
public:
Des();

std::string bitremove(std::string);
std::string tp(std::string);
void split(std::string, std::string&, std::string&);
void splitkey(std::string, std::string&, std::string&);
void subkey(std::string);
std::string leftshift(int, std::string&);

private:
  int shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
  std::string leftkeys [16];
  std::string rightkeys [16];
};
#endif
