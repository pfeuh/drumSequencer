/*
 * file : drumSequencer.ino
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

#include "drumSequencer.h"

DRUM_SEQUENCER item = DRUM_SEQUENCER();

const char PROGMEM title[] = "drumSequencer v. " DRUM_SEQUENCER_VERSION;

const char PROGMEM timestamp[] = __DATE__ " " __TIME__;

#define CONSOLE_OUT_DEV Serial

void cPrint(const char* address)
{
    while(pgm_read_byte(address))
        CONSOLE_OUT_DEV.write(pgm_read_byte(address++));
}

void cPrintLn(const char* address)
{
    cPrint(address);
    CONSOLE_OUT_DEV.write('\n');
}

void setup()
{
    //~ item.begin();
    CONSOLE_OUT_DEV.begin(9600);
    cPrintLn(title);
    cPrintLn(timestamp);

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    if(millis() & 0x200)
        digitalWrite(LED_BUILTIN, 0);
    else
        digitalWrite(LED_BUILTIN, 1);
}

