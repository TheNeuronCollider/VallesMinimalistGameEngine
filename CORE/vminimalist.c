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

void START_ENGINE(){
	
	/* Initializing values */
	done 		= 0;
	id_count 	= 0;
	window 		= 0;
	storedEntities_count = 0;
	storedCAmeras_count  = 0;
	count_entitiesMarkedForDeletion = 0;
	
	for (int i = 0; i < _REGISTEREDBUTTONS_ ; i++){
		BtnBuffer_Raw   [i] = 0;
		BtnBuffer_Last  [i] = 0;
		BtnBuffer_Enter [i] = 0;
		BtnBuffer_Leave [i] = 0;
	}
	
	/* Initializing SDL */
	INIT_SDL();
	
}

void RUN_ENGINE(){
	
	while ( 0 == done ){
		/* Capturing inputs */
		CAPTURE_INPUTS();
		
		// Aplying the new level loaded.
		if (newLevelLoaded){
			APPLY_LEVEL();
		}

		/* Warns about entities that do not have destructors assigned */
		MEMORY_WARNINGS();
		
		/* Deallocates the entities marked for deletion */
		CLEAN_UNUSED_INSTANCES(1);
		
		/* Leaving the main loop if the close button is pressed */
		if (CHECK_WINDOW_CLOSE()){
			KILL_CORELOOP();
		}
		
		/* Updating animations */
		PERFORM_ANIMATIONS();
		
		/* Checking collisions between entities */
		CHECK_COLLISIONS();
		
		/* Updateing behaviors */
		PERFORM_BEHAVIORS();
		
		/* Taking the frame photo and drawing all at screen, but
		only if the current frame is in time and there is no lag.*/
		if (deltaDumped == 0){
			RECORD_CAMS();
			DRAW_RENDER();
		}
		
		/* Updating delta time */
		DELTA_TIME();

	}
	return;
}

void KILL_CORELOOP(){
	done = 1;
	return;
}

void CLOSE_ENGINE(){
	
	// Deallocating the current loaded scene.
	KILL_LEVEL();
	
	// Closing SDL subsystems.
	SDL_Quit();
}

int CHECK_WINDOW_CLOSE(){
	
	static SDL_Event event;
	while( SDL_PollEvent( &event ) != 0 ){
		if (event.type == SDL_QUIT){
			return 1;
		}
	}
	return 0;
}

void SHOW_ERROR (char * title, char * errormsg){
	
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, errormsg, NULL);
	KILL_CORELOOP();
}














