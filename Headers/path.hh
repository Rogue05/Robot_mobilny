#ifndef PATH_HH_
#define PATH_HH_

#include <ostream>
#include <vector>
#include <fstream>

#include "Vector3f.hh"
#include "displayableObject.hh"

/*!
 * \file path.hh
 * \brief Plik zawiera definicjê klasy path opisuj¹cej œcierzkê
 */

/*!
* \brief Klasa definiuj¹ca œcierzkê
*/
class path
	:public displayableObject{
private:
	/*!
	* \brief Wktor przechowywuj¹cy kolejne punkty œcierzki
	*/
	std::vector<geom::vec3f> my_path;
public:
	/*!
	 * \brief Domyœlny konstruktor, nic nie robi
	 *
	 */
	path();
	
	/*!
	 * \brief Konstruktor kopiuj¹cy, tworzy kopiê œcierzki
	 * \param &sourcepath kopiowana œcierzka
	 */
	path(path & sourcepath);

	/*!
	* \brief Dodaje punkt do œcierzki
	* \param newPoint - punkt dodawany do œcierzki
	*/
	void addPoint(geom::vec3f newPoint);

	/*!
	* \brief Funkcja do komunikcji z wektorem
	* \return Punkty tworz¹ce œcierzkê
	*/
	std::vector<geom::vec3f> & getPath();

	/*!
	* \brief ID œcierzki
	*/
	const unsigned int ID;

	//friend std::ostream & operator<<(std::ostream & output, path argpath);

};

/*!
 * \brief Przeci¹rzenie operatora << w celu wypisywania œcierzki
 * \param &output - strumieñ na który zostanie wrzucona œcierzka
 * \param argpath - wrzucana œcierzka
 * \return strumieñ z wrzucon¹ œcierzk¹
 */
//std::ostream & operator<<(std::ostream & output, path argpath);

#endif // !PATH_HH_
