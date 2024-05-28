#include <iostream>
#include <string>

using namespace std;

// Función auxiliar para repetir un patrón
string repeatPattern(const string& pattern, int count) {
    string result;
    for (int i = 0; i < count; ++i) {
        result.append(pattern);
    }
    return result;
}

// Función auxiliar para cada línea central
string centralLine(const string& text, int lineWidth) {
    int margin = (lineWidth - text.length()) / 2;
    string line = "*";
    line += repeatPattern("-", margin - 1);
    line.append(text);
    line += repeatPattern("-", margin - 1);
    line += "*";
    return line;
}

// Imprime las líneas del patrón decorativo
// El patrón decorativo puede ser superior o inferior (isUpper)
void printPatternLines(int c, int m, bool isUpper) {
    for (int i = 0; i < c; i++) {
        int index = isUpper ? i : (c - 1 - i);
        int times = (m - 3 * (1 + 2 * index)) / 2;
        string line(times, '-');
        line += repeatPattern(".|.", 1 + 2 * index);
        line += string(times, '-');
        cout << line << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Comprobar tamaño válido
    if (n <= 0 || m <= 0 || n % 2 == 0 || m % 3 != 0) {
        cerr << "n must be a positive odd number, m must be a positive multiple of 3\n";
        cerr << "n debe ser un número positivo impar y m debe ser múltiplo positivo de 3\n";
        return 1;
    }

    int c = n / 2;

    // Patrón superior
    printPatternLines(c, m, true);

    // Patrón central
    cout << centralLine("WELCOME", m) << endl;
    cout << centralLine("2", m) << endl;
    cout << centralLine("diegomendez40's", m) << endl;
    cout << centralLine("C/C++/ARM", m) << endl;
    cout << centralLine("Tech Library Lounge", m) << endl;

    // Patrón inferior
    printPatternLines(c, m, false);

    return 0;
}