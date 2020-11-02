/**********************************************************************************
// Home (Código Fonte)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Tela de abertura do jogo GravityGuy
//
**********************************************************************************/

#include "Engine.h"
#include "Mario.h"
#include "Menu.h"
#include "Ajuda.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Menu::Init()
{
	// pano de fundo
	fundo = new Sprite("Resources/Menu.jpg");

	// cria itens de menu
	menu[0] = new Item(625, 350, JOGAR, "Resources/Jogar.png");
	menu[1] = new Item(625, 475, AJUDA, "Resources/Ajuda.png");
	menu[2] = new Item(625, 550, SAIR, "Resources/Sair.png");
	
	// toca musica do menu
	Mario::audio->Play(MENU, TRUE);
}

// ------------------------------------------------------------------------------

void Menu::Update(float gameTime)
{
	Mario::mouse->Update(gameTime);

	// destaca item selecionado
	for (int i = 0; i < MaxItens; ++i)
	{
		menu[i]->Update(gameTime);

		bool selected = Mario::scene->Collision(Mario::mouse, menu[i]);

		if (selected)
			menu[i]->Select();
		else
			menu[i]->UnSelect();

		if ((selected) && (menu[i]->Type() == SAIR) && (Mario::mouse->Clicked()))
			window->Close();

		if ((selected) && (menu[i]->Type() == AJUDA) && (Mario::mouse->Clicked()))
		{
			Mario::audio->Stop(MENU);
			Mario::NextLevel<Ajuda>();
			break;
		}

		if ((selected) && (menu[i]->Type() == JOGAR) && (Mario::mouse->Clicked()))
		{
			Mario::audio->Stop(MENU);
			Mario::NextLevel<Level1>();
			break;
		}
	}
}

// ------------------------------------------------------------------------------

void Menu::Draw()
{
	fundo->Draw(window->CenterX(), window->CenterY(), 1.0f);

	for (int i = 0; i < MaxItens; ++i)
		menu[i]->Draw();

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
}

// ------------------------------------------------------------------------------

void Menu::Finalize()
{
	delete fundo;

	for (int i = 0; i < MaxItens; ++i)
		delete menu[i];
}

// ------------------------------------------------------------------------------