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
    initialize();
}

void PATTERN::initialize()
{
    for(byte step_num=0; step_num < PATTERN_NB_STEPS; step_num++)
        steps[step_num] = 0;

    setGroove(PATTERN_GROOVE_DOUBLE_CROCHE);
    setLastStep(PATTERN_NB_STEPS - 1);

    setNote(0,  BD, ON);
    setNote(8,  BD, ON);
    setNote(16, BD, ON);
    setNote(24, BD, ON);

    setNote(4,  SD, ON);
    setNote(12, SD, ON);
    setNote(20, SD, ON);
    setNote(28, SD, ON);

    setNote(0,  HH, ON);
    setNote(2,  HH, ON);
    setNote(4,  HH, ON);
    setNote(6,  HH, ON);
    setNote(8,  HH, ON);
    setNote(10, HH, ON);
    setNote(12, HH, ON);
    setNote(14, HH, ON);
    setNote(16, HH, ON);
    setNote(18, HH, ON);
    setNote(20, HH, ON);
    setNote(22, HH, ON);
    setNote(24, HH, ON);
    setNote(26, HH, ON);
    setNote(28, HH, ON);
    setNote(30, HH, ON);
}

bool  PATTERN::getNote(byte step_num, byte inst_num)
{
    return (steps[step_num] & (1 << inst_num)) != 0;
}

void  PATTERN::setNote(byte step_num, byte inst_num, bool value)
{
    steps[step_num] &= ~(1 << inst_num);
    steps[step_num] |= value << inst_num;
}

byte PATTERN::getGroove()
{
    return groove;
}

void PATTERN::setGroove(byte _groove)
{
    groove = _groove;
}

byte PATTERN::getLastStep()
{
    return lastStep;
}

void PATTERN::setLastStep(byte last_step)
{
    lastStep = last_step;
}

