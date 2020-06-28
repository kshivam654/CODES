// first java script code

// getting started with variables
var name = "Kumar Shivam";
var age = 20;
var student = true;
let x = undefined; //default datatype
//getting started with functions
function biodata(name, age, isStudent){
    return (
        'Name is ' +
        name + 
        ' is of age ' + 
        age +
        ' is a Student : ' +
        isStudent
    );
}
console.log(biodata(name, age, student));