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

/* This is the core of the engine, where all the internal systems are triggered
 and managed inside the very main loop */

#ifndef _VMINIMALIST_
#define _VAMINIMALST_

#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_mixer.h>
#include <Config.h>
#include <FileFinder.h>
#include <EntityData.h>
#include <ButtonDefs.h>
#include <Cam.h>
#include <Animation.h>
#include <Vector2.h>
#include <time.h>
#include <Input.h>
#include <Music.h>
#include <SoundFX.h>
#include <CollisionManager.h>
#include <entityManager.h>
#include <cameraManager.h>
#include <sceneManager.h>
#include <behaviorManager.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

short int done;

void START_ENGINE();  
void RUN_ENGINE();
void KILL_CORELOOP();
void CLOSE_ENGINE();
void SHOW_ERROR (char * title, char * errormsg);
int  CHECK_WINDOW_CLOSE();

#endif