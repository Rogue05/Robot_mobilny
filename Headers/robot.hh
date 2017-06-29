#ifndef ROBOT_HH_
#define ROBOT_HH_

#include <fstream>
#include <memory>

#include "Vector3f.hh"
#include "path.hh"
#include "displayableObject.hh"
#include "setofvertices.hh"

/*!
 * \file robot.hh
 * \brief Plik zawiera definicj� klasy robot
 */

/*!
* \brief Klasa definiuj�ca robota
*/
class robot
	: public displayableObject {
private:
	path myPath;
	unsigned int numofsteps;
	float velocity;
	geom::vec3f front;

public:
	/*!
	* \brief Domy�lny konstruktor, wykonuje konstruktory duboid i displayableObject
	* ustawia velocity na 10, numofsteps na 1 i front na (1, 0, 0)
	*/
	robot();

	/*!
	* \brief ID robota
	*
	*/
	const unsigned int ID;
	
	/*!
	* \brief Warto�� pr�dko�ci
	* \return Zwraca przez referencj� pr�dko�� robota
	*/
	float& getvelocity();
	
	/*!
	* \brief Wektor wspazuj�cy prz�d robota
	* \return Zwraca przez referencj� front robota
	*/
	geom::vec3f & getfront();
	
	/*!
	* \brief Liczba krok�w po�rednich
	* \return Zwraca przez referencj� liczb� krok�w robota
	*/
	unsigned int & getnumofsteps();
	
	/*!
	* \brief Zwraca �cierzk� robota
	* \return Zwraca przez referencj� �cierzk� robota
	*/
	path& getPath();
	
	/*!
	* \brief wykonuje krok d�ugo�ci velocity
	*/
	void performStep();
	
};

#endif // !ROBOT_HH_
