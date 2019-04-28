//1850059 计1班 杨志远

#include <iostream>
using namespace std;

/* ----- 不允许定义任何形式的全局数组!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	char *p = (char *)str;
	for (; ; p++)
	{
		if (*p == '\0')
			return p - str;
	}
    return 0;
}

char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return NULL;
	if (s2 == NULL)
		return s1;
	int s1Length = tj_strlen(s1);
	char *p1 = s1 + s1Length, *p2 = (char *)s2;
	for (; *p2 != '\0'; p1++, p2++)
	{
		*p1 = *p2;
	}
	*p1 = '\0';
    return s1;
}

char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return NULL;
	if (s2 == NULL)
	{
		*s1 = '\0';
		return s1;
	}
	char *p1 = s1, *p2 = (char *)s2;
	for (; *p2 != '\0'; p1++, p2++)
	{
		*p1 = *p2;
	}
	*p1 = '\0';
    return s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	if (s1 == NULL)
		return NULL;
	if (s2 == NULL)
		return s1;
	char *p1 = s1, *p2 = (char *)s2;
	for (int i = 0; *p2 != '\0' && i < len; i++, p1++, p2++)
	{
		*p1 = *p2;
	}
    return s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? 1 : NULL) - ((s2 != NULL) ? 1 : NULL);
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2);
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	char *p1 = (char *)s1, *p2 = (char *)s2;
	for (int i = 0; i < minLength; i++, p1++, p2++)
	{
		if (*p1 != *p2)
			return *p1 - *p2;
	}
	if (s1Length > s2Length)
		return *p1;
	else if (s1Length < s2Length)
		return -*p2;
	else
		return 0;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? 1 : NULL) - ((s2 != NULL) ? 1 : NULL);
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2);
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	char *p1 = (char *)s1, *p2 = (char *)s2;
	for (int i = 0; i < minLength; i++, p1++, p2++)
	{
		if (((*(s1 + i) >= 'a' && *(s1 + i) <= 'z') ? *(s1 + i) - 'a' + 'A' : *(s1 + i)) != ((*(s2 + i) >= 'a' && *(s2 + i) <= 'z') ? *(s2 + i) - 'a' + 'A' : *(s2 + i)))
			return *p1 - *p2;
	}
	if (s1Length > s2Length)
		return *p1;
	else if (s1Length < s2Length)
		return -*p2;
	else
		return 0;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? 1 : NULL) - ((s2 != NULL) ? 1 : NULL);
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2), i = 0;
	int minLength = (s1Length > s2Length ? s2Length : s1Length);
	minLength = (minLength > len ? len : minLength);
	char *p1 = (char *)s1, *p2 = (char *)s2;
	for (; i < minLength; i++, p1++, p2++)
	{
		if (*p1 != *p2)
			return *p1 - *p2;
	}
	if (i != len && s1Length > s2Length)
		return *p1;
	else if (i != len && s1Length < s2Length)
		return -*p2;
	else
		return 0;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL || s2 == NULL)
		return ((s1 != NULL) ? 1 : NULL) - ((s2 != NULL) ? 1 : NULL);
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2), i = 0;
	int minLength = (s1Length > s2Length ? s2Length : s1Length);
	minLength = (minLength > len ? len : minLength);
	char *p1 = (char *)s1, *p2 = (char *)s2;
	for (; i < minLength; i++, p1++, p2++)
	{
		if (((*(s1 + i) >= 'a' && *(s1 + i) <= 'z') ? *(s1 + i) - 'a' + 'A' : *(s1 + i)) != ((*(s2 + i) >= 'a' && *(s2 + i) <= 'z') ? *(s2 + i) - 'a' + 'A' : *(s2 + i)))
			return *p1 - *p2;
	}
	if (i != len && s1Length > s2Length)
		return *p1;
	else if (i != len && s1Length < s2Length)
		return -*p2;
	else
		return 0;
}

char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	int strLength = tj_strlen(str);
	char *p = str;
	for (; *p != '\0'; p++)
	{
		*p = (*p >= 'a' && *p <= 'z') ? *p - 'a' + 'A' : *p;
	}
    return str;
}

char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	int strLength = tj_strlen(str);
	char *p = str;
	for (; *p != '\0'; p++)
	{
		*p = (*p >= 'A' && *p <= 'Z') ? *p - 'A' + 'a' : *p;
	}
	return str;
}

int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	char *p = (char *)str;
	for (; *p != '\0'; p++)
	{
		if (*p == ch)
			return p - str + 1;
	}
    return 0;
}

int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL || tj_strlen(str) < tj_strlen(substr))
		return 0;
	char *p1 = (char *)str, *p2 = (char *)str, *sp = (char *)substr;
	int flag = 0;
	for (; *p1 != '\0'; p1++)
	{
		flag = p1 - str;
		if (*p1 == *substr)
		{
			for (p2 = p1 + 1, sp = (char *)substr + 1; *sp != '\0'; p2++, sp++)
			{
				if (*p2 != *sp)
				{
					flag = -1;
					break;
				}
			}
			if (flag != -1)
			{
				return p1 - str + 1;
			}
		}
	}
    return 0;
}

int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	char *p = (char *)str + tj_strlen(str);
	for (; p - str != -1; p--)
	{
		if (*p == ch)
			return p - str + 1;
	}
    return 0;
}

int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL || tj_strlen(str) < tj_strlen(substr))
		return 0;
	int flag = 0, subLength = tj_strlen(substr);
	char *p1 = (char *)str + tj_strlen(str) - 1, *p2 = (char *)str, *sp = (char *)substr + subLength - 1;
	
	for (; p1 - str != -1; p1--)
	{
		flag = p1 - str;
		sp = (char *)substr + subLength - 1;
		if (*p1 == *sp)
		{
			for (p2 = p1 - 1, sp--; sp - substr != -1; p2--, sp--)
			{
				if (*p2 != *sp)
				{
					flag = -1;
					break;
				}
			}
			if (flag != -1)
			{
				return p1 - str - subLength + 2;
			}
		}
	}
	return 0;
}

char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	int strLength = tj_strlen(str);
	char *p = str, *tp = str + strLength - 1;
	for (int i = 0; i < strLength / 2; i++, p++, tp--)
	{
		char tempCh = *p;
		*p = *tp;
		*tp = tempCh;
	}
    return str;
}
