#pragma once

template<typename T>
class Box
{
public:
	Box(T _soderzhimoye);
	T GetSoderzhimoye();
	void SetSoderzhimoye(T _soderzhimoye);
private:
	T soderzhimoye;
};