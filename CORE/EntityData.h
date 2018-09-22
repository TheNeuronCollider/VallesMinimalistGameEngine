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

/* Here is the structure that represents the Game Entities. As well as most of
the user side functions for managing those game entities. There are few more
functions for this purpose but they are better cataloged inside other modules.*/

#ifndef _ENTITYDATA_
#define _ENTITYDATA_

#include <Config.h>
#include <Collider.h>

typedef struct ENTITYDATA EntityData;

struct ENTITYDATA{
	
	// Position and size.
	double w, h;
	double x, y;
	
	// ¿Is the entity working?
	int isActive;
	
	// Marked for being deallocated.
	short int markedForDeletion;
	
	// ID data.
	void * entity;
	int    id; 
	char   name[100];
	char   className[100];

	// Pointer to the function that acts as behavior.
	void (*ptrBehaviorFN)(EntityData*);
	
	// Pointer to the function that deallocates the custom entity.
	void (*ptrDestructor)(void * _entity);
	
	// Animation data.
	int frame;
	char animationName [100];
	int paused;
	
	// Collision data.
	short int detectable; 
	double    collisionWeight; 
	
	int index_poll_enter;
	int index_poll_stay;
	int index_poll_exit;

	int index_colliders;
	Collider arr_colliders[_MAX_COLLIDERS_PER_ENTITY_];
	
	int index_collData_raw;
	EntityData * arr_collData_raw [_MAX_ENTITY_STORAGE_];
	
	int index_collData_lastRaw;
	EntityData * arr_collData_lastRaw[_MAX_ENTITY_STORAGE_];
	
	int index_collData_enter;
	EntityData * arr_collData_enter[_MAX_ENTITY_STORAGE_];
	
	int index_collData_stay;
	EntityData * arr_collData_stay[_MAX_ENTITY_STORAGE_];
	
	int index_collData_exit;
	EntityData * arr_collData_exit[_MAX_ENTITY_STORAGE_];

};

int 	GET_ID  (EntityData* _EData);
void 	SET_NAME(EntityData * _EData, char * name);
char * 	GET_NAME(EntityData * _EData);
void 	SET_CLASS_NAME(EntityData * _EData, char * name);
char * 	GET_CLASS_NAME(EntityData* _EData);
void 	SET_SIZE(EntityData* _EData, double w, double h);
double 	GET_WIDTH(EntityData* _EData);
double 	GET_HEIGHT(EntityData* _EData);
void 	SET_POS(EntityData* _EData, double x, double y);
void 	SET_POS_X(EntityData *_EData, double x);
void 	SET_POS_Y(EntityData *_EData, double y);
double 	GET_POS_X(EntityData* _EData);
double 	GET_POS_Y(EntityData* _EData);
void	TRANSLATE(EntityData* _EData, double x, double y);
void 	CONFIG_ENTITY_DATA(EntityData * _EData);
void * 	GET_CUSTOM_ENTITY(EntityData * _EData);
void 	SET_BEHAVIOR_FUNCTION(EntityData*_EData,void(*ptrFN)(EntityData*));
void 	SET_DELETION_FUNCTION(EntityData*_EData,void(*ptrFN)(void*));
void 	SET_ACTIVE(EntityData* ent, int mode);
int 	IS_ACTIVE(EntityData * ent);
						  
#endif