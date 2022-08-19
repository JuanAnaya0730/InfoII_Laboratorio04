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
