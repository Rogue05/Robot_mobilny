#ifndef FACTORY_HH_
#define FACTORY_HH_

#include <memory>

#include "objtypes.hh"
#include "robot.hh"
#include "barrier.hh"
#include "path.hh"
#include "displayableObject.hh"

/*!
* \file factory.hh
* \brief Zawiera opis klasy fabric
*/

/*!
* \brief Obiekt opisuj¹cy fabrykê
*/
class factory {
private:
	/*!
	* \brief Prywarny konstruktor zapobiega samodzielnemu tworzeniu obiektow
	*/
	factory() {};
	
public:
	/*!
	* \brief umozliwia komunikacje z fabryka
	* \return Zwraca fabryke przez referencje
	*/
	static factory & get();

	/*!
	* \brief Produkuje obiekty
	* \param type typ produkowanego obiektu
	* \return wskaŸnik na dany obiekt
	*/
	std::shared_ptr<displayableObject> produce(objtypes type);
};

#endif // !FACTORY_HH_
