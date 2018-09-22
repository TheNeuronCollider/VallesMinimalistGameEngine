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

#include <vminimalist.h>

void CONFIG_CAM(Camera * _cam){
	
	_cam -> x = 0;
	_cam -> y = 0;
	_cam -> w = SCREEN_DEFINITION_X;
	_cam -> h = SCREEN_DEFINITION_Y;
	_cam -> render_priority = 0;
	
	for(int i = 0; i < 100; i++){
		strcpy(_cam->viewableNames[i], "NOCLASSNAME");
	};
	
	return;
}

void RECORD_CLASS(Camera * _cam, char * _class){
	
	for (int i = 0; i < 100; i++){
		if (0 == strcmp(_cam->viewableNames[i], "NOCLASSNAME")){
			strcpy(_cam->viewableNames[i],_class);
			return;
		}
	}
	
	SHOW_ERROR("Error", "Exceeded limit of how many classes of entities a \
	                    camera can have");
}

int CAM_HAS_CLASS_NAME(Camera * _cam, char * _name){
	for (int i = 0; i < 20; i++){
		if (0 == strcmp(_cam->viewableNames[i], _name)){
			return 0;
		}
	}
	return -1;
}

int CAM_SEES_ENTITY(Camera * _cam, EntityData * _entity){
	
	double t1 = _cam->y;
	double l1 = _cam->x;
	double b1 = _cam->h + t1;
	double r1 = _cam->w + l1;
	
	double t2 = _entity->y;
	double l2 = _entity->x;
	double b2 = _entity->h + t2;
	double r2 = _entity->w + l2;
	
	
	if (t1 > b2 || l1 > r2 || b1 < t2  || r1 < l2){
		return -1;
	}
	
	return 0;
}


void SET_RENDER_PRIORITY(Camera * _cam, int priority){
	_cam -> render_priority = priority;
}

void SET_CAM_SIZE(Camera * _cam, double w, double h){
	_cam -> w = w;
	_cam -> h = h;
}

double GET_CAM_WIDTH(Camera* _cam){
	return _cam->w;
}

double GET_CAM_HEIGHT(Camera* _cam){
	return _cam->h;
}

void SET_CAM_POS(Camera * _cam, double x, double y){
	_cam -> x = x;
	_cam -> y = y;
}

double GET_CAM_POS_X(Camera *_cam){
	return _cam->x;
}

double GET_CAM_POS_Y(Camera *_cam){
	return _cam->y;
}

