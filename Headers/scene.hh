#ifndef SCENE_HH_
#define SCENE_HH_

#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Vector3f.hh"
#include "path.hh"
#include "displayableObject.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \file scene.hh
 * \brief Plik zawiera definicjê klasy opisuj¹cej scenê
 */

/*!
* \brief Klasa definiuj¹ca scenê
*/
class scene {
private:
	/*!
	 * \brief £¹cze sceny z gnuplotem
	 * £¹cze sceny z gnuplotem
	 *
	 */
	PzG::LaczeDoGNUPlota lacze;

public:
	
	/*!
	 * \brief Globalna translacja, przesówa wszystkie obiekty sceny o transvec
	 * \param &transvec wektor translacji
	 */
	static void translate(geom::vec3f transvec);
	
	/*!
	 * \brief Inicjalizuje scenê
	 * Inicjalizuje scenê
	 *
	 */
	void init();
	
	/*!
	 * \brief Dodaje nowy wskaŸnik na obiekt do sceny
	 * \param &newObject dodawany obiekt
	 */
	void addDisplayableObject(std::shared_ptr<displayableObject> newObject);

	/*!
	 * \brief Resetuje scenê
	 * Ustawia globaln¹ translacjê na 0
	 */
	void reset();
	
	/*!
	 * \brief Odœwierza obraz
	 * Odœwierza obraz
	 *
	 */
	void update();
};

#endif // !SCENE_HH_
