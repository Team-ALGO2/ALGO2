window.addEventListener('DOMContentLoaded', (event) => {
    console.log('DOM fully loaded and parsed');
});

window.addEventListener('scroll', (event) => {
    console.log("scrolling");
});


function openNav() {
    document.getElementById("sidenav").style.width = "200px";
    document.getElementById("main").style.marginLeft = "200px";
}
  
function closeNav() {
    document.getElementById("sidenav").style.width = "0";
    document.getElementById("main").style.marginLeft= "0";
}


function getVideoIntoView() {
    var element = document.getElementById("video");

    element.scrollIntoView({behavior: "smooth", block: "center", inline: "center"});

}