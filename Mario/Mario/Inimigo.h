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

#ifndef _MARIO_INIMIGO_H_
#define _MARIO_INIMIGO_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"						// tipos específicos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// animação de sprites
#include "Platform.h"

// ------------------------------------------------------------------------------

enum EstadoInimigo {ANDARESQ, ANDARDIR};	// estado do jogador

// ---------------------------------------------------------------------------------

class Inimigo : public Object
{
private:
	TileSet   * tileset;				// sprites do personagem
	Animation * anim;					// animação do personagem
	int cont;
	int vel = -200;

public:

	static uint		estado;				// estado atual do player
	static int		vidas;				// vidas
	Inimigo();							// construtor
	~Inimigo();							// destrutor

	float Bottom();						// coordenadas da base
	float Top();						// coordenadas do topo

	void Update(float gameTime);		// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline float Inimigo::Bottom()
{
	return y + tileset->Height() / 2;
}

inline float Inimigo::Top()
{
	return y - tileset->Height() / 2;
}

inline void Inimigo::Draw()
{
	anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif