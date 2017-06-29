#ifndef PATH_HH_
#define PATH_HH_

#include <ostream>
#include <vector>
#include <fstream>

#include "Vector3f.hh"
#include "displayableObject.hh"

/*!
 * \file path.hh
 * \brief Plik zawiera definicj� klasy path opisuj�cej �cierzk�
 */

/*!
* \brief Klasa definiuj�ca �cierzk�
*/
class path
	:public displayableObject{
private:
	/*!
	* \brief Wktor przechowywuj�cy kolejne punkty �cierzki
	*/
	std::vector<geom::vec3f> my_path;
public:
	/*!
	 * \brief Domy�lny konstruktor, nic nie robi
	 *
	 */
	path();
	
	/*!
	 * \brief Konstruktor kopiuj�cy, tworzy kopi� �cierzki
	 * \param &sourcepath kopiowana �cierzka
	 */
	path(path & sourcepath);

	/*!
	* \brief Dodaje punkt do �cierzki
	* \param newPoint - punkt dodawany do �cierzki
	*/
	void addPoint(geom::vec3f newPoint);

	/*!
	* \brief Funkcja do komunikcji z wektorem
	* \return Punkty tworz�ce �cierzk�
	*/
	std::vector<geom::vec3f> & getPath();

	/*!
	* \brief ID �cierzki
	*/
	const unsigned int ID;

	//friend std::ostream & operator<<(std::ostream & output, path argpath);

};

/*!
 * \brief Przeci�rzenie operatora << w celu wypisywania �cierzki
 * \param &output - strumie� na kt�ry zostanie wrzucona �cierzka
 * \param argpath - wrzucana �cierzka
 * \return strumie� z wrzucon� �cierzk�
 */
//std::ostream & operator<<(std::ostream & output, path argpath);

#endif // !PATH_HH_
