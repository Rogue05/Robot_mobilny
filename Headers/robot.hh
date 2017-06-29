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
 * \brief Plik zawiera definicjê klasy robot
 */

/*!
* \brief Klasa definiuj¹ca robota
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
	* \brief Domyœlny konstruktor, wykonuje konstruktory duboid i displayableObject
	* ustawia velocity na 10, numofsteps na 1 i front na (1, 0, 0)
	*/
	robot();

	/*!
	* \brief ID robota
	*
	*/
	const unsigned int ID;
	
	/*!
	* \brief Wartoœæ prêdkoœci
	* \return Zwraca przez referencjê prêdkoœæ robota
	*/
	float& getvelocity();
	
	/*!
	* \brief Wektor wspazuj¹cy przód robota
	* \return Zwraca przez referencjê front robota
	*/
	geom::vec3f & getfront();
	
	/*!
	* \brief Liczba kroków poœrednich
	* \return Zwraca przez referencjê liczbê kroków robota
	*/
	unsigned int & getnumofsteps();
	
	/*!
	* \brief Zwraca œcierzkê robota
	* \return Zwraca przez referencjê œcierzkê robota
	*/
	path& getPath();
	
	/*!
	* \brief wykonuje krok d³ugoœci velocity
	*/
	void performStep();
	
};

#endif // !ROBOT_HH_
