#include "../Headers/displayableObject.hh"

#include <fstream>

std::string displayableObject::getfilename(){
	return filename;
}

displayableObject::displayableObject(){
	pos = geom::vec3f(0, 0, 0);
	rot = geom::vec3f(0, 0, 0);
	sca = geom::vec3f(1, 1, 1);
	filename = "default.txt";
}

void displayableObject::display(){
	if (drawconfig.size() == 0) return;
	int dsize = drawconfig.size();
	char opt;
	geom::vec3f tmpvec;

	std::fstream plik;
	plik.open(filename.c_str(), std::ios::out | std::ios::trunc);

	for (unsigned int i = 0, j = 0; i < mesh.size(); i++, j++) {
		opt = drawconfig[j % dsize];
		while (opt == ' ') { plik << std::endl; j++; opt = drawconfig[j % dsize]; }
		tmpvec = geom::vec3f(mesh[i][0] * sca[0], mesh[i][1] * sca[1], mesh[i][2] * sca[2]);
		geom::rotateVec(tmpvec, rot);
		tmpvec = tmpvec + pos;
		plik << tmpvec << std::endl;
	}

	plik << '#';
	plik.close();
}

void displayableObject::translate(std::vector<displayableObject>& argvec, geom::vec3f transvec){
	for (unsigned int i = 0; i < argvec.size(); i++) argvec[i].pos = argvec[i].pos + transvec;
}

bool displayableObject::boxcol(displayableObject & argobj, geom::vec3f argvec){
	float sizex = 5, sizey = 3, sizez = 2;
	//std::cout << "Pre      " << argvec << "   " << argobj.pos << std::endl;

	argvec = argvec - argobj.pos;
	geom::rotateVec(argvec, geom::vec3f(0, 0, 0) - argobj.rot);

	//std::cout << "Post     " << argvec << std::endl;

	if (argvec[0] * argvec[0] >= sizex * sizex) return false;
	if (argvec[1] * argvec[1] >= sizex * sizey) return false;
	if (argvec[2] * argvec[2] >= sizex * sizez) return false;
	return true;
}

bool displayableObject::boxcol(displayableObject & argobj, displayableObject obj){
	
	for (unsigned int i = 0; i < obj.mesh.size(); i++)if (boxcol(argobj, obj.mesh[i] + obj.pos)) return true;
	return false;
}
