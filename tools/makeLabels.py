#!/usr/bin/python
# -*- coding: utf-8 -*-

 #
 # file : makeLabels.py
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


EMPTY = ""
SPACE = ' '
INSTRUMENT_NAME_SIZE = 16
INSTRUMENT_TYPE_ON = 0
INSTRUMENT_TYPE_ON_OFF = 1
INSTRUMENT_TYPE_TRIG = 2

KIT_NAME_SIZE = 16

def pascalize(text):
    words = text.split()
    ret_text = "".join([word.capitalize() for word in words])
    return ret_text

def getCode(notes, labels, max_size=15):
    clabels = ["KIT_label" + pascalize(label) for label in labels]
    text = EMPTY

    #adding notes
    text += "const byte KIT_instrumentNotes[] PROGMEM = \n{\n"
    for x in range(len(labels)):
        text += "    %s, // %s\n"%(notes[x], labels[x])
    text += "};\n\n"
    
    # adding labels
    for x in range(len(labels)):
        label = labels[x]
        clabel = clabels[x]
        line = 'extern const char %s[] PROGMEM = "%s";'%(clabel, label)
        text += line + '\n'
    text += '\n'

    # adding table of labels
    text += "const char *const KIT_instrumentLabels[] PROGMEM = \n{\n"
    text += "".join(["    %s,\n"%clabel for clabel in clabels])
    text += "};\n\n"
    return text
    
if __name__ == "__main__":

    labels = ["Bass drum", "Snare drum", "Rim shot", "Open hit hat", "Foot hit hat", "Closed hit hat", "Ride cymbal", "Crash cymbal",
        "Ride Bell", "Low tom", "Mid tom", "High tom", "Hand clap", "Tambourine", "Cowbell", "Clave"]
        
    notes = [str(x) for x in (36, 38, 37, 46, 44, 42, 51, 49, 53, 45, 47, 49, 39, 54, 56, 75)]
    
    sys.stdout.write(getCode(notes, labels, KIT_NAME_SIZE))


