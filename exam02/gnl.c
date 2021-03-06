#include <stdlib.h>
#include <unistd.h>

char *gnl(size_t size, int fd)
{
    char *ret, word_one = 0, read_word = read(fd, &word_one, 1);
    if (read_word < 0 || read_word == 0 && size == 0)
        return (NULL);
    if (read_word == 0 || word_one == '\n')
        ret = malloc(size + 2);
    else
        ret = gnl(size + 1, fd);
    if (ret)
    {
        ret[size] = word_one;
        ret[size + 1] = ret[size + 1] * (word_one != '\n');
    }
    return ret;
}

char *get_next_line(int fd)
{
    return (gnl(0, fd));
}

/*
// 원작자 : cjeon
// char *_(size_t a,int b){char*t,c=0,k=read(b,&c,1);if(k<0||k==0&&a==0)return NULL;if(k==0||c=='\n')t=malloc(a+2);else t=_(a+1,b);if(t)t[a]=c,t[a+1]=t[a+1]*(c!='\n'); return t;}
// char *get_next_line(int fd){return _(0,fd);}
*/