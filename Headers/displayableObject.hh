#ifndef DISPLAYABLEOBJECT_HH_
#define DISPLAYABLEOBJECT_HH_

#include <string>

#include "Vector3f.hh"
#include "Matrix3x3f.hh"
#include "setofvertices.hh"

/*!
* \file displayableObject.hh
* \brief Plik zawiera definicj� klasy opisuj�cej obiekt graficzny
*/

/*!
* \brief Klasa definiuj�ca obiekt graficzny
*/
class displayableObject {
protected:
	setofvertices mesh;
	std::string drawconfig;
	std::string filename;

public:

	/*!
	* \brief Zwraca nazw� pliku obiektu
	* \return string z nazw� pliku
	*/
	std::string getfilename();

	/*!
	* \brief Wektor opisuj�cy pozycj�
	*
	*/
	geom::vec3f pos;
	
	/*!
	* \brief Wektor opisuj�cy rotacj�
	*
	*/
	geom::vec3f rot;
	
	/*!
	* \brief Wektor opisuj�cy skal�
	*
	*/
	geom::vec3f sca;
	
	/*!
	* \brief Domy�lny kostruktor
	* Domy�lny kostruktor
	*
	*/
	displayableObject();
	
	/*!
	* \brief Wy�wietla obiekt
	* Wy�wietla obiekt
	* 
	*/
	void display();

	/*!
	* \brief Dokonuje translacji wszystkich obiekt�w
	* \param &argvec wwektor wektor�w do translacji
	* \param transvec wektor translacji
	*/
	static void translate(std::vector<displayableObject> &argvec, geom::vec3f transvec);

	/*!
	* \brief Test kolizji arvec z prostopad�o�cianem
	* \param &argobj postopad�o�cian
	* \param punkt
	* \return true je�eli nast�pi�a kolizja
	* \return false je�eli nie
	*/
	static bool boxcol(displayableObject &argobj, geom::vec3f argvec);

	/*!
	* \brief Test kolizji prostopad�osciany z dowolnym obiektem graficznym
	* \param &argobj prostopad�o�cian
	* \param dowolny obiekt graficzny
	* \return true je�eli nast�pi�a kolizja
	* \return false je�eli nie
	*/
	static bool boxcol(displayableObject &argobj, displayableObject obj);

};

#endif // !DISPLAYABLEOBJECT_HH_
