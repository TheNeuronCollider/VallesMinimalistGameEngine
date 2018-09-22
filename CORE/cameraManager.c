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


void RECORD_CAMS(){
	
	/* Before recording with the cameras, we order them accordingly to their
	render priority values. Cameras with lower render priority display their
	captures first than the other ones.*/
	
	Camera * auxCam;
	for(int i = 0; i < storedCAmeras_count-1; i++){
		if (arr_cameras[i]->render_priority >
		    arr_cameras[i+1]->render_priority){
			
			auxCam = arr_cameras[i];
			arr_cameras[i] = arr_cameras[i+1];
			arr_cameras[i+1] = auxCam;
			
			i = 0;
		}
	}
	
	
	/* Cameras now take a photo of the current frame. All entities are iterated
	for each camera and pass through some filters that determine if the entity
	must be seen or ignored by the camera in context.
	*/
	static SDL_Surface * auxFrameSurface;
	static SDL_Rect auxRect;

	for (int cam_i = 0; cam_i < storedCAmeras_count; cam_i++){
		
		Camera * contextCam;
		contextCam = arr_cameras[cam_i];
		
		for (int ent_i = 0; ent_i < storedEntities_count; ent_i++){
			
			EntityData * contextEnt;
			contextEnt = arr_entities[ent_i];
			
			if(contextEnt->markedForDeletion){
				continue;
			}

			/* Aborting if the context entity is inactive */
			if ( ! IS_ACTIVE(arr_entities[ent_i]) ){
				continue;
			}
			
			/* FILTER 1:
			The camera must be allowed to record this class of entity */
			if (0 == CAM_HAS_CLASS_NAME
			   (contextCam, contextEnt -> className)){
				
				/* FILTER 2:
				The entity must be inside the field of view of the camera*/
				if(0 == CAM_SEES_ENTITY(contextCam, contextEnt)){
					
					/* Filter 3:
					The entity must have an animation to show */
					if (0!=strcmp(contextEnt->animationName,"NOANIMATIONNAME")){
						
						auxFrameSurface = GET_FRAME_SURFACE
						(contextEnt->animationName,contextEnt->frame);

						/* Calculating the aspect ratio of the entities' size
						and position inside the camera that records them, then
						the entities' images are sent to the backbuffer keeping
						their aspect ratios */
						auxRect.x = ((double)SCREEN_DEFINITION_X/100)*
						            ((contextEnt->x - contextCam->x)/
								     (contextCam->w / 100));
							
						auxRect.y = ((double)SCREEN_DEFINITION_Y / 100)*
						            ((contextEnt->y - contextCam->y)/
								     (contextCam->h / 100));
										
						auxRect.h = ((double)SCREEN_DEFINITION_Y) /
						            (contextCam->h / contextEnt->h);
										
						auxRect.w = ((double)SCREEN_DEFINITION_X) /
						            (contextCam->w / contextEnt->w);
	
							
						SDL_BlitScaled(auxFrameSurface,NULL,backBuffer,&auxRect);
					
					}
					
				}
				
			}
			
		}
		
	}
	
}

void STORE_CAMERA(Camera * cam){
	if (storedCAmeras_count == _MAX_CAM_STORAGE_){
		SHOW_ERROR("Error","No se pueden almacenar tantas cámaras.");
		return;
	}
	arr_cameras[storedCAmeras_count] = cam;
	storedCAmeras_count ++;
}



