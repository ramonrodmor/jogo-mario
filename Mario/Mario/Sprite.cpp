/**********************************************************************************
// Sprite (Código Fonte)
// 
// Criação:		11 Jul 2007
// Atualização:	04 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define uma classe para representar um sprite
//
**********************************************************************************/

#include "Sprite.h"
#include "Engine.h"

// ---------------------------------------------------------------------------------

Sprite::Sprite(string filename)
{
	// carrega imagem
	image = new Image(filename);
	localImage = true;
	
	// configura registro sprite
	spriteInfo.texture = image->View();
}

// ---------------------------------------------------------------------------------

Sprite::Sprite(const Image * img)
{
	// aponta para imagem externa
	image = img;
	localImage = false;

	// configura registro sprite
	spriteInfo.texture = image->View();
}

// ---------------------------------------------------------------------------------

Sprite::~Sprite()
{
	if (localImage)
		delete image;
}

// ---------------------------------------------------------------------------------

void Sprite::Draw(float x, float y, float z, float scale, float rotation, Color color)
{
	spriteInfo.x          = x;
	spriteInfo.y          = y;
	spriteInfo.scale      = scale;
	spriteInfo.depth      = z;
	spriteInfo.rotation   = rotation;
	spriteInfo.width      = image->Width();
	spriteInfo.height     = image->Height();
	spriteInfo.texCoord.x = 0;
	spriteInfo.texCoord.y = 0;
	spriteInfo.texSize.x  = 1;
	spriteInfo.texSize.y  = 1;
	spriteInfo.color      = color;

	// adiciona o sprite na lista de desenho
	Engine::renderer->Draw(spriteInfo);
}

// ---------------------------------------------------------------------------------