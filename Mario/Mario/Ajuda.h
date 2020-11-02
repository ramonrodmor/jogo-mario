/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	GameOver do jogo GravityGuy
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
	Animation * anim;				// animação do menu
	Item * voltar;

public:
	void Init();					// inicialização do nível
	void Update(float gameTime);	// lógica da tela de fim
	void Draw();					// desenho da tela
	void Finalize();				// finalização do nível
};

// ------------------------------------------------------------------------------

#endif