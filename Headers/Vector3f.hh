#pragma once
#ifndef VECTOR3F_HH_
#define VECTOR3F_HH_

#include <iostream>
#include <cmath>

/*!
* \file Vector3f.hh
*
* \brief Plik zawiera definicj� klasy template_vec<type> nale��cej do
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
	* \brief Klasa opsuj�ca wektor 3D
	*/
	template<class type>
	class template_vec {
	private:
		/*!
		* \brief Tablica wsp��dnych wektora
		* x = a[0], y = a[1], z = a[2]
		*/
		type a[3];

	public:

		/*!
		* \brief Domy�lny konstruktor
		*
		* Tworzy wektor zerowy;
		*/
		template_vec();

		/*!
		* \brief Konstruktor tworz�cy wektor z zadanych trech wsp��dnych
		* \param arg1 - warto�� dla x
		* \param arg2 - warto�� dla y
		* \param arg3 - warto�� dla z
		*/
		template_vec(type arg1, type arg2, type arg3);

		/*!
		* \brief Metoda zwracaj�ca d�ugo�� wektora
		* \return Zwraca d�ugo�� wektora w zmiennej floar
		*/
		type length() const;

		/*!
		* \brief Metoda normalizyj�ca wektor
		*/
		void normalize();

		/*!
		* \brief Przeci��enie operatora indeksuj�cego dla wektora
		*/
		type & operator[](unsigned int index);

		/*!
		* \brief Przeci��enie operatora indeksuj�cego dla wektora
		*/
		type operator[](unsigned int index) const;

		/*!
		* \brief Przeci��enie operatora + dla wektora
		* \param &argvec - dr�gi z argument�w dodawania
		* \return Zwraca sum� wektora z wektorem argvec
		*/
		template_vec<type> operator+(template_vec<type> &argvec);

		/*!
		* \brief Przeci��enie operatora - dla wektora
		* \param &argvec - dr�gi z argument�w odejmowania
		* \return Zwraca r�nic� wektora z wektorem argvec
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
	* \brief Przeci��enie operatora << dla wektora
	* \param &output - strumie� na kt�ry zostanie wrzucony wektor
	* \param &argvec - wektor wrzucany na strumie�
	* \return Zwraca strumie� z wektorem
	*/
	template<class my_type>
	std::ostream & operator <<(std::ostream &output, template_vec<my_type> &argvec);

	/*!
	* \brief Przeci��enie operatora >> dla wektora
	* \param &input - strumie� z kt�rego zostanie zdj�ty wektor
	* \param &argvec - wektor zdejmowany ze strumienia
	* \return Zwraca strumie� bez wektora
	*/
	template<class my_type>
	std::istream & operator >> (std::istream &input, template_vec<my_type> &argvec);

	/*!
	* \brief Przeci��enie operatora * dla type i wektora
	* \paaram sc - pierwszy z argument�w mno�enia
	* \param &argvec - dr�gi z argument�w mno�enia
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