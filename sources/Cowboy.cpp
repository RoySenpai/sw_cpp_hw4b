/*
 *  Software Systems CPP Course Assignment 4
 *  Copyright (C) 2023  Roy Simanovich
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110) {}

void Cowboy::shoot(Character *other)
{
	if (other == nullptr)
		throw invalid_argument("Other character is null!");

	else if (other == this)
		throw invalid_argument("Cannot shoot yourself!");

	else if (!isAlive())
		throw runtime_error("Cannot shoot while dead!");

	else if (!other->isAlive())
		throw runtime_error("Cannot shoot a dead character!");

	else

	if (hasboolets())
	{
		_bullets--;
		other->hit(10);
	}
}

bool Cowboy::hasboolets() const
{
	return _bullets > 0;
}

void Cowboy::reload()
{
	_bullets = 6;
}

string Cowboy::print() const
{
	if (!isAlive())
		return "Name: C (" + getName() + "), Location: " + getLocation().print();

	return "Name: C " + getName() + ", HP: " + to_string(getHP()) + ", Location: " + getLocation().print();
}