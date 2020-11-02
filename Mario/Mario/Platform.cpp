/**********************************************************************************
// Platform (Código Fonte)
//
// Criação:		21 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
	switch (platType)
	{
	case SMALL:  platform = new Sprite("Resources/chaosmall.gif"); type = SMALL; break;
	case MEDIUM: platform = new Sprite("Resources/chao.gif"); type = MEDIUM; break;
	case BLOCO:  platform = new Sprite("Resources/bloco.gif"); type = BLOCO; break;
	case CASTELO: platform = new Sprite("Resources/Castelo.png"); type = CASTELO; break;
	case CANO: platform = new Sprite("Resources/cano.png"); type = CANO; break;
	case CANO2: platform = new Sprite("Resources/cano2.png"); type = CANO2; break;
	case CASTELOFINAL: platform = new Sprite("Resources/Castelo2.png"); type = CASTELOFINAL; break;
	case PORTA: platform = new Sprite("Resources/Porta.png"); type = PORTA; break;
	case CHAOCASTELO: platform = new Sprite("Resources/chaoCastelo.jpg"); type = CHAOCASTELO; break;
	case PAREDE: platform = new Sprite("Resources/Fundo.png"); type = PAREDE; break;
	case BASE: platform = new Sprite("Resources/base.png"); type = BASE; break;
	case MOEDAS: platform = new Sprite("Resources/moeda.png"); type = MOEDAS; break;
	case COGUMELO: platform = new Sprite("Resources/cogumelo.png"); type = COGUMELO; break;
	case CHEFE: platform = new Sprite("Resources/bauzer.png"); type = CHEFE; break;
	}

	bbox = new Rect(
		x - platform->Width() / 2.0f,
		y - platform->Height() / 2.0f,
		x + platform->Width() / 2.0f,
		y + platform->Height() / 2.0f);

	MoveTo(posX, posY, 0.5f);

	if (type==CHEFE)
		MoveTo(posX, posY, 0.0f);
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
	delete platform;
	delete bbox;
}

// -------------------------------------------------------------------------------

void Platform::Update(float gameTime)
{
	// move plataforma apenas no eixo x
	if (Player::centro == true && ((Player::estado == PANDARDIR) || (Player::estado == GANDARDIR) || 
								   (Player::estado == PPULARDIR) || (Player::estado == GPULARDIR)))
		Translate(-200.0f * gameTime, 0);
	if ((Player::estado == PANDARESQ) || (Player::estado == GANDARESQ) ||
		(Player::estado == PPULARESQ) || (Player::estado == GPULARESQ))
		Translate(200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
