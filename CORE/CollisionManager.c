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

#include <CollisionManager.h>
#include <vminimalist.h>
#include <Collider.h>
#include <Math.h>

int  ARE_COLLIDING(EntityData* entA, EntityData* entB);
void CLEAR_RAW_COLLISIONS();
void CLEAR_COLLISION_CATEGORIES();
void SAVE_LAST_RAW_COLLISIONS();
void CATALOG_COLLISIONS();
void REGISTER_RAW_COLLISIONS(EntityData* entA, EntityData* entB);
int  CHECK_COLLISION_RR(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B);
int  CHECK_COLLISION_CC(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B);
int  CHECK_COLLISION_RC(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B);

int collision_matrix[_MAX_ENTITY_STORAGE_][_MAX_ENTITY_STORAGE_];

void CHECK_COLLISIONS(){
	
	SAVE_LAST_RAW_COLLISIONS();
	CLEAR_RAW_COLLISIONS();
	CLEAR_COLLISION_CATEGORIES();
	
	for (int a=0; a<storedEntities_count; a++){
		
		for(int b=0; b<storedEntities_count; b++){
			
			if(collision_matrix[a][b] == 1){
				continue;
			}

			collision_matrix[a][b] = 1;
			collision_matrix[b][a] = 1;

			if(arr_entities[a]->markedForDeletion ||
			   arr_entities[b]->markedForDeletion){
				continue;
			}
			
			if(arr_entities[a]->detectable == 0 ||
			   arr_entities[b]->detectable == 0){
			    continue;
			}
			
			if(a==b)
				continue;
			
			if (ARE_COLLIDING(arr_entities[a], arr_entities[b])){
				
				REGISTER_RAW_COLLISIONS(arr_entities[a], arr_entities[b]);
				REGISTER_RAW_COLLISIONS(arr_entities[b], arr_entities[a]);
			}
		}
	}
	
	CATALOG_COLLISIONS();

	for(int i = 0; i < _MAX_ENTITY_STORAGE_; i++){
		for(int j = 0; j < _MAX_ENTITY_STORAGE_; j++){
			collision_matrix[j][i] = 0;
		}
	}
}

int ARE_COLLIDING(EntityData* entA, EntityData* entB){

	if ( ! IS_ACTIVE(entA) || ! IS_ACTIVE(entB)){
		return 0;
	}
	
	static Vector2 aPos;
	static Vector2 bPos;
	
	for (int a=0; a < entA->index_colliders; a++){
		for(int b=0; b <entB->index_colliders; b++){
			
			aPos.x = entA->x;
			aPos.y = entA->y;
			bPos.x = entB->x;
			bPos.y = entB->y;
			
			// Checking collision RECT - RECT.
			if(entA->arr_colliders[a].type == RECT &&
			   entB->arr_colliders[b].type == RECT){
			    return CHECK_COLLISION_RR(&aPos,&bPos,
				&entA->arr_colliders[a], &entB->arr_colliders[b]);
			}
			else
			// Cheking collision CIRCLE - CIRCLE.
			if(entA->arr_colliders[a].type == CIRCLE &&
			   entB->arr_colliders[b].type == CIRCLE){
				return CHECK_COLLISION_CC(&aPos,&bPos,
				&entA->arr_colliders[a], &entB->arr_colliders[b]);
			}
			else
			// Checking collision CIRCLE - RECT.
			if(entA->arr_colliders[a].type == CIRCLE &&
			   entB->arr_colliders[b].type == RECT){
			   return CHECK_COLLISION_RC(&aPos,&bPos,
				&entB->arr_colliders[b], &entA->arr_colliders[a]);
			}
			else
			// Checking collision REC - CIRCLE.
			if(entA->arr_colliders[a].type == RECT &&
			   entB->arr_colliders[b].type == CIRCLE){
			   return CHECK_COLLISION_RC(&aPos,&bPos,
				&entA->arr_colliders[a], &entB->arr_colliders[b]); 
			}
		}
	}
	return 0;
}

void CLEAR_RAW_COLLISIONS(){
	for(int ent_i = 0; ent_i < storedEntities_count; ent_i++){
		for(int i = 0; i < arr_entities[ent_i]->index_collData_raw; i++){
			arr_entities[ent_i]->arr_collData_raw[i] = 0;
		}
		arr_entities[ent_i] -> index_collData_raw = 0;
	}
}

void CLEAR_COLLISION_CATEGORIES(){
	for (int i = 0; i < storedEntities_count; i++){
		arr_entities[i]->index_collData_enter = 0;
		arr_entities[i]->index_collData_stay  = 0;
		arr_entities[i]->index_collData_exit  = 0;
	}
}

