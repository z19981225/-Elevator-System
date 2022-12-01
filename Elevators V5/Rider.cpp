//Programmer: Daniel Lai
//ID: 1685269

#include "Rider.h"

#include <iostream>
#include <vector>

#include <cstdlib>
using namespace std;

Rider::Rider(int from, int to) :from(from), to(to), goingUp(from < to ? true : false), goingDown(from > to ? true : false) 
{
}

Rider& Rider::operator=(const Rider& a)
{
	Rider& host = *this;
	if (this != &a)
	{
		const_cast<int&>(host.from) = a.from;
		const_cast<int&>(host.to) = a.to;
		const_cast<bool&>(host.goingUp) = a.goingUp;
		const_cast<bool&>(host.goingDown) = a.goingDown;
	}
	return host;
}