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

void router::addConection(const string &nameNode, const size_t &cost)
{
    connections[nameNode] = cost;
}
