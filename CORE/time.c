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
void DELTA_TIME(){
	
	static Uint32 t1 = 0, t2 = 0;
	t2 = SDL_GetTicks();
	deltaTime = t2 - t1;
	deltaDumped = 0;
	if(deltaTime >= 20){
		deltaTime = 20;
		deltaDumped = 1;
	}
	t1 = SDL_GetTicks();
}

double GET_DELTAT(){
	return (double)deltaTime / 1000;
}

double GET_TIME(){
	return (double)SDL_GetTicks();
}