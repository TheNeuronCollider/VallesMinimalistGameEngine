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

#include <EntityData.h>
#include <vminimalist.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SET_BEHAVIOR_FUNCTION(EntityData* _EData, void(*ptrFN)(EntityData*)){
	_EData->ptrBehaviorFN = ptrFN;
}

void SET_DELETION_FUNCTION( EntityData* _EData, void(*ptrFN)(void *)){
	_EData->ptrDestructor = ptrFN;
}

void SET_NAME(EntityData * _EData, char * name){
	strcpy(_EData -> name, name);
}

char * GET_NAME(EntityData * _EData){
	return _EData -> name;
}

void SET_CLASS_NAME(EntityData * _EData, char * className){
	strcpy(_EData -> className, className);
}

char * GET_CLASS_NAME(EntityData* _EData){
	return _EData -> className;
}

void SET_SIZE(EntityData* _EData, double w, double h){
	_EData -> w = w;
	_EData -> h = h;
}

double GET_WIDTH(EntityData* _EData){
	return _EData->w;
}

double GET_HEIGHT(EntityData* _EData){
	return _EData->h;
}

void SET_POS(EntityData* _EData, double x, double y){
	_EData -> x = x;
	_EData -> y = y;
}

void 	SET_POS_X(EntityData *_EData, double x){
	_EData -> x = x;
}

void 	SET_POS_Y(EntityData *_EData, double y){
	_EData -> y = y;
}

void TRANSLATE(EntityData* _EData, double x, double y){
	SET_POS(_EData, GET_POS_X(_EData) + x, GET_POS_Y(_EData) + y);
}

double GET_POS_X(EntityData* _EData){
	return _EData->x;
}

double GET_POS_Y(EntityData* _EData){
	return _EData->y;
}

void CONFIG_ENTITY_DATA(EntityData * _EData){
	
	_EData->x = 0; 
	_EData->y = 0;
	_EData->w = 32;
	_EData->h = 32;
	_EData->markedForDeletion = 0;
	_EData->isActive = 1;
	_EData->entity = 0;
	_EData->id = 0;
	_EData->ptrBehaviorFN = 0;
	_EData->ptrDestructor = 0;
	_EData->frame = 0;
	_EData->paused = 0;
	_EData->detectable = 1;
	_EData->collisionWeight = 0;
	_EData->index_colliders = 0;
	_EData->index_collData_raw = 0;
	_EData->index_collData_lastRaw = 0;
	_EData->index_collData_enter = 0;
	_EData->index_collData_stay = 0;
	_EData->index_collData_exit = 0;
	_EData->index_poll_enter = 0;
	_EData->index_poll_stay = 0;
	_EData->index_poll_exit = 0;
	strcpy(_EData->name, "NONAME");
	strcpy(_EData->className, "NOCLASSNAME");
	strcpy(_EData->animationName, "NOANIMATIONNAME");

	return;
}


void * GET_CUSTOM_ENTITY(EntityData * _EData){
	char errMsg[1000] = {};
	strcat(errMsg,"You are trying to get the custom entity of ");
	strcat(errMsg,_EData->className);
	strcat(errMsg," but it has no custom entity attached");
	if (_EData -> entity == 0){
		SHOW_ERROR("Error", errMsg);
	}
	return _EData -> entity;
}

int GET_ID(EntityData* _EData){
	return _EData -> id;
}

void SET_ACTIVE(EntityData* ent, int mode){
	ent -> isActive = mode;
}

int IS_ACTIVE(EntityData * ent){
	return ent -> isActive;
}