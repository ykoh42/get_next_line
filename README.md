# Welcome to the GNL! ![score](https://img.shields.io/badge/115/100-5cb85c?style=for-the-badge) 
> Get_next_line(GNL) is the fuction, which returns a line ending with a newline, read from a file descriptor.

## Tester

- **Get_Next_Line_Tester** by [Hellio404](https://github.com/Hellio404)  

    ```shell
    git clone https://github.com/Hellio404/Get_Next_Line_Tester.git
    ```

- **42TESTERS-GNL** by [Mazoise](https://github.com/Mazoise)

    ```shell
    git clone https://github.com/Mazoise/42TESTERS-GNL.git
    ```

- **gnlkiller** by [DontBreakAlex](https://github.com/DontBreakAlex)

    ```shell
    git clone https://github.com/DontBreakAlex/gnlkiller.git
    ```

- **GNL_lover** by [charMstr](https://github.com/charMstr)

    ```shell
    git clone https://github.com/charMstr/GNL_lover.git
    ```

- **42cursus_gnl_tests** by [mrjvs](https://github.com/mrjvs)

    ```shell
    git clone https://github.com/mrjvs/42cursus_gnl_tests.git
    ```

- **gnl-war-machine-v2019** by [Alexandre94H](https://github.com/Alexandre94H)

    ```shell
    git clone https://github.com/Alexandre94H/gnl-war-machine-v2019.git
    ```

---

## Mandatory part
* [get_next_line.h](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line.h)
* [get_next_line.c](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line.c)
* [get_next_line_utils.c](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line_utils.c)

### Rules
1. The function(get_next_line) will store, in the parameter "line", a line that has been read from the file descriptors.
2. It should be memory leak free.
3. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
4. The string stored in the parameter "line" should not contained any '\n'.
5. The parameter(line) is the address of a pointer to a character that will be used to store the line read.
6. The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed (meaning read has returned 0), or if an error has happened respectively.
7. When you've reached the End Of File, you must store the current buffer in "line". If the buffer is empty you must store an empty string in "line".
8. When you've reached the End Of File, your function should keep 0 memory allocated with malloc except the last buffer that you should have stored in "line".
9. What you've stored in "line" should be free-able.
10. Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.
11. Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.
12. Finally we consider that get_next_line has an undefined behavior when reading from a binary file.

---

## Bonus part
* [get_next_line_bonus.h](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line_bonus.h)
* [get_next_line_bonus.c](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line_bonus.c)
* [get_next_line_utils_bonus.c](https://github.com/kohyounghwan/get_next_line/blob/master/get_next_line_utils_bonus.c)

### Rules
In addition to the mandatory part, the following rules are added:

1. It should work on the file descriptors between several calls of get_next_line.
2. It should use a single static variable.