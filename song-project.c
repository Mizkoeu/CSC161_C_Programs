
    /***********************************************************************
     * Name(s)    Nora Schoenle and Mike Zou                               *
     * Box(s):    4529 and 4642                                                      *
     * Assignment name:      Song Project                                  *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for Monday Sept. 12, 2016                                          *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    "The Parting Glass" Sheet Music found at                         *
     *      http://www.music-for-music-teachers.com/parting-glass.html     *
     *   Help obtained                                                     *
     *     none.                   *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

#include "MyroC.h"        //use robot library
#include "eSpeakPackage.h" //use eSpeak Library
#include "scale-notes.h" //use a predefined set of Western pitches

/* 
Plays first phrase of song.
*/
void phrase_1 ()
{
  eSpeakTalk ( "Playing Phrase 1");
  rBeep (.5,pitchA5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchF5);
  rBeep (1,pitchD5);
  rBeep (1,pitchD5);
  rBeep (.5,pitchC5);
  rBeep (.5,pitchD5);
  rBeep (1,pitchF5);
  rBeep (1,pitchF5);
  rBeep (1,pitchG5);
  
}

/*
Plays second phrase of song
 */
void phrase_2 ()
{
  eSpeakTalk ( "Playing Phrase 2");
  rBeep (.5,pitchF5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchA5);
  rBeep (1,pitchA5);
  rBeep (.5,pitchA5);
  rBeep (.5,pitchG5);
  rBeep (.5,pitchF5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchA5);
  rBeep (1,pitchC5);
  rBeep (1,pitchC5);
         
}
/*
Plays third phrase of song
 */
void phrase_3 ()
{
  eSpeakTalk ("Playing Phrase 3");
  rBeep (.5,pitchF5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchA5);
  rBeep (1,pitchD6);
  rBeep (1,pitchC6);
  rBeep (.5,pitchA5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchF5);
  rBeep (1,pitchD5);
  rBeep (1,pitchD5);
  
}
/*
Plays fourth phrase of song
 */
void phrase_4 ()
{
  eSpeakTalk ( "Playing Phrase 4");
  rBeep (1,pitchA5);
  rBeep (.5,pitchC6);
  rBeep (.5,pitchA5);
  rBeep (1,pitchD6);
  rBeep (1.5,pitchC6);
  rBeep (.5,pitchA5);
  rBeep (.5,pitchC6);
  rBeep (.5,pitchA5);
  rBeep (1,pitchD6);
  rBeep (1.5,pitchC6);
}

/*
Plays fifth  phrase of song
 */
void phrase_5 ()
{
  eSpeakTalk ( "Playing Phrase 5");
  rBeep (.5,pitchA5);
  rBeep (1,pitchBf5);
  rBeep (1,pitchA5);
  rBeep (1,pitchG5);
  rBeep (.5,pitchF5);
  rBeep (.5,pitchG5);
  rBeep (1,pitchA5);
  rBeep (1,pitchC5);
  rBeep (1,pitchC5);
}

/* Plays entire song*/
void entire_song ()
{
  /* eSpeak reads song title and other pertinent information*/
   eSpeakTalk ( "Playing The Parting Glass a traditional Irish tune. Sheet music found at music for music teachers .com ");
   
  phrase_1 (); // Plays from beginning to "e'er I had"
  phrase_2 (); // Plays from "I spent" to "company"
  phrase_1 (); // Plays from "and all" to "ever done"
  phrase_3 (); // Plays from "Alas" to "but me"
  phrase_4 (); // Plays from "And all" to "of wit"
  phrase_5 (); // Plays from "to mem'ry" to "recall"
  phrase_1 (); // Plays from "So fill" to "glass"
  phrase_3 (); // Plays from "Goodnight" to end of song
}


int main ()
{
  rConnect ("/dev/rfcomm0"); //Connect to robot
  eSpeakConnect (); //Connect to eSpeak
 
  entire_song();// Plays the song.

  eSpeakTalk ("Song complete"); //Song is complete
  eSpeakDisconnect (); //Disconnect from eSpeak
  rDisconnect (); //Disconnect from robot
  return 0;  
}

  
    
