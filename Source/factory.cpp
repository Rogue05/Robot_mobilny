#include "../Headers/factory.hh"

factory & factory::get(){
	static factory _factory;
	return _factory;
}

std::shared_ptr<displayableObject> factory::produce(objtypes type){
	std::shared_ptr<displayableObject> my_ptr;
	if (type == o_robot) my_ptr = std::shared_ptr<robot>(new robot());
	if (type == o_barrier) my_ptr = std::shared_ptr<barrier>(new barrier());
	if (type == o_path) my_ptr = std::shared_ptr<path>(new path());
	return my_ptr;
}
