// veiculo.h
typedef struct Veiculo {
    char placa[8];
    char dia_semana[15];
    char horario[30];
    struct Veiculo* proximo;
} Veiculo;

typedef struct {
    Veiculo* inicio;
    int quantidade;
} ListaCircular;
