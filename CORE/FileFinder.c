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
#include <FileFinder.h>
#include <vminimalist.h>

void FINDFILEPATH(char * dest, int dest_size, char* filename){
	
	/* The console "dir" command is executed in order to find the file.
	The returned path is stored in a temporal text file buffer. */
	char ins [120];
	strcpy(ins,"dir ");
	strcat(ins,filename);
	strcat(ins," /s /b > FFData/fdir.txt");
	system(ins);
	
	/* Getting the path from the file buffer.*/
	FILE * file = 0;
	char path[1001];
	char c = 0;
	
	file = fopen("FFData/fdir.txt","r+");
	
	int i = 0;
	while (c != EOF){
		c = getc(file);
		path[i] = c;
		i++;
	}
	path[i-2] = '\0'; 
	
	// ERROR if the file does not exist.
	char errmsg[100];
	errmsg[0] = '\0';
	strcat(errmsg,"<<");
	strcat(errmsg,filename);
	strcat(errmsg,">> No existe");
	if(i == 1){
		SHOW_ERROR("Error",errmsg); 
		return;
	}
	
	// Error if the buffer where the path is going to be stored is to short.
	if (dest_size < 1001){
		SHOW_ERROR("Error - FILE FINDER","dest_size must be grater than 1001");
		return;
	}
	
	dest[0] = '\0';
	strcat(dest,path);
	fclose(file);
	return;
}