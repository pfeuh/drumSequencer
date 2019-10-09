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

DRUM_SEQUENCER seq = DRUM_SEQUENCER();

const char PROGMEM title[] = "drumSequencer v. " DRUM_SEQUENCER_VERSION "\n";

const char PROGMEM timestamp[] = __DATE__ " " __TIME__ "\n";

void printNibble(byte value)
{
    value &= 0x0f;
    if(value < 10)
        Serial.write(value +'0');
    else
        Serial.write(value +'a' - 10);
}

void printByte(byte value)
{
    printNibble(value >> 4);
    printNibble(value);
}

void dumpRam(byte* addr)
{
    for(word x = 0; x < 256; x++)
    {
        printByte(*(addr + x));
        Serial.write(' ');
        if(x % 16 == 15)
            Serial.write('\n');
    }
    printByte(*(addr + 256));
    Serial.write('\n');
}

void print_P(const char* address)
{
    while(pgm_read_byte(address))
        Serial.write(pgm_read_byte(address++));
}

void setup()
{
    //~ item.begin();
    Serial.begin(9600);
    print_P(title);
    print_P(timestamp);

    pinMode(LED_BUILTIN, OUTPUT);
    
    KIT* kit = seq.getKit();
    
    for(byte index=0; index < KIT_NB_INSTRUMENTS; index++)
    {
        INSTRUMENT* inst = kit->getInstrument(index);
        Serial.print((const char*)inst->getDataPointer());
        Serial.write(' ');
        Serial.print(inst->getNote());
        Serial.write(' ');
        Serial.print(inst->getChannel());
        Serial.write(' ');
        Serial.print(inst->getType());
        Serial.write(' ');
        Serial.print(inst->getVelocity());
        Serial.write('\n');
    }
    
    SONG* song = seq.getSong(0);
    for(byte x = 0; x < 16; x++)
        song->setPattern(240 + x, x);
    song->insertPattern(240, 0x33);
    //~ song->insertPattern(255, 0x44);
    dumpRam(song->getDataPointer());

}

void loop()
{
    if(millis() & 0x200)
        digitalWrite(LED_BUILTIN, 0);
    else
        digitalWrite(LED_BUILTIN, 1);
}

