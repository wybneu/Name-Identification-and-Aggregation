# Name Identification and Aggregation
The technical aim of the project is to develop software that, given a text corpus, attempts to identify
all of the names of people referenced within. This aims to reinforce several concepts covered
in the subject, including regular expressions, string search, partial matching, and measurements of
effectiveness.

## Synopsis
###### Motivation
In the past years, Name genre analysis in Name Identification and Aggregation has been recognised more significant by its using in the Knowledge Technology. In kinds of documents, genres (adventure, science fiction, mystery, etc.) use the name by different ways which can be found by group of tests. In this report, I will start with the name search regular expression, how to search the name by providing resource, how it works by partial matching in the searching and the effectiveness of different way of searching. After that, a critical analysis will be given for the genre analysis in the field of name identification and aggregation.

###### Orignal
This is a data mining project I made in Melbourne Unviersity.
######  flow
- There are some steps to get out possible names from a document.
- The first step is to get the regular expression for a name. In this step, the type of name will be analysis and different regular expression will be given to deal with different name style.
- The next step is narrow the result which is means to make it approach to the real name. For this, some dictionary file would be used, which will be listed in this report.
- In the following step is to analyses the results of the system. In this step, the precision and recall will be counted.
- Different genre document will be tested and some conclusion will come out.

## Implementation
###### Platfrom
Unix
###### Lanugae
C
###### API & Library
C
###### Regular Expression
Regular expression is a effectively way to get the abstract expression for different type of name;
- For the Single name, the entire name should start with a space and finish with a space to make it a word. Also the first name should start with an Up case char following by other chars. In this case, we read the files line by lines, assumption that a line only has one sentence and one name.
```
[ ][A-Z][a-z]*[ ]
```
- For the double name;
```
[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ]
```
- For the full name with middle name
```
[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ]
```
- For the Hyphenated Names
```
[ ][A-Z][a-z]*[-][A-Z][a-z]*[ ]
```
- For the Names with Apostrophizes
```
[ ][A-Z][‘][A-Z][a-z]*[ ]
```
- For the Names with Apostrophizes
```
[ ][A-Z][a-z]*[& ]*[A-Z][a-z]*[ ]
```
- For all the possible name
```
[ ][A-Z][a-z]*[& ‘-.]*([A-Z][a-z]*[ ]){,2}
```
- For the point name
```
[ ][A-Z][a-z]*[. ]*[A-Z][a-z]*[ ]
```
###### Search algorithm
With the name we got from the Regex function, an array of words is used to judge the truth of name. This array mostly contains the common words start with UP cast letter, just like Month (January), Day (Monday), pronominal letter (They) , Be word (Is), What, When, and so on.
After this quickly filters, the program opens the words.txt dictionary to match new word. In this program, a free list strut has been built up to save the new words and the times this word appears in the text. If there is such new word, the new word will not add to the list.
After this part, a deeper filter needs to be done by the file surnames. In the following part, we will search the surnames.txt files and count each path need to be done from this words to the new words. If this path is less than the gate of the path algorithm, then this new word can be kept and saved. Although this process needs more time, it can give a great filter by this way. (This part is only basic programmed, it cannot running well)
Actually, most names always come with another word such as Mr. Dr. and so on. So the result of double one is more important.
###### run
1. After the server start, it is required a port to build the server
2. Server is starting with a list of client and two buttons, one for kick out the selected client, one for refresh.
3. Start the client and it need some feature to build up the connection with the server.
4. The sever will show the one who want to join in.
5. The main GUI of the client: we can draw here with the different tools and the set for the tools. 
6. The server will join the information of the joined client.
7. We can share what we draw now.
8. When the server is broken, the client will show the information box and quit
9. When the client is kicked out, it will give a message and quit.

## Installation

######linked files : 
surnames.txt words.txt (anytext need to be search)

This files needs to be in a same catalogue
######compile
To compile this files . copy all the file into a catalogue type
```
make
```
or type following command
```
gcc name.c -o name
```
When it compile, there should be some warning , no problem for that.
######run
- To run the program .
```
./name [1/2/3/4/5/6/7/other reguler experssion]  words.txt surnames.txt < file_need_ search.txt 
```
- you can run quick search by 
```
 ./name [1-7] < filename
```
- you can run dictionary search by 
```
./name [1-7] words.txt < filename
```
- you can get the result into a file
```
 ./name [1-7] words.txt <filename >output_filename
```
- for example you want to search the file austen-pride-and-prejudice.txt by single name search
```
./name 1 words.txt < austen-pride-and-prejudice.txt
```

1. single name search
2.  doule name search
3.  full name with middle name search
4. Hyphenated Names (Bob-Smith)
5. Names with Apostrophise (S'Bob)
6. Joint Names (Bob & Jerry)
7. All the name

###### tips
all the books in the report could be download from http://www.gutenberg.org/ 

## Tests

## Other Contributors

## License
This is a project based on learning and studying. Not for any kind of commecial using. This is a project built within a research group in Melbourne University. Please **do not** copy and using it as both commercial and **academic** using directly.  
######Other API license
- [License - GCC - GNU](https://gcc.gnu.org/onlinedocs/libstdc++/manual/license.html)



