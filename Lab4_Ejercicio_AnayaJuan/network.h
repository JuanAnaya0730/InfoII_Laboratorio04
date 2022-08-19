#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "router.h"

using namespace std;

class network
{
private:
    string file;
    vector<router> topology;

    string read();
    void write();

public:
    network();

    void load_network();
    void save_network();
};

#endif // NETWORK_H
