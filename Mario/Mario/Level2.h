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

#ifndef _MARIO_LEVEl2_H_
#define _MARIO_LEVEl2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Sprite.h"
#include "Background.h"
#include "Menu.h"
#include "Level1.h"
#include "Inimigo.h"
#include "Font.h"
#include "Vitoria.h"
#include "Derrota.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
	Player * player;				// player
	Background * fundo;				// background
	Inimigo * inimigo;
	Font * marioFont;

public:
	static Scene * scene;			// cena do n�vel

	void Init();					// inicializa��o do n�vel
	void Update(float gameTime);	// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif