/* This programming is used to search the name in files
    Author : Yingbo Wang
    ID: 349149
 */
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>
#define NULL 0
#define LEN sizeof(struct name)
#define MAXWORD 50
#define MAXBUF 48
int nameofperson = 0;
int namenotperson = 0;
char *filename;
int headflag = 0;
struct name {/*free list for store the new words which has been found*/
    char *name[200];
    int times;
    int change;
    struct name *next;
};
struct name *head = NULL;
struct name *p = NULL;
/*dictionray for quick search*/
char *dictionary[] = { "The", "They", "He", "She", "We", "Both", "Most", "Of",
        "So", "That", "There", "Some", "All", "When", "Who", "To", "What",
        "This", "Then", "While", "It", " If", "Only", "About", "Every"
                "How", "Last", "Now", "Here", "In", "For", "Do", "Is", "Our",
        "Are", "A", "An", "That", "Its", "His", "These", "Those", "whose",
        "Whom", "Their", "I", "At", "As", "By", "Besides", "Next", "Each",
        "Everyone", "One", "You", "Web", "Project", "Email", "Was", "Upon",
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December", "Not", "On",
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
                "Sunday","df","df","df","df","df","df" };
int number = 84;
FILE *f1;
/*delete the space around the words*/
void Trim(char *ptr) {
    char *p, *q;
    if (ptr == NULL)
        return;
    for (p = ptr; *p == ' ' || *p == '\t' || *p == '\n'; ++p)
        ;
    if (*p == 0) {
        *ptr = 0;
        return;
    }
    for (q = ptr; *p; ++p, ++q) {
        *q = *p;
    }
    for (p = q - 1; *p == ' ' || *p == '\t' || *p == '\n'; --p)
        ;
    *(++p) = '\0';
}
showname() {
    p = head;
    do {
        printf("%s %d\n", p->name, p->times);
        p = p->next;
    } while (p != NULL);
}

/*flag 0 mean that no such name, 1 mean there has name*/
int searchname(char * newname) {
    int flag = 0;
    p = head;
    if (headflag == 0) {
        return flag;
    }
    do {
        if ((strcmp(p->name, newname) == 0)) {
            p->times = p->times + 1;
            flag = 1;
        }
        p = p->next;
    } while (p != NULL);
    return flag;
}
/* insert a new word*/
insert(char *newname) {
    struct name *ps;
    p = head;
    if (headflag == 0) {
        p = (struct name *) malloc(LEN);
        strcpy(p->name, newname);
        p->times = 1;
        head = p;
        p->next = NULL;
        headflag = 1;
        nameofperson = 1;
    } else {
        while ((strcmp(newname, p->name) > 0) && (p->next != NULL)) {
            p = p->next;
        }
        ps = (struct name*) malloc(sizeof(struct name));
        strcpy(ps->name, newname);
        ps->times = 1;
        ps->next = p->next;
        p->next = ps;
        nameofperson++;
    }
}

