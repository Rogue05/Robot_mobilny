#include "../Headers/Matrix3x3f.hh"

geom::mat3x3f::mat3x3f(){
	a[0][0] = 1; a[0][1] = a[0][2] = 0;
	a[1][0] = 0; a[1][1] = 1; a[1][2] = 0;
	a[2][0] = a[2][1] = 0; a[2][2] = 1;
}

geom::mat3x3f::mat3x3f(mat3x3f & argmat){
	a[0][0] = argmat[0][0];
	a[0][1] = argmat[0][1];
	a[0][2] = argmat[0][2];

	a[1][0] = argmat[1][0];
	a[1][1] = argmat[1][1];
	a[1][2] = argmat[1][2];

	a[2][0] = argmat[2][0];
	a[2][1] = argmat[2][1];
	a[2][2] = argmat[2][2];
}

geom::mat3x3f::mat3x3f(vec3f arg1vec, vec3f arg2vec, vec3f arg3vec){
	a[0][0] = arg1vec[0];
	a[0][1] = arg1vec[1];
	a[0][2] = arg1vec[2];

	a[1][0] = arg2vec[0];
	a[1][1] = arg2vec[1];
	a[1][2] = arg2vec[2];

	a[2][0] = arg3vec[0];
	a[2][1] = arg3vec[1];
	a[2][2] = arg3vec[2];
}

geom::mat3x3f::mat3x3f(float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9){
	a[0][0] = arg1;
	a[0][1] = arg2;
	a[0][2] = arg3;

	a[1][0] = arg4;
	a[1][1] = arg5;
	a[1][2] = arg6;

	a[2][0] = arg7;
	a[2][1] = arg8;
	a[2][2] = arg9;
}

float * geom::mat3x3f::operator[](unsigned int index){
	return a[index];
}

geom::vec3f geom::mat3x3f::operator*(vec3f argvec){
	return vec3f(argvec[0] * a[0][0] + argvec[1] * a[0][1] + argvec[2] * a[0][2],
		argvec[0] * a[1][0] + argvec[1] * a[1][1] + argvec[2] * a[1][2], 
		argvec[0] * a[2][0] + argvec[1] * a[2][1] + argvec[2] * a[2][2]);
}

geom::mat3x3f geom::mat3x3f::operator*(mat3x3f argmat){
	mat3x3f tmpmat(0,0,0,0,0,0,0,0,0);
	for (short i = 0; i < 3; i++)
		for (short j = 0; j < 3; j++)
			for (short k = 0; k < 3; k++)
				tmpmat[i][j] += (a[i][k] * argmat[k][j]);
	return tmpmat;
}

std::ostream & geom::operator<<(std::ostream & output, mat3x3f argmat){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			output << argmat[i][j] << " ";
		std::cout << "\n";
	}
	return output;
}

void geom::makeRorationXMatrix(mat3x3f & argmat, float angleX){
	argmat = mat3x3f(1, 0, 0, 
		0, cos(angleX), -sin(angleX),
		0, sin(angleX), cos(angleX));
}

void geom::makeRorationYMatrix(mat3x3f & argmat, float angleY){
	argmat = mat3x3f(cos(angleY), 0, sin(angleY),
		0, 1, 0,
		-sin(angleY), 0, cos(angleY));
}

void geom::makeRorationZMatrix(mat3x3f & argmat, float angleZ){
	argmat = mat3x3f(cos(angleZ), sin(angleZ), 0,
		-sin(angleZ), cos(angleZ), 0,
		0, 0, 1);
}

void geom::rotateVec(vec3f & argvec, vec3f rotvec){
	double pi = 3.14159265;
	geom::mat3x3f rotmat;
	geom::makeRorationXMatrix(rotmat, rotvec[0] * pi / 180);
	argvec = rotmat*argvec;
	geom::makeRorationYMatrix(rotmat, rotvec[1] * pi / 180);
	argvec = rotmat*argvec;
	geom::makeRorationZMatrix(rotmat, rotvec[2] * pi / 180);
	argvec = rotmat*argvec;
}
