/**********************************************************************************
// Image (C�digo Fonte)
// 
// Cria��o:		16 Mar 2012
// Atualiza��o:	11 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define uma classe para representar imagens
//
**********************************************************************************/

#include "Image.h"
#include "Graphics.h"

// -------------------------------------------------------------------------------

Image::Image(string filename)
{
	textureView = nullptr;

	// cria sharer resource view da imagem em disco
	D3D11CreateTextureFromFile(
		Graphics::Device(),			// dispositivo Direct3D
		Graphics::Context(),		// contexto do dispositivo
		filename.c_str(),			// nome do arquivo de imagem
		nullptr,					// retorna textura 
		&textureView,				// retorna view da textura
		width,						// retorna largura da imagem
		height);					// retorna altura da imagem
}

// -------------------------------------------------------------------------------

Image::~Image()
{
	// libera mem�ria ocupada pela texture view
	if (textureView)
	{
		// pega ponteiro para recurso
		ID3D11Resource * resource = nullptr;
		textureView->GetResource(&resource);

		// liberando a view n�o libera automaticamente
		// o recurso que foi criado junto com a view
		if (resource)
		{
			resource->Release();
			resource = nullptr;
		}

		textureView->Release();
		textureView = nullptr;
	}
}

// -------------------------------------------------------------------------------