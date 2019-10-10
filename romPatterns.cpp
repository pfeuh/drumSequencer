
/*
 * file : romPatterns.cpp
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
#include "romPatterns.h"
#include "pattern.h"

#define peek pgm_read_byte
#define wpeek pgm_read_word

/**********************/
/* drumkit definition */
/**********************/

#define BD 0x0001 // Bass drum
#define SD 0x0002 // Snare drum
#define RS 0x0004 // Rim shot
#define OH 0x0008 // Open hit hat
#define FH 0x0010 // Foot hit hat
#define HH 0x0020 // Closed hit hat
#define RD 0x0040 // Ride cymbal
#define CR 0x0080 // Crash cymbal
#define RB 0x0100 // Ride Bell
#define LT 0x0200 // Low tom
#define MT 0x0400 // Mid tom
#define HT 0x0800 // High tom
#define HC 001000 // Hand clap
#define TB 0x2000 // Tambourine
#define CB 0x4000 // Cowbell
#define CL 0x8000 // Clave

const word ROM_PATTERNS_billieJean[] PROGMEM = 
{
    /*  0 */ HH | BD,
    /*  1 */ 0,
    /*  2 */ HH,
    /*  3 */ 0,
    /*  4 */ HH | SD,
    /*  5 */ 0,
    /*  6 */ HH,
    /*  7 */ 0,
    /*  8 */ HH | BD,
    /*  9 */ 0,
    /* 10 */ HH,
    /* 11 */ 0,
    /* 12 */ HH | SD,
    /* 13 */ 0,
    /* 14 */ HH,
    /* 15 */ 0,
    /* 16 */ HH | BD,
    /* 17 */ 0,
    /* 18 */ HH,
    /* 19 */ 0,
    /* 20 */ HH | SD,
    /* 21 */ 0,
    /* 22 */ HH,
    /* 23 */ 0,
    /* 24 */ HH | BD,
    /* 25 */ 0,
    /* 26 */ HH,
    /* 27 */ 0,
    /* 28 */ HH | SD,
    /* 29 */ 0,
    /* 30 */ HH,
    /* 31 */ 0,
};

const word ROM_PATTERNS_captainKuku[] PROGMEM = 
{
    /*  0 */ HH | BD,
    /*  1 */ 0,
    /*  2 */ HH,
    /*  3 */ 0,
    /*  4 */ HH | SD,
    /*  5 */ 0,
    /*  6 */ HH,
    /*  7 */ 0,
    /*  8 */ HH | BD,
    /*  9 */ 0,
    /* 10 */ HH,
    /* 11 */ 0,
    /* 12 */ HH | SD,
    /* 13 */ 0,
    /* 14 */ HH,
    /* 15 */ 0,
    /* 16 */ HH | BD,
    /* 17 */ 0,
    /* 18 */ HH | BD,
    /* 19 */ 0,
    /* 20 */ HH | SD,
    /* 21 */ BD,
    /* 22 */ HH,
    /* 23 */ 0,
    /* 24 */ HH | BD,
    /* 25 */ 0,
    /* 26 */ HH,
    /* 27 */ BD,
    /* 28 */ HH | SD,
    /* 29 */ 0,
    /* 30 */ OH,
    /* 31 */ 0,
};

const word ROM_PATTERNS_bossaNova[] PROGMEM = 
{
    /*  0 */ HH | BD,
    /*  1 */ 0,
    /*  2 */ HH | 0,
    /*  3 */ 0,
    /*  4 */ SD | HH,
    /*  5 */ 0,
    /*  6 */ HH | BD,
    /*  7 */ 0,
    /*  8 */ HH | BD,
    /*  9 */ 0,
    /* 10 */ SD | HH,
    /* 11 */ 0,
    /* 12 */ HH,
    /* 13 */ 0,
    /* 14 */ HH | BD,
    /* 15 */ 0,
    /* 16 */ SD | HH | BD,
    /* 17 */ 0,
    /* 18 */ HH,
    /* 19 */ 0,
    /* 20 */ HH,
    /* 21 */ 0,
    /* 22 */ SD | HH | BD,
    /* 23 */ 0,
    /* 24 */ HH | BD,
    /* 25 */ 0,
    /* 26 */ HH,
    /* 27 */ 0,
    /* 28 */ SD | HH,
    /* 29 */ 0,
    /* 30 */ HH | BD,
    /* 31 */ 0,
};

const word ROM_PATTERNS_chaChaCha[] PROGMEM = 
{
    /*  0 */ CB,
    /*  1 */ 0,
    /*  2 */ 0,
    /*  3 */ 0,
    /*  4 */ CB | RS,
    /*  5 */ 0,
    /*  6 */ 0,
    /*  7 */ 0,
    /*  8 */ CB,
    /*  9 */ 0,
    /* 10 */ RS,
    /* 11 */ 0,
    /* 12 */ CB | LT,
    /* 13 */ 0,
    /* 14 */ LT,
    /* 15 */ 0,
    /* 16 */ CB,
    /* 17 */ 0,
    /* 18 */ 0,
    /* 19 */ 0,
    /* 20 */ CB | RS,
    /* 21 */ 0,
    /* 22 */ LT,
    /* 23 */ 0,
    /* 24 */ CB | LT,
    /* 25 */ 0,
    /* 26 */ 0,
    /* 27 */ 0,
    /* 28 */ CB | RS,
    /* 29 */ 0,
    /* 30 */ RS,
    /* 31 */ 0,
};

