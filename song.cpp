/*
 * file : song.cpp
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

#include "song.h"

/*******************/
/* Private methods */
/*******************/


/******************/
/* Public methods */
/******************/

SONG::SONG()
{
    initialize();
}

void SONG::initialize()
{
    for(word index=0; index < SONG_NB_MEASURES; index++)
        setPattern(index, 0);
    cursor = 0;
    nbMeasures = 0;
}

byte SONG::getPattern(word _cursor)
{
    return data[_cursor];
}

void SONG::setPattern(word _cursor, byte pattern)
{
    data[_cursor] = pattern;
}

void SONG::insertPattern(word _cursor, byte pattern)
{
    for(word index = SONG_NB_MEASURES - 2; index > (_cursor - 1); index--)
       data[index+1] = data[index];
    setPattern(_cursor, pattern);
    nbMeasures++;
}

void SONG::cutPattern(word _cursor)
{
    for(word index = _cursor - 1; index < (SONG_NB_MEASURES - 1); index++)
       data[index] = data[index+1];
    nbMeasures--;
}

word SONG::getCursor()
{
    return cursor;
}

void SONG::setcursor(word _cursor)
{
    cursor = _cursor;
}

void SONG::setNbMeasures(word nb_measures)
{
    nbMeasures = nb_measures;
}

word SONG::getNbMeasures()
{
    return nbMeasures;
}

byte* SONG::getDataPointer()
{
    return (byte*)&data;
}
