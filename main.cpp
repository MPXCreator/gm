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
#include <ctime>

#define NAME "Graph Manager"
#define VERSION "1.0.0"
#define AUTHOR "Reyes"
#define NUMBER 22074420

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

bool mode = false; // false for list mode, true for vector mode

gm::Linkedlist<gm::Plane*> list;
std::vector<gm::Plane*> vector;

std::string logTime() {
    time_t now= time(nullptr);
    tm *ltm = localtime(&now);
    std::string time = "[" + std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" +
                       std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" +
                       std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + "]";
    return time;
}

int main(int argc, char** argv) {
    time_t now= time(nullptr);
    tm *ltm = localtime(&now);
    std::ofstream log("log-" + std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(1 + ltm->tm_mon) + "-" +
                               std::to_string(ltm->tm_mday) + "-" + std::to_string(ltm->tm_hour) + ":" +
                               std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) +
                               ".txt", std::ios::out | std::ios::app);
    if (!log.is_open()) {
        std::cerr << RED << "Log file cannot be opened." << std::endl;
        return 1;
    }
    std::clog.rdbuf(log.rdbuf());
    std::clog << NAME << " v" << VERSION << " by " << AUTHOR << " started with [" << argc << "] parameters at " << logTime() << "." << std::endl;
    if (argc > 3) {
        std::cerr << RED << "Too many parameters entered. \nPlease enter gm help to check the usage." << std::endl;
        std::clog << "[ERROR] " << logTime() << " " << "Too many parameters entered." << std::endl;
        return 1;
    }
    else if (argc >= 2) {
        if (strcmp(argv[1], "help") == 0) {
            std::cout << YELLOW
                      << "Usage: gm [command] [options] \n"
                      << "Commands: \n"
                      << "gm mode list: Enter List Mode.\n"
                      << "gm mode vector: Enter Vector Mode.\n"
                      << "gm version: Show the version of the program. \n"
                      << "gm help: Show the usage of the program. \n";
            std::clog << "[INFO] " << logTime() << " " << "Help called." << std::endl;
            return 0;
        }
        else if (strcmp(argv[1], "version") == 0) {
            std::cout << CYAN
                      << NAME << std::endl
                      << "Author: " << AUTHOR << std::endl
                      << "Student ID: " << NUMBER << std::endl
                      << "Version: " << VERSION << std::endl;
            std::clog << "[INFO] " << logTime() << " " << "Version called." << std::endl;
            return 0;
        }
        else if (strcmp(argv[1], "mode") == 0) {
            if (argc == 3) {
                if (strcmp(argv[2], "list") == 0) {
                    std::cout << GREEN << "List mode." << std::endl;
                    std::clog << "[INFO] " << logTime() << " " << "List mode." << std::endl;
                    mode = false;
                }
                else if (strcmp(argv[2], "vector") == 0) {
                    std::cout << GREEN << "Vector mode." << std::endl;
                    std::clog << "[INFO] " << logTime() << " " << "Vector mode." << std::endl;
                    mode = true;
                }
                else {
                    std::cout << RED << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
                    std::clog << "[ERROR] " << logTime() << " " << "Invalid command." << std::endl;
                    return 1;
                }
            }
            else {
                std::cout << RED << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << "Invalid command." << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << RED << "Invalid command. \nPlease enter gm help to check the usage." << std::endl;
            std::clog << "[ERROR] " << logTime() << " " << "Invalid command." << std::endl;
            return 1;
        }
    }
    while (true) {
        std::string command;
        std::cout << std::flush << RESET << "gm> ";
        getline(std::cin, command);
        std::clog << "[OPERATOR] " << logTime() << " " << command << std::endl;
        std::stringstream ss(command);
        std::string word;
        ss >> word;
        if (command == "exit") {
            std::cout << YELLOW << "Bye." << std::endl;
            std::clog << "[INFO] " << logTime() << " " << "Bye." << std::endl;
            break;
        }
        else if (command == "help") {
            std::cout << YELLOW
                      << "Usage: [command] [options] \n"
                      << "Commands: \n"
                      << "mode list: Enter List Mode.\n"
                      << "mode vector: Enter Vector Mode.\n"
                      << "add circle [radius] [x] [y]: Add a circle to the manager. \n"
                      << "add rectangle [x1] [y1] [x2] [y2]: Add a rectangle to the manager. \n"
                      << "load [filename]: Load the binary data from the file. \n"
                      << "save [filename]: Save the binary data to the file. \n"
                      << "show: Show the data in the manager. \n"
                      << "clear: Clear the data in the manager. \n"
                      << "help: Show the usage of the program. \n"
                      << "version: Show the version of the program. \n";
            std::clog << "[INFO] " << logTime() << " " << "Help called." << std::endl;
        }
        else if (word == "mode") {
            ss >> word;
            if (word == "list") {
                std::cout << GREEN << "List mode." << std::endl;
                std::clog << "[INFO] " << logTime() << " " << "List mode." << std::endl;
                mode = false;
                for (auto i : vector)
                    if (i->info().find("Circle") != std::string::npos)
                        list.add(new gm::Circle(*dynamic_cast<gm::Circle*>(i)));
                    else
                        list.add(new gm::Rectangle(*dynamic_cast<gm::Rectangle*>(i)));
                if (!vector.empty()) {
                    std::cout << YELLOW << "Data in vector moved to list." << std::endl;
                    std::clog << "[INFO] " << logTime() << " " << "Data in vector moved to list." << std::endl;
                }
                vector.clear();
            }
            else if (word == "vector") {
                std::cout << GREEN << "Vector mode." << std::endl;
                std::clog << "[INFO] " << logTime() << " " << "Vector mode." << std::endl;
                mode = true;
                for (auto i = list.getHead(); i != nullptr; i = i->next)
                    if (i->data->info().find("Circle") != std::string::npos)
                        vector.push_back(new gm::Circle(*dynamic_cast<gm::Circle*>(i->data)));
                    else
                        vector.push_back(new gm::Rectangle(*dynamic_cast<gm::Rectangle*>(i->data)));
                if (!list.isEmpty()) {
                    std::cout << YELLOW << "Data in list moved to vector." << std::endl;
                    std::clog << "[INFO] " << logTime() << " " << "Data in list moved to vector." << std::endl;
                }
                list.clear();
            }
            else {
                std::cerr << RED << "Invalid command. \nPlease enter help to check the usage." << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << "Invalid command." << std::endl;
                continue;
            }
        }
        else if (command == "version") {
            std::cout << CYAN
                      << NAME << std::endl
                      << "Author: " << AUTHOR << std::endl
                      << "Student ID: " << NUMBER << std::endl
                      << "Version: " << VERSION << std::endl;
            std::clog << "[INFO] " << logTime() << " " << "Version called." << std::endl;
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
                std::cout << GREEN << "Graph added." << std::endl;
                std::clog << "[INFO] " << logTime() << " " << "Graph added." << std::endl;
            }
            catch (std::invalid_argument &e) {
                std::cerr << RED << e.what() << std::endl;
                std::clog << "[ERROR] " << logTime() << " Invalid command." << std::endl;
                continue;
            }
            catch (gm::AreaTooLargeException &e) {
                std::cerr << RED << e.what() << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << e.what() << std::endl;
                continue;
            }
            catch (std::exception &e) {
                std::cerr << RED << e.what() << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << e.what() << std::endl;
                return 1;
            }
            catch (...) {
                std::cerr << RED << "Unknown ERROR." << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << "Unknown ERROR." << std::endl;
                return 1;
            }
        }
        else if (word == "load") {
            ss >> word;
            std::ifstream file(word, std::ios::in | std::ios::binary);
            if (!file.is_open()) {
                std::cerr << RED << "File not found." << std::endl;
                std::clog << "[ERROR] " << logTime() << " " << "File not found." << std::endl;
                continue;
            }
            char type;
            while (file.read(reinterpret_cast<char*>(&type), sizeof(char))) {
                if (type == 'c') {
                    auto circle = new gm::Circle();
                    file.read(reinterpret_cast<char*>(circle), sizeof(gm::Circle));
                    if (mode)
                        vector.push_back(new gm::Circle(*circle));
                    else
                        list.add(new gm::Circle(*circle));
                }
                else if (type == 'r') {
                    auto rectangle = new gm::Rectangle();
                    file.read(reinterpret_cast<char*>(rectangle), sizeof(gm::Rectangle));
                    if (mode)
                        vector.push_back(new gm::Rectangle(*rectangle));
                    else
                        list.add(new gm::Rectangle(*rectangle));
                }
            }
            std::clog << "[INFO] " << logTime() << " " << "File loaded." << std::endl;
            std::cout << GREEN << "File loaded." << std::endl;
        }
        else if (word == "save") {
            ss >> word;
            std::ofstream file(word, std::ios::out | std::ios::binary);
            if (!file.is_open()) {
                std::cerr << RED << "File not found." << std::endl;
                std::clog << "[INFO] " << logTime() << " " << "File not found." << std::endl;
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
            std::clog << "[INFO] " << logTime() << " " << "File saved." << std::endl;
            std::cout << GREEN << "File saved." << std::endl;
        }
        else if (command == "show") {
            std::clog << "[INFO] " << logTime() << " " << "Show called." << std::endl;
            if (mode) {
                sort(vector.begin(), vector.end(), [](gm::Plane* lhs, gm::Plane* rhs) { return lhs->getSize() < rhs->getSize(); });
                for (auto & i : vector) {
                    std::cout << YELLOW << i->info() << std::endl;
                    std::clog << "[DATA] " << logTime() << std::endl << i->info() << std::endl;
                }
            }
            else {
                list.sort([](gm::Plane* lhs, gm::Plane* rhs) { return lhs->getSize() > rhs->getSize(); });
                list.print();
                list.log();
            }
            std::clog << "[INFO] " << logTime() << " " << "Show finished." << std::endl;
        }
        else if (command == "clear") {
            if (mode)
                vector.clear();
            else
                list.clear();
            std::cout << GREEN << "Data cleared." << std::endl;
            std::clog << "[INFO] " << logTime() << " " << "Data cleared." << std::endl;
        }
        else {
            std::cerr << RED << "Invalid command. \nPlease enter help to check the usage." << std::endl;
            std::clog << "[ERROR] " << logTime() << " " << "Invalid command." << std::endl;
            continue;
        }
    }
    return 0;
}
