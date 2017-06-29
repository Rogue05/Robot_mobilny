#ifndef MATRIX3X3F_HH_
#define MATRIX3X3F_HH_

#include <cmath>

#include "Vector3f.hh"

/*!
* \file Matrix3x3f.hh
*
* \brief Plik zawiera definicj� klasy mat3x3f nale��cej do
* przestrzeni nazw geom opisuj�cej geometri�.
*/

/*!
* \brief
*
* Niniejsza przestrze� nazw stanowi modu� logiczny zawieraj�cy
* narz�dzia umo�liwiaj�ce ko�ystanie z geometrii 3D.
*/

namespace geom {

	/*!
	 * \brief Klasa definiuj�ca Macierz 3x3
	 */
	class mat3x3f {
	private:
		float a[3][3];

	public:
		/*!
		 * \brief Domy�lny konstruktor
		 * Tworzy macierz jednostkow�
		 */
		mat3x3f();

		/*!
		 * \brief Konstruktor kopiuj�cy
		 * Tworzy kopi� macierzy
		 * \param &argmat - macierz na podstawie kt�rej powstanie kopia
		 */
		mat3x3f(mat3x3f &argmat);

		/*!
		 * \brief Konstruktor tworz�cy macierz z trzech wektor�w
		 * \param arg1vec - wektor na podstawie kt�rego powstanie pierwszy rz�d macierzy
		 * \param arg2vec - wektor na podstawie kt�rego powstanie dr�gi rz�d macierzy
		 * \param arg3vec - wektor na podstawie kt�rego powstanie trzeci rz�d macierzy
		 */
		mat3x3f(vec3f arg1vec, vec3f arg2vec, vec3f arg3vec);

		/*!
		 * \brief Konstruktor tworz�cy macierz z podanych liczb
		 * \param arg1 \param arg2 \param arg3 - konfuguracja podanych zmiennych w macierzy
		 * \param arg4 \param arg5 \param arg6
		 * \param arg7 \param arg8 \param arg9
		 */
		mat3x3f(float arg1, float arg2, float arg3,	float arg4, float arg5, float arg6,	float arg7, float arg8, float arg9);

		/*!
		 * \brief Przeci��enie operatora indeksuj�cego
		 * \return Zwraca wska�nik na dany rz�d macierzy
		 */
		float * operator[](unsigned int index);

		/*!
		* \brief Przeci��enie operatora * dla macierzy i wektora
		* \param argvec - wektor przemna�any przez macierz
		* \return Wynik przemno�enia macierzy przez wektor
		*/
		vec3f operator*(vec3f argvec);
		
		/*!
		* \brief Przeci��enie operatora * dla dw�ch macierzy
		* \param argmat - macierz przemna�ana przez macierz
		* \return Wynik przemno�enia macierzy przez macierz argmat
		*/
		mat3x3f operator*(mat3x3f argmat);
		
	};

	/*!
	* \brief Przeci��enie operatora << dla macierzy
	* \param &output - strumie� na kt�ry zostanie wrzucona macierz
	* \param &argmat - macierz wrzucana na strumie�
	* \return Zwraca strumie� z macierz�
	*/
	std::ostream & operator<<(std::ostream &output, mat3x3f argmat);

	/*!
	* \brief Funkcja tworz�ca macierz rotacji wok� osi X
	* \param &argmat - przekszta�cana macierz
	* \param angleX - k�t obrotu w radianach
	*/
	void makeRorationXMatrix(mat3x3f &argmat, float angleX);
	
	/*!
	* \brief Funkcja tworz�ca macierz rotacji wok� osi Y
	* \param &argmat - przekszta�cana macierz
	* \param angleY - k�t obrotu w radianach
	*/
	void makeRorationYMatrix(mat3x3f &argmat, float angleY);
	
	/*!
	* \brief Funkcja tworz�ca macierz rotacji wok� osi Z
	* \param &argmat - przekszta�cana macierz
	* \param angleZ - k�t obrotu w radianach
	*/
	void makeRorationZMatrix(mat3x3f &argmat, float angleZ);

	/*!
	* \brief Obraca wektor argvec o konty zadane przez wektor rotvec
	* \param &argvec obracany wektor
	* \param rotvec wektor zawieraj�cy konty obrotu X Y Z
	*/
	void rotateVec(vec3f &argvec, vec3f rotvec);

}

#endif // !MATRIX3X3F_HH_
