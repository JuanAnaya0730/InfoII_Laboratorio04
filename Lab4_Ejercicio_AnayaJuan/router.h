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
    router(const string &name);

    const string &getName() const;
    void addConection(const string &nameNode, const size_t &cost);

};

#endif // ROUTER_H
