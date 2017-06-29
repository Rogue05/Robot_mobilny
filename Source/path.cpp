#include "../Headers/path.hh"
#include <string>

static unsigned int numofpaths = 0;

path::path():ID(numofpaths++){
	displayableObject();

	filename = "Scene_txt/Path";
	filename += std::to_string(ID);
	filename += ".txt";
	drawconfig = "v";
	//for (;;);

}

path::path(path & sourcepath):ID(sourcepath.ID){
	filename = sourcepath.filename;
	drawconfig = "v";

	for (unsigned int i = 0; i < sourcepath.my_path.size(); i++) {
		my_path.push_back(sourcepath.my_path[i]);
	}
}

void path::addPoint(geom::vec3f newPoint){
	mesh.push_back(newPoint);
}

std::vector<geom::vec3f>& path::getPath(){
	return mesh;
}

/*
std::ostream & operator<<(std::ostream & output, path argpath){
	output << "\n";
	for (unsigned int i = 0; i < argpath.my_path.size(); i++) {
		output << argpath.my_path[i] << "\n";
	}
	return output << "\n#\n";
}
*/
