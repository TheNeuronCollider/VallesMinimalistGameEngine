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

/* Here you can configure some of the core parameters of the engine.
For more details see the User Manual (Read the header comment above)*/

/* GRAPHICS
*************/

// Back buffer resolution. 
#define SCREEN_DEFINITION_X 210
#define SCREEN_DEFINITION_Y 210

// Window size.
#define SCREEN_WIDTH 630
#define SCREEN_HEIGHT 630

// How many milliseconds the animation frames last.
#define ANIM_FRAME_SPEED 50

/* CORE 
*************/

// The text displayed at above the window.
#define WINDOWNAME "Made with Valles' Minimalist Engine."

// How many entities can be stored an managed by the core.
#define _MAX_ENTITY_STORAGE_ 500

// How many cameras can exist.
#define _MAX_CAM_STORAGE_ 10

// A trigger, when the count of entities marked for deletion is larger 
//than this trigger, the memory is deallocated.
#define _DELETED_ENTITIES_STACK_SIZE_ 20

// How many colliders each entity can have.
#define _MAX_COLLIDERS_PER_ENTITY_ 10