int check(char *newname) {
    int i = 0;
    for (i = 0; i < number; i++) {
        if (strcmp(newname, dictionary[i]) == 0) {
            namenotperson++;
            return 0;
        }
    }
    return 1;
}
/* check whether the newname is on the dictionary 1 for no such words 0 for has this words*/
int checkinfile(char *newname) {

    char *words[MAXWORD];
    char *buf[MAXBUF];
    char *lastwords[MAXWORD];
    int flag = 0;
    int i = 0;
    int n = 0;
    if (check(newname) == 0)
        return -1;
    if (f1)
        fclose(f1);
    f1 = fopen(filename, "r");
    while (!feof(f1) && (flag == 0)) {
        for (i = 0; i < MAXWORD; i++)
            words[i] = '\0';
        for (i = 0; i < MAXWORD; i++)
            lastwords[i] = '\0';
        fscanf(f1, "%s", words);
        Trim(words);
        if (strcasecmp(words, newname) == 0) {
		namenotperson++;
            return 0;
        }

        if (strcmp(lastwords, words) == 0)
            flag = 1;
        strcpy(lastwords, words);
        n++;
    }
    fclose(f1);
    return 1;
}
/* get the substring*/
static char* substr(const char*str, unsigned start, unsigned end) {
    unsigned n = end - start;
    static char stbuf[256];
    strncpy(stbuf, str + start, n);
    stbuf[n] = 0;
    return stbuf;
}
int main(int argc, char** argv) {
    int flag; /* flag is keep the default reguler expression*/
    char * pattern; /* pattern is used keep the reguler expression */
    int x, z, lno = 0, cflags = 0; /*lno is line number*/
    char ebuf[128], lbuf[256]; /* lbuf is the char array keep the char in a line.*/
    regex_t reg; /* which keep the reguler expression */
    regmatch_t pm[10];
    const size_t nmatch = 10;
    char *newname[200];
    /* build the regular expression*/
    if (argc < 2) {
        printf("you need to use the correct command funcion");
    }
    if (strcmp(argv[1], "1") == 0) {
        pattern = "[ ][A-Z][a-z]*[ ]";
    } else if (strcmp(argv[1], "2") == 0) {
        pattern = "[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ]";
    } else if (strcmp(argv[1], "3") == 0) {
        pattern = "[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ][A-Z][a-z]*[ ]";
    } else if (strcmp(argv[1], "4") == 0) {
        pattern = "[ ][A-Z][a-z]*[-][A-Z][a-z]*[ ]";
    } else if (strcmp(argv[1], "5") == 0) {
        pattern = "[ ][A-Z]['][A-Z][a-z]*[ ]";
    }else if (strcmp(argv[1], "6") == 0) {
        pattern = "[ ][A-Z][a-z]*[& ]*[A-Z][a-z]*[ ]";
    }else if (strcmp(argv[1], "7") == 0) {
        pattern = "[ ][A-Z][a-zA-Z '&-]*[A-Za-z]";
    } else {
        pattern = argv[1];
    }
    z = regcomp(&reg, pattern, cflags);
    if (z != 0) {
        regerror(z, &reg, ebuf, sizeof(ebuf));
        fprintf(stderr, " %s: pattern '%s' \n", ebuf, pattern);
        return 1;
    }
    /*read the files*/
    while (fgets(lbuf, sizeof(lbuf), stdin)) {
        ++lno;
        if ((z = strlen(lbuf)) > 0 && lbuf[z - 1] == '\n')
            lbuf[z - 1] = 0;
        z = regexec(&reg, lbuf, nmatch, pm, 0);
        if (z == REG_NOMATCH)
            continue;
        else if (z != 0) {
            regerror(z, &reg, ebuf, sizeof(ebuf));
            fprintf(stderr, " %s: regcom('%s') \n", ebuf, lbuf);
            return 2;
        }
        /*read the line*/
        for (x = 0; x < nmatch && pm[x].rm_so != -1; ++x) {
            strcpy(newname, substr(lbuf, pm[x].rm_so, pm[x].rm_eo));
            Trim(newname);
            if (argc == 4) {
                filename = argv[3];
                f1 = fopen(filename, "r");
                if (!f1) {
                    argc = 2;
                    printf(
                            "no dictionary file! System will use the simply dictionary!");
                } else {
                    if (checkinfile(newname) == 0) {
                        if (searchname(newname) == 0) {
                            insert(newname);
                        }
                    }
                }

            } else if (argc == 3) {
 		filename=argv[2];
                 if (checkinfile(newname) == 1) {
                    if (headflag == 0) {
                        insert(newname);
                    } else if (searchname(newname) == 0) {
                        insert(newname);
                    }
                }
            }

            if (argc == 2) {
                if (check(newname) == 1) {
                    if (headflag == 0) {
                        insert(newname);
                    } else if (searchname(newname) == 0) {
                        insert(newname);
                    }
                }
            }
        }
    }
    showname();
    printf("name of person %d and name not a person %d\n", nameofperson,
            namenotperson);

    regfree(&reg);
    return 0;
}
