#include <iostream>
#include <vector>

constexpr int TAMANHO = 9;

bool eh_valido(const std::vector<std::vector<int>>& matriz) {
    for (int i = 0; i < TAMANHO; ++i) {
        std::vector<int> freq(10, 0);
        for (int j = 0; j < TAMANHO; ++j) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || freq[num]) return false;
            freq[num] = 1;
        }
    }

    for (int j = 0; j < TAMANHO; ++j) {
        std::vector<int> freq(10, 0);
        for (int i = 0; i < TAMANHO; ++i) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || freq[num]) return false;
            freq[num] = 1;
        }
    }

    for (int bloco_i = 0; bloco_i < 3; ++bloco_i) {
        for (int bloco_j = 0; bloco_j < 3; ++bloco_j) {
            std::vector<int> freq(10, 0);
            for (int i = bloco_i * 3; i < bloco_i * 3 + 3; ++i) {
                for (int j = bloco_j * 3; j < bloco_j * 3 + 3; ++j) {
                    int num = matriz[i][j];
                    if (num < 1 || num > 9 || freq[num]) return false;
                    freq[num] = 1;
                }
            }
        }
    }

    return true;
}

int main() {
    int n, instancia = 1;
    std::cin >> n;

    while (n--) {
        std::vector<std::vector<int>> matriz(TAMANHO, std::vector<int>(TAMANHO));
        for (int i = 0; i < TAMANHO; ++i)
            for (int j = 0; j < TAMANHO; ++j)
                std::cin >> matriz[i][j];

        std::cout << "Instancia " << instancia++ << "\n";
        std::cout << (eh_valido(matriz) ? "SIM" : "NAO") << "\n\n";
    }

    return 0;
}
