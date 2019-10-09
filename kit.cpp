/*
 * file : kit.cpp
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

#include "kit.h"

#define peek pgm_read_byte

const byte KIT_instrumentNotes[] PROGMEM = 
{
    36, // Bass drum
    38, // Snare drum
    37, // Rim shot
    46, // Open hit hat
    44, // Foot hit hat
    42, // Closed hit hat
    51, // Ride cymbal
    49, // Crash cymbal
    53, // Ride Bell
    45, // Low tom
    47, // Mid tom
    49, // High tom
    39, // Hand clap
    54, // Tambourine
    56, // Cowbell
    75, // Clave
};

extern const char KIT_labelBassDrum[] PROGMEM = "Bass drum";
extern const char KIT_labelSnareDrum[] PROGMEM = "Snare drum";
extern const char KIT_labelRimShot[] PROGMEM = "Rim shot";
extern const char KIT_labelOpenHitHat[] PROGMEM = "Open hit hat";
extern const char KIT_labelFootHitHat[] PROGMEM = "Foot hit hat";
extern const char KIT_labelClosedHitHat[] PROGMEM = "Closed hit hat";
extern const char KIT_labelRideCymbal[] PROGMEM = "Ride cymbal";
extern const char KIT_labelCrashCymbal[] PROGMEM = "Crash cymbal";
extern const char KIT_labelRideBell[] PROGMEM = "Ride Bell";
extern const char KIT_labelLowTom[] PROGMEM = "Low tom";
extern const char KIT_labelMidTom[] PROGMEM = "Mid tom";
extern const char KIT_labelHighTom[] PROGMEM = "High tom";
extern const char KIT_labelHandClap[] PROGMEM = "Hand clap";
extern const char KIT_labelTambourine[] PROGMEM = "Tambourine";
extern const char KIT_labelCowbell[] PROGMEM = "Cowbell";
extern const char KIT_labelClave[] PROGMEM = "Clave";

const char *const KIT_instrumentLabels[] PROGMEM = 
{
    KIT_labelBassDrum,
    KIT_labelSnareDrum,
    KIT_labelRimShot,
    KIT_labelOpenHitHat,
    KIT_labelFootHitHat,
    KIT_labelClosedHitHat,
    KIT_labelRideCymbal,
    KIT_labelCrashCymbal,
    KIT_labelRideBell,
    KIT_labelLowTom,
    KIT_labelMidTom,
    KIT_labelHighTom,
    KIT_labelHandClap,
    KIT_labelTambourine,
    KIT_labelCowbell,
    KIT_labelClave,
};

#define KIT_DEFAULT_CHANNEL 1
#define KIT_DEFAULT_TYPE INSTRUMENT_TYPE_ON_OFF
#define KIT_DEFAULT_VELOCITY 127

/*******************/
/* Private methods */
/*******************/


/******************/
/* Public methods */
/******************/

KIT::KIT()
{
    initialize();
}

void KIT::initialize()
{
    for(byte index=0; index < KIT_NB_INSTRUMENTS; index++)
    {
        strcpy_P((char*)instruments[index].getDataPointer(), (char *)pgm_read_word(&(KIT_instrumentLabels[index])));
        instruments[index].setNote(peek(KIT_instrumentNotes + index));
        instruments[index].setChannel(KIT_DEFAULT_CHANNEL);
        instruments[index].setType(KIT_DEFAULT_TYPE);
        instruments[index].setVelocity(KIT_DEFAULT_VELOCITY);
    }
}

void KIT::setName(char* _name)
{
    for (byte x=0; x < INSTRUMENT_NAME_SIZE; x++)
    name[x] = *(_name + x);
}

char* KIT::getName()
{
    return name; 
}

INSTRUMENT* KIT::getInstrument(byte index)
{
    return &instruments[index]; 
}

