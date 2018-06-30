# Implementação: Casamento de Strings com Autômatos Finitos

Casamento de strings baseado em automatos finitos implementado na linguagem C

## Como usar

Assim que executar o programa, ira pedir uma palavra, esta que sera considerada a sua fita do automato, e logo apos, digitar a substring, 
que sera a regra para aceitaçao da sua palavra. 
Escolha uma opcao do menu para rodar qual dos automatos voce desejar, caso queira escolher outra palavra ou sair do programa, escolha a 
opcao para sair.

### Subpalavra

Para simular um automato para achar uma subpalavra, o programa ira rodar dois lacos de repeticao
em conjunto. O primeiro ira percorrer a palavra da fita, caso achar um caractere da fita que
for igual ao primeiro caractere da regra, ele ira abrir um outro laco, desta vez percorrendo 
a subpalavra. Dentro desse laco, ele vai comparar todos os caracteres da palavra da fita com os
caracteres da subpalavra, ate acabar o tamanho da subpalavra. Caso no meio desse novo laco, uma letra da .
fita nao bata com a da subpalavra,o programa quebra e volta para o primeiro laco. Caso a subpalavra acabe, e as letras da fita
baterem com todas as letras da subpalavra, isso quer dizer que o programa chegou ao estado final e é atribuido um valor
negativo a variavel q, o que signigica, que o programa chegou a um estado final, e mesmo que nao ocorram mais ocorrencias
da subpalavra na fita, o programa ira identificar depois que o automato ja esta em seu estado final.



### Prefixo

No automato do prefixo, o programa ira fazer a comparação inicial, que é o primeiro caractere da fita
com o primeiro caractere do prefixo. Caso atenda a essa condição, eh criado um laco para percorrer os caracteres
do prefixo, caso todos os caracteres do prefixo baterem com a sequencia da fita, é atribuido um valor negativo a q 
e o automato entra em um estado final. Caso um dos caracteres for diferente no meio do laço, o programa quebra e ja
sabe que essa palavra nao tem esse prefixo. No caso do primeiro caractere da fita nao ser igual ao primeiro caractere 
do prefixo, na hora o programa ja quebra e avisa que nao é um prefixo.

### Sufixo

No automato de sufixo, ele ira funcionar exatamente como o da subpalavra, com os mesmos lacos e mesma logica, porem,
com uma condicao a mais: ele só aceitara a palavra da fita caso, dentro do laço dos caracteres do sufixo, o sufixo acabe 
e a palavra também acabe. Desta forma, mesmo que ocorram ocorrencias do sufixo, mas nao no final, essa palavra nao sera aceita.



## Autor

* **Bruno Mendonça Santos**


