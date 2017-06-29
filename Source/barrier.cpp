#include "../Headers/barrier.hh"

static unsigned int numofbarriers = 0;

barrier::barrier():ID(numofbarriers++){
	drawconfig = "vv ";
	
	filename = "Scene_txt/Barrier";
	filename += std::to_string(ID);
	filename += ".txt";

	mesh.resize(10);
	mesh[0] = geom::vec3f(-5, -3, -2);
	mesh[1] = geom::vec3f(5, -3, -2);

	mesh[2] = geom::vec3f(-5, 3, -2);
	mesh[3] = geom::vec3f(5, 3, -2);

	mesh[4] = geom::vec3f(-5, 3, 2);
	mesh[5] = geom::vec3f(5, 3, 2);

	mesh[6] = geom::vec3f(-5, -3, 2);
	mesh[7] = geom::vec3f(5, -3, 2);

	mesh[8] = geom::vec3f(-5, -3, -2);
	mesh[9] = geom::vec3f(5, -3, -2);
}

/*
void barrier::display(){
	primitive::cuboid tmpcub(*this);

	//nie dziala
	for (unsigned short i = 0; i < 8; i++) {
		//vertices[i][0] *= sca[0]; vertices[i][1] *= sca[1]; vertices[i][2] *= sca[2];
	}
	geom::mat3x3f rotmat;

	geom::makeRorationXMatrix(rotmat, rot[0]);
	tmpcub.applyMatrix(rotmat);
	geom::makeRorationYMatrix(rotmat, rot[1]);
	tmpcub.applyMatrix(rotmat);

	geom::makeRorationZMatrix(rotmat, rot[2]);
	tmpcub.applyMatrix(rotmat);

	tmpcub.translate(pos);

	std::fstream plik;
	plik.open(filename, std::ios::out | std::ios::trunc);
	//plik << (*this) << std::endl;
	plik << tmpcub << std::endl;

	plik.close();

	//geom::vec3f tempvec = geom::vec3f() - pos;
	//translate(tempvec);

}
*/
void barrier::setPos(geom::vec3f newPos){
	pos = newPos;
}
