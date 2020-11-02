/**********************************************************************************
// Mouse (Arquivo de Cabeçalho)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Gerencia mouse na tela
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
	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto 
}; 

// ---------------------------------------------------------------------------------

#endif