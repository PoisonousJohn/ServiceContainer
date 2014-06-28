#include "ServiceInterface.h"
#include <iostream>

ServiceInterface::ServiceInterface()
{
}

ServiceInterface::~ServiceInterface()
{
    std::cout << "destructor: service: interface" << std::endl;
}
