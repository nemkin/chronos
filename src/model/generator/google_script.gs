function run() {
  
  generate_classes();
  generate_faculty_members_and_licenses();
  generate_data_model();
  generate_data();
  
}

function Table(name) {
  
  this.name = name;
  this.ss = SpreadsheetApp.getActiveSpreadsheet();
   
  this.sheet = this.ss.getSheetByName(this.name);
  
  this.rows = this.sheet.getMaxRows();
  this.cols = this.sheet.getMaxColumns();
  
  this.members = this.sheet.getRange(1,1,1,cols).getValues();
  this.types = this.sheet.getRange(2,1,1,cols).getValues();
  this.values = this.sheet.getRange(3,1,rows-2, cols).getValues();
  
  this.clean = function() {
    this.sheet.deleteRows(4,rows-3);
    this.values = [];
  };
  
  this.update = function() {
    this.sheet.getRange(3,1, this.values.length, cols).setValues(values);
  };
  
  this.indexOf = function(column_name) {
    return this.members.indexOf(column_name);
  }
  
  this.new_row = function() {
    return new Array(this.cols);
  }
  
}

function generate_data_model() {
  
  var res = new Object();
  res["default"] = new Object();
  res["default"]["members"] = [];
  
  var modified_timestamp = new Object();
  modified_timestamp["name"] = "modified_timestamp";
  modified_timestamp["type"] = "timestamp";
  
  var is_deleted = new Object();
  is_deleted["name"] = "is_deleted";
  is_deleted["type"] = "bool";
  
  res["default"]["members"].push(modified_timestamp);
  res["default"]["members"].push(is_deleted);
  
  res.classes = [];
  
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var sheets = ss.getSheets();
  
  for(i=0; i<sheets.length; ++i) {
    
    var class = new Object();
    
    class["class"] = sheets[i].getName();
    class["members"] = [];
    class["references"] = [];
    
    var cols = sheets[i].getMaxColumns();
    
    var sheet_values = sheets[i].getRange(1,1,2,cols).getValues();
    
    for(j=0; j<cols; ++j) {
      
      if(sheet_values[1][j] != "reference") {
        
        var member = new Object();
        member["name"] = sheet_values[0][j];
        member["type"] = sheet_values[1][j];
        class["members"].push(member);
        
      } else {
        
        var reference = new Object();
        reference["class"] = sheet_values[0][j].split("_id")[0];
        class["references"].push(reference);
      }
    }
    
    res["classes"].push(class); 
  }
  
  var json_string= JSON.stringify(res, null, 4);
  
  var file_name = "data_model.json";
  var folder = DriveApp.getFoldersByName("Chronos").next().getFoldersByName("descriptors").next();
  
  var files = folder.getFilesByName(file_name);
  
  while(files.hasNext()) {
    folder.removeFile(files.next());
  }
  
  folder.createFile(file_name, json_string);
}

function generate_data() {
  
  var res = "";
  
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var sheets = ss.getSheets();
  
  for(i=0; i<sheets.length; ++i) {
    
    var rows = sheets[i].getMaxRows();
    var cols = sheets[i].getMaxColumns();
    
    var sheet_name = sheets[i].getName();
    var sheet_header = sheets[i].getRange(1,1,2,cols).getValues();
    var sheet_values = sheets[i].getRange(3,1,rows-2, cols).getValues();
    
    for(j=0; j<rows-2; ++j) {
      
      var string = "INSERT INTO " + sheet_name + " (";
      
      for(k=0; k<cols; ++k) {
        string += sheet_header[0][k] + (k != cols-1 ? "," : ")");
      }
      
      string += " VALUES (";
      
      for(k=0; k<cols; ++k) {
        var around = sheet_header[1][k] == "text" ? "\"" : "";
        string +=  around + sheet_values[j][k] + around + (k != cols-1 ? ", " : ");\n");
      }
      
      res += string;
    }
    
  }
  
  var file_name = "data.sql";
  var folder = DriveApp.getFoldersByName("Chronos").next().getFoldersByName("descriptors").next();
  
  var files = folder.getFilesByName(file_name);
  
  while(files.hasNext()) {
    folder.removeFile(files.next());
  }
  
  folder.createFile(file_name, res);
}

function generate_classes() {
  
  var course = Table("course");
  var class_type = Table("class_type");
  
  var class = Table("class");
  class.clean();
  
  var class_id = 0;
  
  for(course_i=0; course_i<course.values.length; ++course_i) {
    
    for(class_type_i=0; class_type_i<class_type.values.length; ++class_type_i) {
      
      class_id += 1;
      var row = class.new_row();

      row[class.indexOf("id")] = class_id;
      row[class.indexOf("name")] = course.values[course_i][course.indexOf("name")] + " " + class_type.values[class_type_i][class_type.indexOf("name")];
      row[class.indexOf("lesson_count")] = 14;
      row[class.indexOf("iregularity")] = "WEEKLY";
      row[class.indexOf("maximum_student_count")] = class_type.values[class_type_i][class_type.indexOf("name")] == "előadás" ? 600 : 35
      row[class.indexOf("class_type_id")] = class_type.values[class_type_i][class_type.indexOf("id")];
      row[class.indexOf("course_id")] = course.values[course_i][course.indexOf("id")];
      
      class.values.push(row);
    }
  }
  
  class.update();
}

function generate_faculty_members_and_licenses() {
  
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  
  var department = Table("department");
  var class_type = Table("class_type");
  var course = Table("course");
  
  var faculty_member = Table("faculty_member");
  faculty_member.clean();
  
  var license = Table("license");
  license.clean();
  
  var faculty_member_id = 0;
  var license_id = 0;
  
  for(department_i=0; department_i<department.values.length; ++department_i) {
    
    for(class_type_i=0; class_type_i<class_type.values.length; ++class_type_i) {
      
      count = class_type.values[class_type_i][0] == 1 ? 2 : 10
      
      for(c=1; c<=count; ++c) {
        
        faculty_member_id += 1;
        var row = faculty_member.new_row();
        
        row[class.indexOf("name")] = department_values[department_i][2] + " " + class_type_values[class_type_i][1] + "tartó " + c;
        row[class.indexOf("department_id")] = department_values[department_i][0];
        

        row[class.indexOf("name")] = class_id;
        
        var tmp = [];
        tmp.push(faculty_member_id);
        tmp.push(name);
        tmp.push(department_id);
        
        faculty_member_values.push(tmp);
        
        for(k=0; k<course_values.length; ++k) {
          if(course_values[k][3] == department_values[department_i][0]) {
            license_id += 1;
            var tmp2 = [];
            
            tmp2.push(license_id);
            tmp2.push(course_values[k][0]);
            tmp2.push(class_type_values[j][0]);
            tmp2.push(faculty_member_id);
            
            license_values.push(tmp2);
          }
        }
      }
    }
  }
  
  faculty_member.deleteRows(4,faculty_member.getMaxRows()-3);
  license.deleteRows(4,license.getMaxRows()-3);
  
  faculty_member.getRange(3,1, faculty_member_values.length, faculty_member_values[0].length).setValues(faculty_member_values);
  license.getRange(3,1, license_values.length, license_values[0].length).setValues(license_values);
}

