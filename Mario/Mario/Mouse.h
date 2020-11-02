/**********************************************************************************
// Mouse (Arquivo de Cabe�alho)
// 
// Cria��o:		14 Mai 2012
// Atualiza��o:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Gerencia mouse na tela
//
**********************************************************************************/

#ifndef _MARIO_MOUSE_H_
#define _MARIO_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"		
#include "Types.h"		

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
	Mouse();							// construtor
	~Mouse();							// destrutor

	bool Clicked();						// click do mouse
	void Update(float gameTime);		// atualiza��o do objeto
	void Draw();						// desenho do objeto 
}; 

// ---------------------------------------------------------------------------------

#endif