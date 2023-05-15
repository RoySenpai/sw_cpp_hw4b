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

#include "Character.hpp"

namespace ariel
{
	class Cowboy : public Character
	{
		private:
			/*
			* @brief The number of bullets the cowboy has.
			*/
			int _bullets;

		public:
			/*
			* @brief Construct a new Cowboy object.
			* @param name The name of the cowboy.
			* @param location The starting location of the cowboy.
			*/
			Cowboy(std::string name, Point location);

			/*
			* @brief Shoots another character.
			* @param other The other character.
			* @return void
			* @note If the other character is alive and the distance between the two characters is less than or equal to 10, the other character is hit.
			*/
			void shoot(Character *other);

			/*
			* @brief Checks if the cowboy has bullets.
			* @return True if the cowboy has bullets, false otherwise.
			*/
			bool hasboolets() const;

			/*
			* @brief Reloads the cowboy's gun back to 6 bullets.
			* @return void
			*/
			void reload();

			/*
			* @brief Prints the cowboy.
			* @return void
			*/
			std::string print() const override;
	};
}