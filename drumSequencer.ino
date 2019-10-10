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
#include "romPatterns.h"

#define console Serial
DRUM_SEQUENCER seq = DRUM_SEQUENCER();

#include "arduinoDebug.h"
ARDUINO_DEBUG debug = ARDUINO_DEBUG();

const char PROGMEM title[] = "drumSequencer v. " DRUM_SEQUENCER_VERSION "\n";
const char PROGMEM timestamp[] = __DATE__ " " __TIME__ "\n";

unsigned long int userValue = 0;
char userCommand = '\0';

void printNibble(byte value)
{
    value &= 0x0f;
    if(value < 10)
        console.write(value +'0');
    else
        console.write(value +'a' - 10);
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
        console.write(' ');
        if(x % 16 == 15)
            console.write('\n');
    }
    printByte(*(addr + 256));
    console.write('\n');
}

void printWordBin(word value)
{
    word weight = 0x8000;
    
    for(byte x = 0;x < 16; x++)
    {
        if(value & weight)
            console.print('1');
        else
            console.print('0');
        weight >>= 1;
    }
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
                console.write(*label++);
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
        console.write(' ');
        x++;
    }
}

void printBinaryPattern(byte pattern_num)
{
    PATTERN* pattern = seq.getPattern(pattern_num);
    
    console.print(F("\n\n\n\n\n\n PATTERN "));
    console.print(pattern_num + 1);
    console.print(F(" - groove "));
    console.print(pattern->getGroove());
    console.print(F(" - last_step "));
    console.print(pattern->getLastStep() + 1);
    console.write('\n');
    
    for(byte step_num = 0; step_num < PATTERN_NB_STEPS; step_num++)
    {
        printWordBin(pattern->getStep(step_num));
        console.write('\n');
    }
}

void printBinaryRomPattern(byte pattern_num)
{
    word pattern = pgm_read_word(ROM_PATTERNS_getPatternsTable() + pattern_num);
    
    console.print(F("\n\n\n\n\n\n PATTERN "));
    console.print(pattern_num + 1);
    //~ console.print(F(" - groove "));
    //~ console.print(pattern->getGroove());
    //~ console.print(F(" - last_step "));
    //~ console.print(pattern->getLastStep() + 1);
    console.write('\n');
    
    for(byte step_num = 0; step_num < PATTERN_NB_STEPS; step_num++)
    {
        printWordBin(pgm_read_word(pattern + step_num));
        console.write('\n');
    }
}

void printPattern(byte pattern_num)
{
    word weight = 0x8000;
    byte inst_num = KIT_NB_INSTRUMENTS - 1;
    
    PATTERN* pattern = seq.getPattern(pattern_num);
    KIT* kit = seq.getKit();
    
    console.print(F("\n\n\n\n\n\n PATTERN "));
    console.print(pattern_num + 1);
    console.print(F(" - groove "));
    console.print(pattern->getGroove());
    console.print(F(" - last_step "));
    console.print(pattern->getLastStep() + 1);
    console.write('\n');
    
    while(weight)
    {
        printLabel(kit->getInstrument(inst_num)->getName());
        
        for(byte step_num = 0; step_num < PATTERN_NB_STEPS; step_num++)
        {
            if(pattern->getNote(step_num, inst_num))
                console.print(F("O"));
            else
                console.print(F("-"));
        }
        
        // let's prepare next instrument line
        console.write('\n');
        weight >>= 1;
        inst_num--;
    }
}

void print_P(const char* address)
{
    while(pgm_read_byte(address))
        console.write(pgm_read_byte(address++));
}

void executeComand(char command, unsigned long int value)
{
    switch(command)
    {
        case '\0':
        case 'p':
            printPattern(value - 1);
            break;
        case 'b':
            printBinaryPattern(value - 1);
            break;
        case 'r':
            printBinaryRomPattern(value - 1);
            break;
        default:
            console.print(F("Unknown command!\n"));
            break;
    }
}

void userSequencer()
{
    while(console.available())
    {
        char c = console.read();
        switch(c)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                userValue = userValue * 10 + c - '0';
                break;
            case '\n':
                executeComand(userCommand, userValue);
                userValue = 0;
                userCommand = '\0';
                break;
            case '\r':
            case '\t':
            case ' ':
                // ignored characters
                break;
            default:
                // all the rest of ascii codes can be a command
                userCommand = c;
                break;
        }
    }
}

void setup()
{
    console.begin(9600);
    print_P(title);
    print_P(timestamp);

    pinMode(LED_BUILTIN, OUTPUT);
    
    for(byte x = 0; x < 6; x++)
        ROM_PATTERN_copy(seq.getPattern(x), x);
}

void loop()
{
    userSequencer();

    if(millis() & 0x200)
        digitalWrite(LED_BUILTIN, 0);
    else
        digitalWrite(LED_BUILTIN, 1);
}

