#ifndef instrument_h
#define instrument_h

/*
 * file : instrument.h
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

#define INSTRUMENT_VERSION "1.00"

#define INSTRUMENT_TYPE_ON 0
#define INSTRUMENT_TYPE_ON_OFF 1
#define INSTRUMENT_TYPE_TRIG 2

#define INSTRUMENT_NAME_SIZE 16
#define INSTRUMENT_NAME_OFFSET 0
#define INSTRUMENT_NOTE_OFFSET (INSTRUMENT_NAME_OFFSET + INSTRUMENT_NAME_SIZE)
#define INSTRUMENT_PARAMS_OFFSET (INSTRUMENT_NOTE_OFFSET + 1)
#define INSTRUMENT_VELOCITY_OFFSET (INSTRUMENT_PARAMS_OFFSET + 1)
#define INSTRUMENT_DATA_SIZE (INSTRUMENT_VELOCITY_OFFSET + 1)

class INSTRUMENT
{
    public:
        INSTRUMENT();
        byte  getNote();
        byte  getChannel();
        char* getName();
        byte  getType();
        byte  getVelocity();

        void  setNote(byte _note);
        void  setChannel(byte _channel);
        void  setName(char* _name);
        void  setType(byte _type);
        void  setVelocity(byte _velocity);
        byte* getDataPointer();
    
    private:
        byte data[INSTRUMENT_DATA_SIZE];
};

#endif

