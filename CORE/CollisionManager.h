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

/* This module is in charge of detecting collisions between entities. It also
offers functions for adding colliders to the entities, and for setting up 
all kinds of parameters involved in collision detection. */

#ifndef _COLLISION_MANAGER_
#define _COLLISION_MANAGER_

#include <EntityData.h>

/* Triggers the collision checking. */
void CHECK_COLLISIONS();

/* These functions add colliders in form of circles or rectangles. */
void ADD_COLLIDER_RECT(EntityData* _EData,int x, int y, int w, int h);
void ADD_COLLIDER_CIRCLE(EntityData* _EData, int x, int y,int r);

/* These functions are used to know if an entity has just collided, or still
colliding, or stopped colliding. */
EntityData * POLL_COLL_ENTER(EntityData* contextEntity);
EntityData * POLL_COLL_STAY(EntityData* contextEntity);
EntityData * POLL_COLL_EXIT(EntityData* contextEntity);

/* These functions enable or disable the detectable mode. When the detectable
mode is disabled, the game entity is ignored in the collision detection system.
*/
void SET_COLL_DETECTABLE(EntityData* entity, int mode);
int  IS_COLL_DETECTABLE(EntityData* entity);

/* These functions set the collision weight. This value can be used in any
context, for example: a bullet damage power, or a collision force. */
void SET_COLL_WEIGHT(EntityData* entity, double weight);
double GET_COLL_WEIGHT(EntityData* entity);

#endif