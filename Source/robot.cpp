#define _USE_MATH_DEFINES
#include <cmath>
#include "../Headers/robot.hh"

static int numofrobots = 0;

robot::robot(): ID(numofrobots++){
	displayableObject();
	//for (;;);
	//myPath.addPoint(pos);

	mesh.resize(20);
	mesh[0] = geom::vec3f(-5, -3, -2);
	mesh[1] = geom::vec3f(0, -3, -2);

	mesh[2] = geom::vec3f(-5, 3, -2);
	mesh[3] = geom::vec3f(0, 3, -2);

	mesh[4] = geom::vec3f(-5, 3, 2);
	mesh[5] = geom::vec3f(0, 3, 2);

	mesh[6] = geom::vec3f(-5, -3, 2);
	mesh[7] = geom::vec3f(0, -3, 2);

	mesh[8] = geom::vec3f(-5, -3, -2);
	mesh[9] = geom::vec3f(0, -3, -2);

	//nosek
	mesh[10] = geom::vec3f(0, -3, -2);
	mesh[11] = geom::vec3f(5, 0, 0);

	mesh[12] = geom::vec3f(0, 3, -2);
	mesh[13] = geom::vec3f(5, 0, 0);

	mesh[14] = geom::vec3f(0, 3, 2);
	mesh[15] = geom::vec3f(5, 0, 0);

	mesh[16] = geom::vec3f(0, -3, 2);
	mesh[17] = geom::vec3f(5, 0, 0);

	mesh[18] = geom::vec3f(0, -3, -2);
	mesh[19] = geom::vec3f(5, 0, 0);


	velocity = 10;
	numofsteps = 1;
	front = geom::vec3f(1, 0, 0);
	drawconfig = "vv ";

	filename = "Scene_txt/Robot";
	filename += std::to_string(ID);
	filename += ".txt";
	//std::cout << filename << std::endl;

}

float & robot::getvelocity(){
	return velocity;
}

geom::vec3f & robot::getfront(){
	return front;
}

unsigned int & robot::getnumofsteps(){
	return numofsteps;
}

path & robot::getPath(){
	return myPath;
}

void robot::performStep(){
	front = geom::vec3f(1, 0, 0);
	geom::rotateVec(front, rot);

	geom::vec3f step = velocity / numofsteps * front;
	for (unsigned int i = 0; i < numofsteps; i++) {
		front.normalize();
		pos = pos + step;
	}
	myPath.addPoint(pos);

	//std::cout << front << std::endl << rotmat << std::endl;
}
