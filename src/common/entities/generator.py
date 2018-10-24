import os
import json

for file_name in os.listdir('.'):

    if file_name.endswith('.json'):

        with open(file_name) as file:

            data = json.load(file)

            header = ''
            source = ''
            
            class_upper_camel_case = ''.join([part.capitalize() \
                                     for part in data['class'].split('_')])
            
            header += '#pragma once\n'
            header += '\n'
            header += '#ifndef __' + data['class'].upper() + '__H__\n'
            header += '#define __' + data['class'].upper() + '__H__\n'
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
            
            for i, member in enumerate(data['members']):
                
                header +=\
                    '        ' +\
                    member['type'] +\
                    ' p_' +\
                    member['name'] +\
                    (',' if i != len(data['members'])-1 else '') +\
                    '\n'
            
            header += '    );\n'
            header += '\n'
            
            for member in data['members']:
            
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
            
            for member in data['members']:
            
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
            header += '#endif //__' + data['class'].upper() + '__H__\n'
           
            with open(data['class'] + '.h', 'w+') as header_file:

                header_file.write(header)
            
            source += '#include "' + data['class'] + '.h"\n'
            source += '\n'
            source += '#include <sstream>\n'
            source += '\n'
            source += 'using namespace chronos;\n'
            source += '\n'
            source += class_upper_camel_case + '::' + class_upper_camel_case + '(\n'
            source += ') :\n'
            
            for i, member in enumerate(data['members']):
            
                source += '    _' + member['name'] + '('
                
                if member['type'] == 'bool':
                    source += 'false'
                elif member['type'] == 'int':
                    source += '0'
                elif member['type'] == 'std::string':
                    source += '""'
                else:
                    source += '?'

                source += ')' + (',' if i != len(data['members'])-1 else ' {') + '\n'
           
            source += '\n'
            source += '}\n'
            source += '\n'
            source += class_upper_camel_case + '::' + class_upper_camel_case + '(\n' 

            for i, member in enumerate(data['members']):
                
                source +=\
                    '    ' +\
                    member['type'] +\
                    ' p_' +\
                    member['name'] +\
                    (',' if i != len(data['members'])-1 else '') +\
                    '\n'
            
            source += ') :\n'
            
            for i, member in enumerate(data['members']):
            
                source +=\
                    '    _' +\
                    member['name'] +\
                    '(p_' +\
                    member['name'] +\
                    ')' +\
                    (',' if i != len(data['members'])-1 else ' {') +\
                    '\n'

            source += '\n'
            source += '}\n'
            source += '\n' 

            for member in data['members']:
            
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

            max_len = max(map(len, [member['name'] for member in data['members']]))

            source +=\
                '    ss << "' +\
                data['class'] +\
                ' ' +\
                ' ' * (max_len - len(data['class'])) +\
                ' "' +\
                '    ' +\
                ' ' * max_len +\
                ' << std::endl;\n'

            for member in data['members']:

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
 
            with open(data['class'] + '.cpp', 'w+') as source_file:

                source_file.write(source)
            