void SAVE_LAST_RAW_COLLISIONS(){
	
	for(int ent_i = 0; ent_i < storedEntities_count; ent_i++){
		arr_entities[ent_i] -> index_collData_lastRaw 
		= arr_entities[ent_i] -> index_collData_raw;
		
		for(int i = 0; i < arr_entities[ent_i]->index_collData_raw; i++){
			arr_entities[ent_i]->arr_collData_lastRaw[i]
			= arr_entities[ent_i]->arr_collData_raw[i];
		}
	}
}

void CATALOG_COLLISIONS(){
	
	/* Cataloging the collisions for the ENTER and STAY categories. */
	static EntityData* ent;
	static int success;
	
	for(int i_entity = 0; i_entity < storedEntities_count; i_entity++){		
		
		ent = arr_entities[i_entity];
		
		for(int i_raw = 0; i_raw < ent->index_collData_raw; i_raw++){
			success = 0;
			
			for(int i_lraw = 0; i_lraw <ent->index_collData_lastRaw; i_lraw++){
				
				/* Success if the raw collision at the current frame, also
				did happen at the last one */
				if(ent->arr_collData_raw    [i_raw ] == 
				   ent->arr_collData_lastRaw[i_lraw]){
					success = 1;
					break;
				}
			}
			
			/* Success is 1 if the collision also existed at the last frame,
			so this collision is cataloged as STAY. */
			if(success){
				ent->arr_collData_stay[ent->index_collData_stay] = 
				ent->arr_collData_raw[i_raw];
				ent->index_collData_stay ++;		
			}
			/* Otherwise is an ENTER collisision */
			else{
				ent->arr_collData_enter[ent->index_collData_enter] = 
				ent->arr_collData_raw[i_raw];
				ent->index_collData_enter ++;	
			}
		}
	}
	
	/* Caso EXIT 
	Si existe algun elemento en LAST RAW que no exista en las colisiones
	RAW (frame actual) entonces se ha dejado de tocar el objeto, y
	la colisión se cataloga como EXIT.*/
	
	for(int i_entity = 0; i_entity < storedEntities_count; i_entity++){		
		ent = arr_entities[i_entity];
		
		for(int i_lraw = 0; i_lraw < ent->index_collData_lastRaw; i_lraw++){
			success = 1;
			
			for(int i_raw = 0; i_raw <ent->index_collData_raw; i_raw++){
				if( ent->arr_collData_raw    [i_raw ] == 
				    ent->arr_collData_lastRaw[i_lraw]){
					success = 0;
					break;
				}
			}
	
			if(success){
				ent->arr_collData_exit[ent->index_collData_exit] = 
				ent->arr_collData_lastRaw[i_lraw];
				
				ent->index_collData_exit ++;
			}	
		}
	}


}


void REGISTER_RAW_COLLISIONS(EntityData* entA, EntityData* entB){
	entA -> arr_collData_raw[entA -> index_collData_raw] = entB;
	entA -> index_collData_raw ++;

	//entB -> arr_collData_raw[entB -> index_collData_raw] = entA;
	//entB -> index_collData_raw ++;

	return;
}

int CHECK_COLLISION_RR(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B){
	/* Para detectar la colisión obtenemos la ubicación global de
	las caras TOP, LEFT, RIGHT y BOTTOM de ambos colliders.
	
	Las posiciones globales se obtienen sumando las posiciones 
	de los colliders a las posiciones de sus entidades dueñas, y
	en los casos de Bottom y Rigth sumando además la anchura y altura
	del collider*/
	
	static double A_left;	/* */ A_left   = entAPos->x + A->x; 
	static double A_right;	/* */ A_right  = entAPos->x + A->x + A->w;
 	static double A_top;	/* */ A_top    = entAPos->y + A->y; 
	static double A_bottom;	/* */ A_bottom = entAPos->y + A->y + A->h;
	
	static double B_left;	/* */ B_left   = entBPos->x + B->x; 
	static double B_right;	/* */ B_right  = entBPos->x + B->x + B->w;
 	static double B_top;	/* */ B_top    = entBPos->y + B->y; 
	static double B_bottom;	/* */ B_bottom = entBPos->y + B->y + B->h;
	
	// Si las cajas están fuera una de otra, no hay colisión.
	if (A_left > B_right  || A_right < B_left ||
	    A_top  > B_bottom || A_bottom < B_top){
		return 0;
	}
	return 1;
}

