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

#include "Character.hpp"

using namespace std;
using namespace ariel;

Character::Character(string name, Point &location, int health_points) : _name(name), _location(location), _hp(health_points), _inteam(false) {}

bool Character::isAlive() const
{
	return _hp > 0;
}

double Character::distance(Character *other) const
{
	return _location.distance(other->getLocation());
}

void Character::hit(int power)
{
	_hp -= power;
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