/*
  JackTrip: A Multimachine System for High-Quality Audio 
  Network Performance over the Internet

  Copyright (c) 2008 Chris Chafe, Juan-Pablo Caceres,
  SoundWIRE group at CCRMA.
  
  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation
  files (the "Software"), to deal in the Software without
  restriction, including without limitation the rights to use,
  copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following
  conditions:
  
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.
*/

/*
 * audioInfo.cpp
 */

#include "audioInfo.h"
#include <iostream>

AudioInfo::AudioInfo (int sampleRate, int bytesPerSample, int framesPerBuffer,
		      int numChans, int netChans, int secondsBetweenPlucks,
		      bool jack, clock_t * lastTick,
		      int jack_alsa_readable_offset ):
  sampleRate (sampleRate),
  bytesPerSample (bytesPerSample),
  numChans (numChans),
  netHarpStrings (netChans),
  framesPerBuffer (framesPerBuffer),
  secondsBetweenPlucks (secondsBetweenPlucks),
  jack (jack),
  jack_alsa_readable_offset (jack_alsa_readable_offset),
  lastTickTime (lastTick)
{
}

AudioInfo::~AudioInfo ()
{
}

int
AudioInfo::getSampleRate ()
{
  return (sampleRate);
}

int
AudioInfo::getBytesPerSample ()
{
  return (bytesPerSample);
}

int
AudioInfo::getNumChans ()
{
  if (getNumNetHarpStrings () > 0)
    {
      return (getNumNetHarpStrings ());
    }
  else
    {
      return (numChans);
    }
}

int
AudioInfo::getFramesPerBuffer ()
{
  return (framesPerBuffer);
}

void
AudioInfo::setFramesPerBuffer (int newFramesPerBuffer)
{
  framesPerBuffer = newFramesPerBuffer;
}

int
AudioInfo::getBytesPerBuffer ()
{
  return (getFramesPerBuffer () * getBytesPerSample () *
	  getNumChans ());
}

int
AudioInfo::getNumNetHarpStrings ()
{
  return (netHarpStrings);
}

int
AudioInfo::getNumAudioChans ()
{
  return (numChans);
}

int
AudioInfo::getSecondsBetweenPlucks ()
{
  return (secondsBetweenPlucks);
}

int
AudioInfo::getJack_alsa_readable_offset()
{
  return (jack_alsa_readable_offset);	
}

bool AudioInfo::isJack ()
{
  return (jack);
}