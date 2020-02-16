#include "httpd.h"
#include "../Final/src/main.h"

int main(int c, char** v)
{
    serve_forever("12913");
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("<!DOCTYPE html>"
                "<html>"
                "   <body>"
                "       <h1>This is heading 1</h1>"
                "       <h2>This is heading 2</h2>"
                "           <form action='/exp'>"
                "               Expression:<br>"
                "               <input type='text' name='exp'>"
                "               <br><br>"
                "               <input type='submit' value='Submit'>"
                "          </form> "
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

        // Do string parsing here with exp

        


        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("<!DOCTYPE html>"
                "<html>"
                "   <body>"
                "       <h1>Welcome to the C-Calculator</h1>"
                "       <li>Your input was received as: <strong>%s</strong> </li>"
                "       <li>Input was decoded as: <strong>%s</strong> </li>"
                "       <li>Expression is: <strong>%s</strong> </li>"
                "   </body>"
                "</html>", qs, decoded, exp);
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
 
