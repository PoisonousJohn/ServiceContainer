#ifndef ISERVICE_H
#define ISERVICE_H

#include <ServiceContainer/ServiceContainer.h>

#define SERVICE_INSTANCE(T) \
static T* instance() { \
    return ServiceContainer::sharedContainer().getService<T>(); \
}

class ServiceInterface
{
public:
    ServiceInterface();
    virtual ~ServiceInterface();
};

#endif // ISERVICE_H
