#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <map>

#define INF 999999

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
    void setName(const string &name);

    const size_t &getCost(const string &name) const;

    void addConection(const string &name, const size_t &cost);
    void deleteConnection(const string &name);
};

#endif // ROUTER_H
