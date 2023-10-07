#include "../CImg/CImg.h"
#include <string>

using namespace cimg_library;
using namespace std;

#pragma once


/// Classe para desenhar e salvar imagens.
///  
/// Classe para desenhar e salvar imagens. Utiliza a biblioteca CImg.
class Painter
{
private:


public:
	/// Gera uma imagem vazia, com a cor de fundo desejada.
	/// 
	/// Gera uma imagem vazia, com a cor de fundo desejada.
	/// @param width Largura da imagem.
	/// @param height Altura da imagem.
	/// @param color Cor de fundo da imagem.
	/// @returns Struct de imagem do CImg.
	CImg<unsigned char> get_blank_canvas(int width, int height, unsigned char color[]);

	/// Desenha um gradiente horizontal na imagem.
	/// 
	/// Desenha um gradiente horizontal na imagem, com a cor 1 começando na esquerda e indo até a cor 2, na direita.
	/// O gradiente tem formato retangular.
	/// @param image Ponteiro para a imagem na qual o gradiente deve ser desenhado.
	/// @param x0 Coordenada x do ponto superior esquerdo.
	/// @param y0 Coordenada y do ponto superior esquerdo.
	/// @param color1 Cor inicial da esquerda.
	/// @param x1 Coordenada x do ponto inferior direito.
	/// @param y1 Coordenada y do ponto inferior direito.
	/// @param color2 Cor final da direita.
	void draw_horizontal_gradient(CImg<unsigned char> *image, int x0, int y0, unsigned char color1[],
			int x1, int y1, unsigned char color2[]);

	/// Desenha um círculo na imagem.
	/// 
	/// Desenha um círculo na imagem.
	/// @param image Ponteiro para a imagem na qual o círculo deve ser desenhado.
	/// @param center_x Coordenada x do centro do círculo.
	/// @param center_y Coordenada y do centro do círculo.
	/// @param radius Raio do círculo.
	/// @param color Cor do círculo.
	void draw_circle(CImg<unsigned char>* image, int center_x, int center_y, int radius, unsigned char color[]);


	/// Salva uma imagem em formato bmp.
	/// 
	/// Salva uma imagem em formato bmp.
	/// @param image Imagem a ser salva.
	/// @param title Título do arquivo da imagem.
	void save(CImg<unsigned char> image, string title);
};

