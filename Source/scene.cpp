#include "../Headers/scene.hh"
/*
fluktuacje


*/

static std::vector<std::shared_ptr<displayableObject>> sceneObjects;
static geom::vec3f transsum;

void scene::translate(geom::vec3f transvec){
	for (unsigned int i = 0; i < sceneObjects.size(); i++) {
		sceneObjects[i]->pos = sceneObjects[i]->pos + transvec;
	}
	transsum = transsum + transvec;
}

void scene::init(){
	transsum = geom::vec3f(0, 0, 0);

	lacze.ZmienTrybRys(PzG::TR_3D);
	lacze.Inicjalizuj();

	lacze.UstawZakresX(-100, 100);
	lacze.UstawZakresY(-100, 100);
	lacze.UstawZakresZ(-100, 100);
}

void scene::addDisplayableObject(std::shared_ptr<displayableObject> newObject){
	sceneObjects.push_back(newObject);
	lacze.DodajNazwePliku(newObject->getfilename().c_str());
}

void scene::reset(){
	translate(geom::vec3f(0, 0, 0) - transsum);
	transsum = geom::vec3f(0, 0, 0);
}

void scene::update(){
	for (unsigned int i = 0; i < sceneObjects.size(); i++) {
		(*sceneObjects[i]).display();
	}
	lacze.Rysuj();
}
