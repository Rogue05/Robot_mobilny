#ifndef MATRIX3X3F_HH_
#define MATRIX3X3F_HH_

#include <cmath>

#include "Vector3f.hh"

/*!
* \file Matrix3x3f.hh
*
* \brief Plik zawiera definicjê klasy mat3x3f nale¿¹cej do
* przestrzeni nazw geom opisuj¹cej geometriê.
*/

/*!
* \brief
*
* Niniejsza przestrzeñ nazw stanowi modu³ logiczny zawieraj¹cy
* narzêdzia umo¿liwiaj¹ce ko¿ystanie z geometrii 3D.
*/

namespace geom {

	/*!
	 * \brief Klasa definiuj¹ca Macierz 3x3
	 */
	class mat3x3f {
	private:
		float a[3][3];

	public:
		/*!
		 * \brief Domyœlny konstruktor
		 * Tworzy macierz jednostkow¹
		 */
		mat3x3f();

		/*!
		 * \brief Konstruktor kopiuj¹cy
		 * Tworzy kopiê macierzy
		 * \param &argmat - macierz na podstawie której powstanie kopia
		 */
		mat3x3f(mat3x3f &argmat);

		/*!
		 * \brief Konstruktor tworz¹cy macierz z trzech wektorów
		 * \param arg1vec - wektor na podstawie którego powstanie pierwszy rz¹d macierzy
		 * \param arg2vec - wektor na podstawie którego powstanie drógi rz¹d macierzy
		 * \param arg3vec - wektor na podstawie którego powstanie trzeci rz¹d macierzy
		 */
		mat3x3f(vec3f arg1vec, vec3f arg2vec, vec3f arg3vec);

		/*!
		 * \brief Konstruktor tworz¹cy macierz z podanych liczb
		 * \param arg1 \param arg2 \param arg3 - konfuguracja podanych zmiennych w macierzy
		 * \param arg4 \param arg5 \param arg6
		 * \param arg7 \param arg8 \param arg9
		 */
		mat3x3f(float arg1, float arg2, float arg3,	float arg4, float arg5, float arg6,	float arg7, float arg8, float arg9);

		/*!
		 * \brief Przeci¹¿enie operatora indeksuj¹cego
		 * \return Zwraca wska¿nik na dany rz¹d macierzy
		 */
		float * operator[](unsigned int index);

		/*!
		* \brief Przeci¹¿enie operatora * dla macierzy i wektora
		* \param argvec - wektor przemna¿any przez macierz
		* \return Wynik przemno¿enia macierzy przez wektor
		*/
		vec3f operator*(vec3f argvec);
		
		/*!
		* \brief Przeci¹¿enie operatora * dla dwóch macierzy
		* \param argmat - macierz przemna¿ana przez macierz
		* \return Wynik przemno¿enia macierzy przez macierz argmat
		*/
		mat3x3f operator*(mat3x3f argmat);
		
	};

	/*!
	* \brief Przeci¹¿enie operatora << dla macierzy
	* \param &output - strumieñ na który zostanie wrzucona macierz
	* \param &argmat - macierz wrzucana na strumieñ
	* \return Zwraca strumieñ z macierz¹
	*/
	std::ostream & operator<<(std::ostream &output, mat3x3f argmat);

	/*!
	* \brief Funkcja tworz¹ca macierz rotacji wokó³ osi X
	* \param &argmat - przekszta³cana macierz
	* \param angleX - k¹t obrotu w radianach
	*/
	void makeRorationXMatrix(mat3x3f &argmat, float angleX);
	
	/*!
	* \brief Funkcja tworz¹ca macierz rotacji wokó³ osi Y
	* \param &argmat - przekszta³cana macierz
	* \param angleY - k¹t obrotu w radianach
	*/
	void makeRorationYMatrix(mat3x3f &argmat, float angleY);
	
	/*!
	* \brief Funkcja tworz¹ca macierz rotacji wokó³ osi Z
	* \param &argmat - przekszta³cana macierz
	* \param angleZ - k¹t obrotu w radianach
	*/
	void makeRorationZMatrix(mat3x3f &argmat, float angleZ);

	/*!
	* \brief Obraca wektor argvec o konty zadane przez wektor rotvec
	* \param &argvec obracany wektor
	* \param rotvec wektor zawieraj¹cy konty obrotu X Y Z
	*/
	void rotateVec(vec3f &argvec, vec3f rotvec);

}

#endif // !MATRIX3X3F_HH_
