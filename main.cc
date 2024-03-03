//
// Created by aurelien on 03/03/24.
//
#include <fstream>
#include <iostream>
#include <vector>

int main () {
    std::cout << "Rentrez ci-dessous le nom du fichier contenant la liste d'emal\n";
    std::string email_list;
    std::cin >> email_list;
    std::fstream file;
    file.open(email_list);
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : " + email_list + '\n');
    std::vector<std::string> email_vector;
    std::string line;

    // Read the file line by line
    while (std::getline(file, line)) {
        email_vector.push_back(line);
    }

    // Load the second file
    std::cout << "Rentrez ci-dessous le nom du fichier contenant la liste d'email ayant réservé\n";
    std::string email_reserve;
    std::cin >> email_reserve;
    file.open(email_reserve);
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : " + email_reserve + '\n');
    std::vector<std::string> email_reserve_vector;
    while (std::getline(file, line)) {
        email_reserve_vector.push_back(line);
    }

    // Compare the two vectors
    std::vector<std::string> email_not_reserve;
    for (const auto &email : email_vector) {
        if (std::find(email_reserve_vector.begin(), email_reserve_vector.end(), email) == email_reserve_vector.end()) {
            email_not_reserve.push_back(email);
        }
    }

    // Write the result in a file
    std::cout << "Rentrez ci-dessous le nom du fichier dans lequel vous voulez écrire le résultat\n";
    std::string email_not_reserve_file;
    std::cin >> email_not_reserve_file;
    file.open(email_not_reserve_file, std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : " + email_not_reserve_file + '\n');
    for (const auto &email : email_not_reserve) {
        file << email << '\n';
    }
    return 0;
}