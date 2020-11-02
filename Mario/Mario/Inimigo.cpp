/**********************************************************************************
// Player (Código Fonte)
//
// Criação:		20 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define uma classe para o jogador
//
**********************************************************************************/

#include "Inimigo.h"
#include "Mario.h"
#include "Scene.h"						// cena do jogo
#include "Level1.h"

// ---------------------------------------------------------------------------------
uint	Inimigo::estado = NULL;				// estado atual do player
int		Inimigo::vidas = NULL;				// vidas
// ---------------------------------------------------------------------------------

Inimigo::Inimigo()
{
	tileset = new TileSet("Resources/bala1.png", 1, 2);
	anim = new Animation(tileset, 0.150f, true);

	// seqüências de animação do player
	uint andaresq[1] = { 0 };		anim->Add(ANDARESQ, andaresq, 1);
	uint andardir[1] = { 1 };		anim->Add(ANDARDIR, andardir, 1);

	// cria bounding box
	bbox = new Rect(
		x - tileset->TileWidth() / 2.9f - 2,
		y - tileset->TileHeight() / 2.9f - 2,
		x + tileset->TileWidth() / 2.9f - 2,
		y + tileset->TileHeight() / 2.0f - 2);

	// inicializa estado do player
	estado = ANDARESQ;
	type = INIMIGO;
	cont = 0;

	// posição inicial
	MoveTo(1000.0f, 500.0f, 0.0f);
}

// ---------------------------------------------------------------------------------

Inimigo::~Inimigo()
{
	delete bbox;
	delete anim;
	delete tileset;
}

// ---------------------------------------------------------------------------------

void Inimigo::Update(float gameTime)
{
	if (vel < 0 && (Player::centro == true && ((Player::estado == PANDARDIR) || (Player::estado == GANDARDIR) || (Player::estado == PPULARDIR) || (Player::estado == GPULARDIR))))
	{
		estado = ANDARESQ;
		Translate(2 * vel * gameTime, 0);
	}

	else
		Translate(vel * gameTime, 0);

	if (x < 0)
		MoveTo(1000, y);

	if (x > 800 && x <850)
		Mario::audio->Play(TIRO);

	// atualiza animação
	anim->Select(estado);
	anim->NextFrame();
}

// ---------------------------------------------------------------------------------
