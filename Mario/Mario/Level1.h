/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:		14 Fev 2013
// Atualiza��o:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	N�vel 1 do jogo Mario
//
**********************************************************************************/

#ifndef _MARIO_LEVEl1_H_
#define _MARIO_LEVEl1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Sprite.h"
#include "Background.h"
#include "Menu.h"
#include "Level2.h"
#include "Inimigo.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
	Player * player;				// player
	Inimigo * inimigo;
	Background * fundo;				// background
	Font * marioFonte;

public:
	static Scene * scene;			// cena do n�vel

	void Init();					// inicializa��o do n�vel
	void Update(float gameTime);	// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif