#include <stdlib.h>

int 	str_length		(const char *str) {
  if (str == NULL) {
    return -1;
  }
  int lenght = 0;
  while(str[lenght] != '\0') {
    lenght++;
  }
  return lenght;
}

char*	str_duplicate	(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  int len = str_length(str);
  char *copy = malloc((len + 1) * sizeof(char));
  if (copy == NULL) return NULL;

  for(int i = 0; i <= len; i++) {
    copy[i] = str[i];
  }
  return copy;
}

int		str_compare		(const char *stra, const char *strb) {
  int i=0;
  while(stra[i] != '\0' && strb[i] != '\0') {
    if(stra[i] != strb[i]) {
      return(stra[i]<strb[i]) ? -1 : 1;
    }
    i++;
  }

  if(stra[i] == '\0' && strb[i] == '\0') {
    return 0;
  } else if (stra[i] == '\0') {
    return -1;
  } else {
    return 1;
  }
}

int 	str_reverse 	(char *str) {
  if (str == NULL) {
    return 0;
  }

  int len = str_length(str);
  int i = 0;
  int j = len - 1;
  char temp;

  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    
    i++;
    j--;
  }

  return 1;
}

int		str_upper 		(char *str) {
  if (str == NULL) {
    return -1;
  }

  int i=0;
  int count=0;
  while(str[i] != '\0') {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
      count++;
    }
    i++;
  }

  return count;
}

int		str_lower 		(char *str) {
  if(str == NULL) {
    return -1;
  }

  int i=0;
  int count=0;
  while(str[i] != '\0') {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
      count++;
    }
    i++;
  }

  return count;
}

int 	str_copy		(char *dst, const char *src) {
  if(dst == NULL || src == NULL) {
    return -1;
  }

  int src_len = str_length(src)+1;
  int dst_len = str_length(dst)+1;

  if(dst_len < src_len) {
    return 0;
  }

  for (int i = 0; i<src_len; i++) {
    dst[i] = src[i];
  }

  return 1;
}

char* 	str_concatenate (const char *stra, const char *strb) {
  const char *ptr;
  
  if (stra == NULL && strb == NULL) return NULL;
  if (stra == NULL) return str_duplicate(strb);
  if (strb == NULL) return str_duplicate(stra);

  size_t len_a = 0, len_b = 0;
  len_a = str_length(stra);
  len_b = str_length(strb);

  char *resultado = malloc(len_a + len_b + 1);
  if (resultado == NULL) return NULL;

  char *dest = resultado;
  ptr = stra;
  while (*ptr != '\0') {
    *dest = *ptr;
    dest++;
    ptr++;
  }

  ptr = strb;
  while (*ptr != '\0') {
    *dest = *ptr;
    dest++;
    ptr++;
  }

  *dest = '\0';
  return resultado;
}

int 	str_find_first	(const char *str, const char c) {
  if(str == NULL) {
    return -1;
  }

  int pos = 0;
  while(str[pos] != '\0') {
    if(str[pos] == c) {
      return pos;
    }
    pos++;
  }
  if(c == '\0') {
    return pos;
  }

  return -1;
}

int 	str_find_last 	(const char *str, const char c) {
  if(str == NULL) {
    return -1;
  }
  int last_pos = -1;
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == c) {
      last_pos = i;
    }
    i++;
  }

  if (c == '\0') {
    return i;
  }

  return (last_pos != -1) ? last_pos : -1;
}

int 	str_count_words (const char *str) {
  if (str == NULL) {
    return -1;
  }

  int count = 0;
  int in_word = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      in_word = 0;
    } else {
      if (!in_word) {
        count++;
        in_word = 1;
      }
    }
  }

  return count;
}