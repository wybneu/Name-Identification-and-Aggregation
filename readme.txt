this programm is developed for name searching in files.

running envirnment : UNIX system

linked files : surnames.txt words.txt (anytext need to be search)
This files needs to be in a same catalogue

To compile this files . copy all the file into a catalogue type
                 make
or type following command
                 gcc name.c -o name
When it compile, there should be some warning , no problem for that.

To run the program .
                ./name [1/2/3/4/5/6/7/other reguler experssion]  words.txt surnames.txt < file_need_ search.txt 
you can run quick search by 
               ./name [1-7] < filename
you can run dictionary search by 
             ./name [1-7] words.txt < filename
you can get the result into a file
               ./name [1-7] words.txt <filename >output_filename
for example you want to search the file austen-pride-and-prejudice.txt by single name search
               ./name 1 words.txt < austen-pride-and-prejudice.txt

1: single name search
2: doule name search
3: full name with middle name search
4:Hyphenated Names (Bob-Smith)
5:Names with Apostrophise (S'Bob)
6:Joint Names (Bob & Jerry)
7:All the name

all the books in the report could be download from http://www.gutenberg.org/ or /home/subjects/comp90049/local/project1-2012/books/
surnames.txt is /home/subjects/comp90049/local/data-2012/
words.txt     /home/subjects/comp90049/local/data-2012/
enron-skilling.txt    /home/subject/comp90049/local/project1-2012/books/enron-skilling.txt
