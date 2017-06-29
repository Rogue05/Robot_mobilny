#include "Headers/robot.hh"
#include "Headers/scene.hh"
#include "Headers/barrier.hh"
#include "Headers/factory.hh"
#include "Headers/objtypes.hh"

#include <iostream>
#include <memory>
#include <vector>

#define MAXNUM 1000
#define NUMOFROBOTS 3
#define NUMOFBARRIERS 6

using namespace std;
using namespace geom;

static bool shouldend = false;
static unsigned int current = 0;
static unsigned int rlast = NUMOFROBOTS;
static unsigned int blast = NUMOFBARRIERS;

void displayMenu();
void initStuff();
void processopt(char opt);

static scene scena;

/*
static robot myarmy[MAXNUM];
static barrier protectors[MAXNUM];
*/

static shared_ptr<robot> myarmy[MAXNUM];
static shared_ptr<barrier> protectors[MAXNUM];

/*
static vector<robot> myarmy;
static vector<barrier> protectors;
*/
int main(){
	
	//shared_ptr<robot> test = (shared_ptr<robot>)factory::get().produce(o_robot);
	/*for (;;) {
		char a = getc(cin);
		cout << a;
	}*/

	initStuff();
	scena.update();
	char opt = 'q';

	displayMenu();
	while (!shouldend) {
		cout << "Twoj wybor (w - wyswietl menu)> ";
		cin >> opt;
		cout << "Aktualnie wyselekcjonowanym robotem jest:" << endl;
		cout << "\tRobot " << current << " wspolzedne: " << myarmy[current]->pos << endl;
		processopt(opt);
		scena.update();
	}

	int t=1; cin >> noskipws >> t;
	return 0;
}

void displayMenu(){
	cout << "R - dodaj robota" << endl;
	cout << "B - dodaj przeszkode" << endl << endl;
	cout << "z - zmiana szybkosci ruchu robota" << endl;
	cout << "o - obrot robota" << endl;
	cout << "j - jazda na wprost" << endl;
	cout << "s - selekcja robota" << endl << endl;

	cout << "t - zadaj translacje rysunku" << endl;
	cout << "p - powrot do pierwotnego ustawienia rysunku" << endl << endl;

	cout << "w - wyswietl ponownie menu" << endl << endl;

	cout << "k - zakoncz dzialanie programu" << endl;
}

void initStuff(){
	scena.init();
	
	for (int i = 0; i < NUMOFROBOTS; i++) {
		myarmy[i] = shared_ptr<robot>(new robot());
		myarmy[i]->getvelocity() = 10;
		myarmy[i]->getnumofsteps() = 1;
		myarmy[i]->pos = vec3f(30 * i - 30, 0, 0);
		myarmy[i]->getPath().addPoint(myarmy[i]->pos);

		scena.addDisplayableObject(myarmy[i]);
		//scena.addDisplayableObject(myarmy[i]->getPath());
	}

	for (int i = 0; i < NUMOFBARRIERS; i++) {
		protectors[i] = shared_ptr<barrier>(new barrier());
		protectors[i]->rot = vec3f(0, 60 * i, 0);
		protectors[i]->pos = vec3f(20 * (i - 3), 20 * (i - 3), 20 * (i - 3) - 30);

		scena.addDisplayableObject(protectors[i]);
	}

}

void processopt(char opt){
	switch (opt) {
	case 'R': {
		unsigned int i = rlast++;
		
		//myarmy[i] = shared_ptr<robot>(new robot());
		myarmy[i] = static_pointer_cast<robot>(factory::get().produce(o_robot));
		scena.addDisplayableObject(myarmy[i]);
		//scena.addDisplayableObject(myarmy[i]->getPath());

		//myarmy[i] = *(robot*)factory::get().produce(o_robot);

		myarmy[i]->getvelocity() = 10;
		myarmy[i]->getnumofsteps() = 1;
		myarmy[i]->getPath().addPoint(myarmy[i]->pos);

		cout << "Podaj pozycje startowa > ";
		cin >> myarmy[i]->pos;
	} break;
	case 'B': {
		unsigned int i = blast++;

		//protectors[i] = shared_ptr<barrier>(new barrier());
		protectors[i] = static_pointer_cast<barrier>(factory::get().produce(o_barrier));
		scena.addDisplayableObject(protectors[i]);

		cout << "Podaj pozycje startowa > ";
		cin >> protectors[i]->pos;
	}break;
	case 'z': {
		float newveloc = 0;
		cout << "Podaj wartosc predkosci > ";
		cin >> newveloc;
		myarmy[current]->getvelocity() = newveloc;
	}
		break;
	case 'o': {
		vec3f newrot;
		cout << "Podaj katy rotacji X Y Z > ";
		cin >> newrot;
		myarmy[current]->rot = myarmy[current]->rot + newrot;
	}
		break;
	case 'j': {//mniej optymalnie sie chyba nie da
		bool isproblem = false;
		myarmy[current]->performStep();
		for (int i = 0; i < NUMOFBARRIERS; i++) if (displayableObject::boxcol(*protectors[i], *myarmy[current])) isproblem = true;
		for (unsigned int i = 0; i < NUMOFROBOTS; i++) if (displayableObject::boxcol(*myarmy[i], *myarmy[current]) && i != current) isproblem = true;
		if (isproblem) {
			cout << "!!! Ruch nie moze byc kontynuowany ze wzgledu\n!!!na wystapienie kolizji." << endl;
			myarmy[current]->getvelocity() *= -1;
			myarmy[current]->performStep();
			myarmy[current]->getvelocity() *= -1;
		}
	}
		break;
	case 's': {
		cout << "0 - zaniechaj zmiany selekcji" << endl;
		for (unsigned int i = 0; i < rlast; i++) cout << "Robot " << i << " wspolzedne: " << myarmy[i]->pos << endl;
		cout << "Wprowadz numer robota lub 0 > ";
		cin >> current;
		if (current >= rlast) {
			cout << "Nie ma takiego robota" << endl;
			current = 0;
		}
	}
		break;
	case 't': {
		vec3f tmpvec;
		cout << "Podaj wektor translacji > ";
		cin >> tmpvec;
		scene::translate(tmpvec);
	}
		break;
	case 'p': scena.reset(); break;
	case 'w': displayMenu(); break;
	case 'k': shouldend = true; break;
	}
}

