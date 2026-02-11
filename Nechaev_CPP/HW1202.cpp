#include "HW1202.h"

template <typename T>
Box<T>::Box(T _soderzhimoye)
{
	soderzhimoye = _soderzhimoye;
}

template <typename T>
T Box<T>::GetSoderzhimoye()
{
	return soderzhimoye;
}

template <typename T>
void Box<T>::SetSoderzhimoye(T _soderzhimoye)
{
	soderzhimoye = _soderzhimoye;
}