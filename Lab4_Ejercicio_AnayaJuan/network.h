#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "router.h"

using namespace std;

class network
{
private:
    vector<router> topology;

public:
    network();
};

#endif // NETWORK_H
