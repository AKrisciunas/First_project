#include "Mylib.h"
#include "Stud.h"
#include <fstream>

void readFile(vector<Stud> &Vec, string fileName){
    try {
        std::ifstream input(fileName);

        if (!input.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        string line, column;
        int countND=0;
        std::getline(input, line);
        std::istringstream header(line);

        //counting columns from first line
        while (header >> column)
            countND++;

        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            Stud S;

            iss >> S.name >> S.surname;

            int temp;
            for (int i = 0; i < countND-3; i++) {
                if (iss >> temp) {
                    S.nd.push_back(temp);
                }
            }

            iss >> S.egz;
            Vec.push_back(S);
        }
        input.close();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void writeFile(vector<Stud> V, string fileName, int countND) {
    std::ostringstream buffer;
    buffer << std::left << setw(20) << "Vardas" << setw(20) << "Pavarde"; 
    for (int i = 0; i < countND; i++) buffer << setw(20) << "ND" + std::to_string(i+1);
    buffer << "Egz.\n";    
    for (const auto& stud : V) {
        buffer << setw(20) << stud.name << setw(20) << stud.surname << " ";
        for (int i = 0; i < countND; i++)   buffer << setw(20) << stud.nd.at(i)<< " ";   
        buffer << setw(20) << stud.egz << "\n";
    }

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file\n";
        return;
    }
    file << buffer.str();  
    file.close();

}