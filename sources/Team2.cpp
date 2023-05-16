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
#include "Team2.hpp"

using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *other)
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

	cout << "Team " << getLeader()->getName() << " is attacking team " << other->getLeader()->getName() << endl;

	Character* victim = _find_victim(other);

	for (Character* member: getMembers())
	{
		if (!victim->isAlive())
		{
			if (other->stillAlive() == 0)
				break;
			
			victim = _find_victim(other);
		}

		Cowboy* c = dynamic_cast<Cowboy*>(member);
		Ninja* n = dynamic_cast<Ninja*>(member);

		if (c != nullptr && c->isAlive())
		{
			if (c->hasboolets())
				c->shoot(victim);

			else
				c->reload();
		}

		else if (n != nullptr && n->isAlive())
		{
			if (n->getLocation().distance(victim->getLocation()) <= 1)
				n->slash(victim);

			else
				n->move(victim);
		}
	}
}

void Team2::print() const
{
	cout << "Team Leader: " << getLeader()->getName() << endl;

	for (Character *member : getMembers())
		cout << member->print() << endl;
}