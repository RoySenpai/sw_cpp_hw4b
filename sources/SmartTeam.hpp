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

#include "Team.hpp"

namespace ariel
{
	class SmartTeam : public Team
	{
		private:
			/*
			* @brief Find a victim to attack, by looking for the weakest character in the other team.
			* @param other A pointer to the other team.
			* @return A pointer to the victim, or nullptr if there is no victim.
			*/
			Character *_find_victim(Team *other) const override;

			/*
			 * @brief Find a victim to attack, by looking for the closest character in the other team.
			 * @param other A pointer to the other team.
			 * @param ref A pointer to the character to compare the distance to.
			 * @return A pointer to the victim, or nullptr if there is no victim.
			*/
			Character *_find_victim(Team *other, Character *ref) const;

		public:
			/*
			* @brief Construct a new SmartTeam object.
			* @param leader A pointer to the leader of the team.
			*/
			SmartTeam(Character *leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			* @note The attack method is different for the smart team, 
					as it looks for the weakest character in the other team to attack (Cowboys),
					or the closest character to attack (Ninjas).
			*/
			void attack(Team *other) override;

			/*
			* @brief Print the team members
			*/
			void print() const override;
	};
}