#pragma once
#ifndef VECTOR3F_HH_
#define VECTOR3F_HH_

#include <iostream>
#include <cmath>

/*!
* \file Vector3f.hh
*
* \brief Plik zawiera definicjê klasy template_vec<type> nale¿¹cej do
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
	* \brief Klasa opsuj¹ca wektor 3D
	*/
	template<class type>
	class template_vec {
	private:
		/*!
		* \brief Tablica wspó³¿êdnych wektora
		* x = a[0], y = a[1], z = a[2]
		*/
		type a[3];

	public:

		/*!
		* \brief Domyœlny konstruktor
		*
		* Tworzy wektor zerowy;
		*/
		template_vec();

		/*!
		* \brief Konstruktor tworz¹cy wektor z zadanych trech wspó³¿êdnych
		* \param arg1 - wartoœæ dla x
		* \param arg2 - wartoœæ dla y
		* \param arg3 - wartoœæ dla z
		*/
		template_vec(type arg1, type arg2, type arg3);

		/*!
		* \brief Metoda zwracaj¹ca d³ugoœæ wektora
		* \return Zwraca d³ugoœæ wektora w zmiennej floar
		*/
		type length() const;

		/*!
		* \brief Metoda normalizyj¹ca wektor
		*/
		void normalize();

		/*!
		* \brief Przeci¹¿enie operatora indeksuj¹cego dla wektora
		*/
		type & operator[](unsigned int index);

		/*!
		* \brief Przeci¹¿enie operatora indeksuj¹cego dla wektora
		*/
		type operator[](unsigned int index) const;

		/*!
		* \brief Przeci¹¿enie operatora + dla wektora
		* \param &argvec - drógi z argumentów dodawania
		* \return Zwraca sumê wektora z wektorem argvec
		*/
		template_vec<type> operator+(template_vec<type> &argvec);

		/*!
		* \brief Przeci¹¿enie operatora - dla wektora
		* \param &argvec - drógi z argumentów odejmowania
		* \return Zwraca ró¿nicê wektora z wektorem argvec
		*/
		template_vec<type> operator-(template_vec<type> &argvec);

		template<class my_type>
		friend template_vec<my_type> operator * (my_type sc, template_vec<my_type> argvec);

		template<class my_type>
		friend std::ostream & operator <<(std::ostream &output, template_vec<my_type> &argvec);

		template<class my_type>
		friend std::istream & operator >> (std::istream &input, template_vec<my_type> &argvec);
	};

	/*!
	* \brief Przeci¹¿enie operatora << dla wektora
	* \param &output - strumieñ na który zostanie wrzucony wektor
	* \param &argvec - wektor wrzucany na strumieñ
	* \return Zwraca strumieñ z wektorem
	*/
	template<class my_type>
	std::ostream & operator <<(std::ostream &output, template_vec<my_type> &argvec);

	/*!
	* \brief Przeci¹¿enie operatora >> dla wektora
	* \param &input - strumieñ z którego zostanie zdjêty wektor
	* \param &argvec - wektor zdejmowany ze strumienia
	* \return Zwraca strumieñ bez wektora
	*/
	template<class my_type>
	std::istream & operator >> (std::istream &input, template_vec<my_type> &argvec);

	/*!
	* \brief Przeci¹¿enie operatora * dla type i wektora
	* \paaram sc - pierwszy z argumentów mno¿enia
	* \param &argvec - drógi z argumentów mno¿enia
	* \return Zwraca iloczyn type z wektorem argvec
	*/
	template<class my_type>
	template_vec<my_type> operator * (my_type sc, template_vec<my_type> argvec);

	typedef template_vec<float> vec3f;

}


template<class type>
geom::template_vec<type>::template_vec() {
	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
}

template<class type>
geom::template_vec<type>::template_vec(type arg1, type arg2, type arg3) {
	a[0] = arg1;
	a[1] = arg2;
	a[2] = arg3;
}

template<class type>
type geom::template_vec<type>::length() const {
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

template<class type>
void geom::template_vec<type>::normalize() {
	type div = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] /= div;
	a[1] /= div;
	a[2] /= div;
}

template<class type>
type & geom::template_vec<type>::operator[](unsigned int index) {
	return a[index];
}

template<class type>
type geom::template_vec<type>::operator[](unsigned int index) const {
	return a[index];
}

template<class type>
geom::template_vec<type> geom::template_vec<type>::operator+(template_vec<type> & argvec) {
	return template_vec<type>(a[0] + argvec[0], a[1] + argvec[1], a[2] + argvec[2]);
}

template<class type>
geom::template_vec<type> geom::template_vec<type>::operator-(template_vec<type> & argvec) {
	return template_vec<type>(a[0] - argvec[0], a[1] - argvec[1], a[2] - argvec[2]);
}

template<class my_type>
std::ostream & geom::operator<<(std::ostream &output, geom::template_vec<my_type> &argvec) {
	return output << argvec.a[0] << " " << argvec.a[1] << " " << argvec.a[2];
}

template<class my_type>
std::istream & geom::operator >> (std::istream &input, geom::template_vec<my_type> &argvec) {
	return input >> argvec.a[0] >> argvec.a[1] >> argvec.a[2];
}

template<class my_type>
geom::template_vec<my_type> geom::operator*(my_type sc, template_vec<my_type> argvec) {
	return template_vec<my_type>(argvec.a[0] * sc, argvec.a[1] * sc, argvec.a[2] * sc);
}

#endif