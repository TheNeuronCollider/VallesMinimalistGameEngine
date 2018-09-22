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

/* Here is the structure that represents game cameras, as well as the functions
for managing those cameras */

#ifndef _CAM_
#define _CAM_

#include <EntityData.h>

typedef struct CAM{
	double x,y,w,h;
	char   viewableNames [100][50];
	int    render_priority;
}Camera;

/* Configures the initial state of the camera. Acts as a "constructor".
The user must use this function always he/she creates a camera */
void CONFIG_CAM(Camera * _cam);

/* This function tells the camera which classes of entities it can see.*/
void RECORD_CLASS(Camera * _cam, char * _class);

/* Tells if a camera is allowed to see an specific class of game entity.*/
int CAM_HAS_CLASS_NAME(Camera * _cam, char * _name);

/* This function tells if an entity is inside the field of view of the camera.*/
int CAM_SEES_ENTITY(Camera * _cam, EntityData * _entity);

/* Sets the render priority of a camera. Cameras with lower values are rendered
first.*/
void SET_RENDER_PRIORITY(Camera * _cam, int priority);

/* Functions for set and get the size of the camera (its field of view)*/
void SET_CAM_SIZE(Camera * _cam, double w, double h);
double GET_CAM_WIDTH(Camera* _cam);
double GET_CAM_HEIGHT(Camera* _cam);

/* Functions for set and get the camera's position. */
void SET_CAM_POS(Camera * _cam, double x, double y);
double GET_CAM_POS_X(Camera *_cam);
double GET_CAM_POS_Y(Camera *_cam);

#endif