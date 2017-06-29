#ifndef BARRIER_HH_
#define BARRIER_HH_

#include "Vector3f.hh"
#include "displayableObject.hh"

/*!
* \file barrier.hh
* \brief Plik zawiera definicjê klasy opisuj¹cej przeszkodê
*/

/*!
* \brief Klasa definiuj¹ca przeszkodê
*/
class barrier
	:public displayableObject {
public:

	/*!
	* \brief Domyœlny kostruktor
	* Domyœlny kostruktor
	*
	*/
	barrier();

	 /*!
	 * \brief ID przeszkody
	 */
	const unsigned int ID;
	
	/*!
	* \brief Ustawia now¹ pozycjê obiektu
	* \param newPos wektor wskazuj¹cy now¹ pozycjê
	*/
	void setPos(geom::vec3f newPos);
};


#endif // !BARRIER_HH_