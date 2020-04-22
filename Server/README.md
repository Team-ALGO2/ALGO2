# Welcome to the Server part of this project

This folder includes multiple programs such as:  
* A web server
* A templating framework
* More eventually...

## Web Server
The web server is the user-facing part of this project. It acts as an interface that will look the same on all computers and that is user-friendly. This is an advantage over other solutions such as NCURSES which only works on Linux and Mac or using terminal to scanf a string. The website does not require Internet access. The logic code for the server is located in main.c. To access the server, move into the Server directory and run `make` and `./server`. A message will appear along the lines of: `Server started http://127.0.0.1:12913`. You should then go to that address with your browser and the websitte should be there.

## Templating
When the server receives a request, the server will parse an HTML file located in views/. It will read it character by character and send it to the browser, in cases were we may need to have information dependent on the request, there is a minimalistic templating framework in place: in the server code, they are stored with key/values pairs. To store something, you have to call:
```C
remember("key", "value");
```
where key and value are both char array. To use it in HTML, use: 
```HTML
<h1>{{key}}</h1>
``` 
and the server will replace {{key}} with the value you gave it when you called `remember()`.