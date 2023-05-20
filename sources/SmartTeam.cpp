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
#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;

constexpr double MAX_DISTANCE = 100;

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

Character *SmartTeam::_find_victim(Team *other) const
{
	Character *victim = nullptr;

	int minHP = numeric_limits<int>::max();

	for (auto member : other->getMembers())
	{
		if (member->isAlive() && member->getHP() < minHP)
		{
			minHP = member->getHP();
			victim = member;
		}
	}

	if (victim == nullptr)
		cout << "No victim found!" << endl;

	else
		cout << "Victim is " << victim->getName() << endl;

	return victim;
}

Character *SmartTeam::_find_victim(Team *other, Character *ref) const
{
	Character *victim = nullptr;

	double minDistance = numeric_limits<double>::max();

	for (auto member : other->getMembers())
	{
		if (member->isAlive() && ref->distance(member) < minDistance)
		{
			minDistance = ref->distance(member);
			victim = member;
		}
	}

	if (victim == nullptr)
		cout << "No victim found!" << endl;

	else
		cout << "Victim is " << victim->getName() << endl;

	return victim;
}

void SmartTeam::attack(Team *other)
{
	if (other == nullptr)
		throw invalid_argument("Other team is null!");
	
	else if (other == this)
		throw runtime_error("Cannot attack self team!");

	else if (other->stillAlive() == 0)
		throw runtime_error("Other team is dead!");

	else if (stillAlive() == 0)
		throw runtime_error("This team is dead!");
	
	if (!getLeader()->isAlive())
	{
		Character *newLeader = nullptr;

		double minDistance = numeric_limits<double>::max();

		for (Character* member: getMembers())
		{
			if (member->isAlive() && member->distance(getLeader()) < minDistance)
			{
				minDistance = member->distance(getLeader());
				newLeader = member;
			}
		}

		cout << "Team leader " << getLeader()->getName() << " has died, new leader is " << newLeader->getName() << endl;

		setLeader(newLeader);
	}

	Character* victim = _find_victim(other);

	// Vector copies of the alive team members.
	vector<Ninja *> ninjas_copy;
	vector<Cowboy *> cowboys_copy;

	// Split the team into ninjas and cowboys
	for (Character* member: getMembers())
	{
		Cowboy* c = dynamic_cast<Cowboy*>(member);
		Ninja* n = dynamic_cast<Ninja*>(member);

		if (c != nullptr && c->isAlive())
			cowboys_copy.push_back(c);

		else if (n != nullptr && n->isAlive())
			ninjas_copy.push_back(n);
	}

	// Attack with the cowboys
	for (Cowboy* cowboy: cowboys_copy)
	{
		if (!victim->isAlive())
		{
			if (other->stillAlive() == 0)
				return;
			
			victim = _find_victim(other, cowboy);
		}

		if (cowboy->hasboolets())
			cowboy->shoot(victim);

		else
			cowboy->reload();
	}

	// Attack with the ninjas
	for (Ninja* ninja: ninjas_copy)
	{
		if (other->stillAlive() == 0)
			return;
		
		victim = _find_victim(other, ninja);

		if (ninja->distance(victim) <= 1)
			ninja->slash(victim);

		else
			ninja->move(victim);
	}
}

void SmartTeam::print() const
{
	cout << "Team Leader: " << getLeader()->getName() << endl;

	vector<Character *> members_copy = getMembers();

	// Sort the members by HP and print them
	sort(members_copy.begin(), members_copy.end(), [](Character *a, Character *b) {
		return a->getHP() > b->getHP();
	});

	for (Character *member : members_copy)
		cout << member->print() << endl;
}