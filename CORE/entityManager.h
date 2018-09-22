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

/* This module is in charge of managing the memory for game entities and
cameras. It has function for registering entities and cameras for being managed
by the engine's core, as well as functions for releasing the memory they are 
using. */

#ifndef _MEMMANGR_
#define _MEMMANGR_

int id_count; 
int count_entitiesMarkedForDeletion;
int storedEntities_count;
EntityData * arr_entities[_MAX_ENTITY_STORAGE_];

void MEMORY_WARNINGS();
void CLEAN_UNUSED_INSTANCES(int _immediate);
void LINK_AND_STORE(void * _ptrEntity, EntityData * _ptrEntityData);
void DELETE_ENTITY(EntityData * _EData);

#endif

