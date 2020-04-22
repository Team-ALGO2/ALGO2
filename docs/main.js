window.addEventListener('DOMContentLoaded', (event) => {
    console.log('DOM fully loaded and parsed');
});



window.addEventListener('scroll', (event) => {
    var y = window.scrollY
    if (y > 1000)
    {
        var e = document.getElementById("scroll")
        if (e.style.opacity != 0)
        {
            var fadeEffect = setInterval(function () {
                if (!e.style.opacity) {
                    event.style.opacity = 1;
                }
                if (e.style.opacity > 0) {
                    e.style.opacity -= 0.1;
                } else {
                    clearInterval(fadeEffect);
                }
            }, 200);
        }
    
    } else {
        document.getElementById("scroll").style.opacity = 1;
    }
    console.log(y);
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
