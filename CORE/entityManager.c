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

void CLEAN_UNUSED_INSTANCES(int _immediate){

	if (_immediate != 0 || 
	   (_immediate == 0 && count_entitiesMarkedForDeletion > _DELETED_ENTITIES_STACK_SIZE_)){
		
		/* Deallocating the instances marked for deletion, and setting all
		those pointers as 0. */
		for(int i = 0; i < storedEntities_count; i++){
			if (arr_entities[i] != 0){
				if (arr_entities[i] -> markedForDeletion == 1){
					arr_entities[i] -> ptrDestructor(arr_entities[i]);
					
					if (arr_entities[i] -> entity == 0){
						free(arr_entities[i] -> entity);
					}
					
					free(arr_entities[i]);
					arr_entities[i] = 0;
				} 
			}
		}
		
		/* All the empty pointers of the deleted entities are now placed
		at the right side of the entities array.*/
		EntityData * auxptr;
		for(int i = 0; i < _MAX_ENTITY_STORAGE_ - 1; i++){
			if(arr_entities[i] == 0 && arr_entities[i+1] !=0){
				auxptr = arr_entities[i];
				arr_entities[i] = arr_entities[i+1];
				arr_entities[i+1] = auxptr;
				i = 0;
			}
		}
		
		/* Updating indexes. */
		storedEntities_count -= count_entitiesMarkedForDeletion;
		count_entitiesMarkedForDeletion = 0;
		
	}
}	


void MEMORY_WARNINGS(){
	
	for(int i = 0; i < storedEntities_count;i++){	
		if (0 == arr_entities[i] -> ptrDestructor){
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,arr_entities[i]->name,
            "There is an entity that doesn't have a destruction function.",NULL);
		}
		
	}
}

void LINK_AND_STORE(void * _ptrEntity, EntityData * _ptrEntityData){
	
	if (storedEntities_count == _MAX_ENTITY_STORAGE_){
		SHOW_ERROR("Error","Limit of entity storage exceeded!");
		return;
	}

	_ptrEntityData->id = id_count;

	id_count ++;

	_ptrEntityData->entity = _ptrEntity;
	
	arr_entities[storedEntities_count] = _ptrEntityData;

	storedEntities_count ++;

}

void DELETE_ENTITY (EntityData * _EData){
	
	/* The entity is just marked for its deletion. The engine
	will decide when is the best moment for deallocating it */
	_EData -> markedForDeletion = 1;
	count_entitiesMarkedForDeletion ++;
	return;
}
