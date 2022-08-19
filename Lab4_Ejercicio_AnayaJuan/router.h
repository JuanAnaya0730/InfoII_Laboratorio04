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

    const string &getName() const;
};

#endif // ROUTER_H
