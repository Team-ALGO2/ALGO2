#define WEBMODE //Turns on special features designed only for the webserver

#include "httpd.h"
#include "../Final/src/main.h"


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(int c, char** v)
{
    serve_forever("12913");
    return 0;
}
#endif // _DEFMAIN

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("<!DOCTYPE html>"
                "<html>"
                "   <body>"
                "       <style>"    // style tag because why not
                "           #exp {"
                "                  outline: 0;"                                    
                "                  border-width: 0 0 2px;" 
                "                  width: 20%%;"
                "                  border-color: blue;"
                "                  transition: 0.5s;         "
                "                  font-family: Optima, Serif;     "
                "                  font-size: large;                                     "
                "               } "
                "           #exp:focus {"
                "                  border-color: black;"
                "               } "
                "           #connect {"
                "                  font-family: Times, Serif;     "
                "               } "
                "       </style>"


                "       <h1>Welcome</h1>"
                "       <h2>Please enter an expression below</h2>            "
                "           <form action='/exp'>"
                "               <input placeholder='Expression' id='exp' type='text' name='exp' autofocus required>"
                "               <input type='submit' value='&rarr;'>"
                "               <br><br><br>"
                "               <h4>Special commands</h4>        "
                "               <ul>"
                "                   <li>STORE: Set a variable to the user cache</li>"
                "                   <li>GETALL: See all of your variables that are stored in your cache</li>" 
                "                </ul>                    "
                "          </form> "
                "          <p id='connect'>To use the calculator on any devices connected to the same network, type in your address bar the LAN ip address of this computer.</p>"
                "   </body>"
                "</html>");
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
    }

    ROUTE_GET("/exp")
    {
        
        char decoded[strlen(qs) + 1];
    
        decode(qs, decoded);
        fprintf(stderr, BLU"Payload received as: %s\n", qs);
        fprintf(stderr, "Payload decoded: %s\n", decoded);
        int len = strlen(decoded);
        fprintf(stderr, "Payload size: %d\n", len);
        
        char exp[MAX_INPUT_LENGTH];
        
        for (int i = 4; i < len + 1; i++)
        {
            exp[i-4] = decoded[i]; 
        }
        exp[len] = '\0';
        fprintf(stderr, "Extracted exp: %s\n"RESET, exp);


        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("<!DOCTYPE html>");
        printf("<html>");
        printf("   <body>");
        printf("       <h1>C-Calculator</h1>");
        printf("       <li>Your input was received as: <strong>%s</strong> </li>", qs);  // Raw args
        printf("       <li>Input was decoded as: <strong>%s</strong> </li>", decoded);   // urldecoded
        printf("       <li>Expression is: <strong>%s</strong> </li>", exp);              // without the "exp="
        printf("       <br>");                                                          // line break to differentiate parts of output

        //Since we are editing our pipeline so much, this will be commented out until further notice!
        //parseString(exp, MAX_INPUT_LENGTH, 10);


        printf("       <a href='/'>Back</a>");     
        printf("   </body>");
        printf("</html>");
    }

    ROUTE_END()
}



int ishex(int x)
{
	return	(x >= '0' && x <= '9')	||
		(x >= 'a' && x <= 'f')	||
		(x >= 'A' && x <= 'F');
}
 
int decode(const char *s, char *dec)
{
	char *o;
	const char *end = s + strlen(s);
	int c;
 
	for (o = dec; s <= end; o++) {
		c = *s++;
		if (c == '+') c = ' ';
		else if (c == '%' && (	!ishex(*s++)	||
					!ishex(*s++)	||
					!sscanf(s - 2, "%2x", &c)))
			return -1;
 
		if (dec) *o = c;
	}
 
	return o - dec;
}
 
