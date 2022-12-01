//Programmer: Daniel Lai
//ID: 1685269

#include "Floor.h"
#include "Rider.h"
#include "Panel.h"
#include <iomanip>

using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label) :elevation(elevation), name(name), label(label)
{

	panel.addButton("Up");
	panel.addButton("Down");

	if (TOP < elevation) TOP = elevation;
	if (elevation < BOTTOM) BOTTOM = elevation;
}

ostream& operator<<(ostream& out, const Floor& floor)
{

	out.setf(ios::right);
	out << floor.label;
	out.width(15);
	out << floor.name;
	out.width(5);
	out << " at";
	out.width(10);
	out << floor.elevation;
	out.width(10);
	out << "Up/Down:";
	out.width(10);
	out << floor.upRiders.size() << "/" << floor.downRiders.size();
	out.width(10);
	out << " Button:" << floor.panel;
	return out;
}
bool Floor::hasUpRider() const 
{
	if (upRiders.empty()) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}
bool Floor::hasDownRider() const 
{
	if (downRiders.empty()) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}
void Floor::addRider(const Rider& r) 
{
	if (r.goingUp) 
	{
		panel.press("Up");
		upRiders.push(r);
	}
	else
	{
		panel.press("Down");
		downRiders.push(r);
	}

}

Rider Floor::removeUpRider() 
{
	Rider r = upRiders.front();
	try 
	{
		if (upRiders.empty()) 
		{
			throw "error.";
		}
		upRiders.pop();
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	return r;
}

Rider Floor::removeDownRider() 
{
	Rider r = downRiders.front();
	try 
	{
		if (downRiders.empty())
		{
			throw "error.";
		}
		downRiders.pop();
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	return r;
}