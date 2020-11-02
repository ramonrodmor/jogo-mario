/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Nível 1 do jogo Mario
//
**********************************************************************************/

#ifndef _MARIO_LEVEl2_H_
#define _MARIO_LEVEl2_H_

// ------------------------------------------------------------------------------
// Inclusões

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
	static Scene * scene;			// cena do nível

	void Init();					// inicialização do nível
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finalização do nível
};

// -----------------------------------------------------------------------------

#endif