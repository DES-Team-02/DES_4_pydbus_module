#pragma once

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/JetsonStubDefault.hpp>

using namespace v0::commonapi;

class JetsonStubImpl: public JetsonStubDefault
{
public:
	JetsonStubImpl();
	virtual ~JetsonStubImpl();
};