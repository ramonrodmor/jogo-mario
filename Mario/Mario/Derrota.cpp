/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	GameOver do jogo GravityGuy
//
**********************************************************************************/

#include "Engine.h"
#include "Derrota.h"
#include "Mario.h"
#include "Menu.h"

// ----------------------------------------------------------------------

void Derrota::Init()
{
	// cria fontes
	marioFonte = new Font("Resources/fonteMario.png");
	marioFonte->Spacing(20);
	
	title = new Sprite("Resources/Derrota.jpg");
	voltar = new Item(150, 550, VOLTAR, "Resources/Menu.png");
	Mario::audio->Play(GAMEOVER, FALSE);
}

// ----------------------------------------------------------------------

void Derrota::Update(float gameTime)
{
	Mario::mouse->Update(gameTime);
	voltar->Update(gameTime);

	bool selected = Mario::scene->Collision(Mario::mouse, voltar);

	if (selected)
		voltar->Select();
	else
		voltar->UnSelect();

	if ((selected) && (Mario::mouse->Clicked()))
	{
		Mario::audio->Stop(GAMEOVER);
		Mario::NextLevel<Menu>();
	}
}

// ----------------------------------------------------------------------

void Derrota::Draw()
{
	Color black(0.0f, 0.0f, 0.0f, 1.0f);
	Color blue(0.2f, 0.2f, 1.0f, 1.0f);
	Color red(1.0f, 0.2f, 0.2f, 1.0f);
	Color green(0.1f, 0.6f, 0.1f, 1.0f);
	Color branco(1, 1, 1, 1);

	title->Draw(window->CenterX(), window->CenterY(), 0.9f);
	voltar->Draw();

	if (Mario::viewBBox)
	{
		// desenha bounding box dos objetos
		Engine::renderer->BeginPixels();
		Mario::scene->Begin();
		Object * obj = nullptr;
		while (obj = Mario::scene->Next())
		if (obj->bbox)
			Engine::renderer->Draw(obj->bbox, 0xffff00ff);
		Engine::renderer->EndPixels();
	}

	marioFonte->Draw(100, 200, "voce perdeu!", branco, 0.0f, 0.75f, 0.0f);
	marioFonte->Draw(100, 300, "seus pontos: " + to_string(Player::pontos), branco, 0.0f, 0.75f, 0.0f);
}

// ----------------------------------------------------------------------

void Derrota::Finalize()
{
	delete title;
}

// ----------------------------------------------------------------------

