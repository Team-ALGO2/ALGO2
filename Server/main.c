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
        printHTMLFile("views/form.html");  
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

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
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

int printFile(char fname[MAX_FILE_NAME_LEN])
{
    const size_t MAX_LEN = MAX_FILE_LEN;
    FILE * fp;
    char f_array[MAX_LEN +1];
    int c;
    size_t i = -1;
    f_array[MAX_LEN+1] = 0;

    fp = fopen(fname,"r");

    if ( NULL == fp )
        perror("Error opening file");
    else {
        while (EOF != (c = fgetc( fp )) && ++i < MAX_LEN)
            f_array[i] = c;
        fclose (fp);
    }
    f_array[i] = 0;
    printf("%s", f_array);
    return 0;
}

int printHTMLFile(char fname[MAX_FILE_NAME_LEN])
{
    printFile("views/beg.html");
    printFile(fname);
    printFile("views/end.html");
}
 
