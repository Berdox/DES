#include <vector>
#include <string>

#ifndef DES_H
#define DES_H

class Des {
public:
    Des();
    ~Des();
    void run();
    std::vector<std::string> keyGen(std::string); 

};

#endif
