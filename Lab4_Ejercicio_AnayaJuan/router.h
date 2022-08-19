#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class router
{
private:
    string name;
    map<string, size_t> connections;

public:
    router();
};

#endif // ROUTER_H
