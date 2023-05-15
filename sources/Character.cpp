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

#include <iostream>
#include "Character.hpp"

using namespace std;
using namespace ariel;

Character::Character(string name, const Point &location, int health_points) : _name(name), _location(const_cast<Point&>(location)), _hp(health_points), _inteam(false) {}

Character::Character(const Character& other): _name(other._name), _location(other._location), _hp(other._hp), _inteam(other._inteam) {}

Character::Character(Character&& other) noexcept: _name(move(other._name)), _location(other._location), _hp(other._hp)
{
	other._hp = 0;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_hp = other._hp;
		_name = other._name;
	}

	return *this;
}

Character& Character::operator=(Character&& other) noexcept
{
	if (this != &other)
	{
		_hp = other._hp;
		_name = move(other._name);
		other._hp = 0;
	}

	return *this;
}
bool Character::isAlive() const
{
	return (_hp > 0);
}

double Character::distance(Character *other) const
{
	if (other == nullptr)
		throw invalid_argument("Other character is null!");

	return _location.distance(other->getLocation());
}

void Character::hit(int power)
{
	if (power < 0)
		throw invalid_argument("Power cannot be negative!");
	
	_hp -= (_hp - power < 0 ? _hp : power);

	if (_hp == 0)
		cout << _name << " died." << endl;
}

string Character::getName() const
{
	return _name;
}

const Point& Character::getLocation() const
{
	return _location;
}

void Character::setLocation(Point &location)
{
	_location = location;
}

bool Character::isInTeam() const
{
	return _inteam;
}

void Character::setInTeam(bool in_team)
{
	_inteam = in_team;
}

int Character::getHP() const
{
	return _hp;
}