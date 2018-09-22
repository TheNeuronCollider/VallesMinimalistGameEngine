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

/* This module is in charge of managing the animations. It loads, 
manages, updates, and deallocates animations. 

When loaded, the animations are stored inside registries, alongside their 
data, data such as name, frames, size..*/

#ifndef _ANIMLOADER_
#define _ANIMLOADER_

#define _MAX_ANIM_NUMBER_ 200

// Animation registry.
typedef struct ANIMREGISTRY AnimReg;
struct ANIMREGISTRY{
	char name [51];
	int numOf_frames;
	int w,h;
	SDL_Surface ** frames;
	SDL_Surface * arr_frames[100];
};

/* Finds and loads a sprite sheet, it reads the metadata alongside the sheet,
and keeps the info about how to cut that sheet */
int  LOAD_SHEET_AND_META(char * name);

/* Cuts the loaded sprite sheet and stores all the frames inside the context
animation registry */
void CUT_LOADED_SHEET();

/* Tells how many frames an animation has */
int  GET_FRAME_COUNT(char * name);

/* Tells if an animation has finished its current loop. */
int ANIMATION_ENDED(EntityData * entity);

/* Deallocates the memory used by all the loaded animations */
void FREE_TEXTURES_AND_STUFF();

/* Gets the animation registry that matches the given name*/
AnimReg * GETCLIP(char * name);

/* Returns the SDL surface of the given frame */
SDL_Surface * GET_FRAME_SURFACE(char * name, int frame);

/* With this function an animation is assigned to a game entity */					 
void SET_ANIMATION( EntityData* _EData, char * _animName, short _continuous);

/* Gets the name of the current animation a game entity is playing */
char * GET_ANIMATION_NAME(EntityData* _EData);

/* These functions set and get the current frame of the animation of a game 
entity */
void SET_FRAME(EntityData* entity, int frame);
int GET_FRAME(EntityData* entity);

/* Updates all the animation frames */
void PERFORM_ANIMATIONS();

/* Functions for pausing, unpausing an animation, and for knowing this state*/
void PAUSE_ANIMATION(EntityData * entity);
void UNPAUSE_ANIMATION(EntityData * entity);
int IS_ANIMATION_PAUSED(EntityData * entity);

#endif