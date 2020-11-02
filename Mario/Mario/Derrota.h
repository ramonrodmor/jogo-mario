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

#ifndef _MARIO_DERROTA_H_
#define _MARIO_DERROTA_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Item.h"
#include "Animation.h"
#include "Player.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class Derrota : public Game
{
private:
	Sprite * title;					// tela de fim
	Animation * anim;				// anima��o do menu
	Item * voltar;					// anima��o para voltar ao menu
	Font * marioFonte;

public:
	void Init();					// inicializa��o do n�vel
	void Update(float gameTime);	// l�gica da tela de fim
	void Draw();					// desenho da tela
	void Finalize();				// finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif