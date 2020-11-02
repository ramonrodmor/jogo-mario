/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
//
// Cria��o:		14 Fev 2013
// Atualiza��o:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	GameOver do jogo GravityGuy
//
**********************************************************************************/

#ifndef _MARIO_AJUDA_H_
#define _MARIO_AJUDA_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"
#include "Mario.h"
#include "Menu.h"

// ------------------------------------------------------------------------------

class Ajuda : public Game
{
private:
	Sprite * fundo;					// tela de fim
	Animation * anim;				// anima��o do menu
	Item * voltar;

public:
	void Init();					// inicializa��o do n�vel
	void Update(float gameTime);	// l�gica da tela de fim
	void Draw();					// desenho da tela
	void Finalize();				// finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif