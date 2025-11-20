#include <iostream> 
#include <vector> 
#include <unordered_map> 
 
int solvePaths(std::vector<std::vector<int>> const &matrix, int i, int j, int 
cost, std::unordered_map<std::string, int> &uMap){ 
    if( cost < 0) return 0; 
 
    if( i == 0 && j == 0 ){ 
        if( matrix[0][0] - cost == 0) return 1; 
        else return 0; 
    } 
    std::string key = std::to_string(i) + std::to_string(j) + 
std::to_string(cost); 
    if( uMap.find(key) == uMap.end() ){ 
        if ( i == 0 ) uMap[key] = solvePaths(matrix, 0, j - 1, cost - 
matrix[i][j], uMap); 
        else if ( j == 0 ) uMap[key] = solvePaths(matrix, i - 1, 0, cost - 
matrix[i][j], uMap); 
        else uMap[key] = solvePaths(matrix, i - 1, j, cost - matrix[i][j], uMap) + 
solvePaths(matrix, i, j - 1, cost - matrix[i][j], uMap); 
    } 
    return uMap[key]; 
} 
 
int solvePaths(std::vector<std::vector<int>> const &matrix, int cost){ 
    if( matrix.size() == 0) return 0; 
    int I = matrix.size(); 
    int J = matrix[0].size(); 
    std::unordered_map<std::string, int> uMap; 
    return solvePaths(matrix, I - 1, J - 1, cost, uMap); 
}

int main(){ 
    std::vector<std::vector<int>> matrix = { 
            { 4, 7, 1, 6 }, 
            { 6, 7, 3, 9 }, 
            { 3, 8, 1, 2 }, 
            { 7, 1, 7, 3 } 
    }; 
    int cost = 21; 
    std::cout << solvePaths(matrix, cost); 
} 