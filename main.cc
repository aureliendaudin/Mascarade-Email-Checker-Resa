//
// Created by aurelien on 03/03/24.
//
#include <fstream>
#include <iostream>
#include <vector>

int main () {
    /* std::cout << "Rentrez ci-dessous le nom du fichier contenant la liste d'emal\n";
    std::string email_list;
    std::cin >> email_list;*/
    std::fstream file;
    file.open("liste_email.csv");
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : liste_email.csv\n");
    std::vector<std::string> email_vector;
    std::string line;

    // Read the file line by line
    while (std::getline(file, line)) {
        email_vector.push_back(line);
    }
    file.close();

    // Load the second file
    /* std::cout << "Rentrez ci-dessous le nom du fichier contenant la liste d'email ayant réservé\n";
    std::string email_reserve;
    std::cin >> email_reserve;*/
    file.open("liste_email_reservation.csv");
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : liste_email_reservation.csv\n");
    std::vector<std::string> email_reserve_vector;
    while (std::getline(file, line)) {
        email_reserve_vector.push_back(line);
    }

    file.close();
    // Compare the two vectors
    std::vector<std::string> email_not_reserve;
    for (const auto &e : email_vector) {
        int i = 0;
        for (; i < email_reserve_vector.size(); ++i) {
            if (e == email_reserve_vector[i]) {
                break;
            }
        }
        if (i == email_reserve_vector.size())
            email_not_reserve.push_back(e);
    }

    // Write the result in a file
    /*std::cout << "Rentrez ci-dessous le nom du fichier dans lequel vous voulez écrire le résultat\n";
    std::string email_not_reserve_file;
    std::cin >> email_not_reserve_file;*/
    file.open("./liste_email_sans_reservation.txt", std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Je n'ai pas trouvé de fichier avec le nom : liste_email_sans_reservation.txt\n");
    for (const auto &email : email_not_reserve) {
        file << email << '\n';
    }
    file.close();
    return 0;
}