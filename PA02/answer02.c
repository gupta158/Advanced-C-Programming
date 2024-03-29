#include "pa02.h"

/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s)
{	
	char str = 'a';
	int length = 0;
	int var = 0;

    while (str != '\0') 
	{
        str = s[var];
		var++;
        length++;
    }
	
    return length - 1;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c)
{
	char str = 'a';
	int count = 0;
	int var = 0;
	
    while (str != '\0') 
	{
        str = s[var];
		if(str == c)
		{
			count++;
		}
		var++;
    }
	
    return count;

}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)
{
	char str = 'a';
	int var = 0;
	
    while (str != '\0') 
	{
        str = s[var];
		if(str <= 122 && str >= 97)
		{
			str = str - 32;
			s[var] = str;
		}
		var++;
    }	

}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s)
{
	char str = 'a';
	int var = 0;
	
    while (str != '\0') 
	{
        str = s[var];
		if(str <= 90 && str >= 65)
		{
			str = str + 32;
			s[var] = str;
		}
		var++;
    }
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2)
{
	char str = 'a';
	int var = 0;

    while (str != '\0') 
	{
        str = s2[var];
		s1[var] = str;
		var++;
    }
	
}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)
{
   	char str = 'a';
	int var = 0;
	s1[num] = '\0';
    while ((str != '\0') && (var < num)) 
	{
        str = s2[var];
		s1[var] = str;
		var++;
    }

}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) 
{
   
	char str = 'a';
	int var = 0;
	int length = 0;
	
	length = my_strlen(s1);
    while (str != '\0') 
	{
        str = s2[var];
		s1[var + length] = str;
		var++;
    }   
}

/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)
{
   	char str = 'a';
	int var = 0;
	int length = 0;
	
	length = my_strlen(s1);
    while (str != '\0' && var < num) 
	{
        str = s2[var];
		s1[var + length] = str;
		var++;
    }   
}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2)
{
   	char str = 'a';
	int var = 0;
	int var2 = 0;
	int length;
	int pos;
	
	length = my_strlen(s2);
	while(str != '\0' && var2 != length)
	{
		str = s1[var];
		if(str == s2[var2])
		{
			var2++;
		}
		else
		{
			var2 = 0;
		}
		
		var++;
	}
	
	if(var2 == length)
	{
		pos = var - length;
		return &s1[pos];
	}
	
    return NULL;
}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
  	char str = 'a';
	int var = 0;
	int length1;
	int length2;
	
	length2 = my_strlen(s2);
	length1 = my_strlen(s1);
	
	if(pos < length1)
	{
		var = length1 ;
		while (var >= 0)
		{
			str = s1[var];
			s1[var+length2] = str;
			var--;
		}
		//s1[length1+length2] = '/0';
		var = 0;
		while (var < length2) 
		{
			str = s2[var];
			s1[var] = str;
			var++;
		}
	}
	
	else
	{
		while (var <= length2) 
		{
			str = s2[var];
			s1[pos+var] = str;
			var++;
		}
		// s1[var] = '/0';
		
	}	
	// if(pos < length)
	// {
		// while(var < length)
		// {
			// s1[var + length] = s1[var];
			// var++;
		// }
		// var = 0;

		// while (str != '\0') 
		// {
			// str = s2[var];
			// s1[var] = str;
			// var++;
		// }
	// }
	
	// else
	// {
		// while (str != '\0') 
		// {
			// str = s2[var];
			// s1[pos + var] = str;
			// var++;
		// }
	// }
	
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)
{
	int var = 0;
	int length2;
	char str = 'a';
		
	length2 = my_strlen(s);
	if(length > (pos + length2))
	{
		s[pos] = '\0';
	}
	
	else
	{
		while(str != '\0')
		{
			s[pos + var] = s[pos + length + var];
			str = s[pos+var];
			var++;
		}	
	}
	

}

