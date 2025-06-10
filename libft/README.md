# Libft: Library of C functions

## Summary
Libft is a project that involves programming a C library with general-purpose functions.
The goal is to understand how common libc functions work, how to implement them, and how to use them, creating your own library that will serve as the foundation for future C projects.

## CHARACTERS
|                                      Function                                         |                        Description                        |
| :-----------------------------------------------------------------------------------: | :-------------------------------------------------------: |
| [ft_isalnum](https://github.com/ines-sainz/Libft/blob/master/characters/ft_isalnum.c) | Checks if the character is alphanumeric (letter or digit) |
| [ft_isalpha](https://github.com/ines-sainz/Libft/blob/master/characters/ft_isalpha.c) | Checks if the character is an alphabetic letter           |
| [ft_isascii](https://github.com/ines-sainz/Libft/blob/master/characters/ft_isascii.c) | Checks if the character is an ASCII character (0 to 127)  |
| [ft_isdigit](https://github.com/ines-sainz/Libft/blob/master/characters/ft_isdigit.c) | Checks if the character is a digit (0 to 9)               |
| [ft_isprint](https://github.com/ines-sainz/Libft/blob/master/characters/ft_isprint.c) | Checks if the character is printable, including space     |

## CONVERSIONS
|                                        Function                                        |                  Description                    |
| :------------------------------------------------------------------------------------: | :---------------------------------------------: |
| [ft_atoi](https://github.com/ines-sainz/Libft/blob/master/conversions/ft_atoi.c)       | Converts a string to an integer                 |
| [ft_itoa](https://github.com/ines-sainz/Libft/blob/master/conversions/ft_itoa.c)       | Converts an integer to a null-terminated string |
| [ft_tolower](https://github.com/ines-sainz/Libft/blob/master/conversions/ft_tolower.c) | Convert an uppercase letter to lowercase        |
| [ft_toupper](https://github.com/ines-sainz/Libft/blob/master/conversions/ft_toupper.c) | Convert a lowercase letter to uppercase         |

## FILE DESCRIPTORS
|                                                 Function                                          |                         Description                         |
| :-----------------------------------------------------------------------------------------------: | :---------------------------------------------------------: |
| [ft_putchar_fd](https://github.com/ines-sainz/Libft/blob/master/file_descriptors/ft_putchar_fd.c) | Outputs a character to a file descriptor                    |
| [ft_putendl_fd](https://github.com/ines-sainz/Libft/blob/master/file_descriptors/ft_putendl_fd.c) | Outputs a string to a file descriptor followed by a newline |
| [ft_putnbr_fd](https://github.com/ines-sainz/Libft/blob/master/file_descriptors/ft_putnbr_fd.c)   | Outputs a integer to a file descriptor                      |
| [ft_putstr_fd](https://github.com/ines-sainz/Libft/blob/master/file_descriptors/ft_putstr_fd.c)   | Outputs a string to a file descriptor                       |

## MEMORY
|                                         Function                                  |                                    Description                                    |
| :-------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------: |
| [ft_bzero](https://github.com/ines-sainz/Libft/blob/master/memory/ft_bzero.c)     | Sets all bytes in a block of memory to zero                                       |
| [ft_calloc](https://github.com/ines-sainz/Libft/blob/master/memory/ft_calloc.c)   | Allocates memory for an array and initializes all bytes to zero                   |
| [ft_memchr](https://github.com/ines-sainz/Libft/blob/master/memory/ft_memchr.c)   | Searches for the first occurrence of a byte value in a block of memory            |
| [ft_memcmp](https://github.com/ines-sainz/Libft/blob/master/memory/ft_memcmp.c)   | Compares two blocks of memory byte by byte and returns the difference             |
| [ft_memcpy](https://github.com/ines-sainz/Libft/blob/master/memory/ft_memcpy.c)   | Copies a specified number of bytes from a source memory location to a destination |
| [ft_memmove](https://github.com/ines-sainz/Libft/blob/master/memory/ft_memmove.c) | Copies a specified number of bytes between memory areas, handling overlap safely  |
| [ft_memset](https://github.com/ines-sainz/Libft/blob/master/memory/ft_memset.c)   | Sets a block of memory to a specified byte value                                  |

## STRINGS
|                                        Function                                      |                                                    Description                                                     |
| :----------------------------------------------------------------------------------: | :----------------------------------------------------------------------------------------------------------------: |
| [ft_split](https://github.com/ines-sainz/Libft/blob/master/strings/ft_split.c)       | Splits a string into an array of substrings using a delimiter                                                      |
| [ft_strchr](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strchr.c)     | Finds the first occurrence of a character in a string                                                              |
| [ft_strdup](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strdup.c)     | Creates a newly allocated copy of a given string                                                                   |
| [ft_striteri](https://github.com/ines-sainz/Libft/blob/master/strings/ft_striteri.c) | Applies a function to each character of a string, passing its index and address                                    |
| [ft_strjoin](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strjoin.c)   | Concatenates two strings into a newly allocated string                                                             |
| [ft_strlcat](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strlcat.c)   | Appends a source string to a destination string, ensuring the total length does not exceed the size                |
| [ft_strlcpy](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strlcpy.c)   | Copies a source string to a destination buffer, ensuring not exceeding the size                                    |
| [ft_strlen](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strlen.c)     | Returns the number of characters in a string before the null terminator                                            |
| [ft_strmapi](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strmapi.c)   | Creates a new string by applying a function to each character of the input string, passing its index and character |
| [ft_strncmp](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strncmp.c)   | Compares a number of characters of two strings and returns the difference between the first different characters   |
| [ft_strnstr](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strnstr.c)   | Searches for the first occurrence of a substring in a string, but only within the first n characters               |
| [ft_strrchr](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strrchr.c)   | Finds the last occurrence of a character in a string                                                               |
| [ft_strtrim](https://github.com/ines-sainz/Libft/blob/master/strings/ft_strtrim.c)   | Removes all specified characters from the start and end of a string and returns the trimmed result                 |
| [ft_substr](https://github.com/ines-sainz/Libft/blob/master/strings/ft_substr.c)     | Creates and returns a new string containing a part of the original string                                          |

## LISTS
|                                              Function                                            |                                             Description                                         |
| :----------------------------------------------------------------------------------------------: | :---------------------------------------------------------------------------------------------: |
| [ft_lstadd_back](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstadd_back_bonus.c)   | Adds a new node to the end of a linked list, updating the list pointer if it's initially empty  |
| [ft_lstadd_front](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstadd_front_bonus.c) | Adds a new node to the beginning of a linked list by updating the head to point to the new node |
| [ft_lstclear](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstclear_bonus.c)         | Frees and deletes all nodes of a linked list using a given delete function                      |
| [ft_lstdelone](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstdelone_bonus.c)       | Deletes a single list node by freeing its content with a given function and the node itself     |
| [ft_lstiter](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstiter_bonus.c)           | Applies a given function to the content of each node in the linked list                         |
| [ft_lstlast](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstlast_bonus.c)           | Returns the last node of the linked list                                                        |
| [ft_lstmap](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstmap_bonus.c)             | Creates a new linked list by applying a function to each node’s content from the original list  |
| [ft_lstnew](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstnew_bonus.c)             | Creates a new list node with the given content and sets its next pointer to NULL                |
| [ft_lstsize](https://github.com/ines-sainz/Libft/blob/master/lists/ft_lstsize_bonus.c)           | Counts and returns the number of nodes in a linked list                                         |
