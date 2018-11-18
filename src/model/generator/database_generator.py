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
    header += 'class DatabasePartial {\n'
    header += '\n'
    header += 'public:\n'
    header += '\n'
    header += '    DatabasePartial(\n'
    header += '        std::string p_user,\n'
    header += '        std::string p_pass,\n'
    header += '        std::string p_host,\n'
    header += '        std::string p_database\n'
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
    header += '    void fill();\n'
    header += '    void destroy();\n'
    header += '\n'
    header += 'protected:\n'
    header += '\n'
    header += '    std::string _user;\n'
    header += '    pqxx::connection _db;\n'
    header += '\n'
    header += '};\n'
    header += '\n'
    header += '}\n'
    header += '\n' 
    header += '#endif //__DATABASE__H__\n'    
    header += '\n'

    return header

def source(type_model, data_model, data_sql):

    source = ''

    source += '#include "database_partial.h"\n'
    source += '\n'
    source += '#include <iostream>\n'
    source += '\n'
    source += 'using namespace chronos;\n'
    source += '\n'
    source += 'DatabasePartial::DatabasePartial(\n'
    source += '    std::string p_user,\n'
    source += '    std::string p_password,\n'
    source += '    std::string p_host,\n'
    source += '    std::string p_database\n'
    source += '):\n'
    source += '    _user(p_user),\n'
    source += '    _db(\n'
    source += '        "host = " + p_host + " "\n'
    source += '        "dbname = " + p_database + " "\n'
    source += '        "user = " + p_user + " "\n'
    source += '        "password = " + p_password) {\n'
    source += '\n'
    source += '}\n'
    source += '\n'

    for class_model in data_model['classes']:

        source += \
            'std::vector<' +\
            utils.cpp_class_name(class_model) +\
            '> DatabasePartial::get_' +\
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

    source += 'void DatabasePartial::test() {\n'
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
    source += 'void DatabasePartial::init() {\n'
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
    source += 'void DatabasePartial::fill() {\n'
    source += '\n'
    source += '    std::vector<std::string> inserts;\n'
    source += '\n'

    for sql in data_sql:

        source += '    inserts.push_back("'+sql+'");\n'

    source += '    try {\n'
    source += '\n'
    source += '        pqxx::work w(_db);\n'
    source += '\n'
    source += '        for(auto insert : inserts) {\n' 
    source += '\n'
    source += '            w.exec(insert);\n'
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

    source += 'void DatabasePartial::destroy() {\n'
    source += '\n'
    source += '    try {\n'
    source += '\n'
    source += '        pqxx::work w(_db);\n'
    source += '        w.exec("DROP OWNED BY " + _user + ";");\n'
    source += '        w.commit();\n'
    source += '\n'
    source += '    } catch (std::exception& e) {\n'
    source += '\n'
    source += '        std::cerr << e.what();\n'
    source += '    }\n'
    source += '}\n'
    source += '\n'

    return source

def generate(path, type_model, data_model, data_sql, entities_directory_path):

    with open(os.path.join(path, 'database_partial.h'), 'w+') as file:
    
        file.write(header(type_model, data_model, entities_directory_path))
    
    with open(os.path.join(path, 'database_partial.cpp'), 'w+') as file:
    
        file.write(source(type_model, data_model, data_sql))

