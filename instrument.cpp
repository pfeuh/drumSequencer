/*
 * file : instrument.cpp
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

#include "instrument.h"

#define INSTRUMENT_CHANNEL_MASK 0x0f

#define INSTRUMENT_TYPE_MASK 0x30
#define INSTRUMENT_TYPE_POSITION 4

/*******************/
/* Private methods */
/*******************/


/******************/
/* Public methods */
/******************/

INSTRUMENT::INSTRUMENT()
{
}

void INSTRUMENT::setName(char* _name)
{
    for (byte x=0; x < INSTRUMENT_NAME_SIZE; x++)
        data[INSTRUMENT_NAME_OFFSET + x] = *(_name + x);
}

void INSTRUMENT::setChannel(byte _channel)
{
    // passed as [1:16], stored as [0:15]
    data[INSTRUMENT_PARAMS_OFFSET] &= ~INSTRUMENT_CHANNEL_MASK;
    data[INSTRUMENT_PARAMS_OFFSET] |= _channel - 1;
}

void INSTRUMENT::setType(byte _type)
{
    // passed as [0, 1, 2], stored as [0x00, 0x10, 0x20]
    data[INSTRUMENT_PARAMS_OFFSET] &= ~INSTRUMENT_TYPE_MASK;
    data[INSTRUMENT_PARAMS_OFFSET] |= _type << INSTRUMENT_TYPE_POSITION;
}

void INSTRUMENT::setNote(byte _note)
{
    data[INSTRUMENT_NOTE_OFFSET] = _note;
}

void INSTRUMENT::setVelocity(byte _velocity)
{
    data[INSTRUMENT_VELOCITY_OFFSET] = _velocity;
}

byte INSTRUMENT::getNote()
{
    return data[INSTRUMENT_NOTE_OFFSET]; 
}

byte INSTRUMENT::getChannel()
{
    return (data[INSTRUMENT_PARAMS_OFFSET]  & INSTRUMENT_CHANNEL_MASK) + 1;
}

char* INSTRUMENT::getName()
{
    return (char*)&data[INSTRUMENT_NAME_OFFSET]; 
}

byte INSTRUMENT::getType()
{
    return (data[INSTRUMENT_PARAMS_OFFSET] & INSTRUMENT_TYPE_MASK) >> INSTRUMENT_TYPE_POSITION;
}

byte INSTRUMENT::getVelocity()
{
    return data[INSTRUMENT_VELOCITY_OFFSET]; 
}

byte* INSTRUMENT::getDataPointer()
{
    return (byte*)&data;
}