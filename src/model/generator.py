import os
import json

data_model_file_path = 'data_model.json'
prefix = '../common/entities'

with open(data_model_file_path) as data_model_file:

    data_model = json.load(data_model_file)

    for class_model in data_model['classes']:

        header = ''
        source = ''
        
        class_upper_camel_case = ''.join([part.capitalize() \
                                 for part in class_model['class'].split('_')])
        
        header += '#pragma once\n'
        header += '\n'
        header += '#ifndef __' + class_model['class'].upper() + '__H__\n'
        header += '#define __' + class_model['class'].upper() + '__H__\n'
        header += '\n'
        header += '#include <string>\n'
        header += '\n'
        header += 'namespace chronos {\n'
        header += '\n'
        header += 'class ' + class_upper_camel_case + ' {\n'
        header += '\n'
        header += 'public:\n'
        header += '\n'
        header += '    ' + class_upper_camel_case + '();\n'
        header += '\n'
        header += '    ' + class_upper_camel_case + '(\n'
        
        for i, member in enumerate(class_model['members']):
            
            header +=\
                '        ' +\
                member['type'] +\
                ' p_' +\
                member['name'] +\
                (',' if i != len(class_model['members'])-1 else '') +\
                '\n'
        
        header += '    );\n'
        header += '\n'
        
        for member in class_model['members']:
        
            header +=\
                '    ' +\
                member['type'] +\
                ' ' +\
                member['name'] +\
                '() const;\n'
        
        header += '    std::string to_string() const;\n'
        header += '\n'
        header += 'private:\n'
        header += '\n'
        
        for member in class_model['members']:
        
            header +=\
                '    ' +\
                member['type'] +\
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
       
        with open(os.path.join(prefix, class_model['class'] + '.h'), 'w+') as header_file:

            header_file.write(header)
        
        source += '#include "' + class_model['class'] + '.h"\n'
        source += '\n'
        source += '#include <sstream>\n'
        source += '\n'
        source += 'using namespace chronos;\n'
        source += '\n'
        source += class_upper_camel_case + '::' + class_upper_camel_case + '(\n'
        source += ') :\n'
        
        for i, member in enumerate(class_model['members']):
        
            source += '    _' + member['name'] + '('
            
            if member['type'] == 'bool':
                source += 'false'
            elif member['type'] == 'int':
                source += '0'
            elif member['type'] == 'double':
                source += '0.0'
            elif member['type'] == 'std::string':
                source += '""'
            else:
                source += '?'

            source += ')' + (',' if i != len(class_model['members'])-1 else ' {') + '\n'
       
        source += '\n'
        source += '}\n'
        source += '\n'
        source += class_upper_camel_case + '::' + class_upper_camel_case + '(\n' 

        for i, member in enumerate(class_model['members']):
            
            source +=\
                '    ' +\
                member['type'] +\
                ' p_' +\
                member['name'] +\
                (',' if i != len(class_model['members'])-1 else '') +\
                '\n'
        
        source += ') :\n'
        
        for i, member in enumerate(class_model['members']):
        
            source +=\
                '    _' +\
                member['name'] +\
                '(p_' +\
                member['name'] +\
                ')' +\
                (',' if i != len(class_model['members'])-1 else ' {') +\
                '\n'

        source += '\n'
        source += '}\n'
        source += '\n' 

        for member in class_model['members']:
        
            source +=\
                member['type'] +\
                ' ' +\
                class_upper_camel_case +\
                '::' +\
                member['name'] +\
                '() const {\n' +\
                '\n' +\
                '    return _' +\
                member['name'] +\
                ';\n' +\
                '}\n' +\
                '\n'
                 
        source += 'std::string ' + class_upper_camel_case + '::to_string() const {\n'
        source += '\n'
        source += '    std::stringstream ss;\n'
        source += '\n'

        max_len = max(map(len, [member['name'] for member in class_model['members']]))

        source +=\
            '    ss << "' +\
            class_model['class'] +\
            ' ' +\
            ' ' * (max_len - len(class_model['class'])) +\
            ' "' +\
            '    ' +\
            ' ' * max_len +\
            ' << std::endl;\n'

        for member in class_model['members']:

            source +=\
                '    ss << "' +\
                member['name'] +\
                ':' +\
                ' ' * (max_len - len(member['name'])) +\
                ' "' +\
                ' << ' +\
                member['name'] +\
                ' ' * (max_len - len(member['name'])) +\
                ' << std::endl;\n'

        source += '\n'
        source += '    return ss.str();\n'
        source += '}\n'
        source += '\n'

        with open(os.path.join(prefix, class_model['class'] + '.cpp'), 'w+') as source_file:

            source_file.write(source)
        
