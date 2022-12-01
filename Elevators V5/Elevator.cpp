//Programmer: Daniel Lai
//ID: 1685269

#include "Elevator.h"
#include "Panel.h"
#include "Building.h"


#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>



Elevator::Elevator(unsigned int capacity, int speed, int start)
	:CAPACITY(capacity), speed(speed), direction(IDLE), timer(0), atFloorIndex(-1), location(Building::floors[start])
{
	for (int i = 0; i < Building::FLOORS; i++) 
	{
		panel.addButton(Building::floors[i].label);
	}
}

ostream& operator<<(ostream& out, const Elevator& e)
{
	string directionS;
	switch (e.direction) 
	{
	case 0:directionS = "IDEL"; break;
	case 1:directionS = "going Up"; break;
	case -1:directionS = "going Down"; break;
	}
	out.width(10);
	out.setf(ios::right);
	out << "Elevator at ";
	out.width(9);
	out << e.location;
	out.width(10);
	out << directionS;
	out.width(10);
	out << e.riders.size();
	out.width(10);
	out << " riders";
	out.setf(ios::left);
	if (e.atFloorIndex >= 0)
	{
		out.width(20);
		cout << "Door is OPEN|" << e.timer;
	}
	else
		out << " ";
	out<< "        " <<e.panel;

	return out;
}
void Elevator::openDoorTo(int a) 
{
	panel.clear(Building::floors[a].label);
	atFloorIndex = a;
	resetTimer();
}
void Elevator::board(const Rider& r)
{

	riders.push_back(r);
	panel.press(Building::floors[r.to].label);
	if (r.goingUp) 
	{
		direction = UP;
	}
	else
	{
		direction = DOWN;
	}
	resetTimer();
}

bool Elevator::hasRiderForFloor() const 
{
	int i=0;
	if (atFloorIndex == -1)
	{
		return false;
	}
	for (i = 0; i < riders.size(); i++)
	{
		if (riders[i].to == atFloorIndex)
		{
			return true;
		}
	}
	if (i == riders.size())
	{
		return false;
	}
}

void Elevator::removeRider()
{
	vector<Rider>::iterator e;
	for (e = riders.begin(); e != riders.end(); e++)
	{
		if (e->to == atFloorIndex) 
		{ 
			this->panel.clear(Building::floors[e->to].label);
			e = this->riders.erase(e);
			this->resetTimer();
			break;
		}
	}
}

bool Elevator::closeDoor()
{
	if (goingUp() && Building::floors[getFloorIndex()].hasUpRider())
	{
		Building::floors[getFloorIndex()].panel.clear(to_string(getFloorIndex()));
	}
	if (goingDown() && Building::floors[getFloorIndex()].hasDownRider()) 
	{
		Building::floors[getFloorIndex()].panel.clear(to_string(getFloorIndex()));
	}


	if (isOpen())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Elevator::move() 
{
	if (goingUp()) 
	{
		location = location + (speed * timer);
		return true;
	}
	else if (goingDown()) 
	{
		location = location - (speed * timer);
		return true;
	}
	else 
	{
		return false;
	}

}

void Elevator::goIdle() 
{
	direction = IDLE;
}