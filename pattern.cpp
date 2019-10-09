/*
 * file : pattern.cpp
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

#include "pattern.h"

/*******************/
/* Private methods */
/*******************/


/******************/
/* Public methods */
/******************/

PATTERN::PATTERN()
{
    for(byte step=0; step < PATTERN_NB_STEPS; step++)
    {
        for(byte index = 0; index < KIT_NB_INSTRUMENTS; index++)
            setNote(step, index, 1);
        setGroove(PATTERN_GROOVE_DOUBLE_CROCHE);
        setLastNote(15);
    }

}

bool  PATTERN::getNote(byte step, byte index)
{
    if(index <= 7)
        return (notes[step * 2 + 1] & (1 << (index - 8))) != 0;
    else
        return (notes[step * 2] & (1 << index)) != 0;
}

void  PATTERN::setNote(byte step, byte index, bool value)
{
    if(index <= 7)
    {
        notes[step * 2 + 1] &= ~(1 << index);
        notes[step * 2 + 1] |= value << index;
    }
    else
    {
        notes[step * 2] &= ~(1 << (index - 8));
        notes[step * 2] |= value << (index - 8);
    }
}

byte PATTERN::getGroove()
{
    return params & PATTERN_GROOVE_MASK;
}

void PATTERN::setGroove(byte groove)
{
    params &= ~PATTERN_GROOVE_MASK;
    params |= groove;
}

byte PATTERN::getLastNote()
{
    return (params & PATTERN_LAST_NOTE_MASK) >> PATTERN_LAST_NOTE_POSITION;
}

void PATTERN::setLastNote(byte last_note)
{
    params &= ~PATTERN_GROOVE_MASK;
    params |= last_note << PATTERN_LAST_NOTE_POSITION;
}

