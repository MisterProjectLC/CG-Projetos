#include <string>
#include <fstream>
#include "Atividade02/src/color.h"
#include "Atividade03/src/model.h"

using namespace std;

#pragma once


/// Classe para desenhar e salvar imagens. Utiliza a biblioteca CImg.
class Drawer
{
private:
	std::ofstream* myfile;

    double aspect_ratio;
    int image_width;
    int image_height;

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width;
    vec3 camera_center = point3(0, 0, 0);

    vec3 viewport_u;
    vec3 viewport_v;

    vec3 pixel_delta_u = viewport_u;
    vec3 pixel_delta_v = viewport_v;

    // Calculate the location of the upper left pixel.
    vec3 viewport_upper_left;
    vec3 pixel00_loc;

public:
	/// Construtor de um desenhador de uma imagem específica.
	/// @param file Stream do arquivo a ser salvo.
    /// @param aspect_ratio Resolução da imagem.
    /// @param image_width Largura da imagem. A altura é calculada a partir dela e da resolução.
    /// @param focal_length Título do arquivo a ser salvo.
    /// @param viewport_height Título do arquivo a ser salvo.
    Drawer(std::ofstream* file, double aspect_ratio, int image_width, double focal_length, double viewport_height);

	/// Destructor, limpa o arquivo.
	~Drawer();


    /// Muda a posição da câmera.
    /// @param new_camera_pos Nova posição para a câmera.
    void set_camera_pos(vec3 new_camera_pos);


    /// Desenha pixel na imagem.
    /// @param pixel_color Cor do pixel a ser desenhado.
    void draw(color pixel_color);

    /// Desenha face na imagem.
    /// @param face Face a ser desenhada.
    /// @param face_color Cor da face.
    /// @param bg_color Cor do fundo.
    void draw(Face face, color face_color, color bg_color);

    /// Desenha modelo na imagem.
    /// @param model Modelo a ser desenhado.
    /// @param model_color Cor do modelo.
    /// @param bg_color Cor do fundo.
    void draw(Model model, color model_color, color bg_color);


};

