import os
import utils

def header(type_model, data_model, entities_directory_path):

    header = ''
    
    header += '#pragma once\n'
    header += '\n'
    header += '#ifndef __DATABASE__H__\n'    
    header += '#define __DATABASE__H__\n'    
    header += '\n'
    header += '#include <string>\n'
    header += '#include <vector>\n'
    header += '\n'
    header += '#include <pqxx/pqxx>\n'
    header += '\n'
    
    for class_model in data_model['classes']:

        # Hot fix. Entity path has ../ in it.
        header += \
            '#include "model/' +\
            entities_directory_path[3:] +\
            '/' +\
            class_model['class'] +\
            '.h"\n'

    header += '\n'
    header += 'namespace chronos {\n' 
    header += '\n'
    header += 'class Database {\n'
    header += '\n'
    header += 'public:\n'
    header += '\n'
    header += '    Database(\n'
    header += '        std::string user,\n'
    header += '        std::string pass,\n'
    header += '        std::string host = "localhost",\n'
    header += '        std::string database = "chronos"\n'
    header += '    );\n'
    header += '\n' 

    for class_model in data_model['classes']:

        header += \
            '    std::vector<' +\
            utils.cpp_class_name(class_model) +\
            '> get_' +\
            utils.plural(class_model['class']) +\
            '();\n'

    header += '\n'
    header += '    void test();\n'
    header += '    void init();\n'
    header += '    void destroy();\n'
    header += '\n'
    header += 'private:\n'
    header += '\n'
    header += '    pqxx::connection _db;'
    header += '\n'
    header += '};\n'
    header += '\n'
    header += '}\n'
    header += '\n' 
    header += '#endif //__DATABASE__H__\n'    
    header += '\n'

    return header

def source(type_model, data_model):

    source = ''

    source += '#include "database.h"\n'
    source += '\n'
    source += '#include <iostream>\n'
    source += '\n'
    source += 'using namespace chronos;\n'
    source += '\n'
    source += 'Database::Database(\n'
    source += '    std::string user,\n'
    source += '    std::string password,\n'
    source += '    std::string host,\n'
    source += '    std::string database\n'
    source += '):\n'
    source += '    _db(\n'
    source += '        "host = " + host + " "\n'
    source += '        "dbname = " + database + " "\n'
    source += '        "user = " + user + " "\n'
    source += '        "password = " + password) {\n'
    source += '\n'
    source += '}\n'
    source += '\n'

    for class_model in data_model['classes']:

        source += \
            'std::vector<' +\
            utils.cpp_class_name(class_model) +\
            '> Database::get_' +\
            utils.plural(class_model['class']) +\
            '() {\n'

        source += '\n'

        source += \
            '    std::vector<' +\
            utils.cpp_class_name(class_model) +\
            '> ret;\n'

        source += '\n'
        source += '    try {\n'
        source += '\n'
        source += '        pqxx::nontransaction n(_db);\n'
        source += '\n'

        source += \
            '        pqxx::result r(n.exec("SELECT * FROM ' +\
            utils.plural(class_model['class']) +\
            ';"));\n'
        
        source += '\n'
        source += '        for(auto i = r.begin(); i != r.end(); ++i) {\n'
        source += '\n'
        source += \
            '            ' +\
            utils.cpp_class_name(class_model) +\
            ' p(\n' 

        for i, member in enumerate(utils.cpp_class_members(type_model, data_model, class_model)):

            source += \
                '                i[' +\
                str(i) +\
                '].as<' +\
                type_model[member['type']]['cpp'] +\
                '>()' +\
                (',' if i != len(utils.cpp_class_members(type_model, data_model, class_model))-1 else '') +\
                ' // ' +\
                member['name'] +\
                '\n'

        source += '            );\n'
        source += '\n'
        source += '            ret.push_back(p);\n'
        source += '        }\n'
        source += '\n'
        source += '    } catch (std::exception& e) {\n'
        source += '\n'
        source += '        std::cerr << e.what() << std::endl;\n'
        source += '    }\n'
        source += '\n'
        source += '    return ret;\n'
        source += '}\n'
        source += '\n'

    source += 'void Database::test() {\n'
    source += '\n'
    source += '    if(_db.is_open()) {\n'
    source += '\n'
    source += '        std::cout << "Connection successful!" << std::endl;\n'
    source += '\n'
    source += '    } else {\n'
    source += '\n'
    source += '        std::cout << "Connection failed." << std::endl;\n'
    source += '    }\n'
    source += '}\n'
    source += '\n'
    source += 'void Database::init() {\n'
    source += '\n'
    source += '    std::vector<std::string> creates;\n'
    source += '\n'

    for class_model in data_model['classes']:

        source += '    creates.push_back(\n'
        source += \
            '        "CREATE TABLE ' +\
            utils.plural(class_model['class']) +\
            ' ( "\n'

        for i, member in enumerate(utils.sql_class_members(type_model, data_model, class_model)):
        
            source += \
                '            "' +\
                member +\
                (', ' if i != len(utils.sql_class_members(type_model, data_model, class_model))-1 else ');') +\
                '"\n'

        source += '    );\n'
        source += '\n'

    source += '    try {\n'
    source += '\n'
    source += '        pqxx::work w(_db);\n'
    source += '\n'
    source += '        for(auto create : creates) {\n' 
    source += '\n'
    source += '            w.exec(create);\n'
    source += '        }\n'
    source += '\n'
    source += '        w.commit();\n'
    source += '\n'
    source += '    } catch (std::exception& e) {\n'
    source += '\n'
    source += '        std::cerr << e.what();\n'
    source += '    }\n'
    source += '}\n'
    source += '\n'
    source += 'void Database::destroy() {\n'
    source += '\n'
    source += '    std::vector<std::string> drops;\n'
    source += '\n'

    for class_model in data_model['classes']:

        source += \
            '    drops.push_back("DROP TABLE ' +\
            utils.plural(class_model['class']) +\
            ' CASCADE;");\n'

    source += '\n'
    source += '    try {\n'
    source += '\n'
    source += '        pqxx::work w(_db);\n'
    source += '\n'
    source += '        for(auto drop : drops) {\n'
    source += '            \n'
    source += '            w.exec(drop);\n'
    source += '        }\n'
    source += '\n'
    source += '        w.commit();\n'
    source += '\n'
    source += '    } catch (std::exception& e) {\n'
    source += '\n'
    source += '        std::cerr << e.what();\n'
    source += '    }\n'
    source += '}\n'
    source += '\n'

    return source

def generate(path, type_model, data_model, entities_directory_path):

    with open(os.path.join(path, 'database.h'), 'w+') as file:
    
        file.write(header(type_model, data_model, entities_directory_path))
    
    with open(os.path.join(path, 'database.cpp'), 'w+') as file:
    
        file.write(source(type_model, data_model))

