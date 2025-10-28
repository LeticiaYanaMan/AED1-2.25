typedef struct {
  int *data;
  int N;
  int t;
  int s;
} Fcirc;

Fcirc v;
v.data = malloc(N * sizeof(int));
i = N;

// isso caso for para tras
if (delta s > delta t) { // delta s = N - s ; delta t = t-0
  for (i = 0; i < t; i++) {
    V[(N+i)%(N+1)] = V[i];
    t = t-1;
  }
}

// caso for para frente
else {
  s++; t++;
}
 
