function run() {
  
  generate_classes();
  generate_faculty_members_and_licenses();
  generate_data_model();
  generate_sql();
}

function Table(name) {
  
  this.name = name;
  this.ss = SpreadsheetApp.getActiveSpreadsheet();
   
  this.sheet = this.ss.getSheetByName(this.name);
  
  this.rows = this.sheet.getMaxRows();
  this.cols = this.sheet.getMaxColumns();
  
  this.members = this.sheet.getRange(1,1,1,this.cols).getValues()[0];
  this.types = this.sheet.getRange(2,1,1,this.cols).getValues()[0];
  this.values = this.sheet.getRange(3,1,this.rows-2, this.cols).getValues();
  
  this.clean = function() {
    if(4 <= this.rows) {
      this.sheet.deleteRows(4,this.rows-3);
      this.values = [];
    }
  };
  
  this.update = function() {
    this.sheet.getRange(3,1, this.values.length, this.cols).setValues(this.values);
  };
  
  this.indexOf = function(column_name) {
    for(i=0; i<this.members.length; ++i) {
      if(this.members[i].toString() == column_name) {
        return i;
      }
    }
    return -1;
  };
  
  this.new_row = function() {
    return new Array(this.cols);
  };
  
}

function generate_classes() {
  
  var course = new Table("course");
  var class_type = new Table("class_type");
  
  var class = new Table("class");
  class.clean();
  
  var class_id = 0;
  
  for(course_i=0; course_i<course.values.length; ++course_i) {
    
    for(class_type_i=0; class_type_i<class_type.values.length; ++class_type_i) {
      
      class_id += 1;
      var row = class.new_row();

      row[class.indexOf("id")] = class_id;
      row[class.indexOf("name")] = course.values[course_i][course.indexOf("name")] + " " + class_type.values[class_type_i][class_type.indexOf("name")];
      row[class.indexOf("lesson_count")] = 14;
      row[class.indexOf("regularity")] = "WEEKLY";
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
  
  var department = new Table("department");
  var class_type = new Table("class_type");
  var course = new Table("course");
  
  var faculty_member = new Table("faculty_member");
  faculty_member.clean();
  
  var license = new Table("license");
  license.clean();
  
  var faculty_member_id = 0;
  var license_id = 0;
  
  for(department_i=0; department_i<department.values.length; ++department_i) {
    
    for(class_type_i=0; class_type_i<class_type.values.length; ++class_type_i) {
      
      count = class_type.values[class_type_i][0] == 1 ? 2 : 10
      
      for(c=1; c<=count; ++c) {
        
        faculty_member_id += 1;
        var row = faculty_member.new_row();
        
        row[faculty_member.indexOf("id")] = faculty_member_id;
        row[faculty_member.indexOf("name")] = department.values[department_i][department.indexOf("short")] + " " + class_type.values[class_type_i][class_type.indexOf("name")] + "tartó " + c;
        row[faculty_member.indexOf("department_id")] = department.values[department_i][department.indexOf("id")];

        
        Logger.log(faculty_member.indexOf("id"));
        Logger.log(" ");
        
        faculty_member.values.push(row);
        
        for(course_i=0; course_i<course.values.length; ++course_i) {
          if(course.values[course_i][course.indexOf("department_id")] == department.values[department_i][department.indexOf("id")]) {
            
            license_id += 1;
            var row = license.new_row();
            		
            row[license.indexOf("id")] = license_id;
            row[license.indexOf("course_id")] = course.values[course_i][course.indexOf("id")];
            row[license.indexOf("class_type_id")] = class_type.values[class_type_i][class_type.indexOf("id")];
            row[license.indexOf("faculty_member_id")] = faculty_member_id;
            
            license.values.push(row);
          }
        }
      }
    }
  }
  
  faculty_member.update();
  license.update();
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

function generate_sql() {
  
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

