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

#include "Player.h"
#include "Mario.h"
#include "Scene.h"						// cena do jogo
#include "Level1.h"

// ---------------------------------------------------------------------------------
uint	Player::estado = NULL;				// estado atual do player
bool	Player::centro = NULL;				// verifica se o jogador está no centro
int		Player::pontos = NULL;				// contador de pontos
int		Player::moedas = NULL;				// contator de moedas recolhidas
int		Player::vidas = NULL;				// vidas
bool	Player::super = NULL;				// estado do mário, se pequeno ou grande
bool	Player::passarLevel = NULL;			// habilita passagem de level
// ---------------------------------------------------------------------------------

Player::Player()
{
	tileset = new TileSet("Resources/Mario.png", 3, 10);
	anim = new Animation(tileset, 0.150f, true);

	// seqüências de animação do player
	uint pparadod[1] = { 0 };			anim->Add(PPARADOD, pparadod, 1);
	uint pparadoe[1] = { 5 };			anim->Add(PPARADOE, pparadoe, 1);
	uint pandardir[2] = { 1, 0 };		anim->Add(PANDARDIR, pandardir, 2);
	uint pbaixardir[1] = { 2 };			anim->Add(PBAIXARDIR, pbaixardir, 1);
	uint pbaixaresq[1] = { 7 };			anim->Add(PBAIXARESQ, pbaixaresq, 1);
	uint pandaresq[2] = { 6, 5 };		anim->Add(PANDARESQ, pandaresq, 2);
	uint ppulardir[1] = { 3 };			anim->Add(PPULARDIR, ppulardir, 1);
	uint ppularesq[1] = { 8 };			anim->Add(PPULARESQ, ppularesq, 1);
	uint ppulod[1] = { 3 };				anim->Add(PPULOD, ppulod, 1);
	uint ppuloe[1] = { 8 };				anim->Add(PPULOE, ppuloe, 1);
	uint gparadod[1] = { 10 };			anim->Add(GPARADOD, gparadod, 1);
	uint gparadoe[1] = { 15 };			anim->Add(GPARADOE, gparadoe, 1);
	uint gandardir[2] = { 11, 10 };		anim->Add(GANDARDIR, gandardir, 2);
	uint gandaresq[2] = { 16, 15 };		anim->Add(GANDARESQ, gandaresq, 2);
	uint gbaixardir[1] = { 12 };		anim->Add(GBAIXARDIR, gbaixardir, 1);
	uint gbaixaresq[1] = { 17 };		anim->Add(GBAIXARESQ, gbaixaresq, 1);
	uint gpulardir[1] = { 13 };			anim->Add(GPULARDIR, gpulardir, 1);
	uint gpularesq[1] = { 18 };			anim->Add(GPULARESQ, gpularesq, 1);
	uint gpulod[1] = { 13 };			anim->Add(GPULOD, gpulod, 1);
	uint gpuloe[1] = { 18 };			anim->Add(GPULOE, gpuloe, 1);

	// cria bounding box
	bbox = new Rect(
		x - tileset->TileWidth() / 2.9f - 2,
		y - tileset->TileHeight() / 2.9f - 2,
		x + tileset->TileWidth() / 2.9f - 2,
		y + tileset->TileHeight() / 2.0f - 2);

	// inicializa estado do player
	estado = estadoAnterior = PPARADOD;
	cimaCtrl = direitaCtrl = esquerdaCtrl = false;
	super = false;
	centro = false;
	vi = 0;
	moedas = 0;
	pontos = 0;
	vidas = 3;
	type = JOGADOR;

	// posição inicial
	MoveTo(150.0f, 620.0f, 0.0f);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete bbox;
	delete anim;
	delete tileset;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
	if (obj->Type() == INIMIGO)
	{
		if (super)
		{
			super = false;
			obj->MoveTo(1000.0f, obj->Y(), 0.0f);
			estado = PPARADOD;
		}
		else
		{
			vidas--;
			obj->MoveTo(1000.0f, obj->Y(), 0.0f);
			estado = PPARADOD;
		}

	}

	if (obj->Type() == CASTELO || obj->Type() == CANO2)
	{
		estadoAnterior = estado;
		if (!super)
		{
			if (estado == PANDARESQ || estado == PPARADOE || estado == PBAIXARESQ || estado == PPULARESQ)
				estado = PPARADOE;
			else if (estado == PANDARDIR || estado == PPARADOD || estado == PBAIXARDIR || estado == PPULARDIR)
				estado = PPARADOD;
		}
		else if (super)
		{
			if (estado == GANDARESQ || estado == GPARADOE || estado == GBAIXARESQ || estado == GPULARESQ)
				estado = GPARADOE;
			else if (estado == GANDARDIR || estado == GPARADOD || estado == GBAIXARDIR || estado == GPULARDIR)
				estado = GPARADOD;
		}
	}

	else if (obj->Type() == PAREDE)
	{
	}

	else if (obj->Type() == CASTELOFINAL)
	{
		if (window->KeyDown(VK_SPACE))
		{
			passarLevel = true;
		}
	}

	else if (obj->Type() == CHEFE)
	{
		passarLevel = true;
	}

	else if (obj->Type() == BASE)
	{
		if ((obj->Y() - 14) > bbox->Y())
		{
			MoveTo(x, obj->Y() - 44);
			vi = 0;
		}
		else
		{
			MoveTo(x, obj->Y() + 44);
			vi = 0;
		}
	}


	else if (obj->Type() == BLOCO)
	{
		if ((obj->Y() - 74) > bbox->Y())
		{
			MoveTo(x, obj->Y() - 75);
			vi = 0;
		}
		else
		{
			estadoAnterior = estado;
			if (!super)
			{
				if (estado == PANDARESQ || estado == PPARADOE || estado == PBAIXARESQ || estado == PPULARESQ)
					estado = PPARADOE;
				else if (estado == PANDARDIR || estado == PPARADOD || estado == PBAIXARDIR || estado == PPULARDIR)
					estado = PPARADOD;
			}
			else if (super)
			{
				if (estado == GANDARESQ || estado == GPARADOE || estado == GBAIXARESQ || estado == GPULARESQ)
					estado = GPARADOE;
				else if (estado == GANDARDIR || estado == GPARADOD || estado == GBAIXARDIR || estado == GPULARDIR)
					estado = GPARADOD;
			}
		}
	}

	else if (obj->Type() == CANO)
	{
		if ((obj->Y() - 74) > bbox->Y())
		{
			MoveTo(x, obj->Y() - 75);
			vi = 0;
		}
		else
		{
			estadoAnterior = estado;
			if (!super)
			{
				if (estado == PANDARESQ || estado == PPARADOE || estado == PBAIXARESQ || estado == PPULARESQ)
					estado = PPARADOE;
				else if (estado == PANDARDIR || estado == PPARADOD || estado == PBAIXARDIR || estado == PPULARDIR)
					estado = PPARADOD;
			}
			else if (super)
			{
				if (estado == GANDARESQ || estado == GPARADOE || estado == GBAIXARESQ || estado == GPULARESQ)
					estado = GPARADOE;
				else if (estado == GANDARDIR || estado == GPARADOD || estado == GBAIXARDIR || estado == GPULARDIR)
					estado = GPARADOD;
			}
		}
	}

	else if (obj->Type() == MOEDAS)
	{
		Mario::audio->Play(MOEDA);
		obj->MoveTo(0, 800);
		pontos += 100;
	}

	else if (obj->Type() == COGUMELO)
	{
		Mario::audio->Play(COGUMEL);
		obj->MoveTo(0, 800);
		pontos += 1000;
		super = true;
		estado = GPARADOD;
	}

	else if ((obj->Y() - 75) < bbox->Y())
	{
		MoveTo(x, obj->Y() - 75);
		vi = 0;
	}
}

