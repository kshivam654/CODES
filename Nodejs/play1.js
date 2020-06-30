// first java script code

// getting started with variables
// var name = "Kumar Shivam";
// var age = 20;
// var student = true;
// let x = undefined; //default datatype
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

// console.log(biodata(name, age, student));

// how to do objects
const person = {
    name: 'Shivam',
    age: 20,
    contact: 8420355858,
    greet(){
        console.log('Hi, I\'m ' + this.name)
    }
};

// person.greet();

// array's
const language = ['C', 'C++', 'JAVA', 'Python']

//loops --> for loop
// for (let lang of language){
//     console.log(lang)
// }

//some operations on the list
//use of map
// console.log(language.map(lang => 'Language: ' + lang))
/*
map takes one parameter as a function to do operation on the list and 
returns a new modified list and don't hamper the previous list
*/
let [lan1, lan2] = language;
console.log(lan1, lan2);