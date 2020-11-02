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

#ifndef _MARIO_INIMIGO_H_
#define _MARIO_INIMIGO_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Animation.h"					// anima��o de sprites
#include "Platform.h"

// ------------------------------------------------------------------------------

enum EstadoInimigo {ANDARESQ, ANDARDIR};	// estado do jogador

// ---------------------------------------------------------------------------------

class Inimigo : public Object
{
private:
	TileSet   * tileset;				// sprites do personagem
	Animation * anim;					// anima��o do personagem
	int cont;
	int vel = -200;

public:

	static uint		estado;				// estado atual do player
	static int		vidas;				// vidas
	Inimigo();							// construtor
	~Inimigo();							// destrutor

	float Bottom();						// coordenadas da base
	float Top();						// coordenadas do topo

	void Update(float gameTime);		// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

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