int CHECK_COLLISION_CC(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B){
	
	/* La colisión de dos círculos se detecta obteniendo dos puntos con
	las coordenadas globales de ambos círculos y revisando si la distancia
	entre estos dos puntos es menor a la suma de ambos radios. 
	
	Para obtener las coordenadas globales se suman las coordenadas de los
	colliders a las coordenadas de las entidades que son dueñas de los
	colldiders. */
	static Vector2 p1;
	static Vector2 p2;
	
	
	p1.x = entAPos->x + (double)A->x;
	p1.y = entAPos->y + (double)A->y;
	
	p2.x = entBPos->x + (double)B->x;
	p2.y = entBPos->y + (double)B->y;
	
	static double distance;
	distance = sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
	
	if (distance <= A->r + B->r){
		return 1;	
	}
	
	return 0;
}

int CHECK_COLLISION_RC(Vector2 *entAPos, Vector2 *entBPos,Collider*A,Collider*B){
	
	/* Para saber si un rectángulo y un círculo están colisionando,
	obtenemos dos puntos:
	
	p1: Las coordenadas globales del círculo.
	p2: Un punto dentro del rectángulo lo más cerca en X y en Y del
	punto p1, sin salir del rectángulo.
	
	Teniendo ambos puntos, si la distancia entre ellos es menor o
	igual al radio del círculo, entonces hay solución */
	
	static Vector2 p1;
	static Vector2 p2;
	
	p2.x = entBPos->x + B->x;
	p2.y = entBPos->y + B->y;
	
	p1.x = p2.x;
	p1.y = p2.y;
	
	if (p1.x < entAPos->x + A->x)
		p1.x = entAPos->x + A->x;
	
	else if (p1.x > entAPos->x + A->x + A->w) 
		p1.x = entAPos->x + A->x + A->w;
	
	if (p1.y < entAPos->y + A->y)
		p1.y = entAPos->y + A->y;
	
	else if (p1.y > entAPos->y + A->y + A->h)
		p1.y = entAPos->y + A->y + A->h;
	
	static double distance;
	distance = sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
	
	if (distance <= B->r){
		return 1;
	}
	return 0;
}

void ADD_COLLIDER_RECT(EntityData* _EData, int x, int y, 
int w, int h){

	Collider * c = &(_EData -> arr_colliders[_EData->index_colliders]);
	c -> type = RECT;
	c -> x = x;
	c -> y = y;
	c -> w = w;
	c -> h = h;
	
	_EData -> index_colliders ++;
}
										   
void ADD_COLLIDER_CIRCLE(EntityData* _EData, int x, int y,int r){
	
	Collider * c = &(_EData -> arr_colliders[_EData->index_colliders]);
	c -> type = CIRCLE;
	c -> x = x;
	c -> y = y;
	c -> r = r;	
	
	_EData -> index_colliders ++;
}

EntityData * POLL_COLL_ENTER (EntityData* contextEntity){
	if (contextEntity->index_collData_enter == 0){
		return NULL;
	}
	if (contextEntity->index_poll_enter == contextEntity->index_collData_enter){
		contextEntity->index_poll_enter = 0;
		return NULL;
	}
	
	contextEntity->index_poll_enter ++;
	return contextEntity->arr_collData_enter[contextEntity->index_poll_enter-1];

}

EntityData * POLL_COLL_STAY  (EntityData* contextEntity){
	if (contextEntity->index_collData_stay == 0){
		return NULL;
	}
	if (contextEntity->index_poll_stay == contextEntity->index_collData_stay){
		contextEntity->index_poll_stay = 0;
		return NULL;
	}
	
	contextEntity->index_poll_stay ++;
	return contextEntity->arr_collData_stay[contextEntity->index_poll_stay-1];
}

EntityData * POLL_COLL_EXIT  (EntityData* contextEntity){
	if (contextEntity->index_collData_exit == 0){
		return NULL;
	}
	if (contextEntity->index_poll_exit == contextEntity->index_collData_exit){
		contextEntity->index_poll_exit = 0;
		return NULL;
	}
	
	contextEntity->index_poll_exit ++;
	return contextEntity->arr_collData_exit[contextEntity->index_poll_exit-1];
}

void SET_COLL_DETECTABLE(EntityData* entity, int mode){
	entity->detectable = mode;
}

int  IS_COLL_DETECTABLE(EntityData* entity){
	return entity->detectable;
}

void SET_COLL_WEIGHT(EntityData* entity, double weight){
	entity->collisionWeight = weight;
}

double GET_COLL_WEIGHT(EntityData* entity){
	return entity->collisionWeight;
}
