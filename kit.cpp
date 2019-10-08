/*
 * file : kit.cpp
 * Copyright (c) pfeuh <ze.pfeuh@gmail>
 * All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "kit.h"

/*******************/
/* Private methods */
/*******************/


/******************/
/* Public methods */
/******************/

KIT::KIT()
{
}

void KIT::setName(char* _name)
{
    for (byte x=0; x < INSTRUMENT_NAME_SIZE; x++)
    name[x] = *(_name + x);
}

char* KIT::getName()
{
    return name; 
}

INSTRUMENT* KIT::getInstrument(byte index)
{
    return instruments[index]; 
}

void KIT::setInstrument(byte index, INSTRUMENT* instrument)
{
    instruments[index] = instrument; 
}

