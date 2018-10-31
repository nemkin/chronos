def plural(noun):

    return noun + ('e' if noun[-1] == 's' else '') + 's'

def name_of_reference(reference):

    return \
        reference['class'] + '_id' \
        if 'name' not in reference else \
        reference['name']

def cpp_class_name(class_model):

    return ''.join([part.capitalize() \
        for part in class_model['class'].split('_')])

def cpp_class_members(type_model, data_model, class_model):

    ret = []
  
    ret += [{'name': 'id', 'type': 'id'}]
    ret += data_model['default']['members'] 
    ret += class_model['members']

    for reference in class_model['references']:

        ret += [{\
            'name': name_of_reference(reference),\
            'type': 'reference'\
        }]

   
    return ret 

def sql_class_members(type_model, data_model, class_model):

    ret = []

    normal = []
 
    normal += [{'name': 'id', 'type': 'id'}]
    normal += data_model['default']['members'] 
    normal += class_model['members']

    for member in normal: 
        ret += [ \
            member['name'] +\
            ' ' +\
            type_model[member['type']]['sql'] +\
            ' NOT NULL'
        ]

    for reference in class_model['references']:

        ret += [ \
            name_of_reference(reference) +\
            ' ' +\
            type_model['reference']['sql'] +\
            ' REFERENCES ' +\
            plural(reference['class']) +\
            '(id) NOT NULL'
        ]

    return ret 

