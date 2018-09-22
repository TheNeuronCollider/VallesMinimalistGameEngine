/*******************************************************************************
   Valles' Minimalist game Engine v1.0 - Beta.  
   
   Valles Minimalist Game Engine Copyright (C) 2018 Jorge Valles.
   
********************************************************************************
   Jorge Valles - 2018.                                                                  
   jorgevalles.contact@gmail.com                                              
                                                                            
   For more information about the usage of                                    
   this tool, you can download the                                            
   user manual at:                                                            
											                                  
        theneuroncollider.com                                                 
                                                                            
********************************************************************************
 
   Third party credits
   ~~~~~~~~~~~~~~~~~~~

   This engine uses the SDL library for graphics. 
   Visit: https://www.libsdl.org for more information about SDL.

********************************************************************************

   LICENSE
   ~~~~~~~
	
   Distributed under: GNU GPLv3.
   
   - This is free software.
   - You can modify and distribute this software.
   - You must give credit to the original work in a way that is visible to 
     the end user. Also you must mention the copyright shown at the beginning of
	 this document.
	 
   For more details about the GNU GPLv3 license, read the LICENSE file included
   in the engine's folder, or visit (https://www.gnu.org/licenses/gpl.txt).
  
*******************************************************************************/

/* This module offers a way for knowing which keys are pressed, which keys
have been just pressed, and which keys have been released. */

#ifndef _VMININPUT_
#define _VMININPUT_

short int BtnBuffer_Raw  [_REGISTEREDBUTTONS_];
short int BtnBuffer_Last [_REGISTEREDBUTTONS_];
short int BtnBuffer_Enter[_REGISTEREDBUTTONS_];
short int BtnBuffer_Leave[_REGISTEREDBUTTONS_];

/* Tells if a key is pressed */
short int GETBTN(short int _btncode);
// Tells if a key was just pressed */
short int GETBTNDOWN(short int _btncode);
// Tells if a key was released */
short int GETBTNUP(short int _btncode);
// Key input detection.
void CAPTURE_INPUTS();
// This function cleans the button buffers.
void CLEAR_BUTTON_BUFFERS();

#endif
