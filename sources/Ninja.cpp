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

#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int health_points, int speed) : Character(name, location, health_points), _speed(speed) {}

void Ninja::move(Character *other)
{
	if (other == nullptr)
		throw invalid_argument("Other character is null!");

	else if (other == this)
		throw invalid_argument("Cannot move to yourself!");

	else if (!isAlive())
		throw runtime_error("Cannot move while dead!");

	_location = Point::moveTowards(_location, other->getLocation(), _speed);
}

void Ninja::slash(Character *other)
{
	if (other == nullptr)
		throw invalid_argument("Other character is null!");

	else if (other == this)
		throw invalid_argument("Cannot slash yourself!");

	else if (!isAlive())
		throw runtime_error("Cannot slash while dead!");

	else if (!other->isAlive())
		throw runtime_error("Cannot slash a dead character!");

	if (_location.distance(other->getLocation()) <= 1)
		other->hit(40);
}

string Ninja::print() const
{
	if (!isAlive())
			return "Name: N (" + getName() + "), Location: " + getLocation().print();

	return "Name: N " + getName() + ", HP: " + to_string(getHP()) + ", Location: " + getLocation().print();
}