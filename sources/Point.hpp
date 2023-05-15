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
#include <stdexcept>

namespace ariel
{
	class Point
	{
		private:
			/*
			* @brief The x coordinate of the point.
			*/
			double _x;

			/*
			* @brief The y coordinate of the point.
			*/
			double _y;

		public:
			/*
			* @brief Construct a new Point object, default constructor.
			* @note Creates a point at (0.0, 0.0).
			*/
			Point();

			/*
			* @brief Construct a new Point object.
			* @param x The x coordinate of the point.
			* @param y The y coordinate of the point.
			* @note Creates a point at (x,y).
			*/
			Point(double pt_x, double pt_y);

			/*
			* @brief Returns the x coordinate of the point.
			* @return The x coordinate of the point.
			*/
			double getX() const;

			/*
			* @brief Returns the y coordinate of the point.
			* @return The y coordinate of the point.
			*/
			double getY() const;

			/*
			* @brief Returns the distance between this point and other point.
			* @param other The other point.
			* @return The distance between this point and other point.
			*/
			double distance(Point other) const;

			/*
			* @brief Prints the point.
			* @return The point in the following format: (x,y).
			*/
			std::string print() const;

			/*
			* @brief Returns the closest point to the other point, that is at most dist away from the origin point.
			* @param curr The origin point.
			* @param other The other point.
			* @param dist The maximum distance between the points.
			* @return The closest point to the other point, that is at most dist away from the origin point.
			*/
			static Point moveTowards(const Point &curr, const Point &other, const double dist);
	};
}