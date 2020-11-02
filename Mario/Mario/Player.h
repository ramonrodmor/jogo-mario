/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:		20 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define uma classe para o jogador
//
**********************************************************************************/

#ifndef _MARIO_PLAYER_H_
#define _MARIO_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
#include "Platform.h"

// ------------------------------------------------------------------------------

enum EstadoPlayer { PPARADOD, PPARADOE, PANDARESQ, PANDARDIR, PPULARESQ, PPULARDIR, PBAIXARESQ, PBAIXARDIR, PPULOD, PPULOE,
					GPARADOD, GPARADOE, GANDARESQ, GANDARDIR, GPULARESQ, GPULARDIR, GBAIXARESQ, GBAIXARDIR, GPULOD, GPULOE };	// estado do jogador

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	TileSet   * tileset;				// folha de sprites do personagem
	Animation * anim;					// animação do personagem
	bool      cimaCtrl;					// controle do pressionamento da barra de espaço
	bool      direitaCtrl;				// controle do pressionamento da barra de espaço
	bool      esquerdaCtrl;				// controle do pressionamento da barra de espaço
	bool	  controleDirecao;			// controle pra fazer mário andar
	float	  vi;						// velocidade para uso nos pulos e gravidade

public:

	static bool		passarLevel;		// habilita passagem de level
	static uint		estado;				// estado atual do player
	static bool		centro;				// verifica se o jogador está no centro
	static int		pontos;				// contador de pontos
	static int		moedas;				// contator de moedas recolhidas
	static int		vidas;				// vidas
	static bool		super;				// estado do mário, se pequeno ou grande
	uint			estadoAnterior;		// estado anterior do player
	Player();							// construtor
	~Player();							// destrutor

	float Bottom();						// coordenadas da base
	float Top();						// coordenadas do topo

	void OnCollision(Object * obj);		// resolução da colisão
	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

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