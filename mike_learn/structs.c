/* Laboratory Exercise Working with Structs

#include <stdio.h>
#include <string.h>
#include "MyroC.h"
#include "eSpeakPackage.h"

typedef struct
{
  int pitch;
  double duration;
} noteType;

void playSong (char * title, noteType song[], int numNotes)
{
  eSpeakTalk ("I am singing the ");
  eSpeakTalk (title);
  int i;
  for (i=0; i<numNotes; i++)
    rBeep(song[i].duration, song[i].pitch);
}

void adjustNoteLength (noteType * note, double adjustment)
{
  (*note).duration = (*note).duration * adjustment;
}

int main()
{
  eSpeakConnect ();
  rConnect ("/dev/rfcomm0");
  char title[20] = {"The Pho"};
  noteType song[3] = {
    {880, 1},
    {680, 1},
    {1020,1}};
  playSong (title, song, 3);
  int i;
  for (i = 0; i < 3; i++)
    {
      adjustNoteLength (&song[i], 0.5);
    }
  playSong (title, song, 3);
  eSpeakDisconnect();
  rDisconnect ();
  return 0;
}

*/
