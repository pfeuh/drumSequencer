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

#define INSTRUMENT_NAME_SIZE 16
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
    
    private:
        byte  note;
        byte  channel;
        char  name[INSTRUMENT_NAME_SIZE];
        byte  type;
        byte  velocity;
};

#endif

