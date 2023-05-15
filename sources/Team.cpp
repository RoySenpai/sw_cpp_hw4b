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
#include "Team.hpp"

using namespace std;
using namespace ariel;

Character *Team::_find_victim(Team *other)
{
	return nullptr;
}

Team::Team(Character *leader) : _leader(leader), _size(1)
{
	if (leader->isInTeam())
		throw runtime_error("Leader is already in a team!");

	
	_members.push_back(leader);

	leader->setInTeam(true);
}

Team::~Team()
{
	Cowboy *c = nullptr;
	Ninja *n = nullptr;

	while (_members.size() > 0)
	{
		Character *tmp = _members.back();
		_members.pop_back();
		
		c = dynamic_cast<Cowboy *>(tmp);
		n = dynamic_cast<Ninja *>(tmp);

		if (c != nullptr)
		{
			delete c;
		}

		else if (n != nullptr)
		{
			delete n;
		}
	}
}

void Team::add(Character *member)
{
	if (member == nullptr)
		throw invalid_argument("Member is null!");

	else if (member->isInTeam())
		throw runtime_error("Member is already in a team!");

	else if (_size == 10)
		throw runtime_error("Team is full!");

	_members.push_back(member);

	member->setInTeam(true);

	_size++;
}

void Team::attack(Team *other)
{
	for (unsigned int i = 0; i < other->_size; i++)
		other->_members[i]->hit(10);
}

int Team::stillAlive() const
{
	int alive = 0;

	for (unsigned int i = 0; i < _size; i++)
	{
		if (_members[i]->isAlive())
			alive++;
	}

	return alive;
}

Character *Team::getMember(int index) const
{
	return nullptr;
}

int Team::getSize() const
{
	return _size;
}

void Team::print() const
{
	cout << "Team: " << _leader->getName() << endl;

	for (unsigned int i = 0; i < _size; i++)
	{
		if (dynamic_cast<Cowboy *>(_members[i]) != nullptr)
			cout << _members[i]->print() << endl;
	}

	for (unsigned int i = 0; i < _size; i++)
	{
		if (dynamic_cast<Ninja *>(_members[i]) != nullptr)
			cout << _members[i]->print() << endl;
	}
}