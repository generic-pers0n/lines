# Copyright (C) 2019 Avery King <avery98@pm.me>
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
lines: lines.cpp
	g++ -o lines lines.cpp -llines -g --std=c++17

portable: lines.cpp
	g++ -o lines-port lines.cpp -L./build-portable -llines -static -g -DPORT
	mv lines-port build-libs

install: lines # Also requires liblines.so
	install lines /bin

