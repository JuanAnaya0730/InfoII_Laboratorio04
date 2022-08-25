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

void router::setName(const string &name)
{
    this->name = name;
    connections[name] = 0;
}

const size_t &router::getCost(const string &name) const
{
    return connections.find(name)->second;
}

void router::addConection(const string &name, const size_t &cost)
{
    connections[name] = cost;
}

void router::deleteConnection(const string &name)
{
    connections.erase(name);
}
