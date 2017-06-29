#ifndef DISPLAYABLEOBJECT_HH_
#define DISPLAYABLEOBJECT_HH_

#include <string>

#include "Vector3f.hh"
#include "Matrix3x3f.hh"
#include "setofvertices.hh"

/*!
* \file displayableObject.hh
* \brief Plik zawiera definicjê klasy opisuj¹cej obiekt graficzny
*/

/*!
* \brief Klasa definiuj¹ca obiekt graficzny
*/
class displayableObject {
protected:
	setofvertices mesh;
	std::string drawconfig;
	std::string filename;

public:

	/*!
	* \brief Zwraca nazwê pliku obiektu
	* \return string z nazw¹ pliku
	*/
	std::string getfilename();

	/*!
	* \brief Wektor opisuj¹cy pozycjê
	*
	*/
	geom::vec3f pos;
	
	/*!
	* \brief Wektor opisuj¹cy rotacjê
	*
	*/
	geom::vec3f rot;
	
	/*!
	* \brief Wektor opisuj¹cy skalê
	*
	*/
	geom::vec3f sca;
	
	/*!
	* \brief Domyœlny kostruktor
	* Domyœlny kostruktor
	*
	*/
	displayableObject();
	
	/*!
	* \brief Wyœwietla obiekt
	* Wyœwietla obiekt
	* 
	*/
	void display();

	/*!
	* \brief Dokonuje translacji wszystkich obiektów
	* \param &argvec wwektor wektorów do translacji
	* \param transvec wektor translacji
	*/
	static void translate(std::vector<displayableObject> &argvec, geom::vec3f transvec);

	/*!
	* \brief Test kolizji arvec z prostopad³oœcianem
	* \param &argobj postopad³oœcian
	* \param punkt
	* \return true je¿eli nast¹pi³a kolizja
	* \return false je¿eli nie
	*/
	static bool boxcol(displayableObject &argobj, geom::vec3f argvec);

	/*!
	* \brief Test kolizji prostopad³osciany z dowolnym obiektem graficznym
	* \param &argobj prostopad³oœcian
	* \param dowolny obiekt graficzny
	* \return true je¿eli nast¹pi³a kolizja
	* \return false je¿eli nie
	*/
	static bool boxcol(displayableObject &argobj, displayableObject obj);

};

#endif // !DISPLAYABLEOBJECT_HH_