const word ROM_PATTERNS_lesCactus[] PROGMEM = 
{
    /*  0 */ HH | BD,
    /*  1 */ 0,
    /*  2 */ HH,
    /*  3 */ 0,
    /*  4 */ HH | SD,
    /*  5 */ 0,
    /*  6 */ HH | BD,
    /*  7 */ 0,
    /*  8 */ BD,
    /*  9 */ 0,
    /* 10 */ HH,
    /* 11 */ 0,
    /* 12 */ HH | SD,
    /* 13 */ 0,
    /* 14 */ HH | 0,
    /* 15 */ 0,
    /* 16 */ HH | BD,
    /* 17 */ 0,
    /* 18 */ HH,
    /* 19 */ 0,
    /* 20 */ HH | SD,
    /* 21 */ 0,
    /* 22 */ HH | BD,
    /* 23 */ 0,
    /* 24 */ HH | BD,
    /* 25 */ 0,
    /* 26 */ HH,
    /* 27 */ 0,
    /* 28 */ HH | SD,
    /* 29 */ 0,
    /* 30 */ HH,
    /* 31 */ 0,
};

const word ROM_PATTERNS_peterGunn[] PROGMEM = 
{
    /*  0 */ HH | BD,
    /*  1 */ 0,
    /*  2 */ HH,
    /*  3 */ 0,
    /*  4 */ HH | SD,
    /*  5 */ 0,
    /*  6 */ HH,
    /*  7 */ 0,
    /*  8 */ BD,
    /*  9 */ 0,
    /* 10 */ HH | BD,
    /* 11 */ 0,
    /* 12 */ HH | SD,
    /* 13 */ 0,
    /* 14 */ HH | 0,
    /* 15 */ 0,
    /* 16 */ HH | BD,
    /* 17 */ 0,
    /* 18 */ HH,
    /* 19 */ 0,
    /* 20 */ HH | SD,
    /* 21 */ 0,
    /* 22 */ HH | BD,
    /* 23 */ 0,
    /* 24 */ HH | BD,
    /* 25 */ 0,
    /* 26 */ HH,
    /* 27 */ 0,
    /* 28 */ HH | SD,
    /* 29 */ 0,
    /* 30 */ HH,
    /* 31 */ 0,
};

const word* const ROM_PATTERNS_patterns[] PROGMEM =
{
    ROM_PATTERNS_billieJean,
    ROM_PATTERNS_captainKuku,
    ROM_PATTERNS_bossaNova,
    ROM_PATTERNS_chaChaCha,
    ROM_PATTERNS_lesCactus,
    ROM_PATTERNS_peterGunn,
};

#define ROM_PATTERNS_NB_PATTERNS (sizeof(ROM_PATTERNS_patterns) / sizeof(word))

const byte ROM_PATTERNS_grooves[] PROGMEM = 
{
        PATTERN_GROOVE_DOUBLE_CROCHE, // billieJean
        PATTERN_GROOVE_DOUBLE_CROCHE, // captainKuku
        PATTERN_GROOVE_DOUBLE_CROCHE, // bossaNova
        PATTERN_GROOVE_DOUBLE_CROCHE, // chaChaCha
        PATTERN_GROOVE_DOUBLE_CROCHE, // lesCactus
        PATTERN_GROOVE_DOUBLE_CROCHE, // peterGunn
};

const byte ROM_PATTERNS_lastStep[] PROGMEM = 
{
        31, // billieJean
        31, // captainKuku
        31, // bossaNova
        31, // chaChaCha
        31, // lesCactus
        31, // peterGunn
};

void ROM_PATTERN_copy(PATTERN* pattern, byte rom_pattern_num)
{
    const word* rom_ptr = wpeek(&(ROM_PATTERNS_patterns[rom_pattern_num]));
    for(byte step_num = 0;step_num < PATTERN_NB_STEPS; step_num++)
        pattern->setStep(step_num, wpeek(rom_ptr + step_num));
    pattern->setGroove(peek(ROM_PATTERNS_grooves + rom_pattern_num));
    pattern->setGroove(peek(ROM_PATTERNS_lastStep + rom_pattern_num));
};

word ROM_PATTERNS_getPatternsTable()
{
    return (word)ROM_PATTERNS_patterns;
}
//~ const word ROM_PATTERNS_[] = 
//~ {
    //~ /*  0 */ 0,
    //~ /*  1 */ 0,
    //~ /*  2 */ 0,
    //~ /*  3 */ 0,
    //~ /*  4 */ 0,
    //~ /*  5 */ 0,
    //~ /*  6 */ 0,
    //~ /*  7 */ 0,
    //~ /*  8 */ 0,
    //~ /*  9 */ 0,
    //~ /* 10 */ 0,
    //~ /* 11 */ 0,
    //~ /* 12 */ 0,
    //~ /* 13 */ 0,
    //~ /* 14 */ 0,
    //~ /* 15 */ 0,
    //~ /* 16 */ 0,
    //~ /* 17 */ 0,
    //~ /* 18 */ 0,
    //~ /* 19 */ 0,
    //~ /* 20 */ 0,
    //~ /* 21 */ 0,
    //~ /* 22 */ 0,
    //~ /* 23 */ 0,
    //~ /* 24 */ 0,
    //~ /* 25 */ 0,
    //~ /* 26 */ 0,
    //~ /* 27 */ 0,
    //~ /* 28 */ 0,
    //~ /* 29 */ 0,
    //~ /* 30 */ 0,
    //~ /* 31 */ 0,
//~ };




