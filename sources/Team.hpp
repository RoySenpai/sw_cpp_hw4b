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

#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
	class Team
	{
		protected:
			/*
			* @brief A pointer to the leader of the team.
			*/
			Character *_leader;

			/*
			* @brief A vector of pointers to the members of the team.
			*/
			std::vector<Character *> _members;

			/*
			* @brief The size of the team.
			*/
			int _size;

			/*
			* @brief Find a victim to attack.
			* @param other A pointer to the other team.
			* @return A pointer to the victim, or nullptr if there is no victim.
			*/
			static Character *_find_victim(Team *other);

		public:
			/*
			* @brief Construct a new Team object.
			* @param leader A pointer to the leader of the team.
			*/
			Team(Character *leader);

			/*
			* @brief Destroy the Team object.
			* @brief This is a virtual destructor because this class is inherited to other classes.
			*/
			virtual ~Team();

			/*
			* @brief Add a member to the team.
			* @param member A pointer to the member to add.
			*/
			void add(Character *member);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			virtual void attack(Team *other);

			/*
			* @brief Check if the team is still alive
			* @return int The number of alive members
			*/
			int stillAlive() const;

			/*
			* @brief Get a member of the team
			* @param index The index of the member
			* @return A pointer to the member
			*/
			Character *getMember(int index) const;

			/*
			* @brief Get the size of the team
			* @return The size of the team
			*/
			int getSize() const;

			/*
			* @brief Print the team members
			*/
			virtual void print() const;
	};
}