// ---------------------------------------------------------------------------------

void Player::Update(float gameTime)
{

	// desloca mario
	controleDirecao = true;

	if (window->KeyUp(VK_UP))
		cimaCtrl = true;

	if (window->KeyUp(VK_RIGHT))
		direitaCtrl = true;

	if (window->KeyUp(VK_LEFT))
		esquerdaCtrl = true;

	// Condições para que ele fique parado
	if (!super && vi == 0)
	{
		if (estado == PANDARDIR || estado == PBAIXARDIR || estado == PPULARDIR || estado == PPULOD)
		{
			estadoAnterior = estado;
			estado = PPARADOD;
		}
		else if (estado == PANDARESQ || estado == PBAIXARESQ || estado == PPULARESQ || estado == PPULOE)
		{
			estadoAnterior = estado;
			estado = PPARADOE;
		}
	}

	else if (super && vi == 0)
	{
		if (estado == GANDARDIR || estado == GBAIXARDIR || estado == GPULARDIR || estado == GPULOD)
		{
			estadoAnterior = estado;
			estado = GPARADOD;
		}
		else if (estado == GANDARESQ || estado == GBAIXARESQ || estado == GPULARESQ || estado == GPULOE)
		{
			estadoAnterior = estado;
			estado = GPARADOE;
		}
	}
	
	// Condições para pulo do mário com direção
	if (vi == 0 && controleDirecao && cimaCtrl && ((window->KeyDown(VK_UP) && (window->KeyDown(VK_LEFT) || window->KeyDown(VK_RIGHT)))))
	{
		if (!super)
		{
			if (estado == PANDARESQ || estado == PPARADOE || estado == PBAIXARESQ)
			{
				vi = -3.7f;
				estadoAnterior = estado = PPULARESQ;
			}
			else if (estado == PANDARDIR || estado == PPARADOD || estado == PBAIXARDIR)
			{
				vi = -3.7f;
				estadoAnterior = estado = PPULARDIR;
			}
		}
		else if (super)
		{
			if (estado == GANDARESQ || estado == GPARADOE || estado == GBAIXARESQ)
			{
				vi = -3.7f;
				estadoAnterior = estado = GPULARESQ;
			}
			else if (estado == GANDARDIR || estado == GPARADOD || estado == GBAIXARDIR)
			{
				vi = -3.7f;
				estadoAnterior = estado = GPULARDIR;
			}
		}
		cimaCtrl = direitaCtrl = esquerdaCtrl = false;
		Mario::audio->Play(PULO);
	}

	// condições para pulo do mário para cima
	else if ((vi == 0 && (estado == PPARADOD || estado == PPARADOE || estado == GPARADOD || estado == GPARADOE) && cimaCtrl && window->KeyDown(VK_UP)))
	{
		if (!super)
		{
			if (estadoAnterior == PANDARESQ || estado == PPARADOE || estadoAnterior == PBAIXARESQ)
			{
				vi = -3.7f;
				estadoAnterior = estado = PPULOE;
			}
			else if (estadoAnterior == PANDARDIR || estado == PPARADOD || estadoAnterior == PBAIXARDIR)
			{
				vi = -3.7f;
				estadoAnterior = estado = PPULOD;
			}
		}
		else if (super)
		{
			if (estadoAnterior == GANDARESQ || estado == GPARADOE || estadoAnterior == GBAIXARESQ)
			{
				vi = -3.7f;
				estadoAnterior = estado = GPULARESQ;
			}
			else if (estadoAnterior == GANDARDIR || estado == GPARADOD || estadoAnterior == GBAIXARDIR)
			{
				vi = -3.7f;
				estadoAnterior = estado = GPULARDIR;
			}
		}
		cimaCtrl = controleDirecao = false;
		Mario::audio->Play(PULO);
	}

	// Condições para movimento para direita
	else if (vi == 0 && controleDirecao && direitaCtrl && window->KeyDown(VK_RIGHT))
	{
		if (!super && estado != PPULARDIR && estado != PPULARESQ)
		{
			estadoAnterior = estado;
			estado = PANDARDIR;
			if (x < 400)
				Translate(200 * gameTime, 0);
			else
				centro = true;
		}
		else if (super && estado != GPULARDIR && estado != GPULARESQ)
		{
			estadoAnterior = estado;
			estado = GANDARDIR;
			if (x < 400)
				Translate(200 * gameTime, 0);
			else
				centro = true;
		}
	}

	// Condições para movimento para esquerda
	else if (vi == 0 && controleDirecao && esquerdaCtrl == true && window->KeyDown(VK_LEFT))
	{
		if (!super && estado != PPULARDIR && estado != PPULARESQ)
		{
			estadoAnterior = estado;
			estado = PANDARESQ;
			if (x > 400)
				Translate(-200 * gameTime, 0);
		}
		else if (super && estado != GPULARDIR && estado != GPULARESQ)
		{
			estadoAnterior = estado;
			estado = GANDARESQ;
			if (x > 400)
				Translate(-200 * gameTime, 0);
		}
	}

	// Condições para abaixar o mário
	else if (window->KeyDown(VK_DOWN))
	{
		if (!super)
		{
			if (estadoAnterior == PANDARESQ || estadoAnterior == PPARADOE || estadoAnterior == PBAIXARESQ ||
				estadoAnterior == PPULARESQ || estadoAnterior == PPULOE)
			{
				estadoAnterior = estado;
				estado = PBAIXARESQ;
			}
			else if (estadoAnterior == PANDARDIR || estadoAnterior == PPARADOD || estadoAnterior == PBAIXARDIR ||
					 estadoAnterior == PPULARDIR || estadoAnterior == PPULOD)
			{
				estadoAnterior = estado;
				estado = PBAIXARDIR;
			}
		}
		else if (super)
		{
			if (estadoAnterior == GANDARESQ || estadoAnterior == GPARADOE || estadoAnterior == GBAIXARESQ ||
				estadoAnterior == GPULARESQ || estadoAnterior == GPULOE)
			{
				estadoAnterior = estado;
				estado = GBAIXARESQ;
			}
			else if (estadoAnterior == GANDARDIR || estadoAnterior == GPARADOD || estadoAnterior == GBAIXARDIR ||
					 estadoAnterior == GPULARDIR || estadoAnterior == GPULOD)
			{
				estadoAnterior = estado;
				estado = GBAIXARDIR;
			}
		}
	}

	// ----------------------------------------------------
	// ação da gravidade sobre o personagem
	// ----------------------------------------------------
	vi = vi + 10 * gameTime;
	Translate(0, vi);
	
	// atualiza animação
	anim->Select(estado);
	anim->NextFrame();
}

// ---------------------------------------------------------------------------------