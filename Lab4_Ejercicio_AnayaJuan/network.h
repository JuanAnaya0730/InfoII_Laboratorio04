#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <fstream>
#include <vector>
#include "router.h"

using namespace std;

class network
{
private:
    string name;
    vector<router> topology;

    string read();
    void write(const string &data);

public:
    network();

    void load_network();
    void save_network();
};

#endif // NETWORK_H
