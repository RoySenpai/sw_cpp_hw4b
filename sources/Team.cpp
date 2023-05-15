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
#include <limits>
#include "Team.hpp"

using namespace std;
using namespace ariel;

Character* Team::_find_victim(Team *other) {
	Character *victim = nullptr;
	Character *otherLeader = other->_leader;

	double minDistance = numeric_limits<double>::max();

	for (Character* member: other->_members)
	{
		if (member == nullptr || member == otherLeader)
			continue;
			
		if (member->isAlive() && otherLeader->distance(member) < minDistance)
		{
			minDistance = otherLeader->distance(member);
			victim = member;
		}
	}

	if (victim == nullptr && otherLeader->isAlive())
		victim = otherLeader;
		
	return victim;
}

Team::Team(Character *leader) : _leader(leader)
{
	if (leader->isInTeam())
		throw runtime_error("Leader is already in a team!");
	
	_members.push_back(leader);

	leader->setInTeam(true);
}

Team::Team(const Team& other): _leader(other._leader)
{
	for (Character* member: other._members)
	{
		Cowboy* c = dynamic_cast<Cowboy*>(member);
		Ninja* n = dynamic_cast<Ninja*>(member);
		
		if (c != nullptr)
			_members.push_back(new Cowboy(*c));

		else if (n != nullptr)
			_members.push_back(new Ninja(*n));
	}
}

Team::Team(Team&& other) noexcept: _leader(other._leader), _members(move(other._members))
{
    other._leader = nullptr;
}

Team& Team::operator=(const Team& other)
{
	if (this != &other)
	{
		for (Character* member: _members)
			delete member;

		_members.clear();
		_leader = other._leader;

		for (Character* member: other._members)
		{
			Cowboy* c = dynamic_cast<Cowboy*>(member);
			Ninja* n = dynamic_cast<Ninja*>(member);
		
			if (c != nullptr)
				_members.push_back(new Cowboy(*c));

			else if (n != nullptr)
				_members.push_back(new Ninja(*n));
		}
	}

	return *this;
}

Team& Team::operator=(Team&& other) noexcept
{
	if (this != &other)
	{
		for (Character* member : _members)
			delete member;

		_members.clear();

		_leader = other._leader;
		_members = move(other._members);

		other._leader = nullptr;
	}
	
	return *this;
}

Team::~Team()
{
	for (Character *member: _members)
		delete member;
}

void Team::add(Character *member)
{
	if (member == nullptr)
		throw invalid_argument("Member is null!");

	else if (member->isInTeam())
		throw runtime_error("Member is already in a team!");

	else if (_members.size() == 10)
		throw runtime_error("Team is full!");

	_members.push_back(member);

	member->setInTeam(true);
}

void Team::attack(Team *other)
{
	if (other == nullptr)
		throw invalid_argument("Other team is null!");

	else if (other == this)
		throw runtime_error("Cannot attack self team!");

	else if (other->stillAlive() == 0)
		throw runtime_error("Other team is dead!");

	if (!other->_leader->isAlive())
	{
		Character* tmp = Team::_find_victim(other);

		if (tmp != nullptr)
			other->_leader = tmp;

		else
			throw runtime_error("Great, you broke the game!");
	}
	
	Character* victim = Team::_find_victim(other);

	if (victim == nullptr)
		return;

	for (Character* member: _members)
	{
		if (!victim->isAlive())
			return;

		Cowboy* c = dynamic_cast<Cowboy*>(member);

		if (c != nullptr && c->isAlive())
		{
			if (c->hasboolets())
				c->shoot(victim);

			else
				c->reload();
		}
	}

	for (Character* member: _members)
	{
		if (!victim->isAlive())
			return;

		Ninja* n = dynamic_cast<Ninja*>(member);

		if (n != nullptr && n->isAlive())
		{
			if (n->getLocation().distance(victim->getLocation()) <= 1)
				n->slash(victim);

			else
				n->move(victim);
		}
	}
}

int Team::stillAlive() const
{
	int alive = 0;

	for (Character* member: _members)
	{
		if (member->isAlive())
			alive++;
	}

	return alive;
}

const vector<Character*>& Team::getMembers() const {
	return _members;
}

const Character* Team::getLeader() const
{
	return _leader;
}

void Team::setLeader(Character *leader) {
	_leader = leader;
}

int Team::getSize() const
{
	return static_cast<int>(_members.size());
}

void Team::print() const
{
	cout << "Team Leader: " << _leader->getName() << endl;

	for (Character* member: _members)
	{
		if (dynamic_cast<Cowboy*>(member) != nullptr)
			cout << member->print() << endl;
	}

	for (Character* member: _members)
	{
		if (dynamic_cast<Ninja*>(member) != nullptr)
			cout << member->print() << endl;
	}
}