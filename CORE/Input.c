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

void CAPTURE_INPUTS(){
	
	const Uint8 * state = SDL_GetKeyboardState(NULL);
	
	for (int i = 0; i < _REGISTEREDBUTTONS_; i++){
	BtnBuffer_Raw [i] = 0;
	}
	
	if (state[SDL_SCANCODE_0])		
	{BtnBuffer_Raw[BTN_0] = 1;}
	if (state[SDL_SCANCODE_1])		
	{BtnBuffer_Raw[BTN_1] = 1;}
	if (state[SDL_SCANCODE_2])		
	{BtnBuffer_Raw[BTN_2] = 1;}
	if (state[SDL_SCANCODE_3])		
	{BtnBuffer_Raw[BTN_3] = 1;}
	if (state[SDL_SCANCODE_4])		
	{BtnBuffer_Raw[BTN_4] = 1;}
	if (state[SDL_SCANCODE_5])		
	{BtnBuffer_Raw[BTN_5] = 1;}
	if (state[SDL_SCANCODE_6])		
	{BtnBuffer_Raw[BTN_6] = 1;}
	if (state[SDL_SCANCODE_7])		
	{BtnBuffer_Raw[BTN_7] = 1;}
	if (state[SDL_SCANCODE_8])		
	{BtnBuffer_Raw[BTN_8] = 1;}
	if (state[SDL_SCANCODE_9])		
	{BtnBuffer_Raw[BTN_9] = 1;}
	if (state[SDL_SCANCODE_A])		
	{BtnBuffer_Raw[BTN_a] = 1;}
	if (state[SDL_SCANCODE_B])		
	{BtnBuffer_Raw[BTN_b] = 1;}
	if (state[SDL_SCANCODE_C])		
	{BtnBuffer_Raw[BTN_c] = 1;}
	if (state[SDL_SCANCODE_D])		
	{BtnBuffer_Raw[BTN_d] = 1;}
	if (state[SDL_SCANCODE_E])		
	{BtnBuffer_Raw[BTN_e] = 1;}
	if (state[SDL_SCANCODE_F])		
	{BtnBuffer_Raw[BTN_f] = 1;}
	if (state[SDL_SCANCODE_G])		
	{BtnBuffer_Raw[BTN_g] = 1;}
	if (state[SDL_SCANCODE_H])		
	{BtnBuffer_Raw[BTN_h] = 1;}
	if (state[SDL_SCANCODE_I])		
	{BtnBuffer_Raw[BTN_i] = 1;}
	if (state[SDL_SCANCODE_J])		
	{BtnBuffer_Raw[BTN_j] = 1;}
	if (state[SDL_SCANCODE_K])		
	{BtnBuffer_Raw[BTN_k] = 1;}
	if (state[SDL_SCANCODE_L])		
	{BtnBuffer_Raw[BTN_l] = 1;}
	if (state[SDL_SCANCODE_M])		
	{BtnBuffer_Raw[BTN_m] = 1;}
	if (state[SDL_SCANCODE_N])		
	{BtnBuffer_Raw[BTN_n] = 1;}
	if (state[SDL_SCANCODE_O])		
	{BtnBuffer_Raw[BTN_o] = 1;}
	if (state[SDL_SCANCODE_P])		
	{BtnBuffer_Raw[BTN_p] = 1;}
	if (state[SDL_SCANCODE_Q])		
	{BtnBuffer_Raw[BTN_q] = 1;}
	if (state[SDL_SCANCODE_R])		
	{BtnBuffer_Raw[BTN_r] = 1;}
	if (state[SDL_SCANCODE_S])		
	{BtnBuffer_Raw[BTN_s] = 1;}
	if (state[SDL_SCANCODE_T])		
	{BtnBuffer_Raw[BTN_t] = 1;}
	if (state[SDL_SCANCODE_U])		
	{BtnBuffer_Raw[BTN_u] = 1;}
	if (state[SDL_SCANCODE_V])		
	{BtnBuffer_Raw[BTN_v] = 1;}
	if (state[SDL_SCANCODE_W])		
	{BtnBuffer_Raw[BTN_w] = 1;}
	if (state[SDL_SCANCODE_X])		
	{BtnBuffer_Raw[BTN_x] = 1;}
	if (state[SDL_SCANCODE_Y])		
	{BtnBuffer_Raw[BTN_y] = 1;}
	if (state[SDL_SCANCODE_Z])		
	{BtnBuffer_Raw[BTN_z] = 1;}
	if (state[SDL_SCANCODE_DOWN])	
	{BtnBuffer_Raw[BTN_down] = 1;}
	if (state[SDL_SCANCODE_UP])		
	{BtnBuffer_Raw[BTN_up] = 1;}
	if (state[SDL_SCANCODE_LEFT])	
	{BtnBuffer_Raw[BTN_left] = 1;}
	if (state[SDL_SCANCODE_RIGHT])	
	{BtnBuffer_Raw[BTN_right] = 1;}
	if (state[SDL_SCANCODE_RETURN])	
	{BtnBuffer_Raw[BTN_return] = 1;}
	if (state[SDL_SCANCODE_ESCAPE])	
	{BtnBuffer_Raw[BTN_escape] = 1;}
	if (state[SDL_SCANCODE_LSHIFT])	
	{BtnBuffer_Raw[BTN_lshift] = 1;}
	if (state[SDL_SCANCODE_RSHIFT])	
	{BtnBuffer_Raw[BTN_rshift] = 1;}
	if (state[SDL_SCANCODE_LCTRL])	
	{BtnBuffer_Raw[BTN_lctrl] = 1;}
	if (state[SDL_SCANCODE_RCTRL])	
	{BtnBuffer_Raw[BTN_rctrl] = 1;}
	if (state[SDL_SCANCODE_SPACE])	
	{BtnBuffer_Raw[BTN_space] = 1;}
	if (state[SDL_SCANCODE_LALT])	
	{BtnBuffer_Raw[BTN_alt] = 1;}
	if (state[SDL_SCANCODE_RALT])	
	{BtnBuffer_Raw[BTN_altgr] = 1;}
	if (state[SDL_SCANCODE_F1])		
	{BtnBuffer_Raw[BTN_f1] = 1;}
	if (state[SDL_SCANCODE_F2])		
	{BtnBuffer_Raw[BTN_f2] = 1;}
	if (state[SDL_SCANCODE_F3])		
	{BtnBuffer_Raw[BTN_f3] = 1;}
	if (state[SDL_SCANCODE_F4])		
	{BtnBuffer_Raw[BTN_f4] = 1;}
	if (state[SDL_SCANCODE_F5])		
	{BtnBuffer_Raw[BTN_f5] = 1;}
	if (state[SDL_SCANCODE_F6])		
	{BtnBuffer_Raw[BTN_f6] = 1;}
	if (state[SDL_SCANCODE_F7])		
	{BtnBuffer_Raw[BTN_f7] = 1;}
	if (state[SDL_SCANCODE_F8])		
	{BtnBuffer_Raw[BTN_f8] = 1;}
	if (state[SDL_SCANCODE_F9])		
	{BtnBuffer_Raw[BTN_f9] = 1;}
	if (state[SDL_SCANCODE_F10])	
	{BtnBuffer_Raw[BTN_f10] = 1;}
	if (state[SDL_SCANCODE_F11])	
	{BtnBuffer_Raw[BTN_f11] = 1;}
	if (state[SDL_SCANCODE_F12])	
	{BtnBuffer_Raw[BTN_f12] = 1;}

	/* The state of the keyboard has been captured. These keys are immediately
	clasified as buttons that are still pressed. In order to know if a key was
	just pressed or released we compare the current pressed keys with the 
	pressed ones at the last frame */

	for(int i = 0; i < _REGISTEREDBUTTONS_; i++){
		
		// just pressed keys.
		if (BtnBuffer_Raw[i] == 1 &&
			BtnBuffer_Last[i] == 0){
				BtnBuffer_Enter[i] = 1;
			}
			
			
		if (BtnBuffer_Raw[i] == 1 &&
			BtnBuffer_Last[i] == 1){
				BtnBuffer_Enter[i] = 0;
			}
	
	
		// Released keys.
		if (BtnBuffer_Raw[i] == 0 &&
			BtnBuffer_Last[i] == 1){
				BtnBuffer_Leave[i] = 1;
			}
			
			
		if (BtnBuffer_Raw[i] == 0 &&
			BtnBuffer_Last[i] == 0){
				BtnBuffer_Leave[i] = 0;
			}
	
		/* Registering the current key states for the next checking at the
		next frame*/
		BtnBuffer_Last[i] = BtnBuffer_Raw[i];
	}
	return;
}

short int GETBTN(short int _btncode){
	return BtnBuffer_Raw[_btncode];
}
short int GETBTNDOWN(short int _btncode){
	return BtnBuffer_Enter[_btncode];
}
short int GETBTNUP(short int _btncode){
	return BtnBuffer_Leave[_btncode];
}

void CLEAR_BUTTON_BUFFERS(){
	
	for (int i = 0; i < _REGISTEREDBUTTONS_; i++){
		BtnBuffer_Enter[i] = 0;
		BtnBuffer_Raw  [i] = 0;
		BtnBuffer_Leave[i] = 0;
		BtnBuffer_Last [i] = 0;
	}
}