CC=g++
OPT=-pedantic -Wall -std=c++11

OBJ=Obj

all: Source.cpp $(OBJ)/lacze.o $(OBJ)/vector3f.o $(OBJ)/matrix3x3f.o $(OBJ)/robot.o $(OBJ)/scene.o $(OBJ)/path.o $(OBJ)/displayableObject.o $(OBJ)/barrier.o $(OBJ)/factory.o
	$(CC) $(OPT) Source.cpp $(OBJ)/lacze.o $(OBJ)/robot.o $(OBJ)/vector3f.o $(OBJ)/matrix3x3f.o $(OBJ)/scene.o $(OBJ)/path.o $(OBJ)/displayableObject.o $(OBJ)/barrier.o $(OBJ)/factory.o -o obrot

allagain: clear all

$(OBJ)/lacze.o: Source/lacze_do_gnuplota.cpp Headers/lacze_do_gnuplota.hh
	$(CC) $(OPT) -c Source/lacze_do_gnuplota.cpp -o $(OBJ)/lacze.o

$(OBJ)/path.o: Source/path.cpp Headers/path.hh
	$(CC) $(OPT) -c Source/path.cpp -o $(OBJ)/path.o

$(OBJ)/factory.o: Source/factory.cpp Headers/factory.hh
	$(CC) $(OPT) -c Source/factory.cpp -o $(OBJ)/factory.o

$(OBJ)/barrier.o: Source/barrier.cpp Headers/barrier.hh
	$(CC) $(OPT) -c Source/barrier.cpp -o $(OBJ)/barrier.o

$(OBJ)/robot.o: Source/robot.cpp Headers/robot.hh
	$(CC) $(OPT) -c Source/robot.cpp -o $(OBJ)/robot.o

$(OBJ)/scene.o: Source/scene.cpp Headers/scene.hh
	$(CC) $(OPT) -c Source/scene.cpp -o $(OBJ)/scene.o

$(OBJ)/vector3f.o: Source/Vector3f.cpp Headers/Vector3f.hh
	$(CC) $(OPT) -c Source/Vector3f.cpp -o $(OBJ)/vector3f.o

$(OBJ)/matrix3x3f.o: Source/Matrix3x3f.cpp Headers/Matrix3x3f.hh
	$(CC) $(OPT) -c Source/Matrix3x3f.cpp -o $(OBJ)/matrix3x3f.o

$(OBJ)/displayableObject.o: Source/displayableObject.cpp Headers/displayableObject.hh
	$(CC) $(OPT) -c Source/displayableObject.cpp -o $(OBJ)/displayableObject.o

clear:
	rm -fr $(OBJ)/*.o