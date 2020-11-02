/**********************************************************************************
// Background (Arquivo de Cabeçalho)
// 
// Criação:		21 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _MARIO_BACKGROUND_H_
#define _MARIO_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Sprite.h"						// background é composto por sprites
#include "Player.h"

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
	//Sprite * backgF;					// background front
	Sprite * backgB;					// background back
	Sprite * sky;						// fundo estático do background
	float xF, xB;						// posição horizontal dos sprites

public:
	Background();						// construtor
	~Background();						// destrutor

	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif