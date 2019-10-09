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

#include <arduinoDebug.h>
ARDUINO_DEBUG debug = ARDUINO_DEBUG();

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

void printLabel(char* label)
{
    byte x = 0;
    while(1)
    {
        if(*label)
        {
            if(x < INSTRUMENT_NAME_SIZE)
            {
                Serial.write(*label++);
                x++;
            }
            else
                // too long string
                break;
        }
        else
            // '\0' encountered
            break;
    }        
    while(x < INSTRUMENT_NAME_SIZE)
    {
        Serial.write(' ');
        x++;
    }
}

void printPattern(byte pattern_num)
{
    word weight = 0x8000;
    byte inst_num = KIT_NB_INSTRUMENTS - 1;
    
    PATTERN* pattern = seq.getPattern(pattern_num);
    KIT* kit = seq.getKit();
    
    while(weight)
    {
        printLabel(kit->getInstrument(inst_num)->getName());
        
        for(byte step_num = 0; step_num < PATTERN_NB_STEPS; step_num++)
        {
            if(pattern->getNote(step_num, inst_num))
                Serial.print(F("-O-"));
            else
                Serial.print(F("-.-"));
        }
        
        // let's prepare next instrument line
        Serial.write('\n');
        weight >>= 1;
        inst_num--;
    }
}

void print_P(const char* address)
{
    while(pgm_read_byte(address))
        Serial.write(pgm_read_byte(address++));
}

void setup()
{
    Serial.begin(9600);
    print_P(title);
    print_P(timestamp);

    pinMode(LED_BUILTIN, OUTPUT);
    
    //~ KIT* kit = seq.getKit();
    
    //~ for(byte index=0; index < KIT_NB_INSTRUMENTS; index++)
    //~ {
        //~ INSTRUMENT* inst = kit->getInstrument(index);
        //~ Serial.print((const char*)inst->getDataPointer());
        //~ Serial.write(' ');
        //~ Serial.print(inst->getNote());
        //~ Serial.write(' ');
        //~ Serial.print(inst->getChannel());
        //~ Serial.write(' ');
        //~ Serial.print(inst->getType());
        //~ Serial.write(' ');
        //~ Serial.print(inst->getVelocity());
        //~ Serial.write('\n');
    //~ }
    
    //~ SONG* song = seq.getSong(0);
    //~ for(byte x = 0; x < 16; x++)
        //~ song->setPattern(240 + x, x);
    //~ song->insertPattern(240, 0x33);
    //~ dumpRam(song->getDataPointer());
    
    PATTERN* pattern = seq.getPattern(0);
    //~ pattern->setNote(0,  BD, ON);
    //~ pattern->setNote(8,  BD, ON);
    //~ pattern->setNote(16, BD, ON);
    //~ pattern->setNote(24, BD, ON);

    //~ pattern->setNote(4,  SD, ON);
    //~ pattern->setNote(12, SD, ON);
    //~ pattern->setNote(20, SD, ON);
    //~ pattern->setNote(28, SD, ON);

    Serial.println(pattern->getLastStep());
    Serial.println(pattern->getGroove());
    printPattern(0);
    
    //~ dumpRam(pattern->getDataPointer());
    //~ debug.dumpRam((byte*)pattern->steps, PATTERN_NB_STEPS * sizeof(word));

}

void loop()
{
    if(millis() & 0x200)
        digitalWrite(LED_BUILTIN, 0);
    else
        digitalWrite(LED_BUILTIN, 1);
}

