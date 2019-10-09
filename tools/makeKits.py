#!/usr/bin/python
# -*- coding: utf-8 -*-

 #
 # file : makeKits.py
 # Copyright (c) pfeuh <ze.pfeuh@gmail>
 # All rights reserved.
 # 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
 # 
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 # 
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 #

import cStringIO
import sys

TR707 = """Bass Drum l!36
Bass Drum 2!37
Snare Drum 1!38
Snare Drum 2!39
Low Tom!40
Medium Tom!41
High Tom!42
Rim Shot!43
Cowbell!44
Hand Clap!45
Tambourine!46
Closed Hit Hat1!47
Closed Hit Hat2!47
Open Hit Hat!48
Crash!49
Ride!50"""

GeneralMidi="""Ac. Bass Drum!35
Bass Drum!36
Ac. Snare Drum!38
Snare Drum!40
Low Tom!45
Medium Tom!47
High Tom!50
Side stick!37
Cowbell!56
Hand Clap!39
Tambourine!54
Closed Hit Hat!42
Pedal Hit Hat!44
Open Hit Hat!46
Crash!49
Ride!51"""

DrumBrute="""Bass Drum 1!36
Bass Drum 2!37
Snare Drum!38
Clave!41
Low Tom!47
Low Conga!46
High Tom!45
Rim Shot!40
High Conga!44
Hand Clap!39
Tambourine!51
Closed Hit Hat!42
Maracas!50
Open Hit Hat!43
Crash!49
Ride!48"""

EMPTY = ""
SPACE = ' '
INSTRUMENT_NAME_SIZE = 16
INSTRUMENT_TYPE_ON = 0
INSTRUMENT_TYPE_ON_OFF = 1
INSTRUMENT_TYPE_TRIG = 2

KIT_NAME_SIZE = 16

def formatLabel(label, max_size = 16):
    if len(label) >= max_size:
        raise Exception('label "%s" too long, %u instead of %u!\n'%(label, len(label), max_size - 1))
    line = EMPTY
    index = 0
    for car in label:
        line += "'%c', "%car
        index += 1
    line += " %u , "%0
    index +=1
    while index < (max_size ):
        line += "'%c', "%SPACE
        index += 1
    return line

def getInstruments(text, kit_name, channel, type, velocity):
    fp = cStringIO.StringIO(text)
    lines = [line.strip().split('!') for line in fp.readlines()]
    text = "const byte %s[] PROGMEM =\n{\n"%kit_name

    # adding label
    for item in lines:
        name = item[0]
        note = item[1]
        line = "    " + formatLabel(name, INSTRUMENT_NAME_SIZE)
        # adding note
        line += "%u, "%int(note)
        # adding params
        params = (channel - 1) | (type << 4) 
        line += "0x%02x, "%params
        # adding velocity
        line += "0x%02x, "%velocity
        # adding LF
        text += line + '\n'
    text += "};\n\n"
    
    return text
    
def getDrumKits(labels, max_size):
    text = EMPTY
    # adding labels
    for label in labels:
        line = "extern const byte %s PROGMEM;"%label
        text += line + '\n'
    
    # adding table of labels
    text += "const char *const string_table[] PROGMEM = {%s};\n\n"%", ".join(labels)
    return text
    
if __name__ == "__main__":
    
    #~ sys.stdout.write(getInstruments(TR707, "TR_707", 16, INSTRUMENT_TYPE_ON, 0x7f))
    #~ sys.stdout.write(getInstruments(GeneralMidi, "General_Midi", 16, INSTRUMENT_TYPE_ON, 0x7f))
    #~ sys.stdout.write(getInstruments(DrumBrute, "Drum_Brute", 16, INSTRUMENT_TYPE_ON, 0x7f))
    sys.stdout.write(getDrumKits(("TR_707", "General_Midi", "Drum_Brute"), KIT_NAME_SIZE))


