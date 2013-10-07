
#include "Database.h"
#include "Crud.h"

using namespace std;

int main(int, char **)
{
	Database db;
	shared_ptr<Crud<Object>> crud_obj = db.createObjectCrud();
	crud_obj->create(Object());
	vector<Object> objects = crud_obj->read();
	crud_obj->update(Object());
	crud_obj->delet(Object());

	return 0;
}
