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

struct pair
{
    char key[MAX_VARIABLE_LENGTH];
    char value[MAX_INPUT_LENGTH];
};

struct dict
{
    struct pair pairs[MAX_VARIABLE_NUMBER];
};

struct dict rememberedValue;



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



        remember("raw", qs);
        remember("decoded", decoded);
        remember("extracted", exp);

        printf("HTTP/1.1 200 OK\r\n\r\n");
        printHTMLFile("views/result.html");
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
   //  printf("%s", f_array);

    int len = strlen(f_array);

    for (int j = 0; j < len; j++)
    {
        if (((f_array[j] == '{') && (f_array[j+1] == '{'))) // special character
        {
            cacheSET("var", 10);
            cacheSET("var2", 20);
            j = j + 2; // skip {{
            char varName[MAX_VARIABLE_LENGTH] = "";
            while ((f_array[j] != '}') && (f_array[j-1] != '}'))    // while ending characters not found
            {
                if (f_array[j] != ' ')  
                {
                    char add[2];
                    add[0] = f_array[j];
                    add[1] = '\0';
                    strcat(varName, add);
                    j++;
                } else {
                    j++; // skip whitespace
                }
            }
            fprintf(stderr, RED"Found varName: %s\n"RESET, varName);
            for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)  // For every cache in clist
            {
                if (strcmp(rememberedValue.pairs[i].key, varName) == 0)      // If found
                {
                    printf("%s", rememberedValue.pairs[i].value);
                    break;
                } 
        
            }

            j++;  // skip closing }}

        } else {        // else just print normally
            printf("%c", f_array[j]);
        }
        
    }
    return 0;
}

int printHTMLFile(char fname[MAX_FILE_NAME_LEN])
{
    printFile("views/beg.html");
    printFile(fname);
    printFile("views/end.html");
}

int remember(char key[MAX_VARIABLE_LENGTH], char value[MAX_INPUT_LENGTH])
{
    for (int i = 0; i < MAX_VARIABLE_NUMBER; i++)
    {
        if (strcmp(rememberedValue.pairs[i].key, "\0") == 0) 
        { 
            strcpy(rememberedValue.pairs[i].key, key);
            strcpy(rememberedValue.pairs[i].value, value);
            return 0;
        }
    }
    return 1; 
}
