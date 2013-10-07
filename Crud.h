
#pragma once
#include <vector>

struct Object {
};

template <typename T>
class Crud {
public:
	virtual void create(const T &t) = 0;
	virtual std::vector<T> read() const = 0;
	virtual void update(const T &t) = 0;
	virtual void delet(const T &t) = 0;
};
