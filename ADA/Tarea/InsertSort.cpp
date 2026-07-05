#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int editDistance(string sourceString, string targetString) {
    int m = sourceString.length();
    int n = targetString.length();
    vector<vector<int>> dpTable(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) {
        dpTable[i][0] = i;
    }
    
    for (int j = 0; j <= n; j++) {
        dpTable[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sourceString[i - 1] == targetString[j - 1]) {
                dpTable[i][j] = dpTable[i - 1][j - 1];
            } else {
                int insertOp = dpTable[i][j - 1];
                int deleteOp = dpTable[i - 1][j];
                int replaceOp = dpTable[i - 1][j - 1];
                dpTable[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
            }
        }
    }
    
    return dpTable[m][n];
}

vector<string> reconstructOperations(string sourceString, string targetString) {
    int m = sourceString.length();
    int n = targetString.length();
    vector<vector<int>> dpTable(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) {
        dpTable[i][0] = i;
    }
    
    for (int j = 0; j <= n; j++) {
        dpTable[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sourceString[i - 1] == targetString[j - 1]) {
                dpTable[i][j] = dpTable[i - 1][j - 1];
            } else {
                dpTable[i][j] = 1 + min({dpTable[i][j - 1], dpTable[i - 1][j], dpTable[i - 1][j - 1]});
            }
        }
    }
    
    vector<string> operations;
    int i = m, j = n;
    string currentString = sourceString;
    
    while (i > 0 || j > 0) {
        if (i == 0) {
            operations.push_back("Insertar '" + string(1, targetString[j - 1]) + "' en posicion " + to_string(i));
            j--;
        } else if (j == 0) {
            operations.push_back("Eliminar '" + string(1, sourceString[i - 1]) + "' en posicion " + to_string(i));
            i--;
        } else if (sourceString[i - 1] == targetString[j - 1]) {
            i--;
            j--;
        } else {
            int insertCost = dpTable[i][j - 1];
            int deleteCost = dpTable[i - 1][j];
            int replaceCost = dpTable[i - 1][j - 1];
            
            if (replaceCost <= insertCost && replaceCost <= deleteCost) {
                operations.push_back("Sustituir '" + string(1, sourceString[i - 1]) + "' por '" + 
                                    string(1, targetString[j - 1]) + "' en posicion " + to_string(i));
                i--;
                j--;
            } else if (deleteCost <= insertCost) {
                operations.push_back("Eliminar '" + string(1, sourceString[i - 1]) + "' en posicion " + to_string(i));
                i--;
            } else {
                operations.push_back("Insertar '" + string(1, targetString[j - 1]) + "' en posicion " + to_string(i + 1));
                j--;
            }
        }
    }
    
    reverse(operations.begin(), operations.end());
    return operations;
}

void printDpTable(string sourceString, string targetString) {
    int m = sourceString.length();
    int n = targetString.length();
    vector<vector<int>> dpTable(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) {
        dpTable[i][0] = i;
    }
    
    for (int j = 0; j <= n; j++) {
        dpTable[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sourceString[i - 1] == targetString[j - 1]) {
                dpTable[i][j] = dpTable[i - 1][j - 1];
            } else {
                dpTable[i][j] = 1 + min({dpTable[i][j - 1], dpTable[i - 1][j], dpTable[i - 1][j - 1]});
            }
        }
    }
    
    cout << "\nTabla DP (Distancia de Edicion):\n";
    cout << "       ";
    for (int j = 0; j < n; j++) {
        cout << setw(3) << targetString[j];
    }
    cout << "\n    ";
    for (int j = 0; j <= n; j++) {
        cout << setw(3) << dpTable[0][j];
    }
    cout << "\n";
    
    for (int i = 1; i <= m; i++) {
        cout << sourceString[i - 1] << "   ";
        for (int j = 0; j <= n; j++) {
            cout << setw(3) << dpTable[i][j];
        }
        cout << "\n";
    }
}

void analyzeWordTransformations() {
    vector<pair<string, string>> wordPairs = {
        {"KITTEN", "SITTING"},
        {"SATURDAY", "SUNDAY"},
        {"ALGORITHM", "ALTRUISM"},
        {"INTENTION", "EXECUTION"},
        {"HORSE", "ROS"}
    };
    
    for (auto& pair : wordPairs) {
        int distance = editDistance(pair.first, pair.second);
        cout << "\n\"" << pair.first << "\" -> \"" << pair.second << "\"";
        cout << "\nDistancia de edicion: " << distance << " operaciones\n";
    }
}

void demonstrateApplications() {
    vector<string> dictionary = {"hello", "help", "hell", "hero", "helm"};
    string misspelled = "helo";
    
    cout << "\nCorreccion ortografica:\n";
    cout << "Palabra mal escrita: \"" << misspelled << "\"\n";
    cout << "Sugerencias (distancia de edicion):\n";
    
    vector<pair<int, string>> suggestions;
    for (string& word : dictionary) {
        int distance = editDistance(misspelled, word);
        suggestions.push_back({distance, word});
    }
    
    sort(suggestions.begin(), suggestions.end());
    
    for (auto& suggestion : suggestions) {
        cout << "  - \"" << suggestion.second << "\" (distancia: " 
             << suggestion.first << ")\n";
    }
}

int main() {
    string source = "SATURDAY";
    string target = "SUNDAY";
    
    cout << "=== DISTANCIA DE EDICION (LEVENSHTEIN) ===\n\n";
    cout << "Cadena origen:  \"" << source << "\"\n";
    cout << "Cadena destino: \"" << target << "\"\n";
    
    int minDistance = editDistance(source, target);
    cout << "\nDistancia minima de edicion: " << minDistance << " operaciones\n";
    
    printDpTable(source, target);
    
    vector<string> operations = reconstructOperations(source, target);
    for (int i = 0; i < operations.size(); i++) {
        cout << (i + 1) << ". " << operations[i] << "\n";
    }
    
    cout << "1. dpTable[i][j] = distancia minima entre los primeros i caracteres\n";
    cout << "   de la cadena origen y j caracteres de la cadena destino\n";
    cout << "2. Tres operaciones posibles:\n";
    cout << "   - Insertar: dpTable[i][j-1] + 1\n";
    cout << "   - Eliminar: dpTable[i-1][j] + 1\n";
    cout << "   - Sustituir: dpTable[i-1][j-1] + 1\n";
    cout << "3. Si caracteres coinciden: dpTable[i][j] = dpTable[i-1][j-1]\n";
    
    analyzeWordTransformations();
    demonstrateApplications();
    
    return 0;
}




