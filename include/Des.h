/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#ifndef DES_H
#define DES_H

#include <string>

class Des {
public:
Des();

std::string bitremove(std::string);
std::string tp(std::string);
void split(std::string, std::string&, std::string&);
void splitkey(std::string, std::string&, std::string&);
void subkey(std::string);
bool leftnum(int);

};
#endif
