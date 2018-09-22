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

#define _MAX_AUDIO_COUNT_ 200

int i_loadedIndex;

typedef struct SFX_REGISTRY{
	char name [100];
	Mix_Chunk * sound;
}SfxReg;

SfxReg arr_sfx[_MAX_AUDIO_COUNT_];

void PRELOAD_SFX(char * sound){
	
	/* Aborting the function if the sound has been already loaded.*/
	for (int i = 0; i < i_loadedIndex; i++){
		if (0 == strcmp(arr_sfx[i].name, sound)){
			Mix_PlayChannel( -1, arr_sfx[i].sound , 0);
			return;
		}
	}

	/* Adding the ".wav" extension to the file name */
	char fileName[100]={};
	strcat(fileName, sound);
	strcat(fileName,".wav");
	
	/* Getting the directory where the audio file is located */
	char filePath[1001]={};
	FINDFILEPATH(filePath,1001,fileName);
	
	/* Showing an error if the count of audio files loaded reaches the limit */
	if (i_loadedIndex == _MAX_AUDIO_COUNT_){
		SHOW_ERROR("Error!", "Limit of audio files loaded exceeded.");
		return;
	}
	
	/* Loading the audio file */
	strcat(arr_sfx[i_loadedIndex].name, sound);
	arr_sfx[i_loadedIndex].sound = NULL;
	arr_sfx[i_loadedIndex].sound = Mix_LoadWAV(filePath);
	i_loadedIndex ++;
}

void PLAY_SFX(char * sound){
	PRELOAD_SFX(sound);
	
	for (int i = 0; i < i_loadedIndex; i++){
		if (0 == strcmp(arr_sfx[i].name, sound)){
			Mix_PlayChannel( -1, arr_sfx[i].sound , 0);
			return;
		}
	}
	return;
}

void STOP_SFX(){
	Mix_HaltChannel(-1);
}

void FREE_SOUNDS(){
	for(int i = 0; i < i_loadedIndex ; i++){
		Mix_FreeChunk(arr_sfx[i].sound);
		arr_sfx[i].name[0] = '\0';
	}
	i_loadedIndex = 0;
}