// this is an example of single line comment.
/*
this is an example to multi-line comment.
*/
// var myVar = 'this is Kumar Shivam Commanding from JS'
// document.write(myVar)
// alert('tum chutiya ho')
// if (1){
//     document.write('hello baby how do u do')
// }
// now lets do functions
// myfun()
// function myfun(){
//     alert('function ne bulaya hai')
// }

// objects in javascript
// var person = {
//     name: 'Shivam',
//     height: '5.10',
//     age:20
// }
// document.write('<br>' + 'name = ' + person.name)


// how to use JQuery
// $('h1').hide(500).show(500)


$(function(){
// this will execute when the webpage is ready to execute
    $('h1').slideUp(1000).slideDown(1000)

    $('h1').click(function(){
        $('.content').css({
            color: 'blue',
            fontSize: 50
        })
    })
})

$(window).on('load', function(){
    //when the window is fully loaded means the content the image the all files of the window is totally ready including graphics while the document().ready() is invloked a bit earlier.
    // alert('window is loaded')
})