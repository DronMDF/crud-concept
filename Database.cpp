
#include "Database.h"
#include <iostream>
#include <boost/foreach.hpp>
#include "Crud.h"

using namespace std;

template <typename T, typename PRIV>
struct IO {
	PRIV encode(const T &t) const;
	T decode(const PRIV &p) const;
};

struct dbObject {
};

template<>
struct IO<Object, dbObject> {
	dbObject encode(const Object &) const {
		cout << __PRETTY_FUNCTION__ << endl;
		return dbObject();
	}

	Object decode(const dbObject &) const {
		cout << __PRETTY_FUNCTION__ << endl;
		return Object();
	}
};

template <typename T, typename PRIV>
class CrudDb : public Crud<T>, private IO<T, PRIV> {
	void create(const T &t) {
		cout << __PRETTY_FUNCTION__ << endl;
		this->encode(t);

	}
	vector<T> read() const {
		cout << __PRETTY_FUNCTION__ << endl;
		const T t = this->decode(PRIV());
		return vector<T>(1, t);
	}
	void update(const T &) {
		cout << __PRETTY_FUNCTION__ << endl;
	}
	void delet(const T &) {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

shared_ptr<Crud<Object>> Database::createObjectCrud() const {
	return make_shared<CrudDb<Object, dbObject>>();
}
