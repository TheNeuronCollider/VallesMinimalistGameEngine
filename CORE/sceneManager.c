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

void (*pfn_loadedLevel)(void);

void LOAD_LEVEL(void (*pfn_level)(void)){
	CLEAR_BUTTON_BUFFERS();
	pfn_loadedLevel = pfn_level;
	newLevelLoaded = 1;
	return;
}

void APPLY_LEVEL(){
	/* Dumping a "Loading" message before loading the scene */
	SHOW_LOADING_MESSAGE();
	/* Applying */
	CLEAR_BUTTON_BUFFERS();
	newLevelLoaded = 0;
	KILL_LEVEL();
	pfn_loadedLevel();
}

void KILL_LEVEL(){
	
	/* Deallocating all the entities that are currently marked for their
	deletion, then we mark the rest of the entities, and make the final 
	clean up */
	CLEAN_UNUSED_INSTANCES(1);
	for (int i = 0; i < storedEntities_count; i++){
		
		DELETE_ENTITY(arr_entities[i]);
	}
	CLEAN_UNUSED_INSTANCES(1);
	
	/* Deallocating memory used by the cameras */
	for (int i = 0; i < storedCAmeras_count; i++){
		free(arr_cameras[i]);
	}
	storedCAmeras_count = 0;
	
	// Deallocating loaded animations 
	FREE_TEXTURES_AND_STUFF();
	
	// Deallocating the loaded music tracks
	FREE_BGM();
	
	// Deallocating the loaded sounds
	FREE_SOUNDS();
	return;
}

