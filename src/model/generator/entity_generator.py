import os
import utils

def header(type_model, data_model, class_model):

    header = ''
     
    header += '#pragma once\n'
    header += '\n'
    header += '#ifndef __' + class_model['class'].upper() + '__H__\n'
    header += '#define __' + class_model['class'].upper() + '__H__\n'
    header += '\n'
    header += '#include <string>\n'
    header += '\n'
    header += 'namespace chronos {\n'
    header += '\n'
    header += 'class ' + utils.cpp_class_name(class_model) + ' {\n'
    header += '\n'
    header += 'public:\n'
    header += '\n'
    header += '    ' + utils.cpp_class_name(class_model) + '();\n'
    header += '\n'
    header += '    ' + utils.cpp_class_name(class_model) + '(\n'
  
    for i, member in enumerate(utils.cpp_class_members(type_model, data_model, class_model)):
        
        header += \
            '        ' +\
            type_model[member['type']]['cpp'] +\
            ' p_' +\
            member['name'] +\
            (',' if i != len(utils.cpp_class_members(type_model, data_model, class_model))-1 else '') +\
            '\n'
    
    header += '    );\n'
    header += '\n'
    
    for member in utils.cpp_class_members(type_model, data_model, class_model):
    
        header += \
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' ' +\
            member['name'] +\
            '() const;\n'
    
    header += '    std::string to_string() const;\n'
    header += '\n'
    header += 'private:\n'
    header += '\n'
    
    for member in utils.cpp_class_members(type_model, data_model, class_model):
    
        header += \
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' _' +\
            member['name'] +\
            ';\n'
    
    header += '\n'
    header += '};\n'
    header += '\n'
    header += '}\n'
    header += '\n'
    header += '#endif //__' + class_model['class'].upper() + '__H__\n'
    header += '\n'
    
    return header   

def source(type_model, data_model, class_model):

    source = ''
     
    source += '#include "' + class_model['class'] + '.h"\n'
    source += '\n'
    source += '#include <sstream>\n'
    source += '\n'
    source += 'using namespace chronos;\n'
    source += '\n'
    source += utils.cpp_class_name(class_model) + '::' + utils.cpp_class_name(class_model) + '(\n'
    source += ') :\n'
    
    for i, member in enumerate(utils.cpp_class_members(type_model, data_model, class_model)):
    
        source += \
            '    _' +\
            member['name'] +\
            '(' +\
            type_model[member['type']]['default_value'] +\
            ')' +\
            (',' if i != len(utils.cpp_class_members(type_model, data_model, class_model))-1 else ' {') +\
            '\n'
   
    source += '\n'
    source += '}\n'
    source += '\n'
    source += utils.cpp_class_name(class_model) + '::' + utils.cpp_class_name(class_model) + '(\n' 

    for i, member in enumerate(utils.cpp_class_members(type_model, data_model, class_model)):
        
        source += \
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' p_' +\
            member['name'] +\
            (',' if i != len(utils.cpp_class_members(type_model, data_model, class_model))-1 else '') +\
            '\n'
    
    source += ') :\n'
    
    for i, member in enumerate(utils.cpp_class_members(type_model, data_model, class_model)):
    
        source += \
            '    _' +\
            member['name'] +\
            '(p_' +\
            member['name'] +\
            ')' +\
            (',' if i != len(utils.cpp_class_members(type_model, data_model, class_model))-1 else ' {') +\
            '\n'

    source += '\n'
    source += '}\n'
    source += '\n' 

    for member in utils.cpp_class_members(type_model, data_model, class_model):
    
        source += \
            type_model[member['type']]['cpp'] +\
            ' ' +\
            utils.cpp_class_name(class_model) +\
            '::' +\
            member['name'] +\
            '() const {\n' +\
            '\n' +\
            '    return _' +\
            member['name'] +\
            ';\n' +\
            '}\n' +\
            '\n'
             
    source += 'std::string ' + utils.cpp_class_name(class_model) + '::to_string() const {\n'
    source += '\n'
    source += '    std::stringstream ss;\n'
    source += '\n'

    max_len = max(map(len, [member['name'] for member in utils.cpp_class_members(type_model, data_model, class_model)]))

    source += \
        '    ss << "' +\
        class_model['class'] +\
        ' ' +\
        ' ' * (max_len - len(class_model['class'])) +\
        ' "' +\
        '     ' +\
        ' ' * max_len +\
        ' << std::endl;\n'

    for member in utils.cpp_class_members(type_model, data_model, class_model):

        source += \
            '    ss << "' +\
            member['name'] +\
            ':' +\
            ' ' * (max_len - len(member['name'])) +\
            ' "' +\
            ' << _' +\
            member['name'] +\
            ' ' * (max_len - len(member['name'])) +\
            ' << std::endl;\n'

    source += '\n'
    source += '    return ss.str();\n'
    source += '}\n'
    source += '\n'

    return source

def generate(path, type_model, data_model, class_model):

    with open(os.path.join(path, class_model['class'] + '.h'), 'w+') as file:
    
        file.write(header(type_model, data_model, class_model))
    
    with open(os.path.join(path, class_model['class'] + '.cpp'), 'w+') as file:
    
        file.write(source(type_model, data_model, class_model))

