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

/* Definitions of all the keyboard codes used for input detection */

#ifndef _BTNDEFS_
#define _BTNDEFS_

#define _REGISTEREDBUTTONS_ 61

// Numbers and chars
#define BTN_0 		0
#define BTN_1 		1
#define BTN_2 		2
#define BTN_3 		3
#define BTN_4 		4
#define BTN_5 		5
#define BTN_6 		6
#define BTN_7 		7
#define BTN_8 		8
#define BTN_9 		9
#define BTN_q 		10 	
#define BTN_w 		11		
#define BTN_e 		12
#define BTN_r 		13
#define BTN_t 		14
#define BTN_y 		15
#define BTN_u 		16
#define BTN_i 		17
#define BTN_o 		18
#define BTN_p 		19
#define BTN_a 		20
#define BTN_s 		21
#define BTN_d 		22
#define BTN_f 		23	
#define BTN_g 		24
#define BTN_h 		25
#define BTN_j 		26
#define BTN_k 		27
#define BTN_l 		28
#define BTN_z 		29
#define BTN_x 		30
#define BTN_c 		31
#define BTN_v 		32
#define BTN_b 		33
#define BTN_n 		34
#define BTN_m 		45

// Arrows
#define BTN_left 	36	
#define BTN_right 	37	
#define BTN_up		38	
#define BTN_down 	39	

// Special keys
#define BTN_return	40
#define BTN_escape	41
#define BTN_lshift 	42
#define BTN_rshift	43
#define BTN_lctrl	44
#define BTN_rctrl	45
#define BTN_space	46
#define BTN_alt		47
#define BTN_altgr	48

// Function keys
#define BTN_f1		49
#define BTN_f2		50
#define BTN_f3		51
#define BTN_f4		52
#define BTN_f5		53
#define BTN_f6		54
#define BTN_f7		55
#define BTN_f8		56
#define BTN_f9		57
#define BTN_f10		58
#define BTN_f11		59
#define BTN_f12		60
	
#endif