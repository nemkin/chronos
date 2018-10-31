import os
import json
import shutil

import entity_generator
import database_generator

generated_directory_path = '../generated'

entities_directory_path = generated_directory_path + '/entities'
database_directory_path = generated_directory_path + '/database'

descriptors_directory_path = '../descriptors'

type_model_file_path = descriptors_directory_path + '/type_model.json'
data_model_file_path = descriptors_directory_path + '/data_model.json'

with open(type_model_file_path) as type_model_file:

    type_model = json.load(type_model_file)

with open(data_model_file_path) as data_model_file:

    data_model = json.load(data_model_file)

shutil.rmtree(generated_directory_path)

os.makedirs(entities_directory_path)
os.makedirs(database_directory_path)

for class_model in data_model['classes']:

    entity_generator.generate(entities_directory_path, type_model, data_model, class_model)

database_generator.generate(database_directory_path, type_model, data_model, entities_directory_path)
 
