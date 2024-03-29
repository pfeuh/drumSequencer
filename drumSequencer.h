#ifndef drumSequencer_h
#define drumSequencer_h

/*
 * file : drumSequencer.h
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
#include "pattern.h"
#include "kit.h"
#include "song.h"

#define DRUM_SEQUENCER_VERSION "1.00"

#define DRUM_SEQUENCER_NB_PATTERNS 16
#define DRUM_SEQUENCER_NB_SONGS 4

class DRUM_SEQUENCER
{
    public:
        DRUM_SEQUENCER();
        void sequencer();
        KIT* getKit();
        PATTERN* getPattern(byte index);
        SONG* getSong(byte index);

    private:
        PATTERN patterns[DRUM_SEQUENCER_NB_PATTERNS];
        KIT kit;
        SONG songs[DRUM_SEQUENCER_NB_SONGS];
};

#endif

