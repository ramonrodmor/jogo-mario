/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:		20 Abr 2012
// Atualiza��o:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _MARIO_PLAYER_H_
#define _MARIO_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Platform.h"

// ------------------------------------------------------------------------------

enum EstadoPlayer { PPARADOD, PPARADOE, PANDARESQ, PANDARDIR, PPULARESQ, PPULARDIR, PBAIXARESQ, PBAIXARDIR, PPULOD, PPULOE,
					GPARADOD, GPARADOE, GANDARESQ, GANDARDIR, GPULARESQ, GPULARDIR, GBAIXARESQ, GBAIXARDIR, GPULOD, GPULOE };	// estado do jogador

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	TileSet   * tileset;				// folha de sprites do personagem
	Animation * anim;					// anima��o do personagem
	bool      cimaCtrl;					// controle do pressionamento da barra de espa�o
	bool      direitaCtrl;				// controle do pressionamento da barra de espa�o
	bool      esquerdaCtrl;				// controle do pressionamento da barra de espa�o
	bool	  controleDirecao;			// controle pra fazer m�rio andar
	float	  vi;						// velocidade para uso nos pulos e gravidade

public:

	static bool		passarLevel;		// habilita passagem de level
	static uint		estado;				// estado atual do player
	static bool		centro;				// verifica se o jogador est� no centro
	static int		pontos;				// contador de pontos
	static int		moedas;				// contator de moedas recolhidas
	static int		vidas;				// vidas
	static bool		super;				// estado do m�rio, se pequeno ou grande
	uint			estadoAnterior;		// estado anterior do player
	Player();							// construtor
	~Player();							// destrutor

	float Bottom();						// coordenadas da base
	float Top();						// coordenadas do topo

	void OnCollision(Object * obj);		// resolu��o da colis�o
	void Update(float gameTime);		// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline float Player::Bottom()
{
	return y + tileset->Height() / 2;
}

inline float Player::Top()
{
	return y - tileset->Height() / 2;
}

inline void Player::Draw()
{
	anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif