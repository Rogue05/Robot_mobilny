#include "../Headers/Vector3f.hh"

geom::vec3f::vec3f(){
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
}

geom::vec3f::vec3f(float arg1, float arg2, float arg3){
	a[0] = arg1;
	a[1] = arg2;
	a[2] = arg3;
}

float geom::vec3f::length() const{
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

void geom::vec3f::normalize(){
	float div = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] /= div;
	a[1] /= div;
	a[2] /= div;
}

float & geom::vec3f::operator[](unsigned int index){
	return a[index];
}

float geom::vec3f::operator[](unsigned int index) const{
	return a[index];
}

geom::vec3f geom::vec3f::operator+(vec3f & argvec) {
	return vec3f(a[0] + argvec[0], a[1] + argvec[1], a[2] + argvec[2]);
}

geom::vec3f geom::vec3f::operator-(vec3f & argvec) {
	return vec3f(a[0] - argvec[0], a[1] - argvec[1], a[2] - argvec[2]);
}

std::ostream & geom::operator<<(std::ostream &output, geom::vec3f &argvec){
	return output << argvec.a[0] << " " << argvec.a[1] << " " << argvec.a[2];
}

std::istream & geom::operator >> (std::istream &input, geom::vec3f &argvec){
	return input >> argvec.a[0] >> argvec.a[1] >> argvec.a[2];
}

geom::vec3f geom::operator*(float sc, vec3f argvec){
	return vec3f(argvec.a[0] * sc, argvec.a[1] * sc, argvec.a[2] * sc);
}
