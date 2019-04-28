//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
using namespace std;

int tj_strlen(const char str[])
{
	for (int i = 0; ; i++)
	{
		if (str[i] == '\0')
			return i;
	}
}

int tj_strcat(char s1[], const char s2[])
{
	int s1Length = tj_strlen(s1), i = 0;
	for (i = 0; s2[i] != '\0'; i++)
	{
		s1[s1Length + i] = s2[i];
	}
	s1[s1Length + i + 1] = '\0';
	return 0;
}

int tj_strcpy(char s1[], const char s2[])
{
	int s2Length = tj_strlen(s2);
	for (int i = 0; i < s2Length; i++)
	{
		s1[i] = s2[i];
	}
	s1[s2Length] = '\0';
	return 0;
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	int s2Length = tj_strlen(s2);
	for (int i = 0; i < s2Length && i < len; i++)
	{
		s1[i] = s2[i];
	}
	return 0;
}

int tj_strcmp(const char s1[], const char s2[])
{
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2);
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	for (int i = 0; i < minLength; i++)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] - s2[i];
		}
	}
	if (s1Length > s2Length)
		return s1[s1Length - 1];
	else if (s1Length < s2Length)
		return -s2[s2Length - 1];
	else
		return 0;
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2);
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	for (int i = 0; i < minLength; i++)
	{
		if (((s1[i] >= 'a' && s1[i] <= 'z') ? s1[i] - 'a' + 'A' : s1[i]) != ((s2[i] >= 'a' && s2[i] <= 'z') ? s2[i] - 'a' + 'A' : s2[i]))
		{
			return s1[i] - s2[i];
		}
	}
	if (s1Length > s2Length)
		return s1[s1Length - 1];
	else if (s1Length < s2Length)
		return -s2[s2Length - 1];
	else
		return 0;
}

int tj_strncmp(const char s1[], const char s2[], const int len)
{
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2), i = 0;
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	for (i = 0; i < minLength && i < len; i++)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] - s2[i];
		}
	}
	if (i != len && s1Length > s2Length)
		return s1[s1Length - 1];
	else if (i != len && s1Length < s2Length)
		return -s2[s2Length - 1];
	else
		return 0;
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	int s1Length = tj_strlen(s1), s2Length = tj_strlen(s2), i = 0;
	int minLength = s1Length > s2Length ? s2Length : s1Length;
	for (i = 0; i < minLength && i < len; i++)
	{
		if (((s1[i] >= 'a' && s1[i] <= 'z') ? s1[i] - 'a' + 'A' : s1[i]) != ((s2[i] >= 'a' && s2[i] <= 'z') ? s2[i] - 'a' + 'A' : s2[i]))
		{
			return s1[i] - s2[i];
		}
	}
	if (i != len && s1Length > s2Length)
		return s1[s1Length - 1];
	else if (i != len && s1Length < s2Length)
		return -s2[s2Length - 1];
	else
		return 0;
}
int tj_strupr(char str[])
{
	int strLength = tj_strlen(str);
	for (int i = 0; i < strLength; i++)
	{
		str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 'a' + 'A' : str[i];
	}
	return 0;
}

int tj_strlwr(char str[])
{
	int strLength = tj_strlen(str);
	for (int i = 0; i < strLength; i++)
	{
		str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' + 'a' : str[i];
	}
	return 0;
}

int tj_strchr(const char str[], const char ch)
{
	int strLength = tj_strlen(str);
	for (int i = 0; i < strLength; i++)
	{
		if (str[i] == ch)
			return i + 1;
	}
	return 0;
}

int tj_strstr(const char str[], const char substr[])
{
	int strLength = tj_strlen(str);
	int substrLength = tj_strlen(substr);
	int flag = 0;
	for (int i = 0; i < strLength; i++)
	{
		flag = i;
		if (str[i] == substr[0])
		{
			for (int j = 1; j < substrLength; j++)
			{
				if (str[i + j] != substr[j])
				{
					flag = -1;
					break;
				}
			}
			if (flag != -1)
			{
				return i + 1;
			}
		}
	}
	return 0;
}

int tj_strrchr(const char str[], const char ch)
{
	int strLength = tj_strlen(str);
	for (int i = strLength - 1; i >= 0; i--)
	{
		if (str[i] == ch)
			return i + 1;
	}
	return 0;
}

int tj_strrstr(const char str[], const char substr[])
{
	int strLength = tj_strlen(str);
	int substrLength = tj_strlen(substr);
	int flag = 0;
	for (int i = strLength - 1; i >= 0; i--)
	{
		flag = i;
		if (str[i] == substr[substrLength - 1])
		{
			for (int j = 0; j < substrLength; j++)
			{
				if (str[i - j] != substr[substrLength - 1 - j])
				{
					flag = -1;
					break;
				}
			}
			if (flag != -1)
			{
				return i - substrLength + 2;
			}
		}
	}
	return 0;
}

int tj_strrev(char str[])
{
	int strLength = tj_strlen(str);
	for (int i = 0; i < strLength / 2; i++)
	{
		char tempCh = str[i];
		str[i] = str[strLength - 1 - i];
		str[strLength - 1 - i] = tempCh;
	}
	return 0;
}