#ifndef song_h
#define song_h

/*
 * file : song.h
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

#include <Arduino.h>
#include "instrument.h"

#define SONG_VERSION "1.00"

#define SONG_NB_MEASURES 256
#define SONG_INDEX_LAST_MEASURE (0 + SONG_NB_MEASURES)
#define SONG_DATA_SIZE (SONG_INDEX_LAST_MEASURE + 1)

class SONG
{
    public:
        SONG();
        void initialize();
        byte getPattern(word _cursor);
        void setPattern(word _cursor, byte pattern);
        void insertPattern(word _cursor, byte pattern);
        void cutPattern(word _cursor);
        word getCursor();
        void setcursor(word _cursor);
        void setNbMeasures(word nb_measures);
        word getNbMeasures();
        byte* getDataPointer();
    
    private:
        byte data[SONG_NB_MEASURES];
        word cursor;
        word nbMeasures;
    
};

#endif

