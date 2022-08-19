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
    size_t findRouter(const string &nameRout);

public:
    network();

    void load_network(const string &name);
    void save_network();

    void complete();

    int cost(const string &startRouter, const string &destinationRouter);
};

#endif // NETWORK_H
