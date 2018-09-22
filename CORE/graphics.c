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

void INIT_SDL(){
	/* Initializing the SDL subsystems for video and audio */
	
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ){
		printf( "%s\n", SDL_GetError());
		exit(-1);
	}
	
	/* Creating the app window */
	window = SDL_CreateWindow(WINDOWNAME,   SDL_WINDOWPOS_UNDEFINED, 
	                          SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, 
							  SCREEN_HEIGHT,      SDL_WINDOW_SHOWN );
						  
	if( 0 == window ){ printf( "%s\n", SDL_GetError()); exit(-1); }
	
	/* Getting the window's surface */
	windowSurface = SDL_GetWindowSurface(window);

	/* Creating the back buffer surface where all is drawn before being shown
	at the screen. This avoids flickering */
	backBuffer = SDL_CreateRGBSurface(0,SCREEN_DEFINITION_X,SCREEN_DEFINITION_Y,
										32,      0,       0,       0,      0);
	

	/* Giving SDL the ability to load PNG images */
    if(0==(IMG_Init(IMG_INIT_PNG))){
        printf("%s\n", IMG_GetError());
    }
	
	/* Initializing the audio module using the recommended frequency and format
	by lazyfoo.net. */
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ){
       printf("Cannot initialize the audio subsystem.");  
    }
	
}

void DRAW_RENDER(){	
    
	SDL_BlitScaled (backBuffer,NULL,windowSurface,NULL);
	SDL_UpdateWindowSurface(window);
    SDL_FillRect(backBuffer, NULL, SDL_MapRGB(backBuffer->format, 5, 5, 5));
	return;
}

void SHOW_LOADING_MESSAGE(){
	static SDL_Surface * loadingMSG = NULL;
	char path [1002];
	if (NULL == loadingMSG){
		FINDFILEPATH(path,1001,"__l_o_ad_ing_ms_g__.png");
		loadingMSG = IMG_Load(path);
	}
	
	SDL_BlitScaled (loadingMSG,NULL,windowSurface,NULL);
	SDL_UpdateWindowSurface(window);
}
