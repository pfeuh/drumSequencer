#ifndef pattern_h
#define drumSequencer_h

/*
 * file : pattern.h
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

#define PATTERN_VERSION "1.00"

#define PATTERN_NB_NOTES 32

#define PATTERN_GROOVE_NOIRE 0
#define PATTERN_GROOVE_CROCHE 1
#define PATTERN_GROOVE_TRIOLET_CROCHE 2
#define PATTERN_GROOVE_CROCHE_SWING 3
#define PATTERN_GROOVE_DOUBLE_CROCHE 4
#define PATTERN_GROOVE_TRIOLET_DOUBLE_CROCHE 5
#define PATTERN_GROOVE_DOUBLE_CROCHE_SWING 6

#define PATTERN_GROOVE_MASK 0x07
#define PATTERN_LAST_NOTE_MASK 0xf8
#define PATTERN_LAST_NOTE_POSITION 3

class PATTERN
{
    public:
        PATTERN();
        byte  getNote(byte index);
        void  setNote(byte index, byte note);
    
        byte  getGroove();
        void  setGroove(byte groove);
    
        byte  getLastNote();
        void  setLastNote(byte last_note);
    
    private:
        byte  notes[PATTERN_NB_NOTES];
        byte  params; // last note + groove
};

#endif

