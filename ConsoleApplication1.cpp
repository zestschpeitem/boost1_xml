#include <boost/property_tree/ptree.hpp>                                                    
#include <boost/property_tree/xml_parser.hpp>                                               
#include <boost/property_tree/detail/file_parser_error.hpp>                                 
#include <iostream>   
#include <string>

using namespace std;

namespace pt = boost::property_tree;

int check(const string& name_file) { //функция проверяет на наличие нужного файла проверка на путь. Функция которая будет проверять путь.
    try {
        if (std::ifstream(name_file)){
            return 0;
        }
        else {
            cout << "File not find!!!";
                return -1;
        }
    }
    catch (...) {
        std::cout << "Failed !!!";
        return -1;
    }   
}
int output_id_type(const string& name_file) {//вывод пар id и type
    pt::ptree id_type_tree;
    read_xml(name_file, id_type_tree);
    pt::ptree::const_assoc_iterator it;
    it = id_type_tree.find("videoSource");
    if (it != id_type_tree.not_found()) {
        for (auto& m : id_type_tree.get_child("videoSource")) {
            for (auto& p : m.second) {
                for (auto& c : p.second) {
                    if (c.first == "id")
                    {
                        std::cout << "id:" << " " << c.second.data() << "" << std::endl;
                    }
                    if (c.first == "type") {
                        std::cout << "type:" << " " << c.second.data() << "" << std::endl;
                    }
                }
            }
            std::cout << "\n";
        }
        return 0;
    }
    else {
        cout << "videoSource not find";
        return -1;
    }
}
int main(int argc, char* argv[])
{
    if (argc < 1 || argc > 2) {
        cout << "Error!";
        return -1;
    }
    else {
        const string name_file(argv[1]);
            if (check(name_file) == -1) {
                return -1;
            }
            else {
                return output_id_type(name_file);
            }
        }
    }

