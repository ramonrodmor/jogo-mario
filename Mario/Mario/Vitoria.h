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

#ifndef _MARIO_VITORIA_H_
#define _MARIO_VITORIA_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Item.h"
#include "Animation.h"
#include "Player.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class Vitoria : public Game
{
private:
	Sprite * title;					// tela de fim
	Animation * anim;				// animação do menu
	Item * voltar;					// animação para voltar ao menu
	Font * marioFonte;

public:
	void Init();					// inicialização do nível
	void Update(float gameTime);	// lógica da tela de fim
	void Draw();					// desenho da tela
	void Finalize();				// finalização do nível
};

// ------------------------------------------------------------------------------

#endif