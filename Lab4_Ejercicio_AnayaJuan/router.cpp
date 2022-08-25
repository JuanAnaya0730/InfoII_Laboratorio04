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

size_t router::getCost(const string &name) const
{
    return connections.find(name)->second;
}

void router::addConection(const string &nameNode, const size_t &cost)
{
    connections[nameNode] = cost;
}
