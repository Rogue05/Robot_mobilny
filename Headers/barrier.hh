#ifndef BARRIER_HH_
#define BARRIER_HH_

#include "Vector3f.hh"
#include "displayableObject.hh"

/*!
* \file barrier.hh
* \brief Plik zawiera definicj� klasy opisuj�cej przeszkod�
*/

/*!
* \brief Klasa definiuj�ca przeszkod�
*/
class barrier
	:public displayableObject {
public:

	/*!
	* \brief Domy�lny kostruktor
	* Domy�lny kostruktor
	*
	*/
	barrier();

	 /*!
	 * \brief ID przeszkody
	 */
	const unsigned int ID;
	
	/*!
	* \brief Ustawia now� pozycj� obiektu
	* \param newPos wektor wskazuj�cy now� pozycj�
	*/
	void setPos(geom::vec3f newPos);
};


#endif // !BARRIER_HH_