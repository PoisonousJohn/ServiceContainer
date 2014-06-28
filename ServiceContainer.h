#ifndef SERVICECONTAINER_H
#define SERVICECONTAINER_H

#include <unordered_map>
#include <string>
#include <assert.h>

class ServiceInterface;

class ServiceContainer
{
private:
    static ServiceContainer* container;
    std::unordered_map <std::string, ServiceInterface* > services_;

    ServiceContainer();
    ~ServiceContainer();
    
    // forbid copy
    ServiceContainer(const ServiceContainer&);
    ServiceContainer& operator=(const ServiceContainer&);
    
public:
    template <typename T, typename ... Args>
    void registerService( Args ... args ) {
        services_.insert( std::make_pair( T::getId(), new T(args...) ));
    }
    
    void removeService(std::string serviceId);

    void clear();

    template <typename T>
    T* getService() {
        assert(services_.find(T::getId()) != services_.end() && "service not found");
        return static_cast<T*>(services_[T::getId()]);
    }

    static ServiceContainer& sharedContainer();
    
    static void kill();

};

#endif // SERVICECONTAINER_H
