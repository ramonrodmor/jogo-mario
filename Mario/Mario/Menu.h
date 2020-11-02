/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Tela de abertura do jogo GravityGuy
//
**********************************************************************************/

#ifndef _MARIO_HOME_H_
#define _MARIO_HOME_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Mouse.h"

// ------------------------------------------------------------------------------

enum MenuID { JOGAR, AJUDA, SAIR, VOLTAR };

// ------------------------------------------------------------------------------

class Menu : public Game
{
private:
	static const int MaxItens = 3;	// número de itens do menu
	Sprite * fundo;					// background
	Animation * anim;				// animação do menu
	Item    * menu[MaxItens];		// itens do menu
	bool ctrlKey[2];				// controla pressionamento de teclas

public:

	void Init();					// inicia nível
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza nível
};

// -----------------------------------------------------------------------------

#endif