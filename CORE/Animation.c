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

int           loaded_count = 0;
int			  i_forCut = 0;
int           fwidth;
int           fheight;
int           frames;
AnimReg       animations[_MAX_ANIM_NUMBER_];
SDL_Surface * sheet;

int LOAD_SHEET_AND_META(char * name){
	
	/* Before loading, we check if the animation has not been loaded yet.*/
	for(int i = 0; i < loaded_count; i++){
		if(0 == strcmp(animations[i].name,name)){
			return -1;
		}
	}
	
	/* Before loading, we check the name length, can't be so long */
	if (strlen(name) > 50){
		SHOW_ERROR("Error", "Animation names must be smaller than 50 chars.");
		return -1;
	}
	
	/* Loading metadata.*/
	
	strcpy(animations[loaded_count].name,name);
	
	char filewithext [54] = {};
	strcat(filewithext, name);
	strcat(filewithext, ".txt");
	
	char path [1001]; 
	FINDFILEPATH(path,1001,filewithext);
	
	FILE * meta;
	meta = fopen(path,"r+");
	
	char forwhich = ' '; int value; char c;
	c = 'a';
	while (c != EOF){
		
		c = getc(meta);
		if (c == 'w'|| c == 'h' || c == 'f'){ 
			forwhich = c; value=0; continue;
		}
		
		if ((c - 48) >= 0 && (c - 48) <= 9){
			value *= 10;
			value += c - 48;
			
			if (forwhich == 'w'){fwidth = value;}
			if (forwhich == 'h'){fheight = value;}
			if (forwhich == 'f'){frames = value;}
		}
	}
	
	fclose(meta);
	
	/* Loading the sprite sheet */
	for (int i = 0; i < 1001; i++){
		if(path[i] == '\0'){
			path[i-3] = 'p'; path[i-2] = 'n'; path[i-1] = 'g'; path[i-0] = '\0';
			break;
		}
	}
	
	sheet = IMG_Load(path);
	
	char errMsg[100] = {};
	if (sheet == NULL){
		strcat(errMsg,"The SpriteSheet ");
		strcat(errMsg,path);
		strcat(errMsg, " does not exist!");
		SHOW_ERROR("Error",errMsg);
	}
	
	/* Closing */
	
	i_forCut = loaded_count;
	loaded_count += 1;
	
	return 0;
}

void CUT_LOADED_SHEET(){
	
	/* Preparing the animation registry in context for storing the animation
	data */
	
	AnimReg * reg = &animations[i_forCut];
	
	reg->numOf_frames = frames;
	reg->w            = fwidth;
	reg->h            = fheight;

	//reg->frames       = malloc(frames * sizeof(SDL_Surface*));
	
	for (int i = 0; i < frames; i++){
		//reg->arr_frames[i] = malloc(sizeof(SDL_Surface*));
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
			reg->arr_frames[i] = SDL_CreateRGBSurface(0,fwidth,fheight,32,
			0xFF000000, 0x00FF0000, 0x0000FF00, 0x0000000FF);
		}else{
			reg->arr_frames[i] = SDL_CreateRGBSurface(0,fwidth,fheight,32,
			0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
		}
		
	}
	
	/* Cutting the sprite sheet and storing all the data inside the registry.*/
	
	int rows = sheet->h / fheight;
	int cols = sheet->w / fwidth;
	
	SDL_Rect cutter;
	cutter.h = fheight;
	cutter.w = fwidth;

	int current_frame = 0;
	
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			if(current_frame < frames){
				cutter.y = row * fheight;
				cutter.x = col * fwidth;
				SDL_BlitSurface(sheet,&cutter,reg->arr_frames[current_frame],NULL);
				current_frame ++;
			}
			else{
				break;
			}
		}	
	}
	return;
}

int GET_FRAME_COUNT(char * name){
	for (int i = 0; i < loaded_count; i++){
		if (0 == strcmp(animations[i].name,name)){
			return animations[i].numOf_frames;
			break;
		}
	}
}

int ANIMATION_ENDED(EntityData * entity){
	if (GET_FRAME_COUNT(GET_ANIMATION_NAME(entity)) - 1== GET_FRAME(entity)){
		return 1;
	}
	return 0;
}

void FREE_TEXTURES_AND_STUFF(){
	
	SDL_FreeSurface(sheet);
	
	for (int i = 0; i < loaded_count; i++){
		
		animations[i].numOf_frames = 0;
		strcpy(animations[i].name," ");
	
		for(int f = 0; f < animations[i].numOf_frames; f++){
			SDL_FreeSurface(animations[i].arr_frames[f]);
		}
	}
	
	loaded_count = 0;
}

AnimReg * GETCLIP (char * name){
	for (int i = 0; i < loaded_count; i++){
		if (0 == strcmp(animations[i].name, name)){
			return &animations[i];
		}
	}
	
	return 0;
}

SDL_Surface * GET_FRAME_SURFACE(char * name, int frame){
	return (GETCLIP(name) -> arr_frames[frame]);
}

void SET_ANIMATION(EntityData* _EData, char * _name, short _continuous){
	
	/* Loading the sprite sheet if it is not loaded yet */
	if (0 == LOAD_SHEET_AND_META(_name)){
		
		CUT_LOADED_SHEET();
		
	}
	
	/* Setting up the animation */
	strcpy(_EData->animationName, _name);
	_EData->frame = (_continuous) ? _EData->frame  : 0;
	
	if (_EData->frame >= GET_FRAME_COUNT(_name)){
		_EData->frame = 0;
	}
	
	return;
}

char * GET_ANIMATION_NAME(EntityData* _EData){
	return _EData->animationName;
}

void SET_FRAME(EntityData* entity, int frame){
	entity -> frame = frame;
}

int GET_FRAME(EntityData* entity){
	return entity -> frame;
}

void PERFORM_ANIMATIONS(){

	static double timeToNextFrame = 0;
	
	if(GET_TIME() > timeToNextFrame){
		
		timeToNextFrame = GET_TIME() + ANIM_FRAME_SPEED;
		
		for (int i = 0; i < storedEntities_count; i++){
			
			if(arr_entities[i]->paused){
				continue;
			}

			if(arr_entities[i]->markedForDeletion){
				continue;
			}
			
			if (strcmp(arr_entities[i]->animationName,"NOANIMATIONNAME")==0){
				continue;
			}
			
			arr_entities[i] -> frame ++;
			if (arr_entities[i]->frame >= GET_FRAME_COUNT(arr_entities[i]->animationName)){
				arr_entities[i]->frame = 0;
			}
		}
	}
}

void PAUSE_ANIMATION(EntityData * entity){
	entity -> paused = 1;
}

void UNPAUSE_ANIMATION(EntityData * entity){
	entity -> paused = 0;
}

int IS_ANIMATION_PAUSED(EntityData * entity){
	return entity -> paused;
}