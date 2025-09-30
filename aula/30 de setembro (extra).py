print("Hello World!") # equivale a desde o include <stdio.h> até o return 0 de um codigo em C que faz a mesma coisa --- não precisa declarar biblioteca
#alem de ser mais facil de escrever, ocupa menos linhas 

##########################################

def maixmo(a, b): #os blocos começam com : --- não precisa colocar chaves, nem noc meço e nem precisa indiciar fim --- a indentação é bem importante 
  if a > b:
    return a
  else:
    return b # o proprio codigo reconhece se for int, char --- voce n precisa escrever como em C

##########################################

def potencia(a, b):
  prod = 1
  for i in range(b):
    prod = a * prod
  return prod

##########################################

print("Entre com a e b")
a = int(input()) #quando voce recebe uma varivael, precisa dizer qual tipo de dado voce quer que ele seja declarado
b = int(input())
maior = maximo(a, b)
pot = potencia(a, b)
print("Maior: ", maior)
print("a ^b: ", pot)

##########################################

print("Digite 10 números")
lista = [] 
for i in tange(10):
  lista.append(int(input())) # vai adicionando ao vetor de acordo com a quanntidade colocada no range --- não precisa declarar o vetor já definidamente como 10
print("Positivos")
for x in lista:
  if x > 0: # para ver se é maior que 0 
    print(x)

##########################################

a = [10, 20, 30, 40, 50]
a[1] = 25
print(a) 
#imprime certinho a lista, não precisa colocar num for 

##########################################

matriz = [[8, 10, 20]
          [20, 30, 40]
          [50, 60, 70]]
#bem mais facil de declarar matrizes

##########################################
















