#pragma once
#include <memory>
#include "Crud.h"

class Database {
public:
	std::shared_ptr<Crud<Object>> createObjectCrud() const;
};
