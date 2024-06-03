#ifndef JETSONPROXYIMPL_HPP
#define JETSONPROXYIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <CommonAPI/AttributeCacheExtension.hpp>
#include "../src-gen/core/v0/commonapi/JetsonProxy.hpp"
#include <iostream>

using namespace v0::commonapi;

class JetsonProxyImpl {
public:
    JetsonProxyImpl();
    virtual ~JetsonProxyImpl() {}

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<typename CommonAPI::DefaultAttributeProxyHelper<JetsonProxy, CommonAPI::Extensions::AttributeCacheExtension>::class_t> myProxy;
};

#endif // JETSONPROXYIMPL_HPP
