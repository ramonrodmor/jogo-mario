/**********************************************************************************
// Game (C�digo Fonte)
//
// Cria��o:		08 Dez 2012
// Atualiza��o:	15 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Uma class abstrata para representar um jogo.
//
//              Para criar um jogo o programador deve criar uma classe derivada
//              de Game e sobrescrever os m�todos Init, Update, Draw e Finalize.
//              Para rodar o jogo, deve-se passar o objeto Game para o m�todo
//              Start() de um objeto Engine.
//
**********************************************************************************/

#include "Game.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de membros est�ticos da classe

Window * Game::window = nullptr;	// ponteiro para a janela

// -------------------------------------------------------------------------------

Game::Game()
{
	if (!window)
	{
		// assume que a inst�ncia da engine �  
		// criada antes da inst�ncia do jogo
		window = Engine::window;
	}
}

// -------------------------------------------------------------------------------

Game::~Game()
{
}

// -------------------------------------------------------------------------------

void Game::OnPause()
{
	Sleep(10);
}

// -------------------------------------------------------------------------------