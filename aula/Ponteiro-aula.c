int v = 65;
int *p;
p = &v;
printf("%d\n", p); // vai declarar 65
printf("%d\n", *p); // vai declarar o endereço, em numeros, do espaço de v

se eu tivese declarado
char *p;
printf("%s\n", p); // vai declarar A -- correspondente ao numero 65 na tabela ASCII
