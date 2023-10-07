# Atividade 1

## Classe Painter
A classe Painter foi criada para salvar e desenhar imagens. Ela possui 4 funções relevantes:
- get_empty_canvas
- draw_circle
- draw_horizontal_gradient
- save

A pasta doc carrega a documentação desta atividade.


### Círculo
Para a imagem do círculo, foram utilizadas as funções get_empty_canvas, draw_circle e save.
A função draw_circle calcula a distância dos pontos do canvas ao centro, e, se estiver abaixo do valor do raio, muda sua cor.

### Gradiente
Para a imagem do gradiente, foram utilizadas as funções get_empty_canvas, draw_horizontal_gradient e save.
A função draw_horizontal_gradient interpola a cor de gradiente baseado na porcentagem de proximidade do pixel da coordenada extrema
esquerda até a direita.

### Quadrado
Para a imagem do quadrado, foram utilizadas as funções get_empty_canvas, draw_horizontal_gradient e save.
Na função de gradiente, as mesmas duas cores foram dadas. Assim, o quadrado ficou com a mesma cor por toda sua extensão.