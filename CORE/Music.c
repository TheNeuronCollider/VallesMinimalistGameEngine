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

typedef struct MUSIC_REG{
	Mix_Music * track;
	char name [50];
}Track;

Track arr_music[50];

int  index_loadedMusic = 0;
char fileName        [100];
char filePath        [1001];
char currentlyPlaying[100];

Track * GET_TRACK(char * name){
	for(int i = 0; i < index_loadedMusic; i+=1){
		if (0 == strcmp(name, arr_music[i].name)){
			return &arr_music[i];
		}
	}
	
	return NULL;
}

void PRELOAD_BGM(char * name){
	
	/* Aborting the load if the music has been already loaded */
	if (NULL!=GET_TRACK(name))
		return;

	/* Concatenating ".mp3" to the file name */
	fileName[0] = '\0';
	strcat(fileName,name);
	strcat(fileName,".mp3");
	
	/* Getting the directory where the file is located */
	filePath[0] = '\0';
	FINDFILEPATH(filePath,1001,fileName);
	
	/* Once we have the path, we load the music and we store it with all the
	related data inside the correct registry */
	arr_music[index_loadedMusic].name[0] = '\0';
	strcat(arr_music[index_loadedMusic].name,name);
	arr_music[index_loadedMusic].track = Mix_LoadMUS( filePath );
	
	/* There is a limit of how many music tracks can be loaded. We show and
	error if that limit is reached.*/
	index_loadedMusic += 1;
	if (index_loadedMusic == 50)
		SHOW_ERROR("Error","Cannot load more than 50 music tracks (mp3)");
	
	return;
}

void PLAY_BGM (char * name){
	PRELOAD_BGM(name);
	Track * t;
	t = GET_TRACK(name);
	Mix_PlayMusic(t->track, -1);
	RESUME_BGM();
	return;
}

void PAUSE_BGM (){
	
	Mix_PauseMusic();
	return;
}

void RESUME_BGM(){
	
	Mix_ResumeMusic();
	return;
}

void FREE_BGM (){
	Mix_HaltMusic();
	for(int i = 0; i < index_loadedMusic; i+=1){
		
		Mix_FreeMusic(arr_music[i].track);
	}
	index_loadedMusic = 0;
	return;
}


