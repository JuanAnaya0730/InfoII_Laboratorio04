#include "router.h"

router::router()
{

}

router::router(const string &name)
{
    this->name = name;

    connections[name] = 0;
}

const string &router::getName() const
{
    return name;
}

const size_t &router::getCost(string &name)
{
    return connections.find(name)->second;
}

void router::addConection(const string &nameNode, const size_t &cost)
{
    connections[nameNode] = cost;
}
