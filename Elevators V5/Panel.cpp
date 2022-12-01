//Programmer: Daniel Lai
//ID: 1685269

#include"Panel.h"
#include <cstdlib>
using namespace std;

int Panel::Button::count = 0;

ostream& operator<<(ostream& out, const Panel& p)
{
    for (Panel::Button button : p.buttons) 
    {
        if (button.lit)
        {
            out << "[" << button.label << "]";
        }
    }
    return out;
}

void Panel::addButton(string a)
{
    Button newButton;
    newButton.label = a;
    newButton.lit = false;
    newButton.sequence = Button::count;

    buttons.push_back(newButton);
    Button::count = buttons.size();
}

void Panel::press(string a) 
{

    for (unsigned int i = 0; i < buttons.size(); i++) 
    {
        if (a == buttons[i].label) 
        {
            buttons[i].lit = true;
            break;
        }
    }
}
void Panel::clear(string a)
{
    for (unsigned int i = 0; i < buttons.size(); i++) 
    {
        if (a == buttons[i].label) 
        {
            buttons[i].lit = false;
            return;
        }
    }
}
string Panel::getFirstLit()const 
{
    Button least;
    least.sequence = Button::count;

    for (Button button : buttons)
    {
        if (button.lit && button.sequence < least.sequence)
        {
            least = button;
        }
    }
    return least.label;
}
bool Panel::isLit(string a)const 
{
    for (Button button:buttons) 
    {
        if (button.label == a) 
        {
            return button.lit;
        }
    }
    return false;
}
bool Panel::areAnyLit()const 
{
    for (Button button:buttons) 
    {
        if (button.lit)
        {
            return true;
        }
    }

    return false;
}