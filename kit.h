#ifndef kit_h
#define kit_h

/*
 * file : kit.h
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

#define KIT_VERSION "1.00"

#define KIT_NAME_SIZE 16

#define KIT_NB_INSTRUMENTS 16

class KIT
{
    public:
        KIT();
        INSTRUMENT* getInstrument(byte index);
        void setInstrument(byte index, INSTRUMENT* instrument);
        char* getName();
        void setName(char* _name);
    
    private:
        INSTRUMENT* instruments[KIT_NB_INSTRUMENTS];
        char name[KIT_NAME_SIZE];
    
};

#endif

