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
#include "kit.h"

#define PATTERN_VERSION "1.00"

#define PATTERN_NB_STEPS 32

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

#define PATTERN_STEPS_OFFSET 0
#define PATTERN_PARAMS_OFFSET (PATTERN_STEPS_OFFSET + PATTERN_NB_STEPS * 2)
#define PATTERN_DATA_SIZE (PATTERN_PARAMS_OFFSET + 1)

#define BD 0
#define SD 1
#define HH 3
#define ON true
#define OFF false

class PATTERN
{
    public:
        PATTERN();
        void initialize();
        bool getNote(byte step_num, byte inst_num);
        void setNote(byte step_num, byte inst_num, bool value);
    
        byte getGroove();
        void setGroove(byte _groove);
    
        byte getLastStep();
        void setLastStep(byte last_step);

        word steps[PATTERN_NB_STEPS];
    
    private:
        byte groove;
        byte lastStep;

};

#endif

