#include "Linkedlist.h"
#include <iostream>
#include <cstring>
#include <string>
#include "Circle.h"
#include "Rectangle.h"
#include "AreaTooLargeException.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

#define NAME "Graph Manager"
#define VERSION "0.0.1"
#define AUTHOR "Reyes"
#define NUMBER 22074420

bool mode = false; // false for list mode, true for vector mode

gm::Linkedlist<gm::Plane*> list;
std::vector<gm::Plane*> vector;

int main(int argc, char** argv) {
    if (argc > 3) {
        std::cerr << "Too many parameters entered. \nPlease enter gm help to check the usage." << std::endl;
        return 1;
    }
    else if (argc >= 2) {
        if (strcmp(argv[1], "help") == 0) {
            std::cout << "Usage: gm [command] [options] \n"
                      << "Commands: \n"
                      << "gm mode list: Enter List Mode.\n"
                      << "gm mode vector: Enter Vector Mode.\n"
                      << "gm version: Show the version of the program. \n"
                      << "gm help: Show the usage of the program. \n";
            return 0;
        }
        else if (strcmp(argv[1], "version") == 0) {
            std::cout << NAME << std::endl
                      << "Author: " << AUTHOR << std::endl
                      << "Student ID: " << NUMBER << std::endl
                      << "Version: " << VERSION << std::endl;
            return 0;
        }
        else if (strcmp(argv[1], "mode") == 0) {
            if (argc == 3) {
                if (strcmp(argv[2], "list") == 0) {
                    std::cout << "List mode." << std::endl;
                    mode = false;
                }
                else if (strcmp(argv[2], "vector") == 0) {
                    std::cout << "Vector mode." << std::endl;
                    mode = true;
                }
                else {
                    std::cout << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
                    return 1;
                }
            }
            else {
                std::cout << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
                return 1;
            }
        }
        else {
            std::cout << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
            return 1;
        }
    }
    while (true) {
        std::string command;
        std::cout << std::flush << "gm> ";
        getline(std::cin, command); // getline() is used to read the whole line (including spaces
        std::stringstream ss(command);
        std::string word;
        ss >> word;
        if (command == "exit") {
            break;
        }
        else if (command == "help") {
            std::cout << "Usage: [command] [options] \n"
                      << "Commands: \n"
                      << "mode list: Enter List Mode.\n"
                      << "mode vector: Enter Vector Mode.\n"
                      << "add circle [radius] [x] [y]: Add a circle to the manager. \n"
                      << "add rectangle [x1] [y1] [x2] [y2]: Add a rectangle to the manager. \n"
                      << "load [filename]: Load the data from the file. \n"
                      << "save [filename]: Save the data to the file. \n"
                      << "show: Show the data in the manager. \n"
                      << "clear: Clear the data in the manager. \n"
                      << "help: Show the usage of the program. \n"
                      << "version: Show the version of the program. \n";
        }
        else if (word == "mode") {
            ss >> word;
            if (word == "list") {
                std::cout << "List mode." << std::endl;
                mode = false;
            }
            else if (word == "vector") {
                std::cout << "Vector mode." << std::endl;
                mode = true;
            }
            else {
                std::cout << "Invalid command. \nPlease enter help to check the usage." << std::endl;
                continue;
            }
        }
        else if (command == "version") {
            std::cout << NAME << std::endl
                      << "Author: " << AUTHOR << std::endl
                      << "Student ID: " << NUMBER << std::endl
                      << "Version: " << VERSION << std::endl;
        }
        else if (word == "add") {
            std::string type;
            ss >> type;
            try {
                if (type != "circle" && type != "rectangle")
                    throw std::invalid_argument("Invalid command. \nPlease enter help to check the usage.");
                else if (type == "circle") {
                    double radius, x, y;
                    ss >> radius >> x >> y;
                    if (mode)
                        vector.push_back(new gm::Circle(gm::Point(x, y), radius));
                    else
                        list.add(new gm::Circle(gm::Point(x, y), radius));
                }
                else if (type == "rectangle") {
                    double x1, y1, x2, y2;
                    ss >> x1 >> y1 >> x2 >> y2;
                    if (mode)
                        vector.push_back(new gm::Rectangle(gm::Point(x1, y1), gm::Point(x2, y2)));
                    else
                        list.add(new gm::Rectangle(gm::Point(x1, y1), gm::Point(x2, y2)));
                }
            }
            catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
            catch (gm::AreaTooLargeException &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
            catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                return 1;
            }
            catch (...) {
                std::cerr << "Unknown error." << std::endl;
                return 1;
            }
        }
        else if (word == "load") {
            ss >> word;
            std::ifstream file(word, std::ios::in | std::ios::binary);
            if (!file.is_open()) {
                std::cerr << "File not found." << std::endl;
                continue;
            }
            char type;
            while (file.read(reinterpret_cast<char*>(&type), sizeof(char))) {
                if (type == 'c') {
                    gm::Circle* circle = new gm::Circle();
                    file.read(reinterpret_cast<char*>(circle), sizeof(gm::Circle));
                    if (mode)
                        vector.push_back(new gm::Circle(*circle));
                    else
                        list.add(new gm::Circle(*circle));
                }
                else if (type == 'r') {
                    gm::Rectangle* rectangle = new gm::Rectangle();
                    file.read(reinterpret_cast<char*>(rectangle), sizeof(gm::Rectangle));
                    if (mode)
                        vector.push_back(new gm::Rectangle(*rectangle));
                    else
                        list.add(new gm::Rectangle(*rectangle));
                }
            }
            std::clog << "File loaded." << std::endl;
        }
        else if (word == "save") {
            ss >> word;
            std::ofstream file(word, std::ios::out | std::ios::binary);
            if (!file.is_open()) {
                std::cerr << "File not found." << std::endl;
                continue;
            }
            if (mode)
                for (auto & i : vector) {
                    if (i->info().find("Circle") != std::string::npos) {
                        char type = 'c';
                        file.write(reinterpret_cast<char*>(&type), sizeof(char));
                        file.write(reinterpret_cast<char*>(&*dynamic_cast<gm::Circle*>(i)), sizeof(gm::Circle));
                    }
                    else if (i->info().find("Rectangle") != std::string::npos) {
                        char type = 'r';
                        file.write(reinterpret_cast<char*>(&type), sizeof(char));
                        file.write(reinterpret_cast<char*>(&*dynamic_cast<gm::Rectangle*>(i)), sizeof(gm::Rectangle));
                    }
                }
            else
                for (auto i = list.getHead(); i != nullptr; i = i->next)
                    if (i->data->info().find("Circle") != std::string::npos) {
                        char type = 'c';
                        file.write(reinterpret_cast<char*>(&type), sizeof(char));
                        file.write(reinterpret_cast<char*>(&*dynamic_cast<gm::Circle*>(i->data)), sizeof(gm::Circle));
                    }
                    else if (i->data->info().find("Rectangle") != std::string::npos) {
                        char type = 'r';
                        file.write(reinterpret_cast<char *>(&type), sizeof(char));
                        file.write(reinterpret_cast<char *>(&*dynamic_cast<gm::Rectangle *>(i->data)),
                                   sizeof(gm::Rectangle));
                    }
            std::clog << "File saved." << std::endl;
        }
        else if (command == "show") {
            if (mode) {
                sort(vector.begin(), vector.end(), [](gm::Plane* lhs, gm::Plane* rhs) { return lhs->getSize() < rhs->getSize(); });
                for (auto & i : vector)
                    std::cout << i->info() << std::endl;
            }
            else {
                list.sort([](gm::Plane* lhs, gm::Plane* rhs) { return lhs->getSize() > rhs->getSize(); });
                list.print();
            }
        }
        else if (command == "clear") {
            if (mode)
                vector.clear();
            else
                list.clear();
        }
        else {
            std::cout << "Invalid command. \nPlease enter help to check the usage." << std::endl;
            continue;
        }
    }
    return 0;
}
