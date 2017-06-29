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
 * \brief Plik zawiera definicj� klasy opisuj�cej scen�
 */

/*!
* \brief Klasa definiuj�ca scen�
*/
class scene {
private:
	/*!
	 * \brief ��cze sceny z gnuplotem
	 * ��cze sceny z gnuplotem
	 *
	 */
	PzG::LaczeDoGNUPlota lacze;

public:
	
	/*!
	 * \brief Globalna translacja, przes�wa wszystkie obiekty sceny o transvec
	 * \param &transvec wektor translacji
	 */
	static void translate(geom::vec3f transvec);
	
	/*!
	 * \brief Inicjalizuje scen�
	 * Inicjalizuje scen�
	 *
	 */
	void init();
	
	/*!
	 * \brief Dodaje nowy wska�nik na obiekt do sceny
	 * \param &newObject dodawany obiekt
	 */
	void addDisplayableObject(std::shared_ptr<displayableObject> newObject);

	/*!
	 * \brief Resetuje scen�
	 * Ustawia globaln� translacj� na 0
	 */
	void reset();
	
	/*!
	 * \brief Od�wierza obraz
	 * Od�wierza obraz
	 *
	 */
	void update();
};

#endif // !SCENE_HH_
