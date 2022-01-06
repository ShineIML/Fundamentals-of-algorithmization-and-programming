/*
    All documentation for tasks and functions is in the document:
    Problem Set 5. QR Code.pdf
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>


void run_tests();
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
int init_blocks(const int offset, const int cols, bool blocks[offset*8][cols]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);


int main() {
    
    run_tests();
    return 0;

}


void run_tests() {

    //encode_char_test
    bool bits1[8];
    encode_char('A', bits1);
    for (int i = 0; i < 8; i++) {
        printf("%d", bits1[i]);
    }
    printf("\n");

    //decode_byte_test
    bool bits2[8] = {0,1,0,0,0,0,0,1};
    printf("%c\n", decode_byte(bits2));

    //encode_string test
    char* text = "Hello, how are you?";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for (int j = 0; j <= len; j++) {
        printf("%c: ", text[j]);
        for (int i = 0; i < 8; i++) {
            printf("%d", bytes1[j][i]);
        }
        printf("\n");
    }

    //decode_bytes test
    bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);

    //bytes_to_blocks test
    int length = 4+1, cols = 3, offset = 2;
    bool bytes3[4+1][8] = {
    {0,1,0,0,0,0,0,1},
    {0,1,1,0,1,0,0,0},
    {0,1,1,0,1,1,1,1},
    {0,1,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0}
    };
    bool blocks3[offset*8][cols];
    bytes_to_blocks(cols, offset, blocks3, length, bytes3);
    for (int j = 0; j < offset*8; j++) {
        for (int i = 0; i < cols; i++) {
            printf("%d ", (blocks3[j][i] == true) ? 1 : 0);
        }
        printf("\n");
        if (j % 8 == 7) {
            printf("\n");
        }
    }
    //blocks_to_bytes test
    bool blocks4[2*8][3] = {
    {0,0,0},
    {1,1,1},
    {0,1,1},
    {0,0,0},
    {0,1,1},
    {0,0,1},
    {0,0,1},
    {1,0,1},
    {0,0,0},
    {1,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0}
    };
    bool bytes4[length][8];
    blocks_to_bytes(3, 2, blocks4, length, bytes4);
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < 8; i++) {
            printf("%d", bytes4[j][i]);
        }
        printf("\n");
    }
}


int init_blocks(const int offset, const int cols, bool blocks[offset*8][cols]) {
    /*
    * Initializes an empty array of blocks.
    *
    * Fills an array of size `(offset * 8) by cols` with zeros. This is needed
    * to easily pad the output array of blocks with zeros, and not rely on
    * unallocated memory having zeros in place.
    *
    * Returns:
    * -1 if the passed array is NULL.
    * 0 on success.
    *
    */
    if ( !blocks ) {
        return -1;
    }

    int BITS_IN_BYTE = 8;
    for (int i = 0; i < offset * BITS_IN_BYTE; i++) {
        for (int j = 0; j < cols; j++) {
            blocks[i][j] = 0;
        }
    }
    return 0;
}


void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]) {
    /*
    * Reads an array of bytes to be encoded in a QR code, and transforms them
    * to be written into an array of QR code blocks.
    *
    * Returns early on failures. Possible failures:
    * - Source or destination arrays are NULL.
    * - Output array for blocks cannot fit the input bytes.
    */
    // fail on NULL

    if (!blocks || !bytes) {
        fprintf(stderr, "blocks or rows are NULL");
        return;
    }

    // fail if output blocks can't fit the input bytes

    if (offset * cols < rows) {
        fprintf(stderr, "Blocks (%d * %d = %d) cannot fit the bytes (%d).\n", cols, offset, cols * offset, rows);
        return;
    }
    
    int init_res = init_blocks(offset, cols, blocks);
    if (init_res != 0) {
        fprintf(stderr, "Zeroisation failed (CODE: %d).\n", init_res);
        return;
    };
    
    int BITS_IN_BYTE = 8;
    for (int i = 0; i < rows; i++) {
        for ( int j = 0; j < BITS_IN_BYTE; j++ ) {
            int offset_idx = i / cols;
            int cur_write_row = j + BITS_IN_BYTE * offset_idx;
            int cur_write_col = i % cols;
            blocks[cur_write_row][cur_write_col] = bytes[i][j];
        }
    }
}


void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]) {
    /*
    * Reads QR code blocks and decodes them into bytes.
    *
    * Returns early on failures.
    * Possible failures:
    * - Source or destination arrays are NULL.
    * - There are insufficient blocks to decode specified bytes.
    *
    */

    if (!blocks || !bytes) {
        fprintf(stderr, "blocks or rows are NULL");
        return;
    }

    // fail if output blocks can't fit the input bytes

    if (offset * cols < rows) {
        fprintf(stderr, "There are insufficient blocks (%d * %d = %d) to read the bytes (%d).\n", cols, offset, cols * offset, rows);
        return;
    }

    int BITS_IN_BYTE = 8;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < BITS_IN_BYTE; j++) {
            int offset_idx = i / cols;
            int cur_read_row = j + BITS_IN_BYTE * offset_idx;
            int cur_read_col = i % cols;
            bytes[i][j] = blocks[cur_read_row][cur_read_col];
        }
    }
}


void encode_char(const char character, bool bits[8]) {
    
    char tmp = character;
    
    for (int i = 8; i > 0; i--) {
        bits[i-1] = tmp % 2;
        tmp/=2;
    }       
}


char decode_byte(const bool bits[8]) {
    
    int counter = 0;
    char tmp = 0;

    for (int i = 8; i > 0; i--) {
        tmp = bits[i-1] * pow(2,counter) + tmp;
        counter++;
    }
    return tmp;
}


void encode_string(const char string[], bool bytes[strlen(string)+1][8]) {
    
    int len = strlen(string);
    bool tmp[8];
    
    if (string == NULL) {
        bytes = 0;
    }

    for (int i = 0; len >= i; i++) {
        char c = string[i];
        encode_char(c, tmp);
        for (int j = 0; 8 > j; j++) {
            bytes[i][j] = tmp[j];
        }
    }
}


void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]) {
    
    bool tmp[8];
    int len = 8;        
    
    if (rows == 0) {
        string = 0;
    }

    for (int i = 0; rows > i; i++) {
        for (int j = 0; len > j; j++) {
            tmp[j] = bytes[i][j];
        }
        if (tmp != NULL) {
            string[i] = decode_byte(tmp);
        }
    }
}
