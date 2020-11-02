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

#ifndef _MARIO_LEVEl1_H_
#define _MARIO_LEVEl1_H_

// ------------------------------------------------------------------------------
// Inclusões

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
	static Scene * scene;			// cena do nível

	void Init();					// inicialização do nível
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finalização do nível
};

// -----------------------------------------------------------------------------

#endif