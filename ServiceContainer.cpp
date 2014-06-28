#include "ServiceContainer.h"
#include "ServiceInterface.h"
#include <iostream>

ServiceContainer* ServiceContainer::container = NULL;

ServiceContainer::ServiceContainer()
{
}

ServiceContainer::~ServiceContainer()
{
    clear();
    std::cout << "destructor: service container" << std::endl;
}

void ServiceContainer::kill() {
    if (container) {
        delete container;
        container = NULL;
    }
}

void ServiceContainer::clear() {
    for (std::unordered_map<std::string, ServiceInterface* >::iterator it = services_.begin(); it != services_.end(); ++it) {
        std::cout << "destructor: service: " << (*it).first << std::endl;
        delete (*it).second;
    }
    services_.clear();
}

ServiceContainer& ServiceContainer::sharedContainer()
{
    if (container == NULL) {
        container = new ServiceContainer();
    }
    return *container;
}

void ServiceContainer::removeService(std::string serviceId)
{
    std::unordered_map<std::string, ServiceInterface*>::iterator service;
    
    service = services_.find(serviceId);
    
    if ( service != services_.end() )
        services_.erase(service);
    else
        assert(service != services_.end() && "sevice not found");
}
