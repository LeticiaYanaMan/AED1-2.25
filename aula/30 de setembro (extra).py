print("Hello World!") # equivale a desde o include <stdio.h> até o return 0 de um codigo em C que faz a mesma coisa --- não precisa declarar biblioteca

-----------------------------------------------

def maixmo(a, b): #os blocos começam com : --- não precisa colocar chaves, nem noc meço e nem precisa indiciar fim --- a indentação é bem importante 
  if a > b:
    return a
  else:
    return b # o proprio codigo reconhece se for int, char --- voce n precisa escrever como em C

---------------------------------------------

def potencia(a, b):
  prod = 1
  for i in range(b):
    prod = a * prod
  return prod

--------------------------------------------

print("Entre com a e b")
a = int(input()) #quando voce recebe uma varivael, precisa dizer qual tipo de dado voce quer que ele seja declarado
b = int(input())
maior = maximo(a, b)
pot = potencia(a, b)
print("Maior: ", maior)
print("a ^b: ", pot)

--------------------------------------------














