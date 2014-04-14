#ifndef DEFINES_H
#define DEFINES_H

#define TEXT char

#define MAX_NODES 512
#define MAX_LEN 2048
#define ENCODE_LEN 99999
#define MAX_SYMBS 128
#define MAX_CODE_LEN 32

#define QueueFirst 1
#define QueueLast QueueSize
#define ROOT Tree[TreeSize-1]
#define TreeTop Queue[1]

#define LEVEL 0

#define Switch(A,B) ( A=B )
#define ReadFile(F) ( fgets(INPUT , MAX_LEN , F) )
#define EncodeFile(F) ( fprintf(F,"Encoded text:\n%s \n",OUTPUT) )

#endif
