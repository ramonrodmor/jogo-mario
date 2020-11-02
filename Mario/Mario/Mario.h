/**********************************************************************************
// MenuDemo (Arquivo de Cabeçalho)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Exemplo de interface menu
//
**********************************************************************************/

#ifndef _MARIO_H_
#define _MARIO_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Mouse.h"
#include "Item.h"
#include "Sprite.h"
#include "Scene.h"
#include "Ajuda.h"
#include "Resources.h"
#include "Audio.h"

// ------------------------------------------------------------------------------

enum Music  { MENU, MAJUDA, FASE1, GAMEOVER, PULO, MOEDA, COGUMEL, TIRO };
enum MarioObjects { SMALL, MEDIUM, BLOCO, CASTELO, CANO, CANO2, CASTELOFINAL, PORTA, CHAOCASTELO, PAREDE, BASE, MOEDAS, JOGADOR, COGUMELO, INIMIGO, CHEFE };

// ------------------------------------------------------------------------------

class Mario : public Game
{
private:
	
	Sprite  * backg;				// plano de fundo
	bool ctrlKey;					// controla pressionamento de teclas
	static Game * level;			// nível atual do jogo
	
public:

	static Audio	* audio;		// audio do jogo
	static Scene	* scene;		// cena do jogo
	static Mouse	* mouse;		// objeto mouse
	static bool  viewBBox;			// visualiza bounding box

	template<class T>
	static void NextLevel()			// muda para próximo nível do jogo
	{
		if (level)
		{
			level->Finalize();
			delete level;
			level = new T();
			level->Init();
		}
	};

	void Init();					// inicializa jogo
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif