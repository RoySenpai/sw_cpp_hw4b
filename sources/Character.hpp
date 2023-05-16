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

#include <string>
#include "Point.hpp"

namespace ariel
{
	class Character
	{
		private:
			/*
			* @brief The name of the character.
			*/
			std::string _name;

			/*
			* @brief The location of the character.
			*/
			Point _location;

			/*
			 * @brief The health points of the character.
			*/
			int _hp;

			/*
			 * @brief Whether the character is in a team.
			 * @note True if the character is in a team, false otherwise.
			*/
			bool _inteam;

		public:
			/*
			 * @brief Construct a new Character object.
			 * @param name The name of the character.
			 * @param location The starting location of the character.
			 * @param health_points The health points of the character.
			*/
			Character(std::string name, const Point &location, int health_points);

			/*
			 * @brief Construct a new Character object.
			 * @param other The other character.
			 * @note This is a copy constructor.
			*/
			Character(const Character& other);

			/*
			 * @brief Construct a new Character object.
			 * @param other The other character.
			 * @note This is a move constructor.
			*/
			Character(Character&& other) noexcept;

			/*
			 * @brief Overloads the assignment operator.
			 * @param other The other character.
			 * @return The character after the assignment.
			*/
			Character& operator=(const Character& other);

			/*
			 * @brief Overloads the assignment operator.
			 * @param other The other character.
			 * @return The character after the assignment.
			*/
			Character& operator=(Character&& other) noexcept;

			/*
			 * @brief Destroy the Character object.
			 * @note This is a virtual destructor, it doesn't do anything.
			*/
			virtual ~Character() {}

			/*
			 * @brief Checks if the character is alive.
			 * @return True if the character is alive, false otherwise.
			 * @note A character is alive if it has more than 0 health points.
			*/
			bool isAlive() const;

			/*
			 * @brief Check the distance between this character and other character.
			 * @param other The other character.
			 * @return The distance between this character and other character.
			 * @note The distance is calculated by the distance function of Point.
			*/
			double distance(Character *other) const;

			/*
			 * @brief Makes a hit on the character.
			 * @param power The power of the hit.
			 * @return void
			*/
			void hit(int power);

			/*
			 * @brief Gets the name of the character.
			 * @return The name of the character.
			*/
			std::string getName() const;

			/*
			 * @brief Gets the location of the character.
			 * @return The location of the character.
			*/
			const Point& getLocation() const;

			/*
			 * @brief Sets the location of the character.
			 * @param location The new location of the character.
			 * @return void
			*/
			void setLocation(Point& location);

			/*
			 * @brief Checks if the character is in a team.
			 * @return True if the character is in a team, false otherwise.
			*/
			bool isInTeam() const;

			/*
			 * @brief Sets the character to be in a team.
			 * @param inTeam True if the character is in a team, false otherwise.
			*/
			void setInTeam(bool inTeam);

			/*
			 * @brief Gets the health points of the character.
			 * @return The health points of the character.
			*/
			int getHP() const;

			/*
			 * @brief Prints the character.
			 * @return void
			 * @note This is a pure virtual function because this class is abstract.
			*/
			virtual std::string print() const = 0;
	